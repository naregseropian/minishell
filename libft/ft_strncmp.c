/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_strncmp.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2022/12/12 20:39:56 by nseropia          #+#    #+#             */
/*   Updated: 2023/11/30 16:18:18 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_strncmp(const char *s1, const char *s2, size_t n)
{
	size_t	counter;

	counter = 0;
	if (s1 == NULL)
		return (1);
	while ((counter < n) && (s1[counter] || s2[counter]))
	{
		if (s1[counter] != s2[counter])
			return ((unsigned char)s1[counter] - (unsigned char)s2[counter]);
		counter++;
	}
	return (0);
}

//The strcmp() function compares two strings byte-by-byte,
//according to the ordering of your machine's character set.
//The function returns an integer greater than, equal to, 
//or less than 0, if the string pointed to by s1 is greater than,
//equal to, or less than the string pointed to by s2 respectively. 
//The sign of a non-zero return value is determined by the sign of 
//the difference between the values of the first pair of bytes that 
//differ in the strings being compared. 
//The strncmp() function makes the same comparison 
//but looks at a maximum of n bytes. 
//Bytes following a null byte are not compared.