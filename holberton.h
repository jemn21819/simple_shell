#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <unistd.h>
#include <stdio.h>
#include <sys/types.h>
#include <sys/stat.h>
#include <fcntl.h>
#include <sys/wait.h>
#include <stdlib.h>
#include <string.h>
#include <errno.h>
#include <signal.h>

/* print string version */
int _printstr(char *str);

/* string helper functions */
int _strlen(const char *s);
void _strcpy(char *dest, const char *src, size_t n);
char *_strdup(char *str);
int _strcmp(char *s1, char *s2);
int _str_n_cmp(char *s1, const char *s2, int n);

/* tokenizer functions */
char get_delim(const char c, const char *delim);
size_t tok_counter(const char *line, const char *delim);
void tok_string(char **arstr, char *line, const char *delim);
char **tokenizer(char *line, const char *delim);

/* exe */

int exe_cmd(char **av, char **env);
int run_cmd(const char *path, char **av, char **env);

/* path */
char *find_cmd(char *cmd, char **env);
char *append_path(const char *dir, const char *file);
char *_getenv(char **env, char *key);

/* handler for ctrl+c signal */
void handler(int signal);

#endif
