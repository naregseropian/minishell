/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir_util.c                                 :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:48:52 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:32:53 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_read_and_skip_spaces(char **line_read)
{
	while (ft_isspace(**line_read)) 
	{
		(*line_read)++;
	}
}

void	ft_my_pipe(t_shell *shell)
{
	if (pipe(shell->fds) != 0)
	{
		perror("pipe");
		ft_free_shell(shell);
		exit(EXIT_FAILURE);
	}
}

void	ft_heredoc_ctrlc(t_shell *shell)
{
	free(shell->line);
	close(shell->fds[1]);
}

void	ft_write_heredoc(t_shell *shell)
{
	write(shell->fds[1], shell->line, ft_strlen(shell->line));
	write(shell->fds[1], "\n", 1);
	free(shell->line);
}

void	ft_handle_heredoc(char **line_read, t_shell *shell)
{
	ft_my_pipe(shell);
	(*line_read)++;
	ft_read_and_skip_spaces(line_read);
	shell->delimiter = *line_read;
	while (**line_read != '\0' && !ft_isspace(**line_read))
		(*line_read)++;
	shell->delimiter_length = *line_read - shell->delimiter;
	while (1)
	{
		shell->line = readline("> ");
		if (g_signal_received == 1 || !shell->line) 
		{
			ft_heredoc_ctrlc(shell);
			break ;
		}
		if ((ft_strncmp(shell->line, shell->delimiter, shell->delimiter_length)
				== 0 && shell->line[shell->delimiter_length] == '\0')) 
		{
			free(shell->line);
			break ;
		}
		ft_write_heredoc(shell);
	}
	close(shell->fds[1]);
	ft_read_and_skip_spaces(line_read);
}
