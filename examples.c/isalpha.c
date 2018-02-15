#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main (void)
{
    string name = get_string();
    int length = strlen(name);
    for(int i = 0; i<length;i++)
    {
        if(isalpha(name[i]))
        {
            printf("good");
        }
        else
        {
            printf("\n\n what\n\n");
        }
    }
}