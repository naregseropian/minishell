/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_tree_nodes.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:43:50 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:29:38 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

struct s_cmd	*execcmd(void)
{
	struct s_execcmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
		return (NULL);
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = EXEC;
	return ((struct s_cmd *)cmd);
}

struct s_cmd	*pipecmd(struct s_cmd *left, struct s_cmd *right)
{
	struct s_pipecmd	*cmd;

	if (!right)
	{
		ft_free_tree(left);
		return (NULL);
	}
	cmd = malloc(sizeof(*cmd));
	if (!cmd)
	{
		ft_free_tree(left);
		ft_free_tree(right);
		return (NULL);
	}
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = PIPE;
	cmd->left = left;
	cmd->right = right;
	return ((struct s_cmd *)cmd);
}

struct s_cmd	*redircmd(struct s_cmd *subcmd, char *filename, 
					int mode, int fd)
{
	struct s_redircmd	*cmd;

	cmd = malloc(sizeof(*cmd));
	if (!cmd)
	{
		ft_free_tree((struct s_cmd *)cmd);
		return (NULL);
	}
	ft_memset(cmd, 0, sizeof(*cmd));
	cmd->type = REDIR;
	cmd->cmd = subcmd;
	cmd->filename = filename;
	cmd->mode = mode;
	cmd->fd = fd;
	return ((struct s_cmd *)cmd);
}
