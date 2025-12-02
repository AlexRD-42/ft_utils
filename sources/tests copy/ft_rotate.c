/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_rotate.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/12 22:32:08 by adeimlin          #+#    #+#             */
/*   Updated: 2025/05/14 09:14:22 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

// #include "../../include/libft.h"

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>

static void	*ft_memmove(void *dst_void, const void *src_void, size_t n)
{
	char		*dst;
	const char	*src = (const char *) src_void;

	dst = (char *) dst_void;
	if (n == 0 || dst == src)
		return (dst_void);
	if ((uintptr_t) dst < (uintptr_t) src)
	{
		while (n-- > 0)
			*dst++ = *src++;
	}
	else
	{
		dst += n - 1;
		src += n - 1;
		while (n-- > 0)
			*dst-- = *src--;
	}
	return (dst_void);
}

void	ft_rotate(void *array, size_t length, size_t offset, size_t type_size)
{
	unsigned char	buffer[256];
	void			*array_end;

	offset *= type_size;
	length *= type_size;
	array_end = array + length;
	while (offset >= sizeof(buffer))
	{
		ft_memmove(buffer, array, sizeof(buffer));
		ft_memmove(array, array + sizeof(buffer), length - sizeof(buffer));
		ft_memmove(array_end - sizeof(buffer), buffer, sizeof(buffer));
		offset -= sizeof(buffer);
	}
	ft_memmove(buffer, array, offset);
	ft_memmove(array, array + offset, length - offset);
	ft_memmove(array_end - offset, buffer, offset);
}

void	ft_rrotate(void *array, size_t length, size_t offset, size_t type_size)
{
	unsigned char	buffer[256];
	void			*array_end;

	offset *= type_size;
	length *= type_size;
	array_end = array + length;
	while (offset >= 256)
	{
		ft_memmove(buffer, array_end - sizeof(buffer), sizeof(buffer));
		ft_memmove(array + sizeof(buffer), array, length - sizeof(buffer));
		ft_memmove(array, buffer, sizeof(buffer));
		offset -= 256;
	}
	ft_memmove(buffer, array_end - offset, offset);
	ft_memmove(array + offset, array, length - offset);
	ft_memmove(array, buffer, offset);
}

void	ft_rot(void *array, size_t length, ssize_t offset, size_t type_size)
{
	if (offset > (ssize_t) length / 2)
		offset = offset - length;
	else if ((-offset) > (ssize_t) length / 2)
		offset = length + offset;
	if (offset > 0)
		ft_rotate(array, length, offset, type_size);
	else
		ft_rrotate(array, length, -offset, type_size);
}

// Rot(+1): ABCDE -> BCDEA
// Rot(+2): ABCDE -> CDEAB
// Rot(+3): ABCDE -> DEABC
// Rot(+4): ABCDE -> EABCD
// Rot(-1): ROT(+4)
// Rot(-2): ROT(+3) Its better to do ROT -2 cause it saves less on the buffer
#include <stdio.h>

int	main(void)
{
	// int32_t array[64] = {
	// 	0,  1,  2,  3,  4,  5,  6,  7,
	// 	8,  9, 10, 11, 12, 13, 14, 15,
	//    16, 17, 18, 19, 20, 21, 22, 23,
	//    24, 25, 26, 27, 28, 29, 30, 31,
	//    32, 33, 34, 35, 36, 37, 38, 39,
	//    40, 41, 42, 43, 44, 45, 46, 47,
	//    48, 49, 50, 51, 52, 53, 54, 55,
	//    56, 57, 58, 59, 60, 61, 62, 63};

	typedef struct { char r, g, b; } RGB;
	RGB arr[90];
	for (int i = 0; i < 90; i++)
	{
		arr[i].r = i;
		arr[i].g = i + 1;
		arr[i].b = i + 2;
	}

	ft_rotate(arr, 90, 270, sizeof(RGB));

	int valid = 1;
	for (int i = 0; i < 90; i++)
	{
		if (arr[i].r != i || arr[i].g != i+1 || arr[i].b != i+2) 
			valid = 0;
	}
	// char str[] = "abcdefghijklmnopqrstuvwxyz";
	// char str2[] = "abcdefghijklmnopqrstuvwxyz";
	// ft_rot(str, 25, 18, 1);
	// ft_rotate(str2, 25, 18, 1);
	// for (int i=0;i<25;i++)
	// 	printf("%d, ", str[i]);
	// printf("%s", str);
	// printf("\n%s", str2);
}
