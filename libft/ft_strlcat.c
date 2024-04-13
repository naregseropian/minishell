/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlcat.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/08 19:18:28 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 17:18:29 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlcat(char *dest, const char *src, size_t dstsize)
{
	size_t	len_dest;
	size_t	len_src;
	size_t	j;
	size_t	i;

	len_dest = ft_strlen(dest);
	len_src = ft_strlen(src);
	j = len_dest;
	i = 0;
	if (src == NULL)
		return (0);
	if ((dstsize > 0) && (len_dest + 1 < dstsize))
	{
		while ((src[i] != '\0') && (len_dest + 1 + i < dstsize))
		{
			dest[j] = src[i];
			j++;
			i++;
		}
		dest[j] = '\0';
	}
	if (dstsize <= len_dest)
		len_dest = dstsize;
	return (len_dest + len_src);
}

/* 
int main()
{
	char dest[] = "Hello ";
	char src[] = "world";
	size_t size = 3;
	printf("%lu", ft_strlcat(dest, src, size));
} */