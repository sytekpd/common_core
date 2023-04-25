#include <string.h>
#include <string.h>

static void *ft_helpercpy(void *restrict dest, const void *restrict src, size_t n)
{
    char *d = dest;
    const char *s = src;

    while (n-- > 0) {
        *d++ = *s++;
    }

    return dest;
}

void *ft_memcpy(void *restrict dest, const void *restrict src, size_t n)
{
    if (dest == NULL && src == NULL)
        return NULL;
    if (n == 0)
        return dest;
    if (dest > src && dest < src + n)
        return NULL;
    if (src > dest && src < dest + n)
        return NULL;

    // use memcpy for copies smaller than 64 bytes
    if (n < 64) {
        return ft_helpercpy(dest, src, n);
    }

    // use assembly for larger copies
    char *d = dest;
    const char *s = src;

    asm volatile (
        "movq %0, %%rdi\n\t"    // destination pointer in rdi
        "movq %1, %%rsi\n\t"    // source pointer in rsi
        "movq %2, %%rcx\n\t"    // count in rcx
        "shr $4, %%rcx\n\t"     // count / 16
        "cld\n\t"               // clear direction flag
        "rep movsb\n\t"         // move 16 bytes at a time
        :
        : "r" (d), "r" (s), "r" ((long) n)
        : "memory", "rdi", "rsi", "rcx"
    );

    // handle any remaining bytes
    n &= 0xf;
    ft_helpercpy(d + (n & ~0x7), s + (n & ~0x7), n & 0x7);

    return dest;
}


