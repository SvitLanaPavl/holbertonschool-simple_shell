#include "main.h"
/**
 * get_tokenize - gets the input and tokenizes
 * Description: gets the line and tokenizes it
 * @lineptr: command line
 * Return: command array
 */
char **get_tokenize(char *lineptr)
{
	char *token = NULL, **cmd_arr = NULL;
	const char *delim = " \n";
	int i = 0, ntoken = 0, ct = 0, flag = 0;

	/*takes care of all spaces input*/
	while (lineptr[ct] != '\0' && lineptr[ct] != '\n')
	{
		if (lineptr[ct] == ' ' || lineptr[ct] == '\t' || lineptr[ct] == '\r')
			ct++;
		else
			flag = 1, ct++;
	}
	if (flag == 0)
		return (NULL);
	ntoken = get_num_token(lineptr);
	cmd_arr = malloc(sizeof(char *) * ntoken); /*allocate argv*/
	if (cmd_arr == NULL)
	{
		free(cmd_arr);
		return (NULL);
	}
	token = strtok(lineptr, delim); /*store token in argv*/
	while (token)
	{
		cmd_arr[i] = malloc(sizeof(char) * strlen(token));
		if (cmd_arr[i] == NULL)
		{
			for (i--; i >= 0; i--)
				free(cmd_arr[i]);
			free(cmd_arr[i]);
			return (NULL);
		}
		strcpy(cmd_arr[i], token);
		token = strtok(NULL, delim);
		i++;
	}
	cmd_arr[i] = NULL;
	free(token);
	return (cmd_arr);
}
