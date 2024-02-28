#include"shell.h"
/**
 * _getenv - function that searches  the environment list to
  * find the environment variable info, and returns a pointer to
  * the corresponding value string.
 * @info: the environment variable info.
 * Return: a pointer to the corresponding value string.
 */
char *_getenv(char *info)
{
	char *current, *current_key, *current_value, *result;
	int i = 0;

	while (environ[i])
	{
		current = strdup(environ[i]);
		current_key = strtok(current, "=");
		if (strcmp(current_key, info) == 0)
		{
			current_value = strtok(NULL, "\n");
			result = strdup(current_value);
			free(current);
			return (result);
		}
		free(current);
		i++;
	}
	return (NULL);
}


