/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pointer.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/12 22:19:25 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/13 21:35:36 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libftprintf.h"

int	handle_pointer(va_list args)
{
	void	*ptr;

	ptr = va_arg(args, void *);
	return (ft_putptr(ptr));
}
