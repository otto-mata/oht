/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   hash_key.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: tblochet <tblochet@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/21 16:59:56 by tblochet          #+#    #+#             */
/*   Updated: 2025/05/21 17:03:18 by tblochet         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "hashtable.h"

uint32_t	hash_key(char const *key, int capacity)
{
	size_t			len;
	uint64_t		hash;
	unsigned char	*p;
	size_t			i;

	len = 0;
	hash = FNV_OFFSET;
	p = (unsigned char *)key;
	i = 0;
	while (key[len])
		len++;
	while (i < len)
	{
		hash ^= (uint64_t)(p[i]);
		hash *= FNV_PRIME;
		i++;
	}
	return (hash % capacity);
}
