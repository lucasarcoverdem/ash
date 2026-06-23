#include <stdio.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

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

/*************
BUILT-IN CMDS|
*************/
void cmd_exit()
{
    printf("\nExiting...\n");
    exit(0);
}

void cmd_help()
{
    printf("\nBuilt-In commands: \n");
    printf("exit             exit ash.\n");
    printf("help             display this help message.\n");
}

int exbicmd(char **args) // EXecute Built In CoMmanDs
{
    if (args[0] == NULL) return 1;

    if (strcmp(args[0], "exit") == 0)
    {
        cmd_exit();
    }

    if (strcmp(args[0], "help") == 0)
    {
        cmd_help();
    }

    return 0;
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
        exbicmd(args);
    }
    
    return 0;
}

