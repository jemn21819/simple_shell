#ifndef HOLBERTON_H
#define HOLBERTON_H

#include <stdlib.h>
#include <stdio.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>
#include <sys/stat.h>
#include <string.h>
#include <signal.h>

extern char **environ;

/* string helper functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strchr(char *s, char c);
char *_strstr(char *src, char *sub);
char *str_concat(char *s1, char *s2);

/* env and path */

char *_getenv(char *var);
void path(char **argv);
void _env(void);

/* handler for ctrl+c signal */
void handler(int signal);

#endif
