#include "commands.h"
#include <string.h>
#include <stdio.h>

int executeCommand(const char *command, char **args)
{
    if (strcmp(command, "help") == 0)
    {
        executeHelp();
        return 1;
    }
    if (strcmp(command, "pwd") == 0)
    {
        executePwd();
        return 1;
    }
    if (strcmp(command, "ls") == 0)
    {
        executeLs();
        return 1;
    }
    if (strcmp(command, "cd") == 0)
    {
        executeCd(args);
        return 1;
    }
    if (strcmp(command, "code") == 0)
    {
        executeCode(args);
        return 1;
    }
    if (strcmp(command, "exit") == 0)
    {
        return 0;
    }
    printf("Command not recognized!\n");
    return 1;
}