#include "shell.h"

char	**split_line(char *line)
{
	int	bufsize = 64;
	int	i = 0;
	char	**tokens = malloc(bufsize * sizeof(char *));
	char	*token;

	if (!tokens)
	{
		fprintf(stderr, "allocation error in split_line.c: tokens\n");
		exit(EXIT_FAILURE);
	}
	token = ft_strtok(line, TOK_DELIM);
	while (token != NULL)
	{
		if (token[0] == '#')
			break;
		tokens[i] = token;
		i++;
		if (i >= bufsize)
		{
			bufsize += bufsize;
			tokens = realloc(tokens, bufsize * sizeof(char *));
			if (!tokens)
			{
				fprintf(stderr, "reallocation error in split_line: tokens");
				exit(EXIT_FAILURE);
			}
		}
		token = ft_strtok(NULL, TOK_DELIM);
	}
	tokens[i] = NULL;
	return (tokens);
}
