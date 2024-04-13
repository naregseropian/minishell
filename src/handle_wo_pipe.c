/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_wo_pipe.c                                   :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:16:22 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:01:14 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	do_fork(struct s_cmd *cmd, t_shell *shell)
{
	int	pid;

	pid = fork();
	if (pid == -1)
	{
		ft_free_tree(cmd);
		ft_free_shell(shell);
		perror("fork: panic!");
		exit(5);
	}
	else
		return (pid);
}

void	ft_do_without_pipe(struct s_cmd *cmd, t_shell *shell, 
			struct s_cmd *tree)
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
			runcmd(cmd, shell, tree);
		}
		else
			ft_wait_in_parent(pid, shell);
	}
	ft_free_tree(tree);
}

void	ft_wait_in_parent(int pid, t_shell *shell)
{
	if (waitpid(pid, shell->exit_status, 0) < -1)
	{
		printf("waitpid error\n");
		exit(1);
	}
	if (WIFEXITED(*(shell->exit_status)))
		*(shell->exit_status) = WEXITSTATUS(*(shell->exit_status));
	else if (WIFSIGNALED(*(shell->exit_status)))
	{
		*(shell->exit_status) = WTERMSIG(*(shell->exit_status));
		if (*(shell->exit_status) == SIGINT)
			ft_putstr_fd("\n", 2);
		if (*(shell->exit_status) == SIGQUIT)
			ft_putstr_fd("Quit (core dumped)\n", 2);
		*(shell->exit_status) = *(shell->exit_status) + 128;
	}
}

void	runcmd(struct s_cmd *cmd, t_shell *shell, struct s_cmd *tree)
{
	if (cmd->type == EXEC)
		ft_do_exec(cmd, shell, tree);
	if (cmd->type == REDIR)
	{
		ft_do_redir(cmd, shell, tree);
		ft_free_tree(tree);
	}
}
