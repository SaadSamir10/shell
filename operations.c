#include "shell.h"

/**
 *handle_cd - Handles the "cd" (change directory) command.
 *
 *@tokens: An array of tokens containing the command and its arguments.
 *@num_tokens: The number of tokens in the array.
 */
void handle_cd(char *tokens[], int num_tokens)
{
	if (num_tokens > 1)
	{
		if (chdir(tokens[1]) != 0)
		{
			perror("cd");
		}
	}
	else
	{
		fprintf(stderr, "cd: missing argument\n");
	}
}

/**
 *handle_exit - Handles the "exit" command, which exits the shell program.
 */
void handle_exit(void)
{
	exit(EXIT_SUCCESS);
}

/**
 *handle_echo - Handles the "echo" command.
 *
 *@tokens: An array of tokens containing the command and its arguments.
 *@num_tokens: The number of tokens in the array.
 */
void handle_echo(char *tokens[], int num_tokens)
{
	for (int i = 1; i < num_tokens; i++)
	{
		printf("%s ", tokens[i]);
	}

	printf("\n");
}
