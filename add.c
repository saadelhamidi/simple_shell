#include"shell.h"
/** * _execute_command: function that runs the program that (path) references
 * . @tokens: executable array.
 *  * *  @argv: an array of pointers to strings that are sent as command-line arguments to the new program.
 *   Return: 0 is returned upon success, -1 is returned upon error */

int _execute_command(char **tokens, char **argv)
{
	int status = 0, i = 0;
	pid_t child;

	child = fork();

	if (child == 0)
	{
		if (execve(tokens[0], tokens, environ) == -1)
		{
			perror(argv[0]);
			for (i = 0; tokens[i]; i++)
			{
				free(tokens[i]), tokens[i] = NULL;
			}
			free(tokens);
			exit(0);
		}
	}
	else
	{
		waitpid(child, &status, 0);
		for (i = 0; tokens[i]; i++)
		{
			free(tokens[i]), tokens[i] = NULL;
		}
		free(tokens);
	}
	return (WEXITSTATUS(status));
}
