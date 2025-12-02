/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_types.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/13 17:36:17 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:11:08 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_TYPES_H
# define LIBFT_TYPES_H

# include <stdint.h>
# include <stddef.h>

typedef union u_type32
{
	uint32_t	u32;
	int32_t		i32;
	uint8_t		u8[4];
	float		f32;
}	t_32;

typedef union u_type64
{
	uint64_t	u64;
	int64_t		i64;
	double		f64;
	float		f32[2];
	uint32_t	u32[2];
	int32_t		i32[2];
	uint8_t		u8[8];
}	t_64;

typedef union u_ptr
{
	void		*v;
	size_t		*w;
	int8_t		*i8;
	uint8_t		*u8;
	int32_t		*i32;
	uint32_t	*u32;
	int64_t		*i64;
	uint64_t	*u64;
	float		*f32;
	double		*f64;
}	t_ptr;

typedef struct s_array
{
	union
	{
		void		*v;
		size_t		*w;
		int8_t		*i8;
		uint8_t		*u8;
		int32_t		*i32;
		uint32_t	*u32;
		int64_t		*i64;
		uint64_t	*u64;
		float		*f32;
		double		*f64;
	};
	size_t		length;
}	t_array;

#endif
