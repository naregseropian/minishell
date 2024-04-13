/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strnstr.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 18:36:35 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 16:41:27 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strnstr(const char *big, const char *little, size_t len)
{
	size_t	i;
	size_t	j;

	i = 0;
	j = 0;
	if (little[j] == '\0')
		return ((char *)&big[i]);
	while (big[i] != '\0' && i < len)
	{
		i = i - j;
		j = 0;
		while (big[i] == little[j] && i < len)
		{
			i++;
			j++;
			if (little[j] == '\0')
				return ((char *)&big[i - j]);
		}
		i++;
	}
	return (NULL);
}

/* 
#include <bsd/string.h>
#include <stdio.h>

int main()
{
	char haystack[30] = "aaabcabcd";
    char needle[10] = "aabc";


	char *ptr;
	char *ptr1;

	ptr = ft_strnstr(haystack, needle, 30);
	ptr1 = strnstr(haystack, needle, 30);
	printf("%s\n", ptr);
	printf("%s\n", ptr1);
}
 */