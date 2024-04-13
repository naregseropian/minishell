/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_shell.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:42:08 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 16:42:24 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_shell(t_shell *shell)
{
	ft_free(shell->envcpy);
	if (shell->pwd)
	{
		free(shell->pwd);
		shell->pwd = NULL;
	}
	if (shell->old_pwd)
	{
		free(shell->old_pwd);
		shell->old_pwd = NULL;
	}
	free(shell);
	shell = NULL;
}
