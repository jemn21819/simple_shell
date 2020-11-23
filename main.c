#include "holberton.h"

/**
 * main - Display prompt and get a line and initialice process
 * Return: Always 0.
 */

int main(void)
{
	char *prompt = "$ ", *buffer = NULL, *tk = NULL, *av[256];
	size_t bufsize = 1024;
	pid_t child;
	int i = 0, j;

	do {
		if (isatty(STDIN_FILENO) == 1)
			write(1, prompt, 2);
		signal(SIGINT, handler);
		i = getline(&buffer, &bufsize, stdin);
		if (i == -EOF)
		{
			(isatty(STDIN_FILENO) == 1) ? write(1, "\n", 1) : 1;
			free(buffer);
			return (0);
		}
		if (_strcmp(buffer, "exit\n") == 0)
		{
			free(buffer);
			return (0);
		}

		child = fork();
		if (child == -1)
			return (1);
		if (child == 0)
		{
			for (j = 0, tk = strtok(buffer, " \n"); tk; tk = strtok(NULL, " \n"), j++)
				av[j] = tk;
			av[j] = NULL;
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
