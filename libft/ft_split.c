/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: pedrorodrigues <pedrorodrigues@student.    +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/05/05 19:49:17 by pedrorodrig       #+#    #+#             */
/*   Updated: 2023/05/09 23:52:45 by pedrorodrig      ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include <stdlib.h>

static void	free_split(char **arr)
{
	int	i;

	i = 0;
	while (arr[i])
		free(arr[i++]);
	free(arr);
}

static const char	*skip_delim(const char *s, char c)
{
	while (*s && *s == c)
		++s;
	return (s);
}

static char	*extract_word(const char **s, char c)
{
	const char	*start;
	int			len;
	char		*word;
	char		*p;

	start = *s;
	len = 0;
	while (**s && **s != c)
	{
		++len;
		++(*s);
	}
	word = (char *)malloc((len + 1) * sizeof(char));
	if (!word)
		return (NULL);
	p = word;
	*s = start;
	while (**s && **s != c)
	{
		*p++ = **s;
		++(*s);
	}
	*p = '\0';
	return (word);
}

static int	count_words(const char *s, char c)
{
	int	count;

	count = 0;
	while (*s)
	{
		s = skip_delim(s, c);
		if (*s)
		{
			++count;
			while (*s && *s != c)
				++s;
		}
	}
	return (count);
}

char	**ft_split(char const *s, char c)
{
	int		num_words;
	char	**result;
	int		i;

	num_words = count_words(s, c);
	result = (char **)malloc((num_words + 1) * sizeof(char *));
	if (!result)
		return (NULL);
	i = 0;
	while (*s)
	{
		s = skip_delim(s, c);
		if (*s)
		{
			result[i++] = extract_word(&s, c);
			if (!result[i - 1])
			{
				free_split(result);
				return (NULL);
			}
		}
	}
	result[i] = NULL;
	return (result);
}
