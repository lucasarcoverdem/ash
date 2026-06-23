#include <stdio.h>
#include <unistd.h>

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

    printf("%s at %s: \n", login, cwd);
}

void print_banner()
{
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");
    printf("|                    -------                     |\n");
    printf("|                    | ASH |                     |\n");
    printf("|                    -------                     |\n");
    printf("|                    a shell                     |\n");
    printf("=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-=-\n");

    printf("\n                 Welcome to ASH!\n\n");
}

int main(void)
{
    print_banner();
    print_login_and_cwd();
    
    return 0;
}

