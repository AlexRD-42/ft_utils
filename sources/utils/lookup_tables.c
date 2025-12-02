/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   lookup_tables.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 16:40:16 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:39:03 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include "libft_memory.h"

// lut = 0 not separator, lut = 1 is separator, lut = 255 is null terminator
uint8_t	*ft_setlut256(uint8_t *lut, const char *charset)
{
	ft_memset(lut, 0, 256);
	while (*charset != 0)
		lut[*(const uint8_t *) charset++] = 1;
	lut[0] = 0xFF;
	return (lut);
}
