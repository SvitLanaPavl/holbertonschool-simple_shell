#include "main.h"

/**
 * get_location - get the path of this command file
 * @command: user inputs command
 *
 * Return: file path
 */
char *get_location(char *command)
{
	char *path, *path_copy, *path_token, *file_path;
	int command_length, directory_length;
	struct stat buffer;

	path = _getenv("PATH");
	if (path)
	{
		path_copy = strdup(path);
		command_length = strlen(command);
		path_token = strtok(path_copy, ":");
		while (path_token != NULL)/*command file is in subdirectory*/
		{
			directory_length = strlen(path_token);
		file_path = malloc(command_length + directory_length + 2);
			strcpy(file_path, path_token);
			strcat(file_path, "/");
			strcat(file_path, command);
			strcat(file_path, "\0");
			if (stat(file_path, &buffer) == 0)/*success*/
			{
				free(path_copy);
				return (file_path);
			}
			else
			{
				free(file_path);
				path_token = strtok(NULL, ":");
			}
		} /*end while loop*/
		free(path_copy);
		if (stat(command, &buffer) == 0)
			return (command);
		return (NULL);
	}
	return (NULL);
}

/**
 * execmd - get a command & find the path to this command & execute it
 * @argv: the arguments include command as the first element
 * @actual_com: actual command
 * Return: void
 */
void execmd(char **argv, char *actual_com)
{
	if (argv)
	{
		if (execve(actual_com, argv, NULL) == -1)
		{
			print_err(argv[0], argv);
			free(actual_com);
			free(argv);
			exit(EXIT_FAILURE);
			if (errno == ENOENT)
				printf("Command not found: %s\n", argv[0]);
			else
				perror("Error:");
		}
	}
}

/**
 * print_err - print error message
 * @cmd: input command
 * @argv: input line
 *
 * Return: nothing
 */
void print_err(char *cmd, char **argv)
{
	printf("%s", argv[0]);
	printf(": ");
	printf("%s", cmd);
	printf(": not found\n");
}

/**
 * get_num_token - get number of tokens
 * @lineptr: line of command and path
 *
 * Return: number of tokens
 */
int get_num_token(char *lineptr)
{
	int i = 0, num_tokens;

	if (lineptr == NULL)
		return (0);
	while (lineptr[i] == ' ')
		i++;
	num_tokens = 1;
	for (; lineptr[i] != '\n'; i++)
	{
		if (lineptr[i] == ' ')
		{
			while (lineptr[i + 1] == ' ')
				i++;
			if (lineptr[i + 1] != '\0')
				num_tokens++;
		}
	}
	return (num_tokens);
}
/**
 * _getenv - returns a unique character pointer for each environment variable
 * Description: Searches the table of environment variables for an entry
 * corresponding to name and returns a pointer to a buffer containing the
 * current string value of name.
 * @name: name
 * Return: pointer to a buffer containing the current string value of name,
 * or NULL if name not found
 */
char *_getenv(const char *name)
{
	char *value = NULL;
	char **env = environ;

	while (*env)
	{
		if (strncmp(*env, name, strlen(name)) == 0)
		{
			value = strchr(*env, '=');
			if (value)
			{
				value++;
				return (value);
			}
		}
		env++;
	}
	return (NULL);
}
