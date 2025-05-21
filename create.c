/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   create.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:59:16 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

t_table	*ht_create(int capacity)
{
	t_table *table;

	table = malloc(sizeof(t_table));
	if (!table)
		return (0);
	table->size = 0;
	table->capacity = capacity;
	table->entries = malloc(table->capacity * sizeof(t_ht_entry *));
	if (!table->entries)
	{
		free(table);
		return (0);
	}
	return (table);
}
