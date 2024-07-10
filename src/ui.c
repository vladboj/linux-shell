#include <unistd.h>
#include <linux/limits.h>
#include <stdio.h>

#define ANSI_COLOR_BOLD_ORANGE "\e[38;5;208;1m"
#define ANSI_COLOR_BOLD_CYAN "\e[36;1m"
#define ANSI_COLOR_BOLD_GREEN "\e[32;1m"
#define ANSI_COLOR_RESET "\e[0m"

void displayHelpMessage()
{
    printf(ANSI_COLOR_BOLD_GREEN);
    printf("-------------------------------------------\n");
    printf("Type \"help\" to view the available commands!\n");
    printf("-------------------------------------------\n");
    printf(ANSI_COLOR_RESET);
}

void displayCommandPrompt()
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf(ANSI_COLOR_BOLD_ORANGE "user@userDevice:" ANSI_COLOR_RESET ANSI_COLOR_BOLD_CYAN "%s$ " ANSI_COLOR_RESET, cwd);
}
