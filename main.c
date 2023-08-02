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
	char *actual_com = NULL, *buffer = NULL;
	size_t n = 1024;
	ssize_t nchars_read;
	const char *delim = " \n";
	int ntoken = 0, i, status;
	pid_t pid;

	while (1)
	{
		if(isatty(STDIN_FILENO)) /*execmd(argv);*/
			signal (SIGINT, signal_handler);
		printf("%s", prompt);
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read != 1)
		{
			if (nchars_read == -1) /*getline fail or EOF(ctrl_d)*/
			{
				printf("\n");
				return (-1);
			}
			ntoken = get_num_token(lineptr); /*get num of token*/
			argv = malloc(sizeof(char *) * ntoken); /*alocat argv*/
			token = strtok(lineptr, delim); /*store token in argv*/
			for (i = 0; token != NULL; i++)
			{
				argv[i] = malloc(sizeof(char) * strlen(token));
				strcpy(argv[i], token);
				token = strtok(NULL, delim);
			}
			argv[i] = NULL;
			/* builtin should be here */
			builtins_handling(argv, buffer);
			actual_com = get_location(argv[0]);
			pid = fork();
			if (pid == 0)
				execmd(argv, actual_com); /*execute command*/
			else
				wait(&status);
		}
	}
	free(lineptr);
	return (0);
}
