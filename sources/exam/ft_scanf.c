/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_scanf.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: adeimlin <adeimlin@student.42porto.com>    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2025/12/03 10:06:41 by adeimlin          #+#    #+#             */
/*   Updated: 2025/12/03 11:59:07 by adeimlin         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <stddef.h>
#include <stdarg.h>
#include <stdio.h>
#include <ctype.h>

int match_space(FILE *f)
{
	int new_c = fgetc(f);

	while (new_c != EOF && isspace(new_c))
		new_c = fgetc(f);
	if (new_c == EOF)
		return (-1);
	ungetc(new_c, f);
	return (0);	
}

int match_char(FILE *f, char c)
{
	int new_c = fgetc(f);

	if ((char)new_c == c)
		return (1);
	if (new_c != EOF)
		ungetc(new_c, f);
	return (0);
}

int scan_char(FILE *f, va_list ap)
{
	int new_c = fgetc(f);
	char *c = (char *) va_arg(ap, char *);

	if (new_c == EOF)
		return (0);
	*c = (char) new_c;
	return (1);
}

int scan_int(FILE *f, va_list ap)
{
	int		new_c;
	int		sign = -1;
	int		*number = (int *) va_arg(ap, int*);

	new_c = fgetc(f);
	if (new_c == EOF)
		return (EOF);
	*number = 0;
	if (new_c == '+')
		new_c = fgetc(f);
	if (new_c == '-')
	{
		new_c = fgetc(f);
		sign = -sign;
	}
	while(new_c != EOF && isdigit(new_c))
	{
		*number = *number * 10 - ((char)new_c - '0');
		new_c = fgetc(f);
	}
	if (new_c != EOF)
		ungetc(new_c, f);
	*number *= sign;
	return (1);
}

int scan_string(FILE *f, va_list ap)
{
	int		new_c;
	char 	*buffer = (char *) va_arg(ap, char *);
	size_t length;

	length = 0;
	new_c = fgetc(f);
	if (new_c == EOF)
		return (EOF);
	while (new_c != EOF && !isspace(new_c))
	{
		buffer[length] = (char) new_c;
		new_c = fgetc(f);
		length++;
	}
	buffer[length] = 0;
	if (new_c != EOF)
		ungetc(new_c, f);
	return (length > 0);
}

int	match_conv(FILE *f, const char **format, va_list ap)
{
	switch (**format)
	{
		case 'c':
			return scan_char(f, ap);
		case 'd':
			match_space(f);
			return scan_int(f, ap);
		case 's':
			match_space(f);
			return scan_string(f, ap);
		case EOF:
			return -1;
		default:
			return -1;
	}
}

int ft_vfscanf(FILE *f, const char *format, va_list ap)
{
	int nconv = 0;

	int c = fgetc(f);
	if (c == EOF)
		return EOF;
	ungetc(c, f);

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (match_conv(f, &format, ap) != 1)
				break;
			else
				nconv++;
		}
		else if (isspace(*format))
		{
			if (match_space(f) == -1)
				break;
		}
		else if (match_char(f, *format) != 1)
			break;
		format++;
	}
	
	if (ferror(f))
		return EOF;
	return nconv;
}

int ft_scanf(const char *format, ...)
{
	va_list ap;
	int 	ret;

	va_start(ap, format);
	ret = ft_vfscanf(stdin, format, ap);
	va_end(ap);
	return ret;
}
