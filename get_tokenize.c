#include "main.h"
/**
 * get_tokenize - gets the input and tokenizes
 * Description: gets the line and tokenizes it
 * @lineptr: command line
 * Return: void
 */
void get_tokenize(char *lineptr)
{
	char *token = NULL, **cmd_arr = NULL, *actual_cmd = NULL;
	const char *delim = " \n";
	int i = 0, ntoken = 0, status;
	pid_t pid;

	if (space_handler(lineptr) == 0) /*all input is spaces*/
		return;
	ntoken = get_num_token(lineptr);
	cmd_arr = malloc(sizeof(char *) * (ntoken + 1)); /*allocate argv*/
	if (cmd_arr == NULL)
	{
		free(cmd_arr);
		return;
	}
	token = strtok(lineptr, delim); /*store token in argv*/
	while (token)
	{
		cmd_arr[i] = malloc(sizeof(char) * strlen(token) + 1);
		if (cmd_arr[i] == NULL)
		{
			free_tokens(cmd_arr);
			return;
		}
		strcpy(cmd_arr[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	cmd_arr[i] = NULL;
	if (cmd_arr && !builtins_handling(cmd_arr))
	{
		actual_cmd = get_location(cmd_arr[0]);
		if (actual_cmd != NULL)
		{
			pid = fork(); /*builds a child process to execute*/
			if (pid == 0)
				execmd(cmd_arr, actual_cmd);
			else
				wait(&status); /*parent process waits for child*/
		}
	}
	free_tokens(cmd_arr);
	return;
}
/**
 * free_tokens - frees the allocated memory for tokens
 * Description: frees memory
 * @cmd_arr: command array
 * Return: void
 */
void free_tokens(char **cmd_arr)
{
	int i;

	if (cmd_arr == NULL)
		return;
	for (i = 0; cmd_arr[i] != NULL; i++)
	{
		free(cmd_arr[i]);
	}
	free(cmd_arr);
}

/**
 * space_handler - takes care of all spaces as input
 * Description: takes care of spaces
 * @lineptr: line pointer
 * Return: 0 all spaces, -1 otherwise
 */
int space_handler(char *lineptr)
{
	int ct = 0, flag = 0;

	/*takes care of all spaces input*/
	while (lineptr[ct] != '\0' && lineptr[ct] != '\n')
	{
		if (lineptr[ct] == ' ' || lineptr[ct] == '\t' || lineptr[ct] == '\r')
		{
			ct++;
		}
		else
		{
			flag = -1;
			ct++;
		}
	}
	return (flag);
}

