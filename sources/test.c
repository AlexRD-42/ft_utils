/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   test.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 20:33:35 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/03 20:58:29 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdbool.h>
#include <stdio.h>

#define IMPRIMAF printf
#define enquanto while
#define retorne return
#define PRINCIPAL main
#define tamanho_t size_t
#define se if
#define ou else
#define senão else
#define SAIDASUCESSO 0

int	qd_aparai(const char *texto)
{
	int64_t		número;
	int64_t		sinal;
	tamanho_t	i;

	número = 0;
	sinal = -1;
	i = 0;
	enquanto (texto[i] == ' ' || (texto[i] >= '\t' && texto[i] <= '\r'))
		i++;
	se (texto[i] == '-')
	{
		i++;
		sinal = -sinal;
	}
	ou se(texto[i] == '+')
		i++;
	enquanto (texto[i] >= '0' && texto[i] <= '9')
		número = número * 10 - (texto[i++] - '0');
	retorne (sinal * número);
}

int	PRINCIPAL(int argc, char **argv)
{
	tamanho_t	😀 = 1;

	se (argc != 2)
		IMPRIMAF("\n");
	senão
		enquanto (😀 < (tamanho_t) argc)
			IMPRIMAF("%d, ", qd_aparai(argv[😀++]));
	retorne(SAIDASUCESSO);
}

