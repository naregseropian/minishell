/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_cmd.c                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:48:22 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:28:59 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

struct s_cmd	*parsecmd(char *line_read, t_shell *shell)
{
	struct s_cmd	*cmd;

	cmd = parseline(&line_read, shell);
	if (!cmd)
		return (NULL);
	return (cmd);
}

struct s_cmd	*parseline(char **line_read, t_shell *shell)
{
	struct s_cmd	*cmd;

	cmd = parsepipe(line_read, shell);
	if (!cmd)
		return (NULL);
	return (cmd);
}

struct s_cmd	*parsepipe(char **line_read, t_shell *shell)
{
	struct s_cmd	*cmd;

	cmd = parseexec(line_read, shell);
	if (!cmd)
	{
		ft_free_tree(cmd);
		return (NULL);
	}
	while (**line_read == '|' && *(*line_read + 1) != '\0')
	{
		(*line_read)++;
		while (ft_isspace((unsigned char) **line_read))
			(*line_read)++;
		cmd = pipecmd(cmd, parsepipe(line_read, shell));
	}
	return (cmd);
}
