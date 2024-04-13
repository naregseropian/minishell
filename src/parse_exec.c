/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   parse_exec.c                                       :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/12/09 16:58:17 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 18:15:12 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#include "../inc/minishell.h"

char	*parse_argument(char **line_read, t_shell *shell)
{
	char	*temp; 
	char	*part;

	temp = NULL;
	while (**line_read && !ft_isspace(**line_read) && !ft_issymbol(**line_read))
	{
		if (**line_read == '\'' || **line_read == '"')
		{
			part = handle_quoted_string(line_read, shell);
			if (ft_strncmp(part, FLAG, 7) == 0)
				return (NULL);
		}
		else
			part = handle_unquoted_string(line_read, shell);
		temp = ft_gnl_strjoin(temp, part);
	}
	return (temp);
}

struct s_cmd	*parseexec_util(char **line_read, t_shell *shell, 
			struct s_cmd *ret, struct s_execcmd *cmd)
{
	char	*temp;
	int		ac;

	ac = 0;
	while (**line_read)
	{
		skip_spaces(line_read);
		if (**line_read == '\0' || **line_read == '|') 
			break ;
		if (ft_issymbol(**line_read))
		{
			ret = parseredirs(ret, line_read, shell);
			if (!ret)
				return (NULL);
		}
		else
		{
			temp = parse_argument(line_read, shell);
			if (!temp)
				return (ft_free_tree(ret), NULL);
			cmd->av[ac++] = temp;
		}
	}
	cmd->av[ac] = NULL;
	return (ret);
}

struct s_cmd	*parseexec(char **line_read, t_shell *shell)
{
	struct s_execcmd	*cmd;
	struct s_cmd		*ret;

	ret = execcmd();
	cmd = (struct s_execcmd *)ret;
	ret = parseexec_util(line_read, shell, ret, cmd);
	return (ret);
}
