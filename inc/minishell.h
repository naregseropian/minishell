/* ************************************************************************** */
/*                                                                            */
/*                                                        :::      ::::::::   */
/*   minishell.h                                        :+:      :+:    :+:   */
/*                                                    +:+ +:+         +:+     */
/*   By: nseropia <nseropia@student.42.fr>          +#+  +:+       +#+        */
/*                                                +#+#+#+#+#+   +#+           */
/*   Created: 2023/11/27 14:24:28 by nseropia          #+#    #+#             */
/*   Updated: 2023/12/09 19:43:11 by nseropia         ###   ########.fr       */
/*                                                                            */
/* ************************************************************************** */

#ifndef MINISHELL_H
# define MINISHELL_H

# include "../libft/libft.h"
# include <stdio.h>
# include <dirent.h>
# include <errno.h>
# include <fcntl.h>
# include <limits.h>
# include <readline/history.h>
# include <readline/readline.h>
# include <signal.h>
# include <stdbool.h>
# include <stddef.h>
# include <stdint.h>
# include <stdlib.h>
# include <sys/wait.h>
# include <termios.h>
# include <unistd.h>

# define EXEC 1
# define REDIR 2
# define PIPE 3

# define PATH_MAX 4096
# define FLAG "UNEVEN"

extern volatile sig_atomic_t	g_signal_received;

struct					s_cmd
{
	int					type;
};

struct					s_execcmd
{
	int					type;
	char				*av[PATH_MAX];
};

struct					s_redircmd
{
	int					type;
	struct s_cmd		*cmd;
	char				*filename;
	int					mode;
	int					fd;
	int					pfd;
};

struct					s_pipecmd
{
	int					type;
	struct s_cmd		*left;
	struct s_cmd		*right;
};

typedef struct s_shell
{
	char				**envcpy;
	char				*pwd;
	char				*old_pwd;
	char				*home;
	int					*exit_status;
	int					flag_ctrl_c;
	char				**temp;
	int					i;
	int					flag;
	char				*start;
	int					len;
	int					fds[2];
	char				symbol;
	char				*delimiter;
	int					delimiter_length;
	char				*line;
	char				*expand_start;
	char				*var_name;
	char				*value;
}						t_shell;

typedef struct s_export
{
	char	**temp;
	int		i;
	int		flag;
}						t_export;

/* Main */
void				ft_loop(t_shell *shell);
void				ft_loop_util_1(char *line_read, t_shell *shell);
void				ft_loop_util_2(char *line_read, struct s_cmd *cmd, 
						t_shell *shell);
