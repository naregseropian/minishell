/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   ft_exit.c                                          :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/26 17:59:11 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/09 18:36:39 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

unsigned int	ft_strcheck(char *str)
{
	unsigned int	res;
	int				i;

	i = 0;
	res = 0;
	if (str[i] == '+')
		i++;
	if (str[i] == '-')
		i++;
	while (str[i] != '\0')
	{
		if (str[i] >= '0' && str[i] <= '9')
		{
			res = (res * 10) + (str[i] - '0');
			i++;
		}
		else
			return (-1);
	}
	return (res);
}

void	ft_exit_with_status(struct s_execcmd *ecmd, t_shell *shell, 
			int exit_status)
{
	ft_putstr_fd("exit\n", 2);
	ft_free_tree((struct s_cmd *)ecmd);
	ft_free_shell(shell);
	exit(exit_status);
}

void	ft_handle_numeric_argument_error(struct s_execcmd *ecmd, t_shell *shell)
{
	ft_putstr_fd("minishell: ", 2);
	ft_putstr_fd(ecmd->av[1], 2);
	ft_putstr_fd(": numeric argument required\n", 2);
	ft_exit_with_status(ecmd, shell, 2);
}

int	my_exit(struct s_execcmd *ecmd, t_shell *shell)
{
	if (ecmd->av[1] && (int)ft_strcheck(ecmd->av[1]) != -1) 
	{
		*(shell->exit_status) = ft_atoi(ecmd->av[1]);
		ft_exit_with_status(ecmd, shell, *(shell->exit_status));
	}
	else if (ecmd->av[1]) 
		ft_handle_numeric_argument_error(ecmd, shell);
	else
		ft_exit_with_status(ecmd, shell, 0);
	return (0);
}
