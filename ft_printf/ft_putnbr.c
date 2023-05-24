/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:10 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 18:58:24 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	ft_putnbr(int n)
{
	if (n == -2147483648)
	{
		ft_putstr("-2147483648");
		return (11);
	}
	else if (n < 0)
	{
		ft_putchar('-');
		return (1 + ft_putnbr(-n));
	}
	else if (n >= 10)
		return (ft_putnbr(n / 10) + ft_putchar(n % 10 + '0'));
	else if (n >= 0 && n <= 9)
	{
		ft_putchar(n + '0');
		return (1);
	}
	else
		return (-1);
}
