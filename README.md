# Simple Shell #

<img src='https://guideposts.org/wp-content/uploads/2017/04/blog_shell_1540-1024x576.jpg.webp' width="800" height="350" alt='simple-shell'/>

## **_Introduction_** ##
This program is the recreation of the UNIX shell - a command line interpreter - that allows a user to interact with a computer by running commands or programs. The shell parses the commands and sends them to the operating system to perform.

## **_Description_** ##
### The shell should do the following: ###

* Display a prompt and wait for the user to type a command. A command line always ends with a new line.
* The prompt is displayed again each time a command has been executed.
* The command lines are simple, no semicolons, no pipes, no redirections or any other advanced features.
* The command lines should handle arguments
* If an executable cannot be found, print an error message and display the prompt again.
* Handle errors.
* Handle the “end of file” condition (Ctrl+D)
* Handle the PATH
* Implement the exit built-in, that exits the shell
* Implement the env built-in, that prints the current environment
* Handles interactive and non-interactive mode

## **_Implementation and Compilation_** ##
To start using this program, first, clone the repository 
`https://github.com/meisibley/holbertonschool-simple_shell.git`

and compile in the following way
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## **_How to use_** ##
In your terminal, type `./hsh` to run the program. You will see the prompt `($)` which indicates that it is ready to receive the command. 
Currently, this simple shell handles the  *built-in* commands, for instance,

`cd` - change directory, followed by the path or with the options (e.g. `-` for previous working directory or `..` for moving one directory up)<br />
`exit` - exits the shell<br />
`env` - prints the current environment variables

They are run right away. However, if the commands are not built-ins, they are searched for in the `PATH` directory and then are executed. If the command is not found or the user does not have the permission to run it, there will be an error message.

## **_Examples_** ##

**Example 1**

_builtin_
```
($) pwd
/holbertonschool-simple_shell
($) cd
/root
($) cd -
/holbertonschool-simple_shell
($) exit  
```
**Example 2**

_via PATH_
```
($) /bin/ls
README.md compil hsh main.c main.h shell.c test_ls_2
($) ls -la
($) total 48
drwxr-xr-x 3 root root   120 Jul 27 23:57 .
drwxr-xr-x 1 root root  4096 Jul 27 23:42 ..
drwxr-xr-x 8 root root   220 Jul 28 00:05 .git
-rw-r--r-- 1 root root  1257 Jul 27 23:57 README.md
-rwxr-xr-x 1 root root    77 Jul 27 23:42 compil
-rwxr-xr-x 1 root root 17560 Jul 27 23:42 hsh
-rw-r--r-- 1 root root  1877 Jul 27 23:42 main.c
-rw-r--r-- 1 root root   163 Jul 27 23:42 main.h
-rw-r--r-- 1 root root  1506 Jul 27 23:42 shell.c
-rw-r--r-- 1 root root    16 Jul 27 23:42 test_ls_2
```
**Example 3**

_non-interactive mode_

```
($) echo "/bin/ls" | ./hsh
hsh main.c shell.c test_ls_25
```
## **_List of library functions and system calls used_** ##

```
access()
chdir()
execve()
exit()
fork()
free()
getcwd()
getline()
getpid()
isatty()
malloc()
perror()
printf()
signal()
stat()
strtok()
wait()
write()
```
## **_List of custom functions_** ##
```
void execmd(char **argv, char *actual_com);
char *get_location(char *command);
int get_num_token(char *lineptr);
char **get_tokenize(ssize_t nchars_read, char *lineptr);
char *_getenv(const char *name);
void signal_handler(int signum);
void print_err(char *command, char **argv);
int builtins_handling(char **command);
void env_handler(void);
void cd_handler(char **command);
void exit_handler(char **command);
```
## **_Files and their descriptions_** ##

| **Files** | **Descriptions** |
| ----- | ----------- |
| main.h | prototypes of functions and structures, global variables |        
| main.c | recreates a simple shell | 
| shell.c | gets a command, finds a path to this command and executes it; prints error an message; searches the table of environment variables for an entry corresponding to the name|
| signal_handler.c | handles the CTRL C signal to ignore it in this simple shell |
| get_tokenize.c | gets the input and tokenizes it returning the character array |
| builtins_handling.c | handles builtins - cd, env, exit |

## **_Authors_** ##

Mei Sibley <br />
Svitlana Pavlovska
