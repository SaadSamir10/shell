#include "shell.h"

/**
 *start_shell - start my own shell
 *
 *return: void
 */
void start_shell(void)
{
	char input[MAX_INPUT_LENGTH];

	while (1)
	{
		printf(">> ");
		if (fgets(input, MAX_INPUT_LENGTH, stdin) == NULL)
		{
			printf("\n");
			break;
		}

		input[strcspn(input, "\n")] = '\0';

		execute_command(input);
	}
}

