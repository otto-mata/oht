/* ************************************************************************** */
/*                                                                            */
/*                                                                            */
/*   oht.c                                                ┌─┐┌┬┐┌┬┐┌─┐        */
/*                                                        │ │ │  │ │ │        */
/*   By: tblochet <tblochet@student.42.fr>                └─┘ ┴  ┴ └─┘        */
/*                                                        ┌┬┐┌─┐┌┬┐┌─┐        */
/*   Created: 2025/01/29 06:43:05 by tblochet             │││├─┤ │ ├─┤        */
/*   Updated: 2025/01/29 07:53:40 by tblochet             ┴ ┴┴ ┴ ┴ ┴ ┴        */
/*                                                                            */
/* ************************************************************************** */

#include "oht.h"

uint64_t	hash_region(void *region, size_t n)
{
	uint64_t		hash;
	unsigned char	*p;
	size_t			i;

	hash = FNV_OFFSET;
	p = region;
	i = 0;
	while (i < n)
	{
		hash ^= (uint64_t)(p[i]);
		hash *= FNV_PRIME;
		i++;
	}
	return (hash);
}

uint64_t	hash_str(char const *s)
{
	size_t	len;

	len = 0;
	while (s[len])
		len++;
	return (hash_region((void *)s, len));
}

uint32_t	hash_key(char const *key, int capacity)
{
	return (hash_str(key) % capacity);
}

t_oht	*oht_create(__attribute__((unused)) int capacity)
{
	t_oht	*table;

	table = malloc(sizeof(t_oht));
	if (!table)
		return (0);
	table->size = 0;
	table->capacity = OHT_CAPACITY;
	table->entries = calloc(table->capacity, sizeof(t_oht_entry *));
	if (!table->entries)
	{
		free(table);
		return (0);
	}
	return (table);
}
/*
Maybe separate update / insert for more specific usage
*/
void	*oht_insert(t_oht *table, char const *key, void *value)
{
	uint32_t	index;
	t_oht_entry	*entry;
	void		*past_value;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	while (entry)
	{
		if (strcmp(key, entry->key) == 0)
		{
			past_value = entry->value;
			entry->value = value;
			return (past_value);
		}
		entry = entry->next;
	}
	entry = calloc(1, sizeof(t_oht_entry));
	if (!entry)
		return (0);
	strcpy(entry->key, key);
	entry->value = value;
	entry->next = table->entries[index];
	table->entries[index] = entry;
	table->size++;
	return (0);
}

void	*oht_lookup(t_oht *table, char const *key)
{
	uint32_t	index;
	t_oht_entry	*entry;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	while (entry)
	{
		if (strcmp(key, entry->key) == 0)
			return (entry->value);
		entry = entry->next;
	}
	return (0);
}

int	oht_delete(t_oht *table, char const *key, void (*fn_free)(void *))
{
	uint32_t	index;
	t_oht_entry	*entry;
	t_oht_entry	*prev;

	index = hash_key(key, table->capacity);
	entry = table->entries[index];
	prev = 0;
	while (entry)
	{
		if (strcmp(entry->key, key) == 0)
		{
			if (prev)
				prev->next = entry->next;
			else
				table->entries[index] = entry->next;
			fn_free(entry->value);
			table->size--;
			return (1);
		}
		prev = entry;
		entry = entry->next;
	}
	return (0);
}

void	oht_free(t_oht *table, void (*fn_free)(void *))
{
	t_oht_entry	*entry;
	t_oht_entry	*temp;
	uint32_t	index;

	index = 0;
	while (index < table->capacity)
	{
		entry = table->entries[index];
		while (entry)
		{
			temp = entry;
			entry = entry->next;
			fn_free(temp->value);
			free(temp);
		}
		index++;
	}
	free(table->entries);
	free(table);
}

/**
 * @brief Writes the keys stored in TABLE in the KEYS array.
 * @param table Hashtable to retrieve keys from.
 * @param keys Destination for the keys.
 * @return ERROR CODE TBD.
 *
 * Important:
 * The function expects KEYS to be large enough.
 * If KEYS can't accomodate for all the keys, the behaviour of this function is
 * undefined.
 */
int	oht_keys(t_oht *table, char keys[][OHT_KEY_LENGTH])
{
	uint32_t	index;
	t_oht_entry	*entry;
	uint32_t	keys_i;

	index = 0;
	keys_i = 0;
	while (index < table->capacity)
	{
		entry = table->entries[index];
		while (entry)
		{
			strcpy(keys[keys_i], entry->key);
			keys_i++;
			entry = entry->next;
		}
		index++;
	}
	return (0);
}
