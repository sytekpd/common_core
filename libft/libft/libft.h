#ifndef LIBFT_H
# define LIBFT_H

# include <stdlib.h>

typedef struct s_list
{
    void *content;
    struct s_list *next;
} t_list;

int	ft_atoi(const char *restrict str);
void	ft_bzero(void *restrict s, size_t n);
void	*ft_calloc(size_t count, size_t size);
int	ft_isalnum(int i);
int	ft_isalpha(int i);
int	ft_isascii(int i);
int	ft_isdigit(int i);
int	ft_isprint(int i);
void	*ft_memchr(const void *restrict s, int c, size_t n);
int	ft_memcmp(const void *restrict s1, const void *restrict s2, size_t n);
void	*ft_memcpy(void *restrict dest, const void *restrict src, size_t n);
void	*ft_memmove(void *restrict s1, const void *restrict s2, size_t n);
void	*ft_memset(void *restrict b, int c, size_t len);
char	*ft_strchr(const char *restrict s, int i);
char	*ft_strdup(const char *restrict s);
size_t	ft_strlcat(char *restrict dest, const char *restrict const src, size_t size);
size_t	ft_strlcpy(char *restrict dest, const char *restrict const src, size_t size);
size_t	ft_strlen(const char *restrict str);
int	ft_strncmp(const char *restrict s1, const char *restrict s2, size_t n);
char	*ft_strnstr(const char *restrict haystack, const char *restrict needle, size_t len);
char	*ft_strrchr(const char *restrict s, int c);
int	ft_tolower(int i);
int	ft_toupper(int i);

char	*ft_substr(const char *restrict s, unsigned int start, size_t len);
char	*ft_strjoin(const char *restrict s1, const char *restrict s2);
char	*ft_strtrim(const char *restrict s1, const char *restrict set);
char	**ft_split(const char *restrict str, char c);
char	*ft_itoa(int n);
char	*ft_strmapi(const char *restrict s, char (*f)(unsigned int, char));
void	ft_striteri(char *restrict s, void (*f)(unsigned int, char*));
void	ft_putchar_fd(char c, int fd);
void	ft_putstr_fd(const char *restrict s, int fd);
void	ft_putendl_fd(const char *restrict s, int fd);
void	ft_putnbr_fd(int n, int fd);


#endif