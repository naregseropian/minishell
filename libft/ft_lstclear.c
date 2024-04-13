/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstclear.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 15:05:53 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/16 17:00:02 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstclear(t_list **lst, void (*del)(void *))
{
	t_list	*ptr;

	if (lst && *lst && del)
	{
		while (*lst != NULL)
		{
			ptr = *lst;
			*lst = (*lst)->next;
			del(ptr->content);
			free(ptr);
		}
	}
	*lst = (NULL);
}
