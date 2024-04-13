/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   builtins_utils.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 13:40:06 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/08 19:36:22 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	is_builtins(struct s_execcmd *ecmd)
{
	if (ft_strncmp(ecmd->av[0], "cd", 3) == 0)
		return (0);
	else if (ft_strncmp(ecmd->av[0], "export", 7) == 0)
		return (0);
	else if (ft_strncmp(ecmd->av[0], "unset", 6) == 0)
		return (0);
	else if (ft_strncmp(ecmd->av[0], "exit", 5) == 0)
		return (0);
	return (EXIT_FAILURE);
}

void	execute_builtins(struct s_execcmd *ecmd, t_shell *shell)
{
	if (ft_strncmp(ecmd->av[0], "cd", 3) == 0)
	{
		if (my_cd(ecmd, shell) < 0)
			*(shell->exit_status) = 1;
		else
			*(shell->exit_status) = 0;
	}
	else if (ft_strncmp(ecmd->av[0], "export", 7) == 0)
	{
		if (my_export(ecmd, shell) != 0)
			*(shell->exit_status) = 1;
		else
			*(shell->exit_status) = 0;
	}
	else if (ft_strncmp(ecmd->av[0], "unset", 6) == 0)
	{
		my_unset(ecmd, shell);
		*(shell->exit_status) = 0;
	}
	else if (ft_strncmp(ecmd->av[0], "exit", 5) == 0)
		my_exit(ecmd, shell);
}

int	is_two(struct s_execcmd *ecmd)
{
	if (ft_strncmp(ecmd->av[0], "echo", 5) == 0)
		return (0);
	else if (ft_strncmp(ecmd->av[0], "pwd", 4) == 0)
		return (0);
	else if (ft_strncmp(ecmd->av[0], "env", 4) == 0)
		return (0);
	return (EXIT_FAILURE);
}

int	execute_two(struct s_execcmd *ecmd, t_shell *shell)
{
	if (ft_strncmp(ecmd->av[0], "pwd", 4) == 0)
	{
		if (my_pwd(ecmd, shell) != 0)
			*(shell->exit_status) = 1;
		else
			*(shell->exit_status) = 0;
	}
	else if (ft_strncmp(ecmd->av[0], "env", 4) == 0)
	{
		if (my_env(ecmd, shell) != 0)
			*(shell->exit_status) = 1;
		else
			*(shell->exit_status) = 0;
	}
	else if (ft_strncmp(ecmd->av[0], "echo", 5) == 0)
	{
		if (my_echo(ecmd, shell) != 0)
			*(shell->exit_status) = 1;
		else
			*(shell->exit_status) = 0;
	}
	return (EXIT_SUCCESS);
}
