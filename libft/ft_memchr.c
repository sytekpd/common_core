/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:48:51 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 23:15:25 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

void	*ft_memchr(const void *str, int chr, size_t n)
{
	unsigned char	*ptr_str;
	unsigned char	byte;

	ptr_str = (unsigned char *)str;
	byte = (unsigned char)chr;
	while (n--)
		if (*ptr_str++ == byte)
			return ((void *)ptr_str - 1);
	return (NULL);
}
