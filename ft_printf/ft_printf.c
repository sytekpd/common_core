/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_printf.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:00:53 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 20:35:21 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <stdarg.h>
#include <stdbool.h>
#include <stdio.h>

int					validate_format(const char *format);

static int	handle_chars(va_list args)
{
	int	c;

	c = va_arg(args, int);
	ft_putchar(c);
	return (1);
}

typedef struct s_handler
{
	char			specifier;
	int				(*handler)(va_list);
}					t_handler;

static t_handler	g_handlers[] = {
	{'c', handle_chars},
	{'s', handle_string},
	{'p', handle_pointer},
	{'d', handle_int},
	{'i', handle_int},
	{'u', handle_unsigned_int},
	{'x', handle_hex_lower},
	{'X', handle_hex_upper},
	{'%', handle_percent}};

static int	handle_format(va_list args, char specifier)
{
	int	num_handlers;
	int	i;

	num_handlers = sizeof(g_handlers) / sizeof(g_handlers[0]);
	i = -1;
	while (i++, i < num_handlers)
		if (g_handlers[i].specifier == specifier)
			return (g_handlers[i].handler(args));
	return (ft_putchar(specifier));
}

int	ft_printf(const char *format, ...)
{
	va_list	args;
	int		printed_chars;

	printed_chars = 0;
	va_start(args, format);
	if (format == NULL)
		return (-1);
	if (!validate_format(format))
		return (-1);
	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format != '\0')
				printed_chars += handle_format(args, *format);
		}
		else
			printed_chars += ft_putchar(*format);
		format++;
	}
	va_end(args);
	return (printed_chars);
}

int	validate_format(const char *format)
{
	const char	*valid_specifiers;
	const char	*specifier;

	while (*format)
	{
		if (*format == '%')
		{
			format++;
			if (*format == '\0')
				return (0);
			valid_specifiers = "cspdiuxX%";
			specifier = valid_specifiers;
			while (*specifier)
			{
				if (*format == *specifier)
					break ;
				specifier++;
			}
			if (*specifier == '\0')
				return (0);
		}
		format++;
	}
	return (1);
}
