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

/* string helper functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
char *_strcat(char *dest, char *src);
char *_sublook(char *src, char *substr);
char *_chr_locate(char *str, char c);


/* env and path */

void print_env(void);
char *_getenv(char *key);
void path(char **av);


/* handler for ctrl+c signal */
void handler(int signal);

#endif
