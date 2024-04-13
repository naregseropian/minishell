/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:14:22 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/09 18:34:01 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	init(t_shell *shell, char **env, int *exit)
{
	if (init_env(shell, env) == EXIT_FAILURE)
	{
		ft_free(shell->envcpy);
		return (EXIT_FAILURE);
	}
	if (init_dir(shell) == EXIT_FAILURE)
		return (EXIT_FAILURE);
	shell->exit_status = exit;
	return (EXIT_SUCCESS);
}

int	init_env(t_shell *shell, char **env)
{
	int	i;

	shell->envcpy = ft_calloc(PATH_MAX, sizeof(char *));
	if (!shell->envcpy)
		return (EXIT_FAILURE);
	i = -1;
	while (env && env[++i] != 0)
	{
		shell->envcpy[i] = ft_strdup(env[i]);
		if (!shell->envcpy[i])
			return (EXIT_FAILURE);
	}
	shell->home = getenv("HOME");
	return (EXIT_SUCCESS);
}

int	init_dir(t_shell *shell)
{
	char	arr[PATH_MAX];
	char	*wd;

	wd = getcwd(arr, PATH_MAX);
	shell->pwd = ft_strdup(wd);
	if (!shell->pwd)
	{
		free(shell->pwd);
		return (EXIT_FAILURE);
	}
	if (!getenv("OLDPWD"))
		shell->old_pwd = NULL;
	else
	{
		shell->old_pwd = ft_strdup(wd);
		if (!shell->old_pwd)
		{
			free(shell->pwd);
			return (EXIT_FAILURE);
		}
	}
	return (EXIT_SUCCESS);
}
