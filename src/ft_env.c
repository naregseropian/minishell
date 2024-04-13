/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_env.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/25 15:58:27 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/27 15:18:32 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	my_env(struct s_execcmd *ecmd, t_shell *shell)
{
	int	i;

	(void)ecmd;
	i = 0;
	while (shell->envcpy[i] != 0)
	{
		printf("%s\n", shell->envcpy[i]);
		i++;
	}
	return (0);
}
