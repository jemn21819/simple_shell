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

int launcher(char **arg);

int _strlen(char *s);

char *_strncpy(char *dest, char *src, int n);

char *_strdup(char *str);

void free_pointers(char **pointers);

char **line_split(char *line);

int _strcmp(char *s1, char *s2);

#endif
