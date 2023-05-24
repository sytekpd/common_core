/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_hex.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:19:15 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 02:11:53 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

static void	ft_puthex_recursive(unsigned int n, char *hex_digits,
				int printed_chars);
static int	ft_numlen_hex(unsigned int n);

int	handle_hex_lower(va_list args)
{
	unsigned int	n;
	int				printed_chars;
	char			*hex_digits;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (ft_putchar('0'));
	hex_digits = "0123456789abcdef";
	printed_chars = ft_numlen_hex(n);
	if (printed_chars > 0)
		ft_puthex_recursive(n, hex_digits, printed_chars);
	return (printed_chars);
}

int	handle_hex_upper(va_list args)
{
	unsigned int	n;
	int				printed_chars;
	char			*hex_digits;

	n = va_arg(args, unsigned int);
	if (n == 0)
		return (ft_putchar('0'));
	hex_digits = "0123456789ABCDEF";
	printed_chars = ft_numlen_hex(n);
	if (printed_chars > 0)
		ft_puthex_recursive(n, hex_digits, printed_chars);
	return (printed_chars);
}

static int	ft_numlen_hex(unsigned int n)
{
	int	len;

	len = 1;
	while (n >= 16)
	{
		n /= 16;
		len++;
	}
	return (len);
}

static void	ft_puthex_recursive(unsigned int n, char *hex_digits,
		int printed_chars)
{
	if (n >= 16)
		ft_puthex_recursive(n / 16, hex_digits, printed_chars - 1);
	ft_putchar(hex_digits[n % 16]);
}
