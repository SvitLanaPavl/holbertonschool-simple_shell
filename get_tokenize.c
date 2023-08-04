#include "main.h"
/**
 * get_tokenize - gets the input and tokenizes
 * Description: gets the line and tokenizes it
 * @argv: argv
 * Return: argv
 */
char **get_tokenize(char *lineptr)
{
	char *token = NULL, **cmd_arr;
	const char *delim = " \n";
	int i, ntoken = 0;

	ntoken = get_num_token(lineptr);
	cmd_arr = malloc(sizeof(char *) * ntoken); /*alocat argv*/
	if (cmd_arr == NULL)
	{
		free(cmd_arr);
		return (NULL);
	}
	token = strtok(lineptr, delim); /*store token in argv*/
	for (i = 0; token != NULL; i++)
	{
		cmd_arr[i] = malloc(sizeof(char) * strlen(token));
		strcpy(cmd_arr[i], token);
		token = strtok(NULL, delim);
	}
	cmd_arr[i] = NULL;
	free(token);
	return (cmd_arr);
}
