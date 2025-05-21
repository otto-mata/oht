/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hashtable.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/01/29 06:26:58 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:43 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef OHT_H
# define OHT_H
# define OHT_CAPACITY 32
# define OHT_KEY_LENGTH 33
# define FNV_OFFSET 14695981039346656037UL
# define FNV_PRIME 1099511628211UL
# include <stdint.h>
# include <stdlib.h>
# include <string.h>
typedef struct s_ht_entry	t_ht_entry;
typedef struct s_table		t_table;

struct						s_ht_entry
{
	char					key[OHT_KEY_LENGTH];
	void					*value;
	t_ht_entry				*next;
};

struct						s_table
{
	t_ht_entry				**entries;
	uint32_t				size;
	uint32_t				capacity;
};

int							ht_keys(t_table *table, char *keys[OHT_KEY_LENGTH]);
void						ht_teardown(t_table **table, void (*fn_free)(void *));
int							ht_delete(t_table *table, char const *key,
								void (*fn_free)(void *));
void						*ht_lookup(t_table *table, char const *key);
void						*ht_insert(t_table *table, char const *key,
								void *value);
t_table						*ht_create(int capacity);

#endif
