/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   insert.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:58:45 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	*ht_insert(t_table *table, char const *key, void *value)
{
	uint32_t	index;
	t_ht_entry	*entry;
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
	entry = malloc(sizeof(t_ht_entry));
	if (!entry)
		return (0);
	strcpy(entry->key, key);
	entry->value = value;
	entry->next = table->entries[index];
	table->entries[index] = entry;
	table->size++;
	return (0);
}
