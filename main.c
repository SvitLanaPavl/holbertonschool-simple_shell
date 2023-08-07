#include "main.h"

/**
 * main - a simple shell imitates a shell
 * @argc: count of arguments (unused)
 * @argv: an array made of one command and all other arguments
 *
 * Return: 0 if success, -1 if not success
 */
int main(int argc __attribute__((unused)), char **argv __attribute__((unused)))
{
	char *prompt = "($) ", *lineptr = NULL;
	ssize_t	nchars_read;
	size_t n = 1024;

	signal(SIGINT, signal_handler);
	while (1)
	{
		if (isatty(STDIN_FILENO)) /*checks for interactive mode*/
			write(STDOUT_FILENO, prompt, strlen(prompt));
		nchars_read = getline(&lineptr, &n, stdin);
		if (nchars_read != 1) /*input is not just going to a new line*/
		{
			if (nchars_read == -1) /*input command is invalid*/
				exit(0);
			get_tokenize(lineptr); /*divide input into an array and execute*/
		}
	}
	free(lineptr);
	return (0);
}
