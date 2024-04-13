/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_1.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:57:13 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:15:42 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	skip_spaces(char **line_read)
{
	while (ft_isspace(**line_read)) 
		(*line_read)++;
}

int	is_whitespace(char *line_read)
{
	int	i;

	i = 0;
	while (line_read[i])
	{
		if (!isspace(line_read[i]))
			return (0);
		i++;
	}
	return (1);
}

char	*ft_quoted_string_util(char **line_read, t_shell *shell, 
			char quote_type, char *start)
{
	char	*temp;
	char	*part;

	temp = NULL;
	part = NULL;
	while (**line_read && **line_read != quote_type)
	{
		if (quote_type == '"' && **line_read == '$')
		{
			part = handle_variable_expansion(line_read, shell, start);
			temp = concatenate_argument_parts(temp, part);
			start = *line_read;
		}
		else
			(*line_read)++;
	}
	if (**line_read == quote_type)
	{
		part = ft_substr(start, 0, *line_read - start);
		temp = concatenate_argument_parts(temp, part);
		(*line_read)++;
	}
	return (temp);
}

char	*handle_quoted_string(char **line_read, t_shell *shell)
{
	char	quote_type;
	char	*start;
	char	*temp;

	quote_type = **line_read;
	if ((quote_type == '\'' && ft_count_single_quotes(*line_read) % 2 != 0) || 
		(quote_type == '"' && ft_count_double_quotes(*line_read) % 2 != 0))
	{
		ft_putstr_fd("Error: Unmatched quotes\n", 2);
		return (FLAG);
	}
	temp = NULL;
	if (*(*line_read + 1) == quote_type)
	{
		*line_read += 2;
		return (NULL);
	}
	start = *line_read + 1;
	(*line_read)++;
	temp = ft_quoted_string_util(line_read, shell, quote_type, start);
	return (temp);
}

void	count_quotes(const char *str, int *single_quotes, int *double_quotes)
{
	int			in_single_quote;
	int			in_double_quote;
	const char	*p ;

	in_single_quote = 0;
	in_double_quote = 0;
	*single_quotes = 0;
	*double_quotes = 0;
	p = str;
	while (*p)
	{
		if (*p == '\'' && !in_double_quote)
		{
			(*single_quotes)++;
			in_single_quote = !in_single_quote;
		}
		else if (*p == '\"' && !in_single_quote)
		{
			(*double_quotes)++;
			in_double_quote = !in_double_quote;
		}
		p++;
	}
}
