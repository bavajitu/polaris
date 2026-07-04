#include <stdio.h>
#include <stdlib.h>

#define MAXLENGTH 10000

int main()
{
    char UserInput[MAXLENGTH];
    while (true)
    {
        printf(">> ");
        fgets(UserInput, sizeof(UserInput), stdin);
    };
    return 0;
}
