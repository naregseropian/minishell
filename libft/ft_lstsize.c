/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_lstsize.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/01/13 18:36:37 by nseropia          #+#    #+#             */
/*   Updated: 2023/01/16 16:57:55 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "libft.h"

int	ft_lstsize(t_list *lst)
{
	int		i;
	t_list	*ptr;

	i = 0;
	ptr = NULL;
	if (lst == NULL)
		return (0);
	ptr = lst;
	while (ptr != NULL)
	{
		i++;
		ptr = ptr->next;
	}
	return (i);
}

/* int	main()
{
	t_list *	lst;
	t_list *	new1;
	t_list *	new2;
	t_list *	new3;		

	lst = ft_lstnew("captain blaubeer");
	printf("%i\n", ft_lstsize(lst));

	new1 = ft_lstnew("captain brombeer");
	ft_lstadd_front(&lst, new1);
	printf("%i\n", ft_lstsize(lst));

	new2 = ft_lstnew("captain schlaubeer");
	ft_lstadd_front(&lst, new2);
	printf("%i\n", ft_lstsize(lst));

	new3 = ft_lstnew("captain stachelbeer");
	ft_lstadd_front(&lst, new3);
	printf("%i\n", ft_lstsize(lst));
} */