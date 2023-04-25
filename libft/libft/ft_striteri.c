#include <stdlib.h>

void	ft_striteri(char *restrict s, void (*f)(unsigned int, char*))
{
	unsigned int	i;

	if (s == NULL)
		return;

	i = 0;
	while (s[i] != '\0')
	{
		f(i, s + i);
		i++;
	}
}
