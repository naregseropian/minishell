/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_pipe.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:59:13 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:14:00 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_do_with_pipe(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	struct s_execcmd	*ecmd;
	int					pid;

	ecmd = (struct s_execcmd *)cmd;
	pid = 42;
	if (is_builtins(ecmd) == 0)
		execute_builtins(ecmd, shell);
	else if (is_two(ecmd) == 0)
		execute_two(ecmd, shell);
	else
	{
		handle_sigint_ignore();
		pid = do_fork(cmd, shell);
		if (pid == 0)
		{
			handle_sigint_default();
			runpipe(cmd, shell, tree);
		}
		else
			ft_wait_in_parent(pid, shell);
	}
	ft_free_tree(tree);
}

void	ft_do_pipe_util(int *p, int *pid, t_shell *shell)
{
	close(p[0]);
	close(p[1]);
	ft_wait_in_parent_2(pid[0], shell);
	ft_wait_in_parent(pid[1], shell);
}

void	ft_do_pipe(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	int						p[2];
	struct s_pipecmd		*pcmd;
	int						pid[2];

	pcmd = (struct s_pipecmd *)cmd;
	pipe(p);
	pid[0] = do_fork(cmd, shell);
	if (pid[0] == 0)
	{
		dup2(p[1], STDOUT_FILENO);
		close(p[0]);
		close(p[1]);
		runpipe(pcmd->left, shell, tree);
	}
	pid[1] = do_fork(cmd, shell);
	if (pid[1] == 0)
	{
		dup2(p[0], STDIN_FILENO);
		close(p[1]);
		close(p[0]);
		runpipe(pcmd->right, shell, tree);
	}
	ft_do_pipe_util(p, pid, shell);
}

void	runpipe(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	int		exit_status;

	if (cmd->type == EXEC)
		ft_do_exec(cmd, shell, tree);
	if (cmd->type == REDIR)
		ft_do_redir(cmd, shell, tree);
	if (cmd->type == PIPE)
		ft_do_pipe(cmd, shell, tree);
	exit_status = *(shell->exit_status);
	ft_free_tree(tree);
	ft_free_shell(shell);
	exit(exit_status);
}

void	ft_wait_in_parent_2(int pid, t_shell *shell)
{
	if (waitpid(pid, shell->exit_status, 0) < -1)
	{
		printf("waitpid error\n");
		exit(1);
	}
	if (WIFEXITED(*(shell->exit_status)))
		*(shell->exit_status) = WEXITSTATUS(*(shell->exit_status));
	else if (WIFSIGNALED(*(shell->exit_status)))
		*(shell->exit_status) = WTERMSIG(*(shell->exit_status));
}
