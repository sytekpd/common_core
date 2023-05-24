/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_bzero.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:46 by prossi            #+#    #+#             */
/*   Updated: 2023/05/07 21:45:26 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	*ft_memset(void *dest, int c, size_t n);

void	ft_bzero(void *str, size_t n)
{
	ft_memset(str, 0, n);
}

static void	*ft_memset(void *dest, int c, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	byte;

	ptr_dest = dest;
	byte = (unsigned char)c;
	while (n--)
		*ptr_dest++ = byte;
	return (dest);
}
