/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string.c                                    :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:54:44 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:19:02 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*handle_variable_expansion(char **line_read, t_shell *shell, 
			char *start)
{
	char	*part;
	char	*expanded_part;
	char	*new_part;

	part = ft_substr(start, 0, *line_read - start);
	expanded_part = expand_variable(line_read, shell);
	new_part = concatenate_argument_parts(part, expanded_part);
	return (new_part);
}

char	*handle_unquoted_string(char **line_read, t_shell *shell)
{
	char	*start;
	char	*temp;
	char	*part;

	start = *line_read;
	temp = NULL;
	part = NULL;
	while (**line_read && !ft_isspace(**line_read) && 
		!ft_issymbol(**line_read) && **line_read != '"' && **line_read != '\'')
	{
		if (**line_read == '$')
		{
			part = handle_variable_expansion(line_read, shell, start);
			temp = concatenate_argument_parts(temp, part);
			start = *line_read;
		}
		else
			(*line_read)++;
	}
	if (start != *line_read)
	{
		part = ft_substr(start, 0, *line_read - start);
		temp = concatenate_argument_parts(temp, part);
	}
	return (temp);
}

char	*expand_exit_status(char **line_read, t_shell *shell)
{
	char	*buffer;

	buffer = ft_itoa(*(shell->exit_status));
	*line_read += 2;
	return (buffer);
}

char	*expand_variable(char **line_read, t_shell *shell)
{
	init_expand_variable(shell);
	shell->start = *line_read + 1;
	if (*shell->start == '?')
		return (expand_exit_status(line_read, shell));
	else if (ft_isalnum(*shell->start) || *shell->start == '_')
	{
		while (ft_isalnum(*shell->start) || *shell->start == '_')
			shell->start++;
		shell->var_name = ft_substr(*line_read + 1, 0, 
				shell->start - (*line_read + 1));
		*line_read = shell->start;
		shell->value = ft_getenv(shell->var_name, shell);
		free(shell->var_name);
		if (shell->value)
			return (ft_strdup(shell->value));
		else
			return (ft_strdup(""));
	}
	else
	{
		*line_read += 1;
		return (ft_strdup("$"));
	}
	return (ft_strdup(""));
}

char	*concatenate_argument_parts(char *orig, char *part)
{
	char	*new_str;

	if (orig)
	{
		new_str = ft_strjoin(orig, part);
		free(orig);
		free(part);
	}
	else
		new_str = part;
	return (new_str);
}
