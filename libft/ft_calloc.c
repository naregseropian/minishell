/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_calloc.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/20 13:22:59 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/17 14:23:08 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	*ft_calloc(size_t nelem, size_t elsize)
{
	void	*p;

	p = malloc(nelem * elsize);
	if (nelem == 0 && elsize == 0)
		return (p);
	if (p == NULL)
		return (NULL);
	ft_bzero(p, nelem * elsize);
	return (p);
}

/* int	main()
{
	size_t	n = 10;
	size_t	size = 1;
	
	printf("%lu", sizeof(ft_calloc(n, size)));
} */