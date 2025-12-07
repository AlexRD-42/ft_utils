/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   io.c                                               :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/15 15:50:30 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/05 09:11:36 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <threads.h>

#ifndef FT_IO_BUFSIZE
# define FT_IO_BUFSIZE 4096
#endif

// ft_error, ft_write

const char	**ft_strvcpy(char **restrict wdst,
	const char **restrict vec, char *restrict end);

ssize_t	ft_writev(int fd, const char **vec, char endl)
{
	char		buffer[FT_IO_BUFSIZE];
	ssize_t		bytes_written;
	ssize_t		bytes_total;
	const char	**src = vec;
	char		*dst;

	if (vec == NULL || *vec == NULL)
		return (-1);
	bytes_total = 0;
	dst = buffer;
	src = ft_strvcpy(&dst, src, buffer + FT_IO_BUFSIZE);
	while (src != NULL)
	{
		bytes_written = write(fd, buffer, (size_t)(dst - buffer));
		if (bytes_written < 0)
			return (-1);
		bytes_total += bytes_written;
		dst = buffer;
		src = ft_strvcpy(&dst, src, buffer + FT_IO_BUFSIZE);
	}
	dst[-1] = endl;
	bytes_written = write(fd, buffer, (size_t)(dst - buffer - (endl == 0)));
	if (bytes_written < 0)
		return (-1);
	return (bytes_total + bytes_written);
}

// Returned result is not re_entrant
char	*ft_itoa_stt(int64_t number)
{
	static thread_local char	buffer[32];
	char						*ptr;
	const int8_t				sign = (number >= 0) - (number < 0);

	ptr = buffer + 31;
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

char	*ft_itoa_r(int64_t number, char *ptr)
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

// To do: set errno on overflow
int64_t	ft_strtol(const char *str)
{
	int64_t	number;
	int64_t	sign;

	number = 0;
	while (*str == ' ' || (*str >= '\t' && *str <= '\r'))
		str++;
	sign = -1 + ((*str == '-') << 1);
	str += (sign == 1) || (*str == '+');
	while (*str >= '0' && *str <= '9')
		number = number * 10 - (*str++ - '0');
	return (sign * number);
}

int64_t	ft_strntol(const char *str, size_t length)
{
	const char	*end = str + length;
	int64_t		number;
	int64_t		sign;

	number = 0;
	while (str < end && (*str == ' ' || (*str >= '\t' && *str <= '\r')))
		str++;
	sign = -1 + ((*str == '-') << 1);
	str += (sign == 1) || (*str == '+');
	while (*str >= '0' && *str <= '9' && str < end)
		number = number * 10 - (*str++ - '0');
	return (sign * number);
}

ssize_t	ft_putnbr(int64_t number)
{
	const int64_t	sign = (number >= 0) - (number < 0);
	char			buffer[32];
	char			*ptr;

	ptr = buffer + 31;
	*ptr-- = '\n';
	*(ptr) = sign * (number % 10) + '0';
	number = sign * (number / 10);
	while (number != 0)
	{
		*(--ptr) = (number % 10) + '0';
		number /= 10;
	}
	if (sign < 0)
		*(--ptr) = '-';
	return (write(STDOUT_FILENO, ptr, 32 - (uintptr_t)(ptr - buffer)));
}
