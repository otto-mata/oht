/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   teardown.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:57:24 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

void	ht_teardown(t_table **table, void (*fn_free)(void *))
{
	t_ht_entry	*entry;
	t_ht_entry	*temp;
	uint32_t	index;

	index = 0;
	while (index < (*table)->capacity)
	{
		entry = (*table)->entries[index];
		while (entry)
		{
			temp = entry;
			entry = entry->next;
			fn_free(temp->value);
			free(temp);
		}
		index++;
	}
	free((*table)->entries);
	free(*table);
	*table = 0;
}
