/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   shared.h                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/05/28 17:26:13 by adeimlin          #+#    #+#             */
/*   Updated: 2025/06/16 15:18:59 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>

// typedef struct s_rgb
// {
// 	uint8_t	r;
// 	uint8_t	g;
// 	uint8_t	b;
// }	t_rgb;

typedef union u_rgb
{
	struct s_rgb
	{
		uint8_t	r;
		uint8_t	g;
		uint8_t	b;
	};
}	t_rgb;

typedef union u_type8
{
	uint8_t		u8;
	int8_t		i8;
}	t_8;

typedef union u_type16
{
	uint8_t		u8[2];
	int8_t		i8[2];
	uint16_t	u16;
	int16_t		i16;
	_Float16	f16;
}	t_16;

typedef union u_type32
{
	uint8_t		u8[4];
	int8_t		i8[4];
	uint16_t	u16[2];
	int16_t		i16[2];
	uint32_t	u32;
	int32_t		i32;
	_Float16	f16[2];
	float		f32;
}	t_32;

typedef union u_type64
{
	uint8_t		u8[8];
	int8_t		i8[8];
	uint16_t	u16[4];
	int16_t		i16[4];
	uint32_t	u32[2];
	int32_t		i32[2];
	uint64_t	u64;
	int64_t		i64;
	_Float16	f16[4];
	float		f32[2];
	double		f64;
}	t_64;

typedef union u_type128
{
	uint8_t		u8[16];
	int8_t		i8[16];
	uint16_t	u16[8];
	int16_t		i16[8];
	uint32_t	u32[4];
	int32_t		i32[4];
	uint64_t	u64[2];
	int64_t		i64[2];
	__uint128_t	u128;
	__int128_t	i128;
	_Float16	f16[8];
	float		f32[4];
	double		f64[2];
	__float128	f128;
}	t_128;

// ----------------------------

typedef union u_type16
{
	uint8_t		b[2];
	int8_t		c[2];
	uint16_t	us;
	int16_t		s;
	_Float16	h;
}	t_16;

typedef union u_type32
{
	uint8_t		b[4];
	int8_t		c[4];
	uint16_t	us[2];
	int16_t		s[2];
	uint32_t	ui;
	int32_t		i;
	_Float16	h[2];
	float		f;
}	t_32;

typedef union u_type64
{
	uint8_t		b[8];
	int8_t		c[8];
	uint16_t	us[4];
	int16_t		s[4];
	uint32_t	ui[2];
	int32_t		i[2];
	uint64_t	ul;
	int64_t		l;
	_Float16	h[4];
	float		f[2];
	double		d;
}	t_64;

typedef union u_type128
{
	uint8_t		b[16];
	int8_t		c[16];
	uint16_t	us[8];
	int16_t		s[8];
	uint32_t	ui[4];
	int32_t		i[4];
	uint64_t	ul[2];
	int64_t		l[2];
	__uint128_t	ull;
	__int128_t	ll;
	_Float16	h[8];
	float		f[4];
	double		d[2];
	__float128	q;
}	t_128;
