#ifndef _HOLBERTON_H_
#define _HOLBERTON_H_
#include <stdlib.h>
#include <unistd.h>
#include <string.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <signal.h>

/* prompt.c */
void handler(int sig);

/* strtok_example.c */
unsigned int cmd_len(char *s);
char **arr_strtok(char *str);

/* helperfunctions.c */
char *_strncpy(char *dest, char *src, int n);
char *_strncpyconst(char *dest, const char *src, int n);
unsigned int _strlen_const(const char *name);
int _strcmp(char *s1, char *s2);
unsigned int _strlen(char *s);

/* environment.c */
unsigned int find_dir(char *path);
char **env_var(char *cmd, char **environ);
char *_getenv(const char *key, char **environ);
char *_strncpycmd(char *dest, char *src, char *cmd, int n, int c);
void print_env(char **environ);

/*free_it_all.c */
void free_dptr(char **d_ptr);

/*error_message.c*/
void error_msg(char **av, char *cmd, int count);
int _puterror(char c);
void end_of_file(char *buffer);
void fork_fail(void);

/*child_processes.c */
void cmd_null(char *buffer);
void exit_out(char *buffer, char **cmd);
void env_out(char *buffer, char **cmd, char **env);
void parent_free(char *buffer, char **cmd);
void c_path(char **cmd, char *buffer, char **env, char **argv, int count);
#endif
