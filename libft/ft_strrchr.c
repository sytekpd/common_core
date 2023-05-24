/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2021/09/09 14:38:35 by prossi            #+#    #+#             */
/*   Updated: 2023/05/07 23:32:40 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str);

char	*ft_strrchr(const char *str, int chr)
{
	const char		*ptr_str;
	unsigned char	byte;
	unsigned int	str_len;

	str_len = ft_strlen(str);
	ptr_str = str + str_len;
	byte = (unsigned char)chr;
	while (ptr_str >= str)
	{
		if (*ptr_str == byte)
			return ((char *)ptr_str);
		ptr_str--;
	}
	return (NULL);
}

static size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
