/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_xoroshiro128.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/13 17:09:12 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/13 17:09:12 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../../include/libft.h"
// https://prng.di.unimi.it/xoroshiro128plus.c

static uint64_t	state[2] = {9223372036854775783, 6364136223846793005};

t_64 ft_xoroshiro128(void)
{
	const uint64_t	t = state[1] ^ state[0];
	const t_64		result = {state[0] + state[1]};

	state[0] = ((state[0] << 24) | (state[0] >> 40)) ^ t ^ (t << 16);
	state[1] = (t << 37) | (t >> 27);
	return (result);
}
