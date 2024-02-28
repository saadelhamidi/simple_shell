#include"shell.h"
/** 
 *
 * * main: the primary function
 * * @ac: the number of arguments 
 * * @argv: arg vector 
 * * Return: 0 in all cases.*/

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
