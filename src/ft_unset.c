/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_unset.c                                         :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 14:59:25 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/01 14:14:05 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	my_unset(struct s_execcmd *ecmd, t_shell *shell)
{
	int	i;

	i = 0;
	if (!ecmd->av[1])
		return (0);
	while (ecmd->av[++i])
	{
		if ((ecmd->av[i][0] == '_' && ecmd->av[i][1] == '=') || 
			(ecmd->av[i][0] == '_' && !ecmd->av[i][1]))
			return (0);
		replace_env((char *)ecmd->av[i], NULL, shell);
	}
	return (0);
}
