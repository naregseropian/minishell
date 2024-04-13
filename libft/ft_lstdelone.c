/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstdelone.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/14 12:38:31 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/17 12:28:26 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

/* typedef struct	s_list
{
	void			*content;
	struct s_list	*next;
}					t_list; */

/*
** ft_lstdelone - Takes as a parameter a node and frees the memory of the node’s 
** content using the function ’del’ given as a parameter and free the node. 
** The memory of ’next’ must not be freed.
** @lst: The node to free.
** @del: The address of the function used to delete the content.
*/
void	ft_lstdelone(t_list *lst, void (*del)(void *))
{
	if (lst && del)
	{
		del(lst->content);
		free(lst);
	}
}
