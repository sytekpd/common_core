/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:15 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 20:32:25 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"
#include <unistd.h>

int	ft_putstr(const char *s)
{
	size_t	len;

	if (s == NULL)
		return (-1);
	len = ft_strlen(s);
	write(1, s, len);
	return (len);
}
