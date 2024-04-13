/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_free_tree.c                                     :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:42:37 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:30:29 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free_exec(struct s_execcmd *ecmd)
{
	if (*(ecmd->av))
		ft_free_2(ecmd->av);
	free(ecmd);
}

void	ft_free_pipe(struct s_pipecmd *pcmd)
{
	if (pcmd->left)
		ft_free_tree(pcmd->left);
	if (pcmd->right)
		ft_free_tree(pcmd->right);
	if (pcmd)
		free(pcmd);
}

void	ft_free_redir(struct s_redircmd *rcmd)
{
	ft_free_tree(rcmd->cmd);
	if (rcmd->filename)
	{
		free(rcmd->filename);
		rcmd->filename = NULL;
	}
	free(rcmd);
}

void	ft_free_tree(struct s_cmd *cmd)
{
	struct s_execcmd	*ecmd;
	struct s_pipecmd	*pcmd;
	struct s_redircmd	*rcmd;

	if (!cmd)
		return ;
	if (cmd->type == EXEC)
	{
		ecmd = (struct s_execcmd *)cmd;
		ft_free_exec(ecmd);
	}
	else if (cmd->type == PIPE)
	{
		pcmd = (struct s_pipecmd *)cmd;
		ft_free_pipe(pcmd);
	}
	else if (cmd->type == REDIR)
	{
		rcmd = (struct s_redircmd *)cmd;
		ft_free_redir(rcmd);
	}
}
