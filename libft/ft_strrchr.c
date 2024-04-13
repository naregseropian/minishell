/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strrchr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:23:49 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 16:43:29 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strrchr(const char *s, int c)
{
	char	*pointer;
	size_t	i;

	pointer = NULL;
	i = 0;
	while (s[i] != '\0')
	{
		if (s[i] == (char)c)
			pointer = (char *)s;
		s++;
	}
	if (s[i] == (char)c)
		return ((char *)&s[i]);
	return (pointer);
}

/* int main()
{
    const char str[] = "a string like this.\n";
    printf("%s", strrchr(str, 'i'));
    const char str1[] = "a string like this.\n";
    printf("%s", ft_strrchr(str1, 'i'));
} */