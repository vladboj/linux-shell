#include "input.h"
#include <stdio.h>
#include <string.h>

void readInput(char *input)
{
    fgets(input, MAX_INPUT_LENGTH, stdin);

    // Remove newline character
    size_t length = strlen(input);
    if (input[length - 1] == '\n')
    {
        input[length - 1] = '\0';
    }
}

void parseInput(char *input, char *command, char **args)
{
    char *token = NULL;
    const char delimiters[] = " ";
    token = strtok(input, delimiters);
    strcpy(command, token);
    int i = 0;
    while (token)
    {
        token = strtok(NULL, delimiters);
        args[i++] = token;
    }
}
