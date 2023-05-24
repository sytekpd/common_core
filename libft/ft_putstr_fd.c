/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putstr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:15 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/10 15:01:02 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

static size_t	ft_strlen(const char *str);

void	ft_putstr_fd(const char *s, int fd)
{
	if (s == NULL)
		return ;
	if (fcntl(fd, F_GETFD) == -1)
		return ;
	write(fd, s, ft_strlen(s));
}

static size_t	ft_strlen(const char *str)
{
	const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
