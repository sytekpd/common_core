#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str);
static size_t	ft_strnlen(const char *s, size_t max_len);
static void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n);

size_t ft_strlcat(char *restrict dst, const char *restrict const src, size_t size)
{
	size_t dst_len;
	size_t src_len;
	size_t remaining_space;
    size_t chars_to_copy;

    if (!dst || !src)
        return 0;
    dst_len = ft_strnlen(dst, size);
    src_len = ft_strlen(src);
    if (dst_len == size)
        return dst_len + src_len;
    remaining_space = size - dst_len - 1;
    if (src_len < remaining_space)
        chars_to_copy = src_len;
    else
        chars_to_copy = remaining_space;
    ft_memcpy(dst + dst_len, src, chars_to_copy);
    dst[dst_len + chars_to_copy] = '\0';
    return dst_len + src_len;
}

static size_t	ft_strnlen(const char *s, size_t max_len)
{
    const char *end;
	
	end = s;
    while (*end && max_len--)
        end++;
    return (size_t)(end - s);
}

static size_t	ft_strlen(const char *restrict str)
{
	register const char* s;

	s = str;
	while (*s)
		s++;
	return (s - str);
}

static void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
	size_t i;
	unsigned char *d;
    const unsigned char *s;

    if (dest == NULL && src == NULL)
        return NULL;
    if (n == 0)
        return dest;
    if (dest > src && dest < src + n)
        return NULL;
    if (src > dest && src < dest + n)
        return NULL;
	
    d = (unsigned char *) dest;
    s = (const unsigned char *) src;
	i = 0;
    while (i < n) {
        d[i] = s[i];
		i++;
    }
    return dest;
}