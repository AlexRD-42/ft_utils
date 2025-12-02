/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libft_utils.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/07/07 19:43:06 by adeimlin          #+#    #+#             */
/*   Updated: 2025/07/07 20:21:51 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFT_UTILS_H
# define LIBFT_UTILS_H

# include <stdint.h>
# include <stddef.h>

uint8_t		*ft_setlut256(uint8_t *lut, const char *charset);
uint64_t	ft_splitmix64(uint64_t seed);
uint64_t	ft_rand(void);
void		ft_bubble_sort(int32_t *array, size_t length);
void		ft_selection_sort(int32_t *array, size_t length);
void		ft_insertion_sort(int32_t *array, size_t length);

// Prototypes: Array Info ----------------------------------------------------
void		ft_i32v(int32_t *array, size_t length, int32_t *min, int32_t *max);
void		ft_i32p(int32_t *array, size_t length, size_t *min, size_t *max);
void		ft_i64v(int64_t *array, size_t length, int64_t *min, int64_t *max);
void		ft_i64p(int64_t *array, size_t length, size_t *min, size_t *max);
// Prototypes: Number Info ---------------------------------------------------
int64_t		ft_imin(int64_t number1, int64_t number2);
int64_t		ft_imax(int64_t number1, int64_t number2);
int64_t		ft_iabs(int64_t number);
int64_t		ft_iabsdiff(int64_t number1, int64_t number2);
float		ft_min(float number1, float number2);
float		ft_max(float number1, float number2);
float		ft_abs(float number);
float		ft_absdiff(float number1, float number2);

#endif
