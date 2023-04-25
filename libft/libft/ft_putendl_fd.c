#include <fcntl.h>

void ft_putstr_fd(const char *restrict s, int fd);
void ft_putchar_fd(char c, int fd);

void	ft_putendl_fd(const char *restrict s, int fd)
{
	if (fcntl(fd, F_GETFD) == -1)
        return;
	ft_putstr_fd(s, fd);
	ft_putchar_fd('\n', fd);
}
