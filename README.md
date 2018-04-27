## Simple_Shell Project 
![seashell](http://www.lostsaloon.com//wp-content/uploads/linux-ls-command.png)

## Table of Contents
* [Synopsis](#synopsis)
* [Environment](#environment)
* [Repository Contents](#repository-contents)
* [Features](#features)
* [Builtins](#builtins)
* [How to Install](#how-to-install)
* [How to Run](#To-run)
* [Example Code](#example-code)
* [To do List](#to-do-list)
* [Authors](#authors)

## Synopsis
The objective of the simple_shell project is to learn and implement the base functionality of a UNIX command line interface. Working on this project helped my partner and I learn how to manipulate the environment of processes and how to create them, as well as understanding how a shell uses the `PATH` environment variable to find programs and execute them with the `execve` system call.

## Environment
Tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

## Repository Contents

| File | Description	|
| ----- | ----- |
| [builtins.c](builtins.c)	| builtins for the shell |
| [check4builtin.c](check4builtin.c) | checks if the string being passed is a builtin command |
| [check_input.c](check_input.c) | checks for input from stdin |
| [create_array.c](create_array.c) | creates an array of the commands from stdin |
| [create_child.c](create_child.c) | creates a child process and executes a command |
| [exec_path.c](exec_path.c) | concatenates two strings with '/', used if command isn't given with a full path |
| [find_command.c](find_command.c) | looks for command in PATH |
| [find_path.c](find_path.c) | finds the PATH variable in environment |
| [free_array.c](free_array.c) | frees an array of pointers |
| [free_things.c](free_things.c) | frees the argument pointers |
| [get_command.c](get_command.c) | gets the first argument from string which is the command itself |
| [main.c](main.c) | Entry point for the shell |
| [not_in_path.c](not_in_path.c) | checks if an argument is an executable file path |
| [shell.h](shell.h) | header file |
| [token_count.c](token_count.c) | counts the number of tokens in a string |

## Features
* Handles the `PATH`
* Handles command lines with arguments

## Builtins
* exit
* env

## How to install
To install our shell, clone the repository to a directory, then run the executable.
`https://github.com/kevanlucc/simple_shell.git`

## To run
Compile the code with the following flags: 
`gcc -Wall -Werror -Wextra -pedantic *.c -o hsh`

Run the executable:
`./hsh`

###### Example code
```
$ ./hsh
sHell$ ls -l
total 100
-rw-rw-r-- 1 vagrant vagrant  1087 Nov 19 19:20 LICENSE.md
-rw-rw-r-- 1 vagrant vagrant   662 Nov 19 19:20 README.md
-rw-rw-r-- 1 vagrant vagrant   492 Nov 19 19:20 _strcmp.c
-rw-rw-r-- 1 vagrant vagrant   294 Nov 19 19:20 _strcpy.c
-rw-rw-r-- 1 vagrant vagrant   389 Nov 19 19:20 _strdup.c
-rw-rw-r-- 1 vagrant vagrant   199 Nov 19 19:20 _strlen.c
-rw-rw-r-- 1 vagrant vagrant   331 Nov 19 20:08 builtins.c
-rw-rw-r-- 1 vagrant vagrant   316 Nov 19 20:06 check4builtin.c
-rw-rw-r-- 1 vagrant vagrant  1071 Nov 19 19:59 check_input.c
-rw-rw-r-- 1 vagrant vagrant   844 Nov 19 19:20 create_array.c
-rw-rw-r-- 1 vagrant vagrant   480 Nov 19 19:20 create_child.c
-rw-rw-r-- 1 vagrant vagrant   713 Nov 19 19:20 exec_path.c
-rw-rw-r-- 1 vagrant vagrant  2148 Nov 19 19:20 find_command.c
-rw-rw-r-- 1 vagrant vagrant   375 Nov 19 19:20 find_path.c
-rw-rw-r-- 1 vagrant vagrant   317 Nov 19 19:20 free_array.c
-rw-rw-r-- 1 vagrant vagrant   310 Nov 19 19:20 free_things.c
-rw-rw-r-- 1 vagrant vagrant   636 Nov 19 19:20 get_command.c
-rwxrwxr-x 1 vagrant vagrant 14650 Nov 19 23:19 hsh
-rw-rw-r-- 1 vagrant vagrant  1169 Nov 19 19:20 main.c
-rw-rw-r-- 1 vagrant vagrant   894 Nov 19 19:20 not_in_path.c
-rw-rw-r-- 1 vagrant vagrant  1052 Nov 19 19:47 shell.h
-rw-rw-r-- 1 vagrant vagrant   545 Nov 19 19:20 token_count.c
sHell$
```

## Authors

* Binita Rai [**Github**](https://github.com/rayraib) | [**Twitter**](https://twitter.com/rayrai_b)
* Kevan Lucchini [**Github**](https://github.com/kevanlucc) | [**Twitter**](https://twitter.com/kevan_lucchini)

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>
