/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:19:27 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 20:40:38 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_string(va_list args)
{
	const char	*str;

	str = va_arg(args, const char *);
	if (str == NULL)
		return (ft_putstr("(null)"));
	return (ft_putstr(str));
}
