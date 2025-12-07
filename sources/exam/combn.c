/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   combn.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 15:28:40 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/03 17:35:41 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <unistd.h>
#include <stdbool.h>

static void ft_print(uint32_t *ptr, size_t length)
{
	for (size_t i = 0; i < length; i++)
		printf("%d ", ptr[i]);
	printf("\n");
}

// 1 3 0 5 4 = 2
static inline
void	set_lut(uint32_t *index_array, int32_t *lut, size_t count, size_t max_count)
{
	size_t	i;

	i = 0;
	while (i < max_count)
	{
		lut[i] = i;
		i++;
	}
	i = 0;
	while (i < count)
	{
		lut[index_array[i]] = -1;	// Already in use
		i++;
	}
}

// 1 3 0 5 4 = 2
static inline
uint32_t	ft_min_unique(int32_t *lut)
{
	size_t	i;

	i = 0;
	while (lut[i] == -1)
		i++;
	lut[i] = -1;
	return (i);
}

static
bool	increment(uint32_t *index_array, size_t perm_size, size_t max_size)
{
	size_t	i;
	int32_t	lut[max_size];

	i = perm_size - 1;
	while (index_array[i] + 1 > max_size - 1)	// Overflow
	{
		if (i == 0)
			return (false);
		i--;
	}
	index_array[i]++;	// If it is unique, normal behavior. otherwise, get min unique value
	set_lut(index_array, lut, i + 1, max_size);	// Set everything to the left as used
											// Then everything in tail is set according to LUT
	while (i < perm_size)
	{
		index_array[i] = ft_min_unique(lut);
		i++;
	}
	return (true);
}

// static
// bool	increment(uint32_t *index_array, size_t perm_size, size_t max_size)
// {
// 	size_t	i;

// 	index_array[perm_size - 1] += 1;
// 	i = perm_size - 1;
// 	while (index_array[i] > max_size - (perm_size - i))
// 	{
// 		if (i == 0)
// 			return (false);
// 		index_array[i - 1] += 1;
// 		i--;
// 	}
// 	i++;
// 	while (i < perm_size)
// 	{
// 		index_array[i] = index_array[i - 1] + 1;
// 		i++;
// 	}
// 	return (true);
// }

int	main()
{
	size_t		i;
	size_t		count = 5;
	size_t		perm_size = 5;
	uint32_t	values[count];
	size_t		total_count = 0;

	for (i = 0; i < count; i++)
		values[i] = i;
	while(true)
	{
		ft_print(values, perm_size);
		total_count++;
		if (increment(values, perm_size, count) == false)
			break;
	}
	printf("%d", total_count);
}

// int	main()
// {
// 	size_t		i;
// 	size_t		count = 9;
// 	size_t		perm_size = 1;
// 	uint32_t	values[count];
// 	size_t		total_count = 0;

// 	for (i = 0; i < count; i++)
// 		values[i] = i;
// 	while(perm_size < count)
// 	{
// 		// ft_print(values, perm_size);
// 		total_count++;
// 		if (increment(values, perm_size, count) == false)
// 		{
// 			for (i = 0; i < count; i++)
// 				values[i] = i;
// 			perm_size++;
// 		}
// 	}
// 	printf("%d", total_count);
// }