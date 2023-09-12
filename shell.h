#ifndef SHELL_H
#define SHELL_H

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <sys/types.h>
#include <sys/wait.h>

#define MAX_INPUT_LENGTH 1024

void start_shell(void);
void execute_command(char *input);
void parse_tokens(char *input, char *tokens[], int *num_tokens);
void handle_cd(char *tokens[], int num_tokens);
void handle_exit(void);
void handle_echo(char *tokens[], int num_tokens);
void execute_external_command(char *tokens[]);

#endif /* SHELL_H */
