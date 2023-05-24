/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:46 by prossi            #+#    #+#             */
/*   Updated: 2023/05/08 12:05:25 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>
#include <string.h>

static void	*ft_memset(void *dest, int chr, size_t n);

void	*ft_calloc(size_t count, size_t size)
{
	size_t	total_size;
	void	*ptr;

	total_size = count * size;
	ptr = malloc(total_size);
	if (ptr)
		ft_memset(ptr, 0, total_size);
	return (ptr);
}

static void	*ft_memset(void *dest, int chr, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	byte;

	ptr_dest = dest;
	byte = (unsigned char)chr;
	while (n--)
		*ptr_dest++ = byte;
	return (dest);
}
