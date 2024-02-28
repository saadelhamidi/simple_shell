#include"shell.h"
/**
 * read_inp - read a command from the stdin.
 * line_check - function this check for spaces.
 * command: void.
 * Return: 0 found a character, 1 Null line.
 */
char *read_inp(void)
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
