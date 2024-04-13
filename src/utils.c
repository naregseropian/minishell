/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   utils.c                                            :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 10:46:00 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/26 20:47:03 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

int	env_count(char **env)
{
	int	i;

	i = 0;
	while (env && env[i] != 0)
		i++;
	return (i);
}

int	ft_isspace(int c)
{
	return (c == ' ' || c == '\t' || c == '\n' || c == '\r' || c == '\v'
		|| c == '\f');
}

int	ft_issymbol(int c)
{
	return (c == '|' || c == '>' || c == '<');
}
