#include "holberton.h"
/**
 * cmd_null - frees the buffer we create when the double ptr command
 * returned null
 * @buffer: the buffer we created from getline
 */
void cmd_null(char *buffer)
{
	free(buffer);
	exit(EXIT_SUCCESS);
}
/**
 * exit_out - frees the buffer and commands we created from the
 * getline function, then exits child process
 * @buffer: buffer we created from getline
 * @cmd: double pointer array we created to store all commands
 * from the prompt
 */
void exit_out(char *buffer, char **cmd)
{
	int status = 0;

	if (cmd[1] != NULL)
	{
		status = _atoi(cmd[1]);
	}
	free(buffer);
	free_dptr(cmd);
	exit(status);
}

/**
 * env_out - frees the buffer and commands we created from the
 * getline function, prints the env, then exits child process
 * @buffer: buffer we created from getline
 * @cmd: double pointer array we created to store all commands
 * from the prompt
 * @env: environment variables from your login
 *
 * Return: void
 */
void env_out(char *buffer, char **cmd, char **env)
{
	free(buffer);
	free_dptr(cmd);
	print_env(env);
	exit(EXIT_SUCCESS);
}
/**
 * parent_free - frees buffer and commands you created
 * with the getline function from the prompt
 * @buffer: buffer we created from getline
 * @cmd: double pointer array we created to store all commands
 * from the prompt
 *
 * Return: void
 */
void parent_free(char *buffer, char **cmd)
{
	free(buffer);
	free_dptr(cmd);
}

/**
 * c_path - creates a double ptr array of all your directories
 * from your $PATH variable, checks if the first command you
 * entered is a executable in all your directories, then executes.
 * If not found, prints out an error message, then frees buffer and
 * commands you created with the getline function from the prompt
 * @buffer: buffer we created from getline
 * @cmd: double pointer array we created to store all commands
 * from the prompt
 * @env: environment variables from your login
 * @argv: argument vector from int main
 * @count: number of times you've entered commands to the prompt
 *
 * Return: void
 */
void c_path(char **cmd, char *buffer, char **env, char **argv, int count)
{
	struct stat fStat2;
	int i;
	char **dir;

	i = 0;
	dir = env_var(cmd[0], env);
	while (dir[i])
	{
		if (stat(dir[i], &fStat2) == 0)
			execve(dir[i], cmd, NULL);
		++i;
	}

	/* if no command found, print error message */
	error_msg(argv, cmd[0], count);

	free(buffer);
	free_dptr(cmd);
	free_dptr(dir);
	exit(EXIT_SUCCESS);
}
