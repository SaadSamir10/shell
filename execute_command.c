#include "shell.h"

/**
 *execute_command - Executes a shell command based on the input string.
 *
 *@input: The input string containing the command to execute.
 */
void execute_command(char *input)
{
	char *tokens[MAX_INPUT_LENGTH];
	int num_tokens = 0;

	parse_tokens(input, tokens, &num_tokens);

	if (num_tokens == 0)
	{
		return;
	}

	if (strcmp(tokens[0], "cd") == 0)
	{
		handle_cd(tokens, num_tokens);
	}
	else if (strcmp(tokens[0], "exit") == 0)
	{
		handle_exit();
	}
	else if (strcmp(tokens[0], "echo") == 0)
	{
		handle_echo(tokens, num_tokens);
	}
	else
	{
		execute_external_command(tokens);
	}
}

/**
 *parse_tokens - Parses an input string into an array of tokens.
 *@input: The input string to parse.
 *@tokens: An array to store the parsed tokens.
 *@num_tokens: A pointer to an integer to store the number of tokens.
 */
void parse_tokens(char *input, char *tokens[], int *num_tokens)
{
	char *token = strtok(input, " ");

	while (token != NULL)
	{
		tokens[(*num_tokens)++] = token;
		token = strtok(NULL, " ");
	}

	tokens[*num_tokens] = NULL;
}

/**
 *execute_external_command - Executes an external shell command.
 *
 *@tokens: An array of tokens containing the command and its arguments.
 */
void execute_external_command(char *tokens[])
{
	pid_t child_pid = fork();

	if (child_pid == -1)
	{
		perror("fork");
		exit(EXIT_FAILURE);
	}

	if (child_pid == 0)
	{
		if (execvp(tokens[0], tokens) == -1)
		{
			fprintf(stderr, "Command not found: %s\n", tokens[0]);
			exit(EXIT_FAILURE);
		}
	}
	else
	{
		wait(NULL);
	}
}
