/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_fibonacci.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/04/11 14:08:49 by adeimlin          #+#    #+#             */
/*   Updated: 2025/04/11 14:08:49 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>

int64_t	ft_fibonacci(int64_t index)
{
	int64_t	prev;
	int64_t	current;
	int64_t	next;

	if (index <= 0)
		return (0);
	if (index <= 1)
		return (1);
	prev = 0;
	current = 1;
	while (index > 1)
	{
		next = prev + current;
		prev = current;
		current = next;
		index--;
	}
	return (next);
}
