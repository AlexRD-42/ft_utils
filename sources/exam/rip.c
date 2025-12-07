/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   rip.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 12:02:27 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/03 12:08:25 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <unistd.h>
#include <stdbool.h>

int	main(int argc, char **argv, char **envp)
{
	ssize_t	pdepth = 0;
	char c;
	char	*ostr = argv[1];
	char	*str = argv[1];

	while (*str != 0)
	{
		c = *str;
		pdepth = (c == '(') - (c == ')');
		str++;
	}
	if (pdepth < 0)
	{
		c = ')';
		pdepth = -pdepth;
	}
	else
	{
		c = '(';
	}
	str = ostr;
	while (pdepth > 0 && *str != 0)
	{
		if (*str == c)
		{
			*str = ' ';
			pdepth--;
		}
		str++;
	}
}
