### Objective

The goal of the Minishell project is to pair-develop a simple, functional shell program, similar to a basic version of bash. This project focuses on enhancing knowledge of process management, file descriptors in C as well as team work. This project was developed with Mauri Zalazar @smzalazar.

### Project Requirements

- **Language**: C
- **Error Handling**: Functions should be robust and handle errors gracefully without causing crashes.
- **Memory Management**: Properly manage heap memory to avoid leaks.
- **Makefile**: Include rules for `$(NAME)`, `all`, `clean`, `fclean`, and `re`. Ensure the Makefile does not perform unnecessary recompilations.

### Core Features

- **Prompt Display**: Show a prompt for user commands.
- **Command History**: Maintain a history of executed commands.
- **Command Execution**: Locate and execute the correct program based on the PATH environment variable or relative/absolute paths.
- **Signal Handling**: Use minimal global variables for signal management to ensure thread safety and reliability.
- **Quote Handling**: Properly handle single and double quotes in commands.
- **Redirections**: Support input (`<`), output (`>`), append (`>>`), and here-document (`<<`) redirections.
- **Pipes**: Implement piping (`|`) between commands.
- **Environment Variables**: Support expansion of environment variables.
- **Exit Status**: Handle the special variable `$?` to show the exit status of the last executed command.
- **Interactive Mode**:
    - `ctrl-C`: Display a new prompt.
    - `ctrl-D`: Exit the shell.
    - `ctrl-\`: Ignore.
- **Built-in Commands**: Implement `echo` with `n`, `cd`, `pwd`, `export`, `unset`, `env`, and `exit`.

### Implementation

- Used structs to represent nodes for pipe symbol, redirection symbol and exec.
- Parsing is done using recursive descent parser.
- Execution is achieved by walking the tree recursively. “executing” the nodes and creating child processes (fork function) as required.
