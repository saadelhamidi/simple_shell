#include "main.h"

/**
 * main - Entry point
 *
 * Return: Always 0 (Success)
 */
extern char **environ;
int main(void)
{
	char *prompt = NULL;
	char *token;
	size_t cmd_size = 0;
	pid_t pid;
	int i;
	char *args[30];

	while (1)
	{
		printf("#cisfun$ ");
		if (getline(&prompt, &cmd_size, stdin) == -1)
		{
			if (feof(stdin))
			{
				break;
			}
			else
			{
				perror("Error reading prompt");
				return (1);
			}
		}
		prompt[strcspn(prompt, "\n")] = '\0';
		if (strcmp(prompt, "exit") == 0)
		{
			break;
		}
		token = strtok(prompt, " ");
		i = 0;
		while (token != NULL)
		{
			args[i++] = token;
			token = strtok(NULL, " ");
		}

		args[i] = NULL;
		pid = fork();
		if (pid == -1)
		{
			perror("Fork failed");
			return (1);
		}

		if (pid == 0)
		{
			if (execve(args[0], args, environ) == -1)
			{
				perror("Error");
				return (1);
			}
		}
		else
		{
			int status;

			if (waitpid(pid, &status, 0) == -1)
			{
				perror("Wait failed");
				return (1);
			}
		}
	}

	free(prompt);
	return (0);
}
