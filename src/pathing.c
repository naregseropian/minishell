/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   pathing.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/24 17:05:46 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 20:08:48 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

void	ft_free(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	else
	{
		while (ptr[i])
		{
			if (ptr[i] != NULL)
			{
				free(ptr[i]);
				ptr[i] = NULL;
			}
			i++;
		}
		if (ptr != NULL)
		{
			free(ptr);
			ptr = NULL;
		}
	}
}

void	ft_free_2(char **ptr);

void	ft_free_2(char **ptr)
{
	int	i;

	i = 0;
	if (ptr == NULL)
		return ;
	else
	{
		while (ptr[i])
		{
			if (ptr[i] != NULL)
			{
				free(ptr[i]);
				ptr[i] = NULL;
			}
			i++;
		}
	}
}

char	*get_long_path(char **envcpy)
{
	char	*long_path;

	long_path = NULL;
	while (*envcpy != NULL)
	{
		if (ft_strncmp(*envcpy, "PATH=", 5) == 0)
		{
			long_path = (*envcpy + 5);
			break ;
		}
		envcpy++;
	}
	return (long_path);
}

char	**get_path_array(char *long_path)
{
	char	**path_array;

	if (!long_path)
		return (NULL);
	path_array = ft_split(long_path, ':');
	return (path_array);
}

char	*get_cmd_path(char **av, char **envcpy)
{
	char	*single_path;
	char	*temp_path;
	char	*long_path;
	char	**path_array;
	int		i;

	i = 0;
	long_path = get_long_path(envcpy);
	if (long_path == NULL)
		return (NULL);
	path_array = get_path_array(long_path);
	while (path_array[i] != NULL)
	{
		temp_path = ft_strjoin(path_array[i], "/");
		single_path = ft_strjoin(temp_path, *av);
		free(temp_path);
		if (access(single_path, X_OK | F_OK) == 0)
			return (ft_free(path_array), (single_path));
		else
			free(single_path);
		i++;
	}
	return (ft_free(path_array), *av);
}
