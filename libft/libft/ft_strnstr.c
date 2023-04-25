#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str);
static int ft_strncmp(const char *restrict s1, const char *restrict s2, size_t n);

char	*ft_strnstr(const char *haystack, const char *needle, size_t n)
{
	size_t	haystack_len;
	size_t	needle_len;
	size_t	i;

	if (!haystack || !needle)
		return (NULL);

	haystack_len = ft_strlen(haystack);
	needle_len = ft_strlen(needle);
	if (needle_len > n)
		return (NULL);
	i = 0;
	while (i <= haystack_len - needle_len && i <= n - needle_len)
	{
		if (ft_strncmp(haystack + i, needle, needle_len) == 0)
			return ((char *)haystack + i);
		i++;
	}
	return (NULL);
}

static size_t	ft_strlen(const char *restrict str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

static int ft_strncmp(const char *restrict s1, const char *restrict s2, size_t n)
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