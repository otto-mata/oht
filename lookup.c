/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:58:18 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	*ht_lookup(t_table *table, char const *key)
{
	uint32_t	index;
	t_ht_entry	*entry;

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
