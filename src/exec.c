/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   exec.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:01:45 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 20:01:19 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_cmd_error(struct	s_execcmd *ecmd, t_shell *shell, struct s_cmd *tree)
{
	int		exit_status;

	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(ecmd->av[0], 2);
	ft_putstr_fd(": command not found\n", 2);
	*(shell->exit_status) = 127;
	exit_status = *(shell->exit_status);
	ft_free_tree(tree);
	ft_free_shell(shell);
	exit(exit_status);
}

void	ft_free_tree_and_shell_perror(struct s_cmd *tree, t_shell *shell)
{
	ft_free_tree(tree);
	ft_free_shell(shell);
	perror("minishell");
	exit(126);
}

void	ft_free_tree_and_shell(struct s_cmd *tree, t_shell *shell)
{
	ft_free_tree(tree);
	ft_free_shell(shell);
	exit(1);
}

void	ft_do_exec(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	struct s_execcmd		*ecmd;
	char					*path;

	ecmd = (struct s_execcmd *)cmd;
	handle_sigquit_default();
	if (ecmd->av[0] == 0)
		ft_free_tree_and_shell(tree, shell);
	if (ecmd->av[0][0] == 0)
		ft_cmd_error(ecmd, shell, tree);
	if (access(ecmd->av[0], X_OK) == 0)
		(path = ecmd->av[0]);
	else
		path = get_cmd_path(ecmd->av, shell->envcpy);
	if (path && access(path, F_OK | X_OK) == 0)
	{
		if (execve(path, ecmd->av, shell->envcpy) == -1)
			ft_free_tree_and_shell_perror(tree, shell);
	}
	else
		ft_cmd_error(ecmd, shell, tree);
}

/* void	ft_do_exec(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	struct s_execcmd		*ecmd;
	char					*path;

	ecmd = (struct s_execcmd *)cmd;
	handle_sigquit_default();
	if (ecmd->av[0] == 0)
		ft_free_tree_and_shell(tree, shell);
	if (ecmd->av[0][0] == 0)
		ft_cmd_error(ecmd, shell, tree);
	if (access(ecmd->av[0], X_OK) == 0)
		(path = ecmd->av[0]);
	else
		path = get_cmd_path(ecmd->av, shell->envcpy);
	if (access(path, F_OK | X_OK) == 0)
	{
		if (execve(path, ecmd->av, shell->envcpy) == -1)
			ft_free_tree_and_shell_perror(tree, shell);
	}
	else
		ft_cmd_error(ecmd, shell, tree);
}
 */