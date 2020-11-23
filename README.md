# Simple Shell

### Description:

This is a simple UNIX command interpreter that replicates the simple shell (sh). This simple shell was made in C programming language.
This project was made as part of Cohort 13 of Holberton School Puerto Rico.

### Installation:

Clone the repository into your working directory and consider use GCC compiler with -Wall -Wextra -Werror -pedantic flags for best results.
	
	gcc -Wall -Werror -Wextra -pedantic *.c -o hsh

### Usage

After the compilation, the hsh program can stand-alone in interactive or non-interactive mode.

### Run the shell:

	./hsh

### Interactive Mode:

	$ ./hsh
	($) /bin/ls
	hsh main.c shell.c
	($)
	($) exit
	$

### Non-Iteractive Mode:

	$ echo "/bin/ls" | ./hsh
	hsh main.c shell.c test_ls_2
	$
	$ cat test_ls_2
	/bin/ls
	/bin/ls
	$
	$ cat test_ls_2 | ./hsh
	hsh main.c shell.c test_ls_2
	hsh main.c shell.c test_ls_2
	$

### Authors:

All code written by:
 [Jaime Martinez](https://github.com/jemn21819),
 [Jeff Martinez](https://github.com/Jeff-28).

