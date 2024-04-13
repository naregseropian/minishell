/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strdup.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 15:26:50 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 16:34:13 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

char	*ft_strdup(const char *s)
{
	char	*pointer;
	size_t	str_size;
	size_t	i;

	str_size = ft_strlen(s) + 1;
	i = 0;
	pointer = (char *)malloc(sizeof(char) * str_size);
	if (pointer == NULL || str_size == 0)
		return (NULL);
	while (s[i] != '\0')
	{
		pointer[i] = s[i];
		i++;
	}
	pointer[i] = '\0';
	return (pointer);
}

/*
	//ft_memcpy(pointer, s, str_size); //void *dest, const void *src, size_t n
    while (s[i] != '\0')
    {
        p[i] = s[i];
        i++;
    }
    p[i] = '\0';
    return p;
*/
