#ifndef MAIN_H
#define MAIN_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/stat.h>
#include <sys/types.h>
#include <signal.h>
#include <sys/wait.h>
#include <errno.h>
#include <linux/limits.h>

extern char **environ;
void execmd(char **argv, char *actual_com);
char *get_location(char *command);
int get_num_token(char *lineptr);
char *_getenv(const char *name);
void signal_handler(int signum);
void print_err(char *command, char **argv);
/*builtins*/
int builtins_handling(char **command);
void env_handler(void);
void cd_handler(char **command);
void exit_handler(char **command);
#endif
