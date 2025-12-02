/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_merge_rsort.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/24 14:57:20 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/24 15:23:11 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdio.h>
#include <stdlib.h>
#include <stdint.h>

void	merge(int32_t *array, int32_t *temp, uint32_t left, uint32_t right)
{
	uint32_t		i;
	uint32_t		j;
	uint32_t		k;
	const uint32_t	mid = left + (right - left) / 2;

	i = left;
	while (i <= mid)
	{
		temp[i] = array[i];
		i++;
	}
	i = left;
	j = mid + 1;
	k = left;
	while (i <= mid && j <= right)
	{
		if (temp[i] <= array[j])
			array[k++] = temp[i++];
		else
			array[k++] = array[j++];
	}
	while (i <= mid)
		array[k++] = temp[i++];
}

void	recurse(int32_t *array, int32_t *temp, uint32_t left, uint32_t right)
{
	uint32_t	mid;

	if (left < right)
	{
		mid = left + (right - left) / 2;
		recurse(array, temp, left, mid);
		recurse(array, temp, mid + 1, right);
		merge(array, temp, left, right);
	}
}

void	ft_merge_sort(int32_t *array, size_t length)
{
	int32_t	buffer[4096];
	int32_t	*ptr;

	if (length > 4096)
	{
		ptr = (int32_t *)malloc(length * sizeof(int32_t));
		if (ptr == NULL)
			return ;
	}
	else
		ptr = buffer;
	iterativeMergeSort(array, ptr, length);
	if (length > 4096)
		free(ptr);
}

int main()
{
    int32_t arr[] = {12, 11, 13, 5, 6, 7, 9, 4, 100, 20};
    int32_t n = sizeof(arr) / sizeof(arr[0]);

    ft_merge_sort(arr, n);
    for (int i = 0; i < n; i++)
        printf("%d ", arr[i]);
    return 0;
}