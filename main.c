#include "main.h"

/**
 * main - a simple shell imitates a shell
 * @argc: count of arguments (unused)
 * @argv: an array made of one command and all other arguments
 *
 * Return: 0 if success, -1 if not success
 */
int main(int argc __attribute__((unused)), char **argv)
{
	char *prompt = "($) ", *lineptr = NULL, *token;
	size_t n = 1024;
	ssize_t nchars_read;
	const char *delim = " \n";
	int num_token = 0, i, status;
	pid_t pid;
	
	if (!isatty(STDIN_FILENO))
		execmd(argv);

	while (1)
	{
		signal (SIGINT, signal_handler);
		printf("%s", prompt);

		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read != 1)
		{
		if (nchars_read == -1) /*check getline fail or EOF or CTRL_D*/
			return (-1);
		num_token = get_num_token(lineptr); /*get number of token*/
		argv = malloc(sizeof(char *) * num_token); /*allocat argv[]*/
		token = strtok(lineptr, delim); /*store each token in argv[]*/
		for (i = 0; token != NULL; i++)
		{
			argv[i] = malloc(sizeof(char) * strlen(token));
			strcpy(argv[i], token);
			token = strtok(NULL, delim);
		}
		argv[i] = NULL;
		/*if (strcmp(argv[0], "exit") == 0)
		{
			ext = 0;
			free(lineptr), free(argv);
			return (0);
		}*/
		pid = fork();
		if (pid == 0)
			execmd(argv); /*execute command*/
		else
			wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
