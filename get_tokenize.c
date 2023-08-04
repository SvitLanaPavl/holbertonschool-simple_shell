#include "main.h"
/**
 * get_tokenize - gets the input and tokenizes
 * Description: gets the line and tokenizes it
 * @argv: argv
 * Return: argv
 */
char **get_tokenize(char *lineptr)
{
	char *token = NULL, **argv;
	const char *delim = " \n";
	int i, ntoken = 0;

	ntoken = get_num_token(lineptr);
	argv = malloc(sizeof(char *) * ntoken); /*alocat argv*/
	if (argv == NULL)
	{
		free(argv);
		return (NULL);
	}
	token = strtok(lineptr, delim); /*store token in argv*/
	for (i = 0; token != NULL; i++)
	{
		argv[i] = malloc(sizeof(char) * strlen(token));
		strcpy(argv[i], token);
		token = strtok(NULL, delim);
	}
	argv[i] = NULL;
	free(token);
	return (argv);
}
