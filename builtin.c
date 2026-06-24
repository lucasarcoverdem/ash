#include <stdio.h>
#include <stdlib.h>
#include <unistd.h>
#include "builtin.h"

void cmd_exit()
{
    printf("\nExiting...\n");
    exit(0);
}

void cmd_help()
{
    printf("\nBuilt-In commands: \n");
    printf("exit              exit ash.\n");
    printf("help              print this help message.\n");
    printf("goto <dir>        change directory.\n");
    printf("          ash also supports cmds 'gt' and 'cd'.\n");
    printf("-----------------------------------------------\n");
    printf("Or use any other external command. e.g.:\n");
    printf("ls                list directory.\n");
    printf("echo <str>        print text.\n");
    printf("etc....\n");
}

void cmd_goto(char *dir)
{
    if (dir == NULL)
        printf("\nError: expected directory.\n");
    else
    {
        if (chdir(dir) != 0)
            perror("command failed");
    }
}

