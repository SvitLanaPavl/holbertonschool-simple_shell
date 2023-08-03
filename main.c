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
	char *prompt = "($) ", *token, *actual_com = NULL;
	int status, restr;
	pid_t pid;

	while (1)
	{
		if (isatty(STDIN_FILENO)) /*execmd(argv);*/
			signal(SIGINT, signal_handler);
		printf("%s", prompt);
		argv = get_tokenize(argv);
			if (!builtins_handling(argv))
			{
				actual_com = get_location(argv[0]);
				pid = fork();
				if (pid == 0)
				{
					restr = access(actual_com, X_OK);
					if (restr == -1)
					{
						printf("You are not allowed to run this command\n");
						exit(1);
					}
					else
					execmd(argv, actual_com); /*execute command*/
				}
				else
					wait(&status);
			}
		}
	};
	return (0);
}
