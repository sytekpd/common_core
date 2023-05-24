/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memmove.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:48:59 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 18:15:29 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void	*ft_memmove(void *dest, const void *src, size_t n)
{
	char		*ptr_dest;
	const char	*ptr_src;
	size_t		i;

	if (dest == NULL && src == NULL)
		return (NULL);
	ptr_dest = (char *)dest;
	ptr_src = (const char *)src;
	i = n;
	if (ptr_src < ptr_dest && ptr_src + n > ptr_dest)
		while (i--)
			*(ptr_dest + i) = *(ptr_src + i);
	else
		while (n--)
			*ptr_dest++ = *ptr_src++;
	return (dest);
}
