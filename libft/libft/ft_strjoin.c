#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str);

char *ft_strjoin(const char *restrict s1, const char *restrict s2)
{
    size_t len1, len2;
    char *str, *p;

    if (!s1 || !s2)
        return (NULL);

    len1 = ft_strlen(s1);
    len2 = ft_strlen(s2);
    str = malloc(len1 + len2 + 1);
    if (!str)
        return (NULL);
    p = str;
    while (*s1)
        *p++ = *s1++;
    while (*s2)
        *p++ = *s2++;
    *p = '\0';
    return (str);
}

static size_t	ft_strlen(const char *restrict str)
{
	register const char* s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}