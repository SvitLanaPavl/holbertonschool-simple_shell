#include "main.h"
/**
 * get_tokenize - gets the input and tokenizes
 * Description: gets the line and tokenizes it
 * @argv: argv
 * Return: argv
 */
int get_tokenize(**argv)
{
char *lineptr = NULL, token;
const char *delim = " \n";
int i, ntoken = 0;
size_t n = 1024;
ssize_t nchars_read;

	nchars_read = getline(&lineptr, &n, stdin);
	if (nchars_read == -1)
	{
		printf("\n");
		return (-1);
	}
	ntoken = get_num_token(lineptr);
	argv = malloc(sizeof(char *) * ntoken); /*alocat argv*/
	token = strtok(lineptr, delim); /*store token in argv*/
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
free(lineptr);
return (argv);
}
