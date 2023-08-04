#include "main.h"
/**
 * signal_handler - handles signal
 * Description: handles signal
 * @signum: signal number
 * Return: void
 */
void signal_handler(int signum)
{
	char *prompt = "\n($) ";

	if (signum == SIGINT)
		write(STDOUT_FILENO, prompt, strlen(prompt));
}

