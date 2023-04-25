#include <stdlib.h>

static size_t	ft_strlen(const char *restrict str)
{
	size_t	i;

	i = 0;
	while (str[i])
		i++;
	return (i);
}

char	*ft_substr(const char *s, size_t start, size_t len)
{
	size_t	i;
	char	*str;

	if (s == NULL)
		return (NULL);

	if (start >= ft_strlen(s)) {
		str = (char *)malloc(1);
		if (str == NULL)
			return (NULL);
		*str = '\0';
		return (str);
	}

	str = (char *)malloc(sizeof(*s) * (len + 1));
	if (str == NULL)
		return (NULL);

	i = 0;
	while (i < len && s[start + i] != '\0') {
		str[i] = s[start + i];
		i++;
	}
	str[i] = '\0';

	return (str);
}
