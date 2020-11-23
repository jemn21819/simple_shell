#include "holberton.h"

/**
 * main - Display prompt and get a line and initialice process
 * Return: Always 0.
 */

int main(void)
{
	char *prompt = "$ ", *line = NULL, *tk = NULL, *av[256];
	size_t bufsize = 1024;
	pid_t pid;
	int i = 0, j;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(STDOUT_FILENO, prompt, 2);
		signal(SIGINT, handler);
		i = getline(&line, &bufsize, stdin);
		if (i == EOF)
		{
			(isatty(STDIN_FILENO) == 1)
				write(STDOUT_FILENO, "\n", 1);
			return ((free(line), 0);
		}
		if (_strcmp(line, "exit\n") == 0)
			return ((free(line), 0);
		
		pid = fork();
		if (pid == -1)
			return (1);
		if (pid == 0)
		{
			for (j = 0, tk = strtok(line, " \n"); tk; tk = strtok(NULL, " \n"), j++)
				av[j] = tk;
			av[j] = '\0';
			if (av[0][0] != '.')
				path(&av[0]);
			if (execve(av[0], av, NULL) == -1)
				perror("Error:");
			exit(0);
		}
		else
			wait(NULL);
	} while (1);
	return (0);
}
