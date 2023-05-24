/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:46 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/12 00:45:33 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str);
static char		*ft_strchr(const char *str, int chr);
static void		*ft_memcpy(void *dest, const void *src, size_t n);
static char		*allocate_result(size_t len);

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*result;
	size_t	len;
	size_t	start;
	size_t	end;

	if (!s1 || !set || !*s1)
		return (allocate_result(0));
	len = ft_strlen(s1);
	start = 0;
	while (s1[start] && ft_strchr(set, s1[start]))
		start++;
	end = len - 1;
	while (end > start && ft_strchr(set, s1[end]))
		end--;
	len = end - start + 1;
	result = allocate_result(len);
	if (!result)
		return (NULL);
	ft_memcpy(result, s1 + start, len);
	result[len] = '\0';
	return (result);
}

size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static char	*ft_strchr(const char *str, int chr)
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

void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	unsigned char	*ptr_dest;
	unsigned char	*ptr_src;

	ptr_dest = (unsigned char *)dest;
	ptr_src = (unsigned char *)src;
	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if ((dest >= src && dest < src + n) || (src >= dest && src < dest + n))
		return (NULL);
	while (n--)
		*ptr_dest++ = *ptr_src++;
	return (dest);
}

static char	*allocate_result(size_t len)
{
	char	*result;

	result = (char *)malloc(len + 1);
	if (!result)
		return (NULL);
	if (!len)
		*result = '\0';
	return (result);
}
