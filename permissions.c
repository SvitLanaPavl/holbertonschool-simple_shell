#include "main.h"
/**
 * permissions - checks for existence and permissions
 * Description: check whether the command exists and the user has permission
 * to run it
 * @command: command
 * Return: 0 if it exists and has permission, -1 otherwise
 */
int permissions(char *command)
{
	if (access(command, F_OK) != 0)
	{
		print_err(command);
		return (-1);
	}
	else
	{
		if (access(command, X_OK) == -1)
		{
			printf("You are not allowed to run this command.");
			return (-1);
		}
		return (0);
	}
}
