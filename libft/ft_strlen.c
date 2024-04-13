/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strlen.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/11/30 13:25:38 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/14 17:12:27 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

size_t	ft_strlen(const char *str)
{
	unsigned long	i;

	i = 0;
	if (str == NULL && str[i] == '\0')
		return (0);
	while (str[i] != '\0')
	{
		i++;
	}
	return (i);
}

/* int	main()
{
	char str[] = "";
	printf("%lu", strlen(str));
}
 */