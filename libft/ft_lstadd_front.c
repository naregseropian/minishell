/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstadd_front.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 13:44:20 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/16 16:53:21 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

void	ft_lstadd_front(t_list **lst, t_list *new)
{
	if (lst == NULL && new == NULL)
		return ;
	new->next = *lst;
	*lst = new;
}

//////////////////////
/* lst: The address of a pointer to the first link of
a list.
new: The address of a pointer to the node to be
added to the list. */
//////////////////////

/* int     main(void)
{
	t_list *node1;
	t_list *list;
	
	list = ft_lstnew("List");
	node1 = ft_lstnew("Node1");
	//printf("%s", );
	ft_lstadd_front(&list, node1);
	//printf("%s", );
	
	return(0);
} */