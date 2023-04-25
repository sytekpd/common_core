#include <stdint.h>
#include <string.h>

void *ft_memset(void *dest, int c, size_t n)
{
    char *d;
    uint64_t *dd;
    uint64_t cccc;
    size_t count;

    d = dest;
    // use assembly for large blocks
    if (n >= 64) {
        dd = (uint64_t *) d;
        cccc = (uint64_t) (unsigned char) c;
        cccc = (cccc << 56) | (cccc << 48) | (cccc << 40) | (cccc << 32) |
               (cccc << 24) | (cccc << 16) | (cccc << 8) | cccc;
        count = n / 8;
        asm volatile (
            "movq %0, %%rdi\n\t"    // destination pointer in rdi
            "movq %1, %%rax\n\t"    // value to set in rax
            "movq %2, %%rcx\n\t"    // count in rcx
            "cld\n\t"               // clear direction flag
            "rep stosq\n\t"         // store 8 bytes at a time
            :
            : "r" (dd), "r" (cccc), "r" ((long) count)
            : "memory", "rdi", "rax", "rcx"
        );
        d += count * 8;
        n -= count * 8;
    }
    // set any remaining bytes
    while (n-- > 0)
        *d++ = c;
    return dest;
}



/*
#include <stddef.h>
#include <stdint.h>


uint64_t create_pattern(int c) {
    uint64_t pattern = (unsigned char)c;
    pattern = (pattern << 8) | pattern;
    pattern = (pattern << 16) | pattern;
    pattern = (pattern << 32) | pattern;
    return pattern;
}

unsigned char *handle_unaligned_start(unsigned char *dst, int c, size_t *len) {
    while ((uintptr_t)dst % sizeof(uint64_t) != 0 && *len > 0) {
        *dst++ = (unsigned char)c;
        --(*len);
    }
    return dst;
}

uint64_t *write_large_blocks(uint64_t *dst_aligned, uint64_t pattern, size_t *num_blocks) {
    while (*num_blocks > 0) {
        size_t count = (*num_blocks + 7) / 8;
        *num_blocks -= count * 8;

        while (count > 0) {
            *dst_aligned++ = pattern;
            count--;
        }
    }
    return dst_aligned;
}

unsigned char *write_remaining_bytes(unsigned char *dst, int c, size_t remaining_bytes) {
    while (remaining_bytes > 0) {
        *dst++ = (unsigned char)c;
        --remaining_bytes;
    }
    return dst;
}

void *ft_memset(void *restrict b, int c, size_t len) {
    unsigned char *dst = (unsigned char *)b;
    uint64_t pattern;

    if (len == 0) {
        return b;
    }

    pattern = create_pattern(c);
    dst = handle_unaligned_start(dst, c, &len);

    uint64_t *dst_aligned = (uint64_t *)dst;
    size_t num_blocks = len / (8 * sizeof(uint64_t));
    size_t remaining_bytes = len % (8 * sizeof(uint64_t));

    dst_aligned = write_large_blocks(dst_aligned, pattern, &num_blocks);
    remaining_bytes /= sizeof(uint64_t);

    dst_aligned = write_large_blocks(dst_aligned, pattern, &remaining_bytes);
    dst = (unsigned char *)dst_aligned;
    remaining_bytes = len % sizeof(uint64_t);

    dst = write_remaining_bytes(dst, c, remaining_bytes);

    return b;
}
*/