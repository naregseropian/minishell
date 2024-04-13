/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_substr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/26 10:10:02 by NaregSeropi       #+#    #+#             */
/*   Updated: 2023/01/14 16:49:14 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_substr(char const *s, unsigned int start, size_t len)
{
	char	*p;
	size_t	i;
	size_t	len_from_start;

	if (start > ft_strlen(s) || s == NULL)
		return (ft_strdup(""));
	i = 0;
	len_from_start = ft_strlen(s + start);
	if (len_from_start < len)
		len = len_from_start;
	p = (char *)malloc(sizeof(char) * (len + 1));
	if (p == (NULL))
		return (NULL);
	while (s[start + i] != '\0' && i < len)
	{
		p[i] = s[start + i];
		i++;
	}
	p[i] = '\0';
	return (p);
}

/* char    *ft_substr(char const *s, unsigned int start, size_t len)
{
    char    *ptr;
    size_t  i;
    i = 0;
    if (!s)
        return (0);
    if (ft_strlen(s) < start)
    {
        ptr = (char *)malloc(sizeof(char));
        if (!ptr)
            return (0);
        *ptr = '\0';
        return (ptr);
    }
    if (start + len > ft_strlen(s))
        len = ft_strlen(s) - start;
    ptr = (char *)malloc(len + 1);
    if (!ptr)
        return (0);
    while (s[start] != 0 && i < len)
        ptr[i++] = s[start++];
    ptr[i] = '\0';
    return (ptr);
} */

/* #include <stdio.h>
int main()
{
    char const str[] = "tripouille";
    unsigned int b = 5;
    size_t l = 5;
    printf("%s\n", ft_substr(str, b, l));
} */
