#include "main.h"
/**
 * builtins_handling - handles builtins
 * Description: checks for builtins
 * @command: command
 * Return: 0 in success
 */
int builtins_handling(char **command)
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
					return (1);
				case 2:
					cd_handler(command);
					return (1);

			}
		}
		i++;
	}
	return (0);
}
/**
 * env_handler - handles environment
 * Description: handles environment
 * Return: void
 */
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
/**
 * cd_handler - handles directories
 * Description: handles directories
 * @command: command
 * Return: void
 */
void cd_handler(char **command)
{
	int value = -1;
	char dir[PATH_MAX];

	if (command[1] == NULL)
	{
		value = chdir(_getenv("HOME"));
	}
	else if (strcmp(command[1], "-") == 0)
	{
		if (_getenv("OLDPWD") == NULL)
			return;
		value = chdir(_getenv("OLDPWD"));
	}
	else
		value = chdir(command[1]);
	if (value == -1)
		perror("address");
	else if (value != -1)
	{
		getcwd(dir, sizeof(dir));
		setenv("OLDPWD", _getenv("PWD"), 1);
		setenv("PWD", dir, 1);
		printf("%s\n", dir);
	}
}
/**
 * exit_handler - handles exit
 * Description: handles exit
 * @command: command
 * Return: void
 */
void exit_handler(char **command)
{
	char *message = "Too many arguments\n";

	if (command[1])
	{
		write(STDOUT_FILENO, message, strlen(message));
	}
	/*free_token(command);*/
	exit(EXIT_SUCCESS);
}
