#include "ui.h"
#include "input.h"
#include "command_handler.h"

void main()
{
    char input[MAX_INPUT_LENGTH];
    char command[MAX_INPUT_LENGTH / 2];
    char *args[MAX_INPUT_LENGTH / 2];

    displayHelpMessage();
    int shouldRun = 1;
    while (shouldRun)
    {
        displayCommandPrompt();
        readInput(input);
        parseInput(input, command, args);
        shouldRun = executeCommand(command, args);
    }
}