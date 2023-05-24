/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:20 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 22:23:24 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

char	*ft_strchr(const char *str, int chr)
{
	const char	*ptr_str;
	char		byte;

	ptr_str = str;
	byte = (unsigned char)chr;
	while (*ptr_str)
	{
		if (*ptr_str == byte)
			return ((char *)ptr_str);
		ptr_str++;
	}
	if (*ptr_str == byte)
		return ((char *)ptr_str);
	return (NULL);
}
