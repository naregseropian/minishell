/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   redir.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:12:47 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 17:13:03 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_do_redir_util(struct s_cmd *tree, t_shell *shell)
{
	ft_free_tree(tree);
	ft_free_shell(shell);
	perror("Failed to open file");
	exit(EXIT_FAILURE);
}

void	ft_do_redir(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	struct s_redircmd	*rcmd;

	rcmd = (struct s_redircmd *)cmd;
	if (rcmd->filename)
	{
		close(rcmd->fd);
		if (open(rcmd->filename, rcmd->mode, 0777) < 0)
			ft_do_redir_util(tree, shell);
		runcmd(rcmd->cmd, shell, tree);
	}
	if (rcmd->pfd >= 0)
	{
		if (dup2(rcmd->pfd, 0) < 0)
		{
			ft_free_tree(tree);
			ft_free_shell(shell);
			perror("dup2");
			exit(EXIT_FAILURE);
		}
		close(rcmd->pfd);
		runcmd(rcmd->cmd, shell, tree);
	}
}
