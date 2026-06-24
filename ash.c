#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>
#include <sys/wait.h>

#include "builtin.h"

#define MAX_INPUT_LEN 1024
#define MAX_ARGS_QTD 64

char login[256]; // "username"
char cwd[1024]; // Current Working Directory

// get user login
void get_login()
{
    login[255] = '\0';
    getlogin_r(login, sizeof(login));
}

void get_cwd()
{
    // try to get cwd. if it fails, exit function.
    if (getcwd(cwd, sizeof(cwd)) == NULL)
    {
        printf("Could not get current working directory!\n");
        return;
    }
}

void print_login_and_cwd()
{
    get_login();
    get_cwd();

    printf("\n%s at %s:", login, cwd);
}

void get_input(char *input)
{
    printf("\n> ");
    if (fgets(input, MAX_INPUT_LEN, stdin) == NULL)
    {
        printf("\nExiting...\n");
        exit(0);
    }

    input[strcspn(input, "\n")] = 0;
}

void parse_input(char *input, char **args)
{
    int i = 0;
    args[i] = strtok(input, " ");

    while (args[i] != NULL && i < MAX_ARGS_QTD - 1)
    {
        i++;
        args[i] = strtok(NULL, " ");
    }
}

int exbicmd(char **args) // execute built-in commands
{
    if (args[0] == NULL) return 1;

    if (strcmp(args[0], "exit") == 0)
    {
        cmd_exit();
    }

    if (strcmp(args[0], "help") == 0)
    {
        cmd_help();
        return 1;
    }

    if (strcmp(args[0], "goto") == 0 || strcmp(args[0], "gt") == 0 || strcmp(args[0], "cd") == 0)
    {
        char *dir;
        dir = args[1];
        cmd_goto(dir);
        return 1;
    }

    return 0;
}

void execmd(char **args) // execute externel commands
{
    pid_t pid = fork(); // creates a child process
    
    if(pid == 0)
    {
        if (execvp(args[0], args) < 0) // execute cmd
        {
            perror("\nError: command failed!");
        }
        exit(1);
    }
    else {
        wait(NULL); //parent waits child finish
    }
}

void print_banner()
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("|                    -------                     |\n");
    printf("|                    | ASH |                     |\n");
    printf("|                    -------                     |\n");
    printf("|                    a shell                     |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    printf("\n                 Welcome to ASH!\n");
}

int main(void)
{
    char input[MAX_INPUT_LEN];
    char *args[MAX_ARGS_QTD];

    print_banner();

    while (1)
    {
        print_login_and_cwd();
        get_input(input);
        parse_input(input, args);

        if (exbicmd(args)) continue;
        execmd(args);
    }
    
    return 0;
}

