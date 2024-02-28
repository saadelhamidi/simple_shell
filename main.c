#include "shell.h"
/**
 * main - main function
 * @ac : arg count
 * @argv : arg vector
 * Return: 0 always.
 */
int main(int ac, char **argv)
{
	char *command = NULL;
	char **tokens = NULL;
	int status = 0;
	(void)ac;
	for (;;)
	{
		command = read_command();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		tokens = split_line(command);
		if (tokens == NULL)
		{
			continue;
		}
		status = _execute(tokens, argv);
	}
	return (0);
}
