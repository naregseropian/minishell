/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_echo.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/17 11:41:42 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/27 15:18:29 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	my_echo_util(struct s_execcmd *ecmd, t_shell *shell, int i, int n_flag)
{
	if (ft_strncmp("~", ecmd->av[i], 2) == 0)
		ecmd->av[i] = ft_getenv("HOME", shell);
	if (ecmd->av[i + 1])
		printf("%s ", ecmd->av[i]);
	else if (!n_flag)
		printf("%s\n", ecmd->av[i]);
	else
		printf("%s", ecmd->av[i]);
}

int	my_echo(struct s_execcmd *ecmd, t_shell *shell)
{
	int	n_flag;
	int	i;

	n_flag = 0;
	i = 0;
	if (!ecmd->av[1])
		printf("\n");
	while (ecmd->av[++i])
	{
		if (i == 1 && ft_strncmp("-n", ecmd->av[i], 3) == 0 && !ecmd->av[i + 1])
		{
			i++;
			return (0);
		}
		while (ft_strncmp("-n", ecmd->av[i], 3) == 0 && ecmd->av[i + 1])
		{
			n_flag = 1;
			i++;
		}
		my_echo_util(ecmd, shell, i, n_flag);
	}
	return (0);
}
