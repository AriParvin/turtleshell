#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <unistd.h>
#include <stdlib.h>
#include <string.h>
#include <sys/wait.h>

#define TOK_DELIM " \t\r\n\a\""
extern	char **environ;

/* main.c */
void	shell_interactive();
void	shell_no_interactive();

/* shell_interactive */
char	*read_line(void);
char	**split_line(char *line);
int	execute_args(char **args);

/* execute_args */
int	new_process(char **args);

/* shell_no_interactive */
char	*read_stream(void);

/* builtin functions */
int	ft_cd(char **args);
int	ft_exit(char **args);
int	ft_env(char **args);
int	ft_help(char **args);

#endif
