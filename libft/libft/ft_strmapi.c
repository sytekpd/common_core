#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str);

char	*ft_strmapi(char const *restrict s, char (*f)(unsigned int, char))
{
	unsigned int	i;
	char			*str;

	if (s == NULL)
		return (NULL);

	i = 0;
	str = (char *)malloc(sizeof(char) * (ft_strlen(s)) + 1);
	if (str == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		str[i] = f(i, s[i]);
		i++;
	}
	str[i] = '\0';
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
