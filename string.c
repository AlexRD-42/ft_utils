/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   string.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/11/30 11:44:46 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/01 10:40:17 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>

size_t	ft_strlen(const char *str)
{
	const char	*ostr = str;

	while (*str != 0)
		str++;
	return ((size_t)(str - ostr));
}

const
char	*ft_strfind(const char *str, const char *charset, uint8_t ref)
{
	size_t	i;
	size_t	lookup_table[256 / sizeof(size_t)];

	i = 0;
	while (i < (256 / sizeof(size_t)))
		lookup_table[i++] = 0UL;
	while (*charset != 0)
	{
		((uint8_t *)lookup_table)[(uint8_t)(*charset)] = 1;
		charset++;
	}
	ref = (ref != 0);
	((uint8_t *)lookup_table)[0] = ref;
	while (((uint8_t *)lookup_table)[(uint8_t)(*str)] != ref)
		str++;
	if (*str != 0)
		return (str);
	return (NULL);
}

// Copies a null terminated array of strings into a single buffer
// Returns: NULL) Incomplete Copy, !NULL) pointer to the end of the copy
char	*ft_strvcpy_stt(
	char *restrict			dst	/*mutable pointer to a buffer*/,
	const char **restrict	vec	/*null terminated array of cstrings*/,
	char *restrict			end	/*end = pointer to the end of the buffer*/)
{
	static _Thread_local const char	*restrict	src = NULL;
	static _Thread_local size_t					local_index = 0;
	size_t										length;
	size_t										space_left;

	while (vec[local_index] != NULL)
	{
		if (src == NULL || *src == 0)
			src = (const char *restrict)vec[local_index];
		length = ft_strlen(src) + (vec[local_index + 1] == NULL);
		while (length > 0)
		{
			if (dst >= end)
				return (NULL);
			space_left = (size_t)(end - dst);
			if (length < space_left)
				space_left = length;
			length -= space_left;
			while (space_left-- > 0)
				*dst++ = *src++;
		}
		local_index++;
	}
	local_index = 0;
	return (dst);
}

// Copies a null terminated array of strings into a single buffer
// Returns: NULL on full copy, or the mutated vec array for incomplete copies
const char	**ft_strvcpy(
	char **restrict			wdst	/*mutable pointer to a buffer*/,
	const char **restrict	vec		/*null terminated array of cstrings*/,
	char *restrict			end		/*end = pointer to the end of the buffer*/)
{
	const char	*restrict	src;
	char		*restrict	dst;
	size_t					length;
	size_t					space_left;

	dst = (char *restrict)*wdst;
	while (*vec != NULL)
	{
		src = (const char *restrict)*vec++;
		length = ft_strlen(src) + (*vec == NULL);
		while (length > 0)
		{
			if (dst >= end)
				return (vec - 1);
			space_left = (size_t)(end - dst);
			if (length < space_left)
				space_left = length;
			length -= space_left;
			while (space_left-- > 0)
				*dst++ = *src++;
			*wdst = dst;
			vec[-1] = src;
		}
	}
	return (NULL);
}

char	*ft_strlcpy(char *restrict dst, const char *restrict src, size_t dst_size)
{
	char		*odst;
	size_t		src_len;
	size_t		length;

	odst = dst;
	src_len = 0;
	while (src[src_len] != 0)
		src_len++;
	if (dst_size != 0)
	{
		if (dst_size > src_len)
			length = src_len;
		else
			length = dst_size - 1;
		while (length > 0)
		{
			*dst++ = *src++;
			length--;
		}
		*dst = 0;
	}
	return (odst);
}

size_t	ft_strlcat(char *dst, const char *src, size_t dst_size)
{
	char	*odst;

	odst = dst;
	while (dst_size > 0 && *dst != 0)
	{
		dst++;
		dst_size--;
	}
	while (*src != 0 && dst_size > 1)
	{
		*dst++ = *src++;
		dst_size--;
	}
	if (dst_size != 0)
		*dst = 0;
	while (*src++ != 0)
		dst++;
	return ((size_t)(dst - odst));
}

// 0x00: NULL or not ascii	 	0x01: Info Chars
// 0x02: (\t, \n, \v, \f, \r)	0x04: Symbols,
// 0x08: (0~9) 					0x10: (A~Z)
// 0x20: (a~z)
// 0x40: (A~Z, a~z, 0-9, _)		0x80: (A~F, X, a~f, x, 0~9)
uint8_t	ft_ascii(const char c)
{
	static const uint8_t	ltable[256] = {
		0x00, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01,	// (0x00 ~ 0x07)
		0x01, 0x02, 0x02, 0x02, 0x02, 0x02, 0x01, 0x01,	// (0x08 ~ 0x0F) space
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, // (0x10 ~ 0x17)
		0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, 0x01, // (0x18 ~ 0x1F)
		0x02, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, // symbols
		0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
		0xC8, 0xC8, 0xC8, 0xC8, 0xC8, 0xC8, 0xC8, 0xC8,	// digits
		0xC8, 0xC8, 0x04, 0x04, 0x04, 0x04, 0x04, 0x04,
		0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0xD0, 0x50, 0x50,
		0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50,	// upper
		0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50, 0x50,
		0xD0, 0x50, 0x50, 0x04, 0x04, 0x04, 0x04, 0x44,
		0x04, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0xE0, 0x60,	// lower and hex
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60,	// lower
		0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0x60, 0xE0,	// lower
		0x60, 0x60, 0x60, 0x04, 0x04, 0x04, 0x04, 0x01	// lower
	};

	return (ltable [(const uint8_t) c]);
}
