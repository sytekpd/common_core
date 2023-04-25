#include <stddef.h>
#include <stdint.h>
#include <stdlib.h>

void *ft_memmove(void *restrict s1, const void *restrict s2, size_t n) {
    unsigned char *dst;
    const unsigned char *src;

    if (!s1 || !s2) {
        return NULL;
    }

    dst = (unsigned char *)s1;
    src = (const unsigned char *)s2;

    if (src < dst) {
        dst += n;
        src += n;

        while (n >= sizeof(uint64_t)) {
            n -= sizeof(uint64_t);
            *((uint64_t *)dst - 1) = *((const uint64_t *)src - 1);
            dst -= sizeof(uint64_t);
            src -= sizeof(uint64_t);
        }

        while (n >= sizeof(uint32_t)) {
            n -= sizeof(uint32_t);
            *((uint32_t *)dst - 1) = *((const uint32_t *)src - 1);
            dst -= sizeof(uint32_t);
            src -= sizeof(uint32_t);
        }

        while (n--) {
            *--dst = *--src;
        }
    } else {
        while (n >= sizeof(uint64_t)) {
            n -= sizeof(uint64_t);
            *((uint64_t *)dst) = *((const uint64_t *)src);
            dst += sizeof(uint64_t);
            src += sizeof(uint64_t);
        }

        while (n >= sizeof(uint32_t)) {
            n -= sizeof(uint32_t);
            *((uint32_t *)dst) = *((const uint32_t *)src);
            dst += sizeof(uint32_t);
            src += sizeof(uint32_t);
        }

        while (n--) {
            *dst++ = *src++;
        }
    }

    return s1;
}
