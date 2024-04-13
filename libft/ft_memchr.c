/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_memchr.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/21 13:23:54 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 16:18:43 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_memchr(const void *s, int c, size_t n)
{
	size_t	i;

	i = 0;
	while (i < n)
	{
		if (((unsigned char *)s)[i] == (unsigned char)c)
			return ((void *)s + i);
		i++;
	}
	return (NULL);
}

//The  memchr()  function scans the initial n bytes of the memory area
//pointed to by s for the first instance of c.  Both c and  the  bytes
//of the memory area pointed to by s are interpreted as unsigned char.

//return a pointer to the matching byte 
//or NULL if the character does not occur in the given memory area.
