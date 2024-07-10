#include <stdio.h>
#include <linux/limits.h>
#include <unistd.h>
#include <dirent.h>
#include <wait.h>

void executeHelp()
{
    printf("pwd ---------> display current working directory\n");
    printf("ls ----------> list contents of current working directory\n");
    printf("cd <path> ---> change working directory to the specified path\n");
    printf("code <path> -> open VS Code in the specified path\n");
    printf("exit --------> exit the shell\n");
}

void executePwd()
{
    char cwd[PATH_MAX];
    getcwd(cwd, sizeof(cwd));
    printf("%s\n", cwd);
}

void executeLs()
{
    DIR *dr = opendir(".");
    struct dirent *de;
    while ((de = readdir(dr)) != NULL)
    {
        printf("%s\n", de->d_name);
    }
    closedir(dr);
}

void executeCd(char **args)
{
    chdir(args[0]);
}

void executeCode(char **args)
{
    int pid = fork();
    if (pid == 0)
    {
        execlp("code", "code", args[0], NULL);
    }
}