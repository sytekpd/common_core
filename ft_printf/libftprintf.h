/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   libftprintf.h                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:00:36 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 02:11:12 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef LIBFTPRINTF_H
# define LIBFTPRINTF_H

# include <stdarg.h>
# include <stdlib.h>

typedef struct s_flags
{
	int	minus;
	int	zero;
	int	width;
	int	precision;
	int	uppercase;
}		t_flags;

int		ft_printf(const char *format, ...);

size_t	ft_strlen(const char *str);
int		ft_putchar(char c);
int		ft_putstr(const char *s);
int		ft_putnbr(int n);
int		ft_putunbr(unsigned int n);
int		ft_numlen(unsigned int n);
int		ft_putptr(void *ptr);

int		handle_char(va_list args);
int		handle_string(va_list args);
int		handle_pointer(va_list args);
int		handle_int(va_list args);
int		handle_unsigned_int(va_list args);
int		handle_hex_lower(va_list args);
int		handle_hex_upper(va_list args);
int		handle_percent(va_list args);

#endif
