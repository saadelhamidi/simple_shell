#include "shell.h"

/**
 * remove_comments - Remove comments from a line by replacing '#' with '\0'
 * @line: Input line
 */
void remove_comments(char *line) {
    char *comment_pos = strchr(line, '#');
    if (comment_pos != NULL) {
        *comment_pos = '\0';
    }
}

/**
 * main - Entry point for the simple shell program
 * @ac: Argument count
 * @argv: Argument vector
 * Return: Always returns 0
 */
int main(int ac, char **argv) {
    char *command = NULL;
    char **tokens = NULL;
    int status = 0;

    (void) ac;

    for (;;) {
        command = read_inp();

        // Remove comments from the command line
        remove_comments(command);

        if (command == NULL) {
            if (isatty(STDIN_FILENO)) {
                write(STDOUT_FILENO, "\n", 1);
            }
            return status;
        }

        tokens = token_inp(command);

        if (tokens == NULL) {
            continue;
        }

        status = _execute_command(tokens, argv);
    }

    return 0;
}

