/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strmapi.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/05 17:36:10 by NaregSeropi       #+#    #+#             */
/*   Updated: 2023/01/14 16:40:00 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strmapi(char const *s, char (*f)(unsigned int, char))
{
	char	*a;
	int		i;
	int		size;

	i = 0;
	size = ft_strlen(s) + 1;
	a = (char *)malloc(sizeof(char) * size);
	if (a == NULL)
		return (NULL);
	while (s[i] != '\0')
	{
		a[i] = f(i, s[i]);
		i++;
	}
	a[i] = '\0';
	return (a);
}

/* char ftry(unsigned int i, char c)
{
	return c - 32 + i - i;
}

int main()
{
	char str[] = "hello world";
	printf("%s", ft_strmapi(str, ftry));
} */