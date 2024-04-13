/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_cd.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:38:16 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/27 15:18:19 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	my_cd(struct s_execcmd *ecmd, t_shell *shell)
{
	char	arr[PATH_MAX];
	char	*wd;
	int		status;

	if (!ecmd->av[1] || ft_strncmp(ecmd->av[1], "~", 1) == 0)
		wd = ft_strdup(shell->home);
	else if (ft_strncmp(ecmd->av[1], "-", 1) == 0)
		wd = ft_strdup(ft_getenv("OLDPWD", shell));
	else
		wd = ft_strdup(ecmd->av[1]);
	(void)getcwd(arr, PATH_MAX);
	status = chdir(wd);
	if (status < 0)
		printf("minishell: cd: %s: %s\n", wd, strerror(errno));
	else
	{
		free(wd);
		wd = ft_strjoin("OLDPWD=", arr);
		replace_env("OLDPWD", wd, shell);
		free(wd);
		(void)getcwd(arr, PATH_MAX);
		wd = ft_strjoin("PWD=", arr);
		replace_env("PWD", wd, shell);
	}
	return (free(wd), status);
}
