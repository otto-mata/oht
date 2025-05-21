/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 07:21:37 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"
#include <stdio.h>

int	main(void)
{
	t_table	*table;

	table = ht_create(32);
	if (!table)
		return (dprintf(2,
				"Can't create table (most likely malloc/calloc fail).\n"));
	char *value = strdup("oui bonjour je suis une valeur");
	char key[OHT_KEY_LENGTH] = "big_clef_mon_gars";
	ht_insert(table, key, value);
	ht_insert(table, "ssss", strdup("gngngngn"));
	void *stored = ht_lookup(table, key);
	printf("Stored: %s (was %s)\n", (char *)stored, value);
	char keys[32][33];	
	ht_keys(table, keys);
	printf("Key for this value is: %s\n", *keys);
	ht_delete(table, key, free);
	stored = ht_lookup(table, key);
	printf("Deleted record, should be null: %s\n", (char*)stored);
	ht_teardown(table, free);
	
	return (0);
}
