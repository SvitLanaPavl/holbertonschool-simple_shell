#include "main.h"

int builtins_handling(char **command, char *buffer)
{
	int i = 0;
	char *builtins[] = {"exit", "env", "cd", NULL};

	while (builtins[i])
	{
		if (strcmp(command[0], builtins[i]) == 0)
		{
			switch (i)
			{
				case 0:
					exit_handler(command);
					break;
				case 1:
					env_handler();
					break;
				case 2:
					cd_handler(command, buffer);

			}
		}
		i++;
	}
	return (0);
}

void env_handler(void)
{
	size_t i;
	int length;

	for (i = 0; environ[i]; i++)
	{
		length = strlen(environ[i]);
		write(STDOUT_FILENO, environ[i], length);
		write(STDOUT_FILENO, "\n", 1);
	}
}

void cd_handler(char **command, char *buffer)
{
	char *dir = getcwd(buffer, strlen(buffer));

	if (command[1] == NULL)
		dir = _getenv("HOME");
	else if (strcmp(command[1], "-") == 0)
		dir = _getenv("OLDPWD");
	else
	{
		dir = command[1];
		if (chdir(dir) == -1)
			perror("getcwd");
	}
}

void exit_handler(char **command)
{
	char *message = "Too many arguments";

	if (command[1])
	{
		write(STDOUT_FILENO, message, strlen(message));
	}
	/*free_token(command);*/
	exit (EXIT_SUCCESS);
}
