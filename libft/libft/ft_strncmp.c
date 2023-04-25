#include <stdlib.h>

int ft_strncmp(const char *restrict s1, const char *restrict s2, size_t n)
{
    const unsigned char *p1 = (const unsigned char *)s1;
    const unsigned char *p2 = (const unsigned char *)s2;
    size_t i = 0;

    while (i < n) {
        if (p1[i] != p2[i] || p1[i] == '\0' || p2[i] == '\0')
            break;
        i++;
    }
    if (i == n)
        return 0;
    return (p1[i] - p2[i]);
}

