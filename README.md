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

## **_Implementation and Compilation_** ##
Clone the repository 
`https://github.com/meisibley/holbertonschool-simple_shell.git`

and compile the following way
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## **_How to use_** ##
To start using the program, type `./hsh`. You will see the prompt `($)` which indicates that it is ready to receive the command. 
The commands can be *built-ins*, like

`cd` - change directory
`echo` - write a string to stdout
`pwd` - print working directory

*aliases* which are shortcuts that reference a command, or *executable files*.

## **_Examples_** ##

**Example 1**

_builtin_
```
($) pwd
($) /holbertonschool-simple_shell  
```
**Example 2**

_alias_
```
($) la
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

_executable_

```
($) ./sum
($) The sum of 2 and 3 is 5
```
## **_List of library functions and system calls_** ##

```
access
chdir
close
closedir
execve
exit
fflush
fork
free
getcwd
getline
getpid
isatty
kill
malloc
open
opendir
perror
printf
putchar
read
readdir
signal
stat
strtok
wait
waitpid
write
```
## **_List of custom functions_** ##
```
_strdup
_strlen
_strcpy
_strcat
```
## **_Files and their descriptions_** ##

| **Files** | **Descriptions** |
| ----- | ----------- |
| main.h | prototypes of functions and structures |        
| main.c | recreates a simple shell | 
| shell.c | gets the path of the command file and executes it |
| custom_funcs.c | recreated library functions |

## **_Authors_** ##

Mei Sibley

Svitlana Pavlovska
