/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_putnbr_fd.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:10 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/10 15:08:22 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <fcntl.h>
#include <unistd.h>

static void		ft_putchar_fd(char c, int fd);
static void		ft_putstr_fd(const char *restrict s, int fd);

void	ft_putnbr_fd(int n, int fd)
{
	if (fcntl(fd, F_GETFD) == -1)
		return ;
	if (n == -2147483648)
		ft_putstr_fd("-2147483648", fd);
	else if (n < 0)
	{
		ft_putchar_fd('-', fd);
		ft_putnbr_fd(-n, fd);
	}
	else if (n >= 10)
	{
		ft_putnbr_fd(n / 10, fd);
		ft_putchar_fd(n % 10 + '0', fd);
	}
	else
		ft_putchar_fd(n + '0', fd);
}

static void	ft_putchar_fd(char c, int fd)
{
	if (fcntl(fd, F_GETFD) == -1)
		return ;
	write(fd, &c, 1);
}

static size_t	ft_strlen(const char *restrict str)
{
	register const char	*s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static void	ft_putstr_fd(const char *restrict s, int fd)
{
	if (s == NULL)
		return ;
	if (fcntl(fd, F_GETFD) == -1)
		return ;
	write(fd, s, ft_strlen(s));
}
