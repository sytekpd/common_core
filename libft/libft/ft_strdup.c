#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str);

char *ft_strdup(const char *restrict s)
{
    int i;
    int j;
    char *str;

    i = 0;
    j = ft_strlen(s);
    str = (char *)malloc(sizeof(*str) * (j + 1));
    if (str == NULL)
        return NULL;
    while (i < j)
    {
        str[i] = s[i];
        i++;
    }
    str[i] = '\0';
    return str;
}

static size_t	ft_strlen(const char *restrict str)
{
	register const char* s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}