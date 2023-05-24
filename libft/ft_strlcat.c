/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:29 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/07 23:30:32 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static size_t	ft_strlen(const char *str);
static size_t	ft_strnlen(const char *s, size_t max_len);
static void		*ft_memcpy(void *dest, const void *src, size_t n);

size_t	ft_strlcat(char *dest, const char *src, size_t size)
{
	size_t	dest_len;
	size_t	src_len;
	size_t	remaining_space;
	size_t	chars_to_copy;

	if (!dest && !src)
		return (0);
	dest_len = ft_strnlen(dest, size);
	src_len = ft_strlen(src);
	if (dest_len == size)
		return (dest_len + src_len);
	remaining_space = size - dest_len - 1;
	if (src_len < remaining_space)
		chars_to_copy = src_len;
	else
		chars_to_copy = remaining_space;
	ft_memcpy(dest + dest_len, src, chars_to_copy);
	dest[dest_len + chars_to_copy] = '\0';
	return (dest_len + src_len);
}

static size_t	ft_strnlen(const char *s, size_t max_len)
{
	const char	*end;

	end = s;
	while (*end && max_len--)
		end++;
	return ((size_t)(end - s));
}

static size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static void	*ft_memcpy(void *dest, const void *src, size_t n)
{
	size_t				i;
	unsigned char		*d;
	const unsigned char	*s;

	if (dest == NULL && src == NULL)
		return (NULL);
	if (n == 0)
		return (dest);
	if (dest > src && dest < src + n)
		return (NULL);
	if (src > dest && src < dest + n)
		return (NULL);
	d = (unsigned char *)dest;
	s = (const unsigned char *)src;
	i = 0;
	while (i < n)
	{
		d[i] = s[i];
		i++;
	}
	return (dest);
}
