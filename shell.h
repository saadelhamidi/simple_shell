#ifndef SHELL_H
#define SHELL_H
#include<stdio.h>
#include<unistd.h>
#include<sys/types.h>
#include<sys/wait.h>
#include<sys/stat.h>
#include<errno.h>
#include <stdlib.h>
#include <string.h>
#include<fcntl.h>
extern char **environ;
int _execute_command(char **tokens, char **argv);
char **token_inp(char *input_line);
char *read_inp(void);


#endif
