/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_loop.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:40:03 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:32:36 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_loop_util_1(char *line_read, t_shell *shell)
{
	shell->flag_ctrl_c = 0;
	if (g_signal_received != 0)
		*(shell->exit_status) = 130;
	g_signal_received = 0;
	if (!line_read)
	{
		rl_clear_history();
		ft_free_shell(shell);
		write(1, "exit\n", 5);
		exit(1);
	}
}

void	ft_loop_util_2(char *line_read, struct s_cmd *cmd, t_shell *shell)
{
	if (ft_is_pipe(line_read) == 1)
		ft_do_with_pipe(cmd, shell, cmd);
	else
		ft_do_without_pipe(cmd, shell, cmd);
	free(line_read);
	line_read = NULL;
}

void	ft_loop(t_shell *shell)
{
	char			*line_read;
	struct s_cmd	*cmd;

	line_read = (char *) NULL;
	line_read = readline("minishell$ ");
	ft_loop_util_1(line_read, shell);
	if (ft_strlen(line_read) == 0 || (is_whitespace(line_read)))
		return ;
	cmd = NULL;
	if (line_read && *line_read)
	{
		add_history(line_read);
		cmd = parsecmd(line_read, shell);
		if (!cmd && g_signal_received != 0)
			return (*(shell->exit_status) = 130, free(line_read));
		if (!cmd && g_signal_received == 0)
			return (free(line_read));
	}
	ft_loop_util_2(line_read, cmd, shell);
}
