#include "main.h"

/**
 * main - a simple shell imitates a shell
 * @ac: count of arguments
 * @argv: an array made of one command and all other arguments
 *
 * Return: 0 if success, -1 if not success
 */
int main (int argc __attribute__((unused)), char **argv)
{
	char *prompt = "($) ";
	char *lineptr = NULL, *lineptr_copy = NULL;
	size_t n = 0;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_token = 0;
	char *token;
	int i, ext = 1;
	int status;
	pid_t pid;

	/*create a loop for the shell's prompt*/
	while (ext == 1)
	{
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		/*check if the getline func failed or reached EOF or user use \
		 * CTRL + D*/
		if (nchars_read == -1)
		{
			printf("Exiting shell....\n");
			return (-1);
		}
		/*allocate space for a copy of the lineptr*/
		lineptr_copy = malloc(sizeof(char) * nchars_read);
		if (lineptr_copy == NULL)
		{
			perror("tsh: memory allocation error");
			return (-1);
		}
		/*copy lineptr to lineptr_copy*/
		strcpy(lineptr_copy, lineptr);
		/***split the string(lineptr) into an array of word***/
		/*calculate the total number of token*/
		token = strtok(lineptr, delim);
		while (token != NULL)
		{
			num_token++;
			token = strtok(NULL, delim);
		}
		num_token++;
		/*allocate space to hold the array of strings*/
		argv = malloc(sizeof(char *) * num_token);
		/*store each token in the argv array*/
		token = strtok(lineptr_copy, delim);
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		if (strcmp(argv[0], "exit") == 0)
		{
			ext = 0;
			free(lineptr_copy), free(lineptr), free(argv);
			return (0);
		}
		/*execute the command*/
		pid = fork();
		if (pid == 0)
			execmd(argv);
		else
			wait(&status);
	}
	/*free up allocated memory*/
	free(lineptr_copy);
	free(lineptr);
	return (0);
}
