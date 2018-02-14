#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

int main(void)
{

    int number_of_names;
    do
    {
        number_of_names = get_int("Number of names: ");
    } while(number_of_names < 1);


    string* names = NULL;
    //printf("\nSize of one string: %lu\n", sizeof(string));
    //printf("\nSize of all names: %i\n", size);

    printf("** Asking for names\n" );
    for(int index = 0; index < number_of_names; index++)
    {
        int size = sizeof(string) * (index + 1);
        printf("%i\n",size);
        names = realloc(names, size);
        printf("%i - ", index + 1);
        names[index] = get_string("Write a name: ");
    }

    printf("\n\n** Display names\n" );
    for(int index = 0; index < number_of_names; index++)
    {
        printf("%i - %s\n", index + 1, names[index]);
    }

    free(names);
}