/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:22:11 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 16:33:37 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strchr(const char *s, int c)
{
	size_t	i;

	i = 0;
	while (s[i] != (char)c && s[i] != '\0')
		s++;
	if (s[i] == (char)c)
		return ((char *)s);
	return (NULL);
}

/* char *ft_strchr(const char *s, int c)
{
    int counter;

    counter = 0;
    while (*s != '\0')
    {
        if (*s == (char)c)
        {
            counter++;
            return (char*)s;
        }
        s++;
    }
    if ((char)c == '\0')
        return ((char*)s);
    return (NULL);
} */

/* int main()
{
	const char str1[] = "a string like this.\n";
    printf("%s", ft_strchr(str1, 'i'));
} */