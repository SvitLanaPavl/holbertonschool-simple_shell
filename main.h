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
extern char **environ;
void execmd(char **argv);
char *get_location(char *command);
int get_num_token(char *lineptr);
char *_getenv(const char *name);
#endif
