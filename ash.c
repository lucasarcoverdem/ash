#include <stdio.h>
#include <unistd.h>

char login[256]; // "username"

// get user login
void get_login()
{
    login[255] = '\0';
    getlogin_r(login, sizeof(login));
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
    get_login();
    print_banner();
    
    return 0;
}

