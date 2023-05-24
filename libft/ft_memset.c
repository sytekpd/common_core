/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memset.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:01 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 22:03:37 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdint.h>
#include <string.h>

void	*ft_memset(void *dest, int chr, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	byte;

	ptr_dest = dest;
	byte = (unsigned char)chr;
	while (n--)
		*ptr_dest++ = byte;
	return (dest);
}
