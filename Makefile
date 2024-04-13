NAME	:= minishell

S	:= src/
O	:= obj/

CC	:= cc 
CFLAGS := -Wall -Wextra -Werror -g

SRCS	:= $S/main.c $S/init.c $S/utils.c $S/signals.c $S/builtins_utils.c $S/ft_cd.c $S/ft_pwd.c $S/env.c $S/ft_echo.c $S/ft_env.c $S/ft_export.c $S/ft_unset.c $S/ft_exit.c $S/pathing.c $S/signals2.c $S/ft_loop.c $S/ft_free_shell.c $S/ft_free_tree.c $S/ft_tree_nodes.c $S/parse_cmd.c $S/parse_redir.c $S/parse_redir_util.c $S/exec.c $S/handle_pipe.c $S/handle_string.c $S/handle_string_1.c $S/parse_exec.c $S/redir.c $S/handle_wo_pipe.c $S/handle_string_2.c $S/init_1.c

OBJS	:= $(SRCS:$S/%.c=$O/%.o)

LIBFT	:= libft/libft.a
INCS	:= -Iinc -I/home/linuxbrew/.linuxbrew/opt/readline/include

all: $(LIBFT) $(NAME)

$(LIBFT):
		make -C libft

$O/%.o: $S/%.c
		@mkdir -p $(@D)
		$(CC) $(CFLAGS) $(INCS) -c $< -o $@

$(NAME) : $(LIBFT) $(OBJS)
		$(CC) $(OBJS) $(LIBFT) -o $(NAME) -lreadline -L /home/linuxbrew/.linuxbrew/opt/readline/lib

clean:
		rm -f $(OBJS)
		make clean -C libft

fclean: clean
		rm -f $(NAME)
		rm -f $(LIBFT)

re: fclean all

.PHONY: all, clean, fclean, re