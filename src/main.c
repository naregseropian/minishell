/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   main.c                                             :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/10/10 12:03:10 by ubuntu            #+#    #+#             */
/*   Updated: 2023/12/09 18:32:39 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

volatile sig_atomic_t	g_signal_received = 0;

int	main(int argc, char **argv, char **env)
{
	t_shell	*shell;
	int		exit;

	exit = 0;
	shell = malloc(sizeof(t_shell));
	if (!shell)
		return (0);
	if (init(shell, env, &exit) == EXIT_FAILURE)
	{
		free(shell);
		return (EXIT_FAILURE);
	}
	handle_signals();
	while (argc && argv)
	{
		ft_loop(shell);
		handle_signals();
		if (g_signal_received != 0)
		{
			*(shell->exit_status) = 130;
			shell->flag_ctrl_c = 1;
			g_signal_received = 0;
		}
	}
	return (0);
}
