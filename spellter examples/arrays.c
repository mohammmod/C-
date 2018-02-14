#include <stdio.h>
#include <cs50.h>
#include <string.h>

#define NUMBER_OF_NAMES 5

int main(void)
{
    string names[NUMBER_OF_NAMES];

    printf("** Asking for names\n" );
    for(int index = 0; index < NUMBER_OF_NAMES; index++)
    {
        printf("%i - ", index + 1);
        names[index] = get_string("write a name: ");
    }

    printf("\n\n** Display names\n" );
    for(int index = 0; index < NUMBER_OF_NAMES; index++)
    {
        printf("%i - %s\n", index + 1, names[index]);
    }
}