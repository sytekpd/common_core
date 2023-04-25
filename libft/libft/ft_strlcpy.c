#include <stdlib.h>

size_t ft_strlcpy(char *restrict dest, const char *restrict const src, size_t size)
{
	size_t i = 0;
	if (size == 0)
	{
		while (src[i])
			i++;
		return i;
	}

	while (i < size - 1 && src[i] != '\0')
	{
		dest[i] = src[i];
		i++;
	}
	dest[i] = '\0';
	while (src[i] != '\0')
		i++;
	return i;
}
