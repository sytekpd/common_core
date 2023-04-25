#include "libft.h"
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <fcntl.h>
#include <unistd.h>

char my_toupper(unsigned int i, char c)
{
    (void)c;
    return ft_toupper(i);
}

void test_function(unsigned int i, char *c)
{
    printf("ft_striteri: %u: %c\n", i, *c);
}

int main(void)
{
    char str1[] = "Hello, world!";
    char str2[] = "Hello, World!";
    char str3[] = "hello, world!";
    char str4[] = "Test string";
    char str5[] = "Another test string";
    //char str6[] = "";
    char str7[] = "    Trim this!    ";
    char str8[] = "split,this,string,by,comma";
    char str9[] = "-1234";
    char str10[] = "abcd";

    // Test ft_atoi
    printf("ft_atoi: %d\n", ft_atoi(str9));
    
    // Test ft_bzero
    char buffer[10];
    ft_bzero(buffer, sizeof(buffer));
    printf("ft_bzero: ");
    for (size_t i = 0; i < sizeof(buffer); i++) {
        printf("%d ", buffer[i]);
    }
    printf("\n");

    // Test ft_calloc
    int *arr = ft_calloc(5, sizeof(int));
    printf("ft_calloc: ");
    for (int i = 0; i < 5; i++) {
        printf("%d ", arr[i]);
    }
    printf("\n");
    free(arr);

    // Test ft_isalnum
    printf("ft_isalnum: %d\n", ft_isalnum('a'));
    printf("ft_isalnum: %d\n", ft_isalnum('1'));
    printf("ft_isalnum: %d\n", ft_isalnum('$'));
    
    // Test ft_isalpha
    printf("ft_isalpha: %d\n", ft_isalpha('a'));
    printf("ft_isalpha: %d\n", ft_isalpha('1'));
    printf("ft_isalpha: %d\n", ft_isalpha('$'));

    // Test ft_isascii
    printf("ft_isascii: %d\n", ft_isascii(42));
    printf("ft_isascii: %d\n", ft_isascii(127));
    printf("ft_isascii: %d\n", ft_isascii(128));

    // Test ft_isdigit
    printf("ft_isdigit: %d\n", ft_isdigit('5'));
    printf("ft_isdigit: %d\n", ft_isdigit('x'));
    printf("ft_isdigit: %d\n", ft_isdigit('0'));

    // Test ft_isprint
    printf("ft_isprint: %d\n", ft_isprint(' '));
    printf("ft_isprint: %d\n", ft_isprint(9));
    printf("ft_isprint: %d\n", ft_isprint(127));

    // Test ft_memchr
    char *s = "Hello, world!";
    char c = ',';
    printf("ft_memchr: %s\n", (char *)ft_memchr(s, c, strlen(s)));

    // Test ft_memcmp
    printf("ft_memcmp: %d\n", ft_memcmp(str4, str5, sizeof(str4)));

    // Test ft_memcpy
    char dest[sizeof(str4)];
    ft_memcpy(dest, str4, sizeof(str4));
    printf("ft_memcpy: %s\n", dest);

    // Test ft_memmove
    printf("ft_memmove: %s\n", (char *)ft_memmove(str1+1, str1, strlen(str1)+1));
    
    // Test ft_memset
    char str11[] = "aaaaaaaaa";
    printf("ft_memset: %s\n", (char *)ft_memset(str11, 'b', 5));
    
    // Test ft_strchr
    printf("ft_strchr: %s\n", ft_strchr(str1, 'o'));
    
    // Test ft_strdup
    char *str12 = ft_strdup(str5);
    printf("ft_strdup: %s\n", str12);
    free(str12);
    
    // Test ft_strlcat
    char dest2[20] = "This is a";
    printf("ft_strlcat: %lu\n", ft_strlcat(dest2, " test", 20));
    
    // Test ft_strlcpy
    char dest3[20];
    printf("ft_strlcpy: %lu\n", ft_strlcpy(dest3, "This is a test", 20));
    
    // Test ft_strlen
    printf("ft_strlen: %lu\n", ft_strlen(str1));
    
    // Test ft_strncmp
    printf("ft_strncmp: %d\n", ft_strncmp(str2, str3, strlen(str2)));
    
    // Test ft_strnstr
    printf("ft_strnstr: %s\n", ft_strnstr(str5, "test", strlen(str5)));
    
    // Test ft_strrchr
    printf("ft_strrchr: %s\n", ft_strrchr(str1, 'o'));
    
    // Test ft_tolower
    printf("ft_tolower: %c\n", ft_tolower('A'));
    
    // Test ft_toupper
    printf("ft_toupper: %c\n", ft_toupper('a'));

    // Test ft_substr
    printf("ft_substr: %s\n", ft_substr(str1, 7, 5));

    // Test ft_strjoin
    printf("ft_strjoin: %s\n", ft_strjoin(str4, str5));

    // Test ft_strtrim
    printf("ft_strtrim: %s\n", ft_strtrim(str7, " "));

    // Test ft_split
    char **split_str = ft_split(str8, ',');
    for (int i = 0; split_str[i]; i++)
        printf("ft_split: %s\n", split_str[i]);
    free(split_str);

    // Test ft_itoa
    printf("ft_itoa: %s\n", ft_itoa(-1234));

    // Test ft_strmapi

    char *mapi_str = ft_strmapi(str10, my_toupper);
    printf("ft_strmapi: %s\n", mapi_str);
    free(mapi_str);

    // Test ft_striteri
    ft_striteri(str4, &test_function);

    // Test ft_putchar_fd
    ft_putchar_fd('a', 1);

    // Test ft_putstr_fd
    ft_putstr_fd(str4, 1);

    // Test ft_putendl_fd
    ft_putendl_fd(str4, 1);

    // Test ft_putnbr_fd
    ft_putnbr_fd(1234, 1);

    return (0);
}