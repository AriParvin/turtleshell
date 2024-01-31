#include "shell.h"

int	execute_args(char **args)
{
	char	*builtin_func_list[] = {"cd", "env", "help", "exit"};
	int	(*builtin_func[])(char **) = {&ft_cd, &ft_env, &ft_help, &ft_exit};
	int	i = 0;

	if (args[0] == NULL)
		return (-1);
	while (i < sizeof(builtin_func_list) / sizeof(char *))
	{
		if (ft_strcmp(args[0], builtin_func_list[i]) == 0)
			return ((*builtin_func[i])(args));
	}
	return (new_process(args));
}
