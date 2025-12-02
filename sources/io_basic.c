/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io_basic.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/25 09:45:51 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/02 09:37:37 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <fcntl.h>

ssize_t	ft_read_size(const char *filename)
{
	const int32_t	fd = open(filename, O_RDONLY);
	uint8_t			buffer[16 * 1024];
	ssize_t			bytes_read;
	ssize_t			bytes_total;

	if (fd < 0)
		return (-1);
	bytes_total = 0;
	bytes_read = read(fd, buffer, sizeof(buffer));
	while (bytes_read > 0)
	{
		bytes_total += bytes_read;
		bytes_read = read(fd, buffer, sizeof(buffer));
	}
	if (bytes_read < 0)
		return (-1);
	close(fd);
	return (bytes_total);
}

// Receives and endptr to a buffer guaranteed to hold size of number
char	*ft_itoa_stack(int64_t number, char *ptr)
{
	const int8_t	sign = (number >= 0) - (number < 0);

	*ptr = 0;
	*(--ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign == -1)
		*(--ptr) = '-';
	return (ptr);
}

// Decide on naming and check if strlen is higher than overflow
// Open an issue because of uint8_t *
uint64_t	ft_atoi_hex(const char *str)
{
	uint64_t				number;
	static const uint8_t	lut[256] = {
	['0'] = 0, ['1'] = 1, ['2'] = 2, ['3'] = 3, ['4'] = 4,
	['5'] = 5, ['6'] = 6, ['7'] = 7, ['8'] = 8, ['9'] = 9,
	['A'] = 10, ['B'] = 11, ['C'] = 12, ['D'] = 13, ['E'] = 14, ['F'] = 15,
	['a'] = 10, ['b'] = 11, ['c'] = 12, ['d'] = 13, ['e'] = 14, ['f'] = 15};

	number = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	str += (str[0] == '0' && (str[1] == 'x' || str[1] == 'X')) << 1;
	while (lut[*(const uint8_t *) str] || *str == '0')
		number += (number << 4) + lut[*(const uint8_t *) str++];
	return (number);
}

ssize_t	ft_putnchar(const char c, int fd, size_t length)
{
	size_t			i;
	ssize_t			bytes;
	size_t			buffer[256 / sizeof(size_t)];

	i = 0;
	bytes = 0;
	buffer[0] = (0x0101010101010101 & UINTPTR_MAX) * (const size_t) c;
	while (length > sizeof(size_t) && i < 256 / sizeof(size_t))
		buffer[i++] = buffer[0];
	while (length >= 256)
	{
		bytes += write(fd, buffer, 256);
		length -= 256;
	}
	bytes += write(fd, buffer, length);
	return (bytes);
}

ssize_t	ft_putbits(const uint8_t byte, int fd)
{
	uint64_t	expand;

	expand = (((uint64_t)byte * 0x8040201008040201ULL) >> 7);
	expand = (expand & 0x0101010101010101ULL) | 0x3030303030303030ULL;
	return (write(fd, &expand, 8));
}
