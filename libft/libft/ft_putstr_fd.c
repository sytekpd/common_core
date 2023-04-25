#include <unistd.h>
#include <fcntl.h>

static size_t	ft_strlen(const char *restrict str);

void	ft_putstr_fd(const char *restrict s, int fd)
{
	if (s == NULL)
		return;
	if (fcntl(fd, F_GETFD) == -1)
        return;
	write(fd, s, ft_strlen(s));
}

static size_t	ft_strlen(const char *restrict str)
{
	register const char* s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
