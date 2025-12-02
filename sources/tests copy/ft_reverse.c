/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_reverse.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 20:37:23 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 23:57:32 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

void	ft_reverse64(void *array_void, size_t length)
{
	uint64_t	*start;
	uint64_t	*end;
	uint64_t	buffer;

	start = (uint64_t *) array_void;
	end = start + length - 1;
	while (start < end)
	{
		buffer = *start;
		*start = *end;
		*end = buffer;
		start++;
		end--;
	}
}

static
void	ft_reverse32(void *array_void, size_t length)
{
	uint32_t	*start;
	uint32_t	*end;
	uint32_t	buffer;

	start = (uint32_t *) array_void;
	end = start + length - 1;
	while (start < end)
	{
		buffer = *start;
		*start = *end;
		*end = buffer;
		start++;
		end--;
	}
}

// Better to do memcpys with element size
// void	ft_reverse(void *array_void, size_t length, uint8_t type)
// {
// 	unsigned char	*start;
// 	unsigned char	*end;
// 	unsigned char	buffer;

// 	if (type == 32)
// 		return (ft_reverse32(array_void, length));
// 	if (type == 64)
// 		return (ft_reverse64(array_void, length));
// 	start = (unsigned char *) array_void;
// 	end = start + length - 1;
// 	while (start < end)
// 	{
// 		buffer = *start;
// 		*start = *end;
// 		*end = buffer;
// 		start++;
// 		end--;
// 	}
// }
