/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   init_1.c                                           :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 18:33:29 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:34:05 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	init_export(t_shell *shell)
{
	shell->temp = NULL;
	shell->i = 1;
	shell->flag = 0;
}

void	init_redir(t_shell *shell)
{
	shell->delimiter = NULL;
	shell->delimiter_length = 0;
	shell->line = NULL;
	shell->start = NULL;
	shell->len = 0;
	shell->fds[0] = 0;
	shell->fds[1] = 0;
}

void	init_expand_variable(t_shell *shell)
{
	shell->expand_start = NULL;
	shell->var_name = NULL;
	shell->value = NULL;
}
