/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_export.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 16:16:29 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/09 18:34:54 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

static void	ft_export_util(t_shell *shell)
{
	ft_putstr_fd("minishell: export: not a valid identifier\n", 2);
	shell->flag = 1;
	(shell->i)++;
}

int	my_export(struct s_execcmd *ecmd, t_shell *shell)
{
	init_export(shell);
	if (!ecmd->av[1])
		return (0);
	while (ecmd->av[shell->i])
	{
		if (ft_strchr(ecmd->av[shell->i], '='))
		{
			if (ecmd->av[shell->i][0] == '=')
			{
				ft_export_util(shell);
				continue ;
			}
			else if (!ft_isalpha(ecmd->av[shell->i][0]))
			{
				ft_export_util(shell);
				continue ;
			}
			shell->temp = ft_split(ecmd->av[shell->i], '=');
			replace_env(shell->temp[0], (char *)ecmd->av[shell->i], shell);
			ft_free(shell->temp);
		}
		(shell->i)++;
	}
	return (shell->flag);
}
