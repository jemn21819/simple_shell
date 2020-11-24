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

/* helping functions */
int _strlen(char *s);
int _strcmp(char *s1, char *s2);
int _strncmp(const char *s1, const char *s2, size_t n);
char *_strcat(char *s1, char *s2);
int _intlen(int n);
int _atoi(char *str);
char *_strdup(char *s1);
char *itoa(int n);
void _printf(char *str);
int _putchar(char c);

void mem_set(void *mem, int byte, size_t n);
char *get_env_var_val(char *env_var);
char *get_full_comd_path(char **tokens, char *env_var_val);
void free_str_array(char **array);
char **parse_path(char *line, char);
int count_chars(char *s1, char seperator);
int count_words(char *s, char seperator);

int count_chars(char *line, char space);
int count_tokens(char *line);
int exec_bltins_prgrms(char **tokens, char **env, int status, char *line);
int exit_shell(char **tokens, char *line);
int _env(char **env);
int exec_prgrms(char **tokens, char *line);
char **_strtok(char *line);
void prompt(void);
char *_getline(void);


/* handler for ctrl+c signal */
void handler(int signal);

#endif
