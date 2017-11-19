## Simple_Shell Project
## Table of Contents
* [Synopsis](#Synopsis)
* [Environment](#Environment)
* [Repository Contents](#Repository Contents)
* [Description of Functions](#Description of Functions)
* [Features](#Features)
* [How to Install](#How to install)
* [Compilation](#Compilation)
* [Example Code](#Example Code)
* [To do List](#To do List]
* [Authors](#Authors)
### Synopsis
The objective of the simple_shell project is to learn and implement the base functionality of a UNIX command line interface. Working on this project helped my partner and I learn how to manipulate the environment of processes and how to create them, as well as understanding how a shell uses the `PATH` environment variable to find programs and execute them with the `execve` system call.

### Environment
Tested on `Ubuntu 14.04 LTS` via Vagrant in VirtualBox.

## Repository Contents

| File | Description	|
| ----- | ----- |
| builtins.c	| builtins for the shell |
| check4builtin.c | checks if the string being passed is a builtin command |
| check_input.c | checks for input from stdin |
| create_array.c | creates an array of the commands from stdin |
| create_child.c | creates a child process and executes a command |
| exec_path.c | concatenates two strings with '/', used if command isn't given with a full path |
| find_command.c | looks for command in PATH |
| find_path.c | finds the PATH variable in environment |
| free_array.c | frees an array of pointers |
| free_things.c | frees the argument pointers |
| get_command.c | gets the first argument from string of argume

### Description of Functions

|	|	|
| ----- | ----- |

### How to install

### Compilation

###### Example code

### To do List

### Authors

* Binita Rai [**Github**](https://github.com/rayraib)[**Twitter**](https://twitter.com/rayrai_b)
* Kevan Lucchini [**Github**](https://github.com/kevanlucc)[**Twitter**](https://twitter.com/kevan_lucchini)

<p align="center">
<a href="https://www.holbertonschool.com"><img src="https://intranet.hbtn.io/assets/holberton-logo-simplified-d4e8a1e8bf5ad93c8c3ce32895b4b53749b477b7ba7342d7f064e6883bcd3be2.png"></a>
</p>
