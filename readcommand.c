#include"shell.h"
/**
 * read_command - read a command from the stdin.
 * line_check - function that check for spaces.
 * command: void.
 * Return: 0 foound a character, 1 Null line.
 */
char *read_command(void)
{
	char *command = NULL;
	size_t len = 0;
	ssize_t n;

	if (isatty(STDIN_FILENO))
	{
		putchar('$');
		putchar(' ');
	}
	n = getline(&command, &len, stdin);
	if (n == -1)
	{
		free(command);
		return (NULL);
	}
	return (command);
}
