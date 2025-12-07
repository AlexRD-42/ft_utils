/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   nqueens.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/02 18:21:43 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/03 09:43:22 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <unistd.h>
#include <stdio.h>

// Goal: Generate 12345, 12354, 12435, ... , 54321

static
void	stt_swap(int *a, int *b)
{
	const int	tmp = *a;

	*a = *b;
	*b = tmp;
}

int main(void)
{
	int32_t	digits[64] = {1, 2, 3, 4};
	size_t	i;

	i = 0;
	while (i < 999999999)
		i++;
	printf("done");
	return (0);
}
