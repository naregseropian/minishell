/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   env.c                                              :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/18 13:43:19 by ubuntu            #+#    #+#             */
/*   Updated: 2023/11/27 14:23:04 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*ft_getenv(char *var_name, t_shell *shell)
{
	char	*var;
	int		len;
	int		i;

	i = 0;
	len = ft_strlen(var_name);
	while (shell->envcpy[i])
	{
		var = shell->envcpy[i];
		if (!ft_strncmp(var, var_name, len) && var[len] == '=' && var[len + 1])
			return (var + len + 1);
		i++;
	}
	return (NULL);
}

void	replace_env(char *key, char *replace, t_shell *shell)
{
	int		i;
	char	*temp;

	temp = ft_strjoin(key, "=");
	i = -1;
	while (shell->envcpy[++i])
	{
		if (ft_strncmp(shell->envcpy[i], temp, ft_strlen(temp)) == 0)
			break ;
	}
	free(shell->envcpy[i]);
	free(temp);
	if (replace)
		shell->envcpy[i] = ft_strdup(replace);
	else
	{
		while (shell->envcpy[i + 1])
		{
			shell->envcpy[i] = shell->envcpy[i + 1];
			++i;
		}
		shell->envcpy[i] = NULL;
	}
}
