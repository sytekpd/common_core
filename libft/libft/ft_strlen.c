#include <stdlib.h>

size_t	ft_strlen(const char *restrict str)
{
	register const char* s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}
