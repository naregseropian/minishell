/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strtrim.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 22:32:26 by NaregSeropi       #+#    #+#             */
/*   Updated: 2023/01/16 12:30:16 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

static	int	ft_start(char const *s1, char const *set)
{
	int	start;
	int	count;

	start = 0;
	while (s1[start] != '\0')
	{
		count = 0;
		while (set[count] != '\0')
		{
			if (s1[start] == set[count])
				break ;
			count++;
		}
		if (set[count] == '\0')
			return (start);
		start++;
	}
	return (start);
}

static int	ft_end(char const *s1, char const *set)
{
	int	end;
	int	count;

	end = ft_strlen(s1) - 1;
	while (end != 0)
	{
		count = 0;
		while (set[count] != '\0')
		{
			if (s1[end] == set[count])
				break ;
			count ++;
		}
		if (set[count] == '\0')
			return (end);
		end--;
	}
	return (end);
}

char	*ft_strtrim(char const *s1, char const *set)
{
	char	*p;
	size_t	start;
	size_t	end;
	size_t	i;

	i = 0;
	start = ft_start(s1, set);
	end = ft_end(s1, set);
	if (start > end || s1[i] == '\0')
		return (ft_strdup(""));
	p = (char *)malloc(sizeof(char) * ((end - start) + 2));
	if (p == (NULL))
		return (NULL);
	while (start <= end)
	{
		p[i] = s1[start];
		start++;
		i++;
	}
	p[i] = '\0';
	return (p);
}

/* int	main()
{
	char str[] = "xyzNAREGzyx";
	char set[] = "xyz";

	printf("%i\n", ft_start(str, set));
	printf("%i\n", ft_end(str, set));
	printf("%s", ft_strtrim(str, set));
} */