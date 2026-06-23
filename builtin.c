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

