/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   byte_copy.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/19 11:54:09 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/13 16:19:27 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

// Safe for dst < src
void	*byte_fwd_copy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void;
	src = (const char *) src_void;
	if ((uintptr_t) dst == (uintptr_t) src)
		return (dst_void);
	while (length > 0)
	{
		*dst++ = *src++;
		length--;
	}
	return (dst_void);
}

// Safe for dst > src
void	*byte_bwd_copy(void *dst_void, const void *src_void, size_t length)
{
	char		*dst;
	const char	*src;

	dst = (char *) dst_void + length;
	src = (const char *) src_void + length;
	if ((uintptr_t) dst == (uintptr_t) src)
		return (dst_void);
	while (length > 0)
	{
		*--dst = *--src;
		length--;
	}
	return (dst_void);
}

void	*ft_move(void *dst_void, const void *src_void, size_t n)
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