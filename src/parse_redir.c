/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_redir.c                                      :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:49:58 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:23:02 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_get_filename(char **line_read, t_shell *shell)
{
	shell->start = *line_read;
	while (**line_read != '\0' && !ft_isspace((unsigned char)**line_read) && 
		!ft_issymbol(**line_read))
		(*line_read)++;
	shell->len = *line_read - shell->start;
}

struct s_cmd	*ft_apply_redir(struct s_cmd *cmd, char *filename, 
					t_shell *shell)
{
	if (shell->symbol == '<')
		cmd = redircmd(cmd, filename, O_RDONLY, STDIN_FILENO);
	else if (shell->symbol == '>')
		cmd = redircmd(cmd, filename, O_WRONLY | O_CREAT | O_TRUNC, 
				STDOUT_FILENO);
	else if (shell->symbol == '+')
		cmd = redircmd(cmd, filename, O_WRONLY | O_CREAT | O_APPEND, 
				STDOUT_FILENO);
	else if (shell->symbol == '*')
	{
		cmd = redircmd(cmd, NULL, 0, shell->fds[0]);
		((struct s_redircmd *)cmd)->pfd = shell->fds[0];
	}
	return (cmd);
}

struct s_cmd	*ft_handle_redirection(char **line_read, t_shell *shell, 
					struct s_cmd *cmd)
{
	char	*filename;

	ft_read_and_skip_spaces(line_read);
	ft_get_filename(line_read, shell);
	filename = ft_substr(shell->start, 0, shell->len);
	if (filename[0] == '\0') 
	{
		free(filename);
		filename = NULL;
	}
	cmd = ft_apply_redir(cmd, filename, shell);
	if (cmd == NULL)
		return (NULL);
	ft_read_and_skip_spaces(line_read);
	return (cmd);
}

struct s_cmd	*parseredirs(struct s_cmd *cmd, char **line_read, 
					t_shell *shell)
{
	init_redir(shell);
	while (**line_read != '\0' && (**line_read == '<' || **line_read == '>'))
	{
		shell->symbol = **line_read;
		(*line_read)++;
		if (shell->symbol == '>' && **line_read == '>')
		{
			shell->symbol = '+';
			(*line_read)++;
		}
		else if (shell->symbol == '<' && **line_read == '<')
		{
			shell->symbol = '*';
			ft_handle_heredoc(line_read, shell);
		}
		cmd = ft_handle_redirection(line_read, shell, cmd);
		if (cmd == NULL)
			return (NULL);
	}
	return (cmd);
}
