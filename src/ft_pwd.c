/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_pwd.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/23 15:38:28 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/27 15:24:39 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	my_pwd(struct s_execcmd *ecmd, t_shell *shell)
{
	char	wd[PATH_MAX];

	(void)shell;
	if (ft_strncmp(ecmd->av[0], "pwd", 4) == 0)
	{
		if (getcwd(wd, PATH_MAX) != NULL)
			printf("%s\n", wd);
		else
		{
			perror("getcwd");
			return (1);
		}
	}
	return (0);
}