void				ft_wait_in_parent(int pid, t_shell *shell);
void				ft_wait_in_parent_2(int pid, t_shell *shell);
int					do_fork(struct s_cmd *cmd, t_shell *shell);
void				ft_do_exec(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
char				*handle_variable_expansion(char **line_read, 
						t_shell *shell, char *start);
char				*handle_unquoted_string(char **line_read, t_shell *shell);
char				*handle_quoted_string(char **line_read, t_shell *shell);
char				*expand_variable(char **line_read, t_shell *shell);
char				*expand_exit_status(char **line_read, t_shell *shell);
char				*concatenate_argument_parts(char *orig, char *part);
int					ft_count_single_quotes(char *line);
int					ft_is_pipe(char *line);
int					ft_is_quote(char *line);
int					ft_count_double_quotes(char *line);
char				*ft_quoted_string_util(char **line_read, t_shell *shell, 
						char quote_type, char *start);
void				ft_do_redir(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				count_quotes(const char *str, int *single_quotes, 
						int *double_quotes);
void				ft_do_without_pipe(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				ft_do_with_pipe(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				ft_wait_in_parent(int pid, t_shell *shell);
void				runcmd(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				runpipe(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				ft_cmd_error(struct	s_execcmd *ecmd, t_shell *shell, 
						struct s_cmd *tree);
void				ft_do_pipe(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				ft_do_pipe_util(int *p, int *pid, t_shell *shell);

/*Parse Redir*/
void				ft_read_and_skip_spaces(char **line_read);
void				ft_my_pipe(t_shell *shell);
void				ft_heredoc_ctrlc(t_shell *shell);
void				ft_write_heredoc(t_shell *shell);
void				ft_handle_heredoc(char **line_read, t_shell *shell);
void				ft_get_filename(char **line_read, t_shell *shell);
struct s_cmd		*ft_apply_redir(struct s_cmd *cmd, char *filename, 
						t_shell *shell);
struct s_cmd		*ft_handle_redirection(char **line_read, t_shell *shell, 
						struct s_cmd *cmd);
struct s_cmd		*parseredirs(struct s_cmd *cmd, char **line_read, 
						t_shell *shell);

/* Init */
int					init(t_shell *shell, char **env, int *exit);
int					init_env(t_shell *shell, char **env);
int					init_dir(t_shell *shell);
void				init_export(t_shell *shell);
void				init_redir(t_shell *shell);
void				init_expand_variable(t_shell *shell);

/* Env */
char				*ft_getenv(char *var, t_shell *shell);
void				replace_env(char *key, char *replace, t_shell *shell);

/* Utils */
int					env_count(char **env);
int					ft_isspace(int c);
int					ft_issymbol(int c);
void				skip_spaces(char **line_read);
int					is_whitespace(char *line_read);
void				ft_free(char **ptr);

/* Signals */
void				sigint_handler(int signum);
void				handle_sigint(void);
void				handle_sigquit_interactive(void);
void				handle_sigquit_default(void);
void				handle_signals(void);
void				handle_sigint_default(void);
void				handle_sigint_ignore(void);

/* Free */
void				ft_free_tree(struct s_cmd *cmd);
void				ft_free_exec(struct s_execcmd *ecmd);
void				ft_free_pipe(struct s_pipecmd *pcmd);
void				ft_free_redir(struct s_redircmd *rcmd);
void				ft_free_shell(t_shell *shell);
void				ft_free_2(char **ptr);
void				ft_free_tree_and_shell(struct s_cmd *tree, t_shell *shell);
void				ft_free_tree_and_shell_perror(struct s_cmd *tree, 
						t_shell *shell);

/* Pathing */
char				*get_long_path(char **envp);
char				**get_path_array(char *long_path);
char				*get_cmd_path(char **av, char **envcpy);

/* Builtins */
void				execute_builtins(struct s_execcmd *ecmd,
						t_shell *shell);
int					is_builtins(struct s_execcmd *ecmd);
int					my_echo(struct s_execcmd *ecmd, t_shell *shell);
int					my_exit(struct s_execcmd *ecmd, t_shell *shell);
int					my_cd(struct s_execcmd *ecmd, t_shell *shell);
int					my_pwd(struct s_execcmd *ecmd, t_shell *shell);
int					my_env(struct s_execcmd *ecmd, t_shell *shell);
int					my_unset(struct s_execcmd *ecmd, t_shell *shell);
int					is_two(struct s_execcmd *ecmd);
int					execute_two(struct s_execcmd *ecmd, t_shell *shell);
int					my_export(struct s_execcmd *ecmd, t_shell *shell);

/* Parse Tree */
struct s_cmd		*parsecmd(char *line_read, t_shell *shell);
struct s_cmd		*parseline(char **line_read, t_shell *shell);
struct s_cmd		*parseexec(char **line_read, t_shell *shell);
char				*parse_argument(char **line_read, t_shell *shell);
struct s_cmd		*parseexec_util(char **line_read, t_shell *shell, 
						struct s_cmd *ret, struct s_execcmd *cmd);
struct s_cmd		*parsepipe(char **line_read, t_shell *shell);
struct s_cmd		*execcmd(void);
struct s_cmd		*pipecmd(struct s_cmd *left, struct s_cmd *right);
void				runpipe(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
void				runcmd(struct s_cmd *cmd, t_shell *shell, 
						struct s_cmd *tree);
struct s_cmd		*redircmd(struct s_cmd *subcmd, char *file, int mode,
						int fd);

#endif
