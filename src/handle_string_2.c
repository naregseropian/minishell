/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   handle_string_2.c                                  :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 17:15:25 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 17:53:36 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	ft_is_pipe(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '|')
			return (1);
		i++;
	}
	return (0);
}

int	ft_count_single_quotes(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '\'')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_count_double_quotes(char *line)
{
	int	i;
	int	count;

	i = 0;
	count = 0;
	while (line[i])
	{
		if (line[i] == '"')
		{
			count++;
		}
		i++;
	}
	return (count);
}

int	ft_is_quote(char *line)
{
	int	i;

	i = 0;
	while (line[i])
	{
		if (line[i] == '"' || line[i] == '\'')
			return (1);
		i++;
	}
	return (0);
}
