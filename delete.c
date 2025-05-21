/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   delete.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:57:50 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

int	ht_delete(t_table *table, char const *key, void (*fn_free)(void *))
{
	uint32_t	index;
	t_ht_entry	*entry;
	t_ht_entry	*prev;

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
