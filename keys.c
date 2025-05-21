/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   keys.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:43:05 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:05:22 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

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
int	ht_keys(t_table *table, char *keys[OHT_KEY_LENGTH])
{
	uint32_t	index;
	t_ht_entry	*entry;
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
