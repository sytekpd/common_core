/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_unsigned_int.c                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:19:30 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/12 22:54:43 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_unsigned_int(va_list args)
{
	unsigned int	n;

	n = va_arg(args, unsigned int);
	return (ft_putunbr(n));
}
