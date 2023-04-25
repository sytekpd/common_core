#include <unistd.h>
#include <fcntl.h>

void	ft_putchar_fd(char c, int fd)
{
	if (fcntl(fd, F_GETFD) == -1)
        return;
	write(fd, &c, 1);
}
