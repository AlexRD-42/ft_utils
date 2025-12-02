/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_writev_test.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/27 21:35:34 by adeimlin          #+#    #+#             */
/*   Updated: 2025/11/29 12:06:44 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

#define FT_BUFFER_SIZE 16384

void	*ft_memcpy(void *restrict vdst, const void *restrict vsrc, size_t length);
size_t	ft_strlen(const char *str);

static
char	*stt_cpy(int fd, const char *restrict src, char *restrict dst, char *end)
{
	size_t	space_left;
	size_t	length;

	length = ft_strlen(src);
	while (length > 0)
	{
		space_left = (size_t)(end - dst);
		if (length < space_left)
			space_left = length;
		length -= space_left;
		while (space_left > 0)
		{
			*dst++ = *src++;
			space_left--;
		}
		if (dst >= end)
		{
			dst = end - FT_BUFFER_SIZE;
			write(fd, dst, FT_BUFFER_SIZE);
		}
	}
	return (dst);
}

ssize_t	ft_buffered_write(int fd, const char *src)
{
	char	dst[FT_BUFFER_SIZE];
	ssize_t	bytes_written;
	size_t	length;

	length = ft_strlen(src);
	while (length > FT_BUFFER_SIZE)
	{
		bytes_written = write(fd, src, FT_BUFFER_SIZE);
		if (bytes_written < 0)
			return (-1);
		src += FT_BUFFER_SIZE;
		length -= FT_BUFFER_SIZE;
	}
	if (length > 0)
	{
		ft_memcpy(dst, src, length);
		bytes_written = write(fd, src, FT_BUFFER_SIZE);
		if (bytes_written < 0)
			return (-1);
	}
	return ((ssize_t)length);
}

void	ft_writev(int fd, const char **restrict vec, char endl)
{
	char					buffer[FT_BUFFER_SIZE];
	const char *restrict	src;
	char *restrict			dst;

	dst = buffer;
	while (*vec != NULL)
	{
		src = *vec++;
		dst = stt_cpy(fd, src, dst, buffer + FT_BUFFER_SIZE);
	}
	*dst++ = endl;
	write(fd, buffer, FT_BUFFER_SIZE);
}

void	ft_writev_chunk_solo(int fd, const char **restrict vec, char endl)
{
	char					buffer[FT_BUFFER_SIZE];
	const char *restrict	src;
	char *restrict			dst;
	size_t					length;
	size_t					chunk;

	dst = buffer;
	while (*vec != NULL)
	{
		src = *vec++;
		while (*src != 0)
		{
			length = ft_strlen(src);
			chunk = (size_t)(buffer + FT_BUFFER_SIZE - 1 - dst);
			if (length < chunk)
				chunk = length;
			while (chunk--)
				*dst++ = *src++;
			if (dst >= (buffer + FT_BUFFER_SIZE - 1))
				dst = buffer;
			(dst == buffer) && write(fd, buffer, FT_BUFFER_SIZE - 1);
		}
	}
	*dst++ = endl;
	write(fd, buffer, (size_t)(dst - buffer - (endl == 0)));
}

ssize_t	ft_writev(int fd, char **restrict vec, char endl)
{
	char					buffer[FT_BUFFER_SIZE];
	ssize_t					bytes_written;
	const char *restrict	src;
	char *restrict			dst;

	dst = buffer;
	bytes_written = 0;
	while (*vec != NULL)
	{
		src = *vec++;
		while (*src != 0)
		{
			*dst++ = *src++;
			if (dst >= buffer + FT_BUFFER_SIZE - 1)
			{
				if (write(fd, buffer, FT_BUFFER_SIZE - 1) == -1)
					return (-1);
				bytes_written += FT_BUFFER_SIZE - 1;
				dst = buffer;
			}
		}
	}
	*dst++ = endl;
	return (bytes_written + write(fd, buffer, (size_t)(dst - buffer - (endl == 0))));
}

int main()
{
	ft_writev(1, (const char **){NULL, NULL, NULL}, '\n');
}
