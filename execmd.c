#include "main.h"

/**
 * execmd - get a command & find the path to this command & execute it
 * @argv: the arguments include command as the first element
 *
 * Return: nothing
 */
void execmd(char **argv)
{
	char *command = NULL, *actual_command = NULL;

	if (argv)
	{
		/*get the command*/
		command = argv[0];
		/*generate the path to this command before pass it to execve*/
		actual_command = get_location(command);
		if (execve(actual_command, argv, NULL) == -1)
		{
			perror("Error:");
		}
	}
}
