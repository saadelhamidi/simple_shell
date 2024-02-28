#include "shell.h"
/** * main: the primary function *
 * @ac: the number of arguments @argv: arg vector
 * * Return: 0 in all cases.*
 */
int main(int ac, char **argv)
{
	char *command = NULL;
	char **tokens = NULL;
	int status = 0;
	(void)ac;
	for (;;)
	{
		command = read_inp();
		if (command == NULL)
		{
			if (isatty(STDIN_FILENO))
			{
				write(STDOUT_FILENO, "\n", 1);
			}
			return (status);
		}
		tokens = token_inp(command);
		if (tokens == NULL)
		{
			continue;
		}
		status = _execute_command(tokens, argv);
	}
	return (0);
}
