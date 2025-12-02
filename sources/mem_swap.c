/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   mem_swap.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 16:39:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:33:42 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include "libft_memory.h"

void	ft_swap(void *a_void, void *b_void, size_t length)
{
	size_t	buffer[256 / sizeof(size_t)];
	uint8_t	*a;
	uint8_t	*b;

	a = (uint8_t *) a_void;
	b = (uint8_t *) b_void;
	while (length >= 256)
	{
		ft_memcpy(buffer, a, 256);
		ft_memcpy(a, b, 256);
		ft_memcpy(b, buffer, 256);
		a += 256;
		b += 256;
		length -= 256;
	}
	ft_memcpy(buffer, a, length);
	ft_memcpy(a, b, length);
	ft_memcpy(b, buffer, length);
}

void	ft_swap8(void *a, void *b)
{
	uint8_t	temp;

	temp = *(uint8_t *) a;
	*(uint8_t *) a = *(uint8_t *) b;
	*(uint8_t *) b = temp;
}

void	ft_swap32(void *a, void *b)
{
	uint32_t	temp;

	temp = *(uint32_t *) a;
	*(uint32_t *) a = *(uint32_t *) b;
	*(uint32_t *) b = temp;
}

void	ft_swap64(void *a, void *b)
{
	uint64_t	temp;

	temp = *(uint64_t *) a;
	*(uint64_t *) a = *(uint64_t *) b;
	*(uint64_t *) b = temp;
}
