/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_split.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/02 15:41:29 by NaregSeropi       #+#    #+#             */
/*   Updated: 2023/01/14 16:32:18 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static size_t	ft_word_count(char const *s, char delimiter)
{
	size_t	word_count;
	size_t	i;

	word_count = 0;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] != delimiter && (s[i + 1] == delimiter || s[i + 1] == '\0'))
			word_count++;
		i++;
	}
	return (word_count);
}

static size_t	ft_word_length(char const *s, unsigned int word_count, \
								char delimiter)
{
	size_t	i;
	size_t	count;
	size_t	len;

	i = 0;
	count = 0;
	len = 0;
	while (s[i] == delimiter)
		i++;
	while (count < word_count)
	{
		if (s[i] == delimiter && s[i + 1] != delimiter)
			count++;
		i++;
	}
	while (s[i] != delimiter && s[i] != '\0')
	{
		i++;
		len++;
	}
	return (len);
}

static size_t	ft_word_index(char const *s, unsigned int word_count, \
								char delimiter)
{
	size_t	i;
	size_t	count;

	i = 0;
	count = 0;
	while (s[i] == delimiter)
		i++;
	while (count < word_count)
	{
		if (s[i] == delimiter && s[i + 1] != delimiter)
			count++;
		i++;
	}
	return (i);
}

void	ft_word_fill(char const *s, char *str, size_t index, char delimiter)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = ft_word_index(s, index, delimiter);
	while (s[j] != '\0' && s[j] != delimiter)
	{
		str[i] = s[j];
		i++;
		j++;
	}
	str[i] = '\0';
}

char	**ft_split(char const *s, char delimiter)
{
	char	**array;
	size_t	word_count;
	size_t	i;

	word_count = ft_word_count(s, delimiter);
	array = (char **)malloc(sizeof(char *) * (word_count + 1));
	i = 0;
	if (array == NULL)
		return (NULL);
	while (i < word_count)
	{
		array[i] = (char *)malloc(sizeof(char) * \
					(ft_word_length(s, i, delimiter) + 1));
		ft_word_fill(s, array[i], i, delimiter);
		i++;
	}
	array[i] = 0;
	return (array);
}

/* int main()
{
	char str[] = "  My  split";
	char delimiter = ' ';
	ft_split(str, delimiter);
} */
