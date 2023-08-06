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
	char *prompt = "($) ", *actual_com = NULL, *lineptr = NULL;
	int status, restr;
	ssize_t	nchars_read;
	size_t n = 1024;
	pid_t pid;

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
			argv = get_tokenize(lineptr); /*divide input into an array*/
			if (argv && !builtins_handling(argv))
			{
				actual_com = get_location(argv[0]);
				restr = access(actual_com, X_OK);/*checks permission*/
				if (actual_com && restr == -1)
					printf("You are not allowed to run this command\n");
				pid = fork(); /*builds a child process to execute*/
				if (pid == 0)
					execmd(argv, actual_com);
				else
					wait(&status); /*parent process waits for child*/
			}
		}
	}
	free(actual_com), free(lineptr), free(argv);
	return (0);
}
