# Simple Shell
## **_Introduction_** ##

This is the program that allows a user to interact with a computer by running commands or programs.

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

and compile this way
`gcc -Wall -Werror -Wextra -pedantic -std=gnu89 *.c -o hsh`

## **_How to use_** ##
To start using the program run the following command `./hsh`

## **_Examples_** ##
## **_List of library functions and system calls_** ##
## **_List of custom functions_** ##
## **_Authors_** ##
