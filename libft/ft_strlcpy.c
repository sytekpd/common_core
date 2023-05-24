/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcpy.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:31 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 20:44:39 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str);

size_t	ft_strlcpy(char *dest, const char *src, size_t size)
{
	char		*ptr_dest;
	const char	*ptr_src;

	if (size < 1)
		return (ft_strlen(src));
	ptr_dest = dest;
	ptr_src = src;
	while (*ptr_src && --size)
		*ptr_dest++ = *ptr_src++;
	*ptr_dest = '\0';
	return (ft_strlen(src));
}

static size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
