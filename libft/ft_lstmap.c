/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstmap.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/17 11:40:23 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/17 13:22:30 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

t_list	*ft_lstmap(t_list *lst, void *(*f)(void *), void (*del)(void *))
{
	t_list	*ptr;
	t_list	*new_list;
	t_list	*new_node;

	ptr = NULL;
	new_list = NULL;
	if (lst == NULL)
		return (NULL);
	ptr = lst;
	while (ptr != NULL)
	{
		new_node = ft_lstnew(f(ptr->content));
		if (new_node == NULL)
		{
			ft_lstclear(&new_list, del);
			return (NULL);
		}
		ft_lstadd_back(&new_list, new_node);
		ptr = ptr->next;
	}
	return (new_list);
}
