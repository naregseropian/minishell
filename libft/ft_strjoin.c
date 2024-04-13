/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strjoin.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/29 21:53:43 by NaregSeropi       #+#    #+#             */
/*   Updated: 2023/01/14 16:35:20 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strjoin(char const *s1, char const *s2)
{
	size_t	i;
	char	*p;

	p = (char *)malloc(sizeof(char) * (ft_strlen(s1) + ft_strlen(s2) + 1));
	if (p == (NULL))
		return (NULL);
	i = 0;
	while (s1[i] != '\0')
	{
		p[i] = s1[i];
		i++;
	}
	i = 0;
	while (s2[i] != '\0')
	{
		p[ft_strlen(s1) + i] = s2[i];
		i++;
	}
	p[ft_strlen(s1) + i] = '\0';
	return (p);
}
/*
#include <stdio.h>
int main()
{
    char * s = ft_strjoin("tripouille", "42");
    printf("%s", s);
}
*/