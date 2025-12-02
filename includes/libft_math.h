/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_math.h                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/06/17 15:18:38 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:21:47 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_MATH_H
# define LIBFT_MATH_H

# include <stdint.h>
# include <stddef.h>

# ifndef EPS
#  define EPS 0.00000011920929f
# endif

typedef struct s_matrix
{
	float		*data;
	uint32_t	rows;
	uint32_t	cols;
}	t_matrix;

// Prototypes: Math ----------------------------------------------------------
float		ft_qinvsqrt(float number);
float		ft_qsqrt(float number);
float		ft_average(float *array, uint32_t length);
uint32_t	ft_log2(uint32_t number);
uint32_t	ft_log(uint64_t number, uint8_t base);
int64_t		ft_sqrt(int64_t number);
int64_t		ft_factorial(int64_t number);
int64_t		ft_power(int64_t number, uint64_t power);
size_t		ft_fibonacci(size_t index);
uint8_t		ft_isprime(size_t number);

#endif
