/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   float_math.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 10:28:32 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/23 14:37:18 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <libft_types.h>

// This is faster than receiving a t_32 (thank god)
float	ft_qinvsqrt(float number)
{
	t_32	result;

	result.f32 = number;
	result.u32 = 0x5f3759df - (result.u32 >> 1);
	result.f32 = result.f32 * (1.5f - (number * 0.5f * result.f32 * result.f32));
	return (result.f32);
}

float	ft_qsqrt(float number)
{
	t_32	result;

	result.f32 = number;
	result.u32 = (result.u32 >> 1) + 0x1FBD3EE0;
	result.f32 = 0.5f * (result.f32 + number / result.f32);
	return (result.f32);
}

// Check length division
float	ft_average(float *array, size_t length)
{
	float	sum;
	size_t	i;

	sum = 0;
	i = 0;
	while (i < length)
	{
		sum += *array;
		array++;
		i++;
	}
	return (sum / (float) length);
}
