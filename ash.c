#include <stdio.h>

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
    return 0;
}

