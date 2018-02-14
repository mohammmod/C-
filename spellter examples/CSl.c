#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

int main(void)
{
    const char * name = get_string("enter name plase: ");
    int namelen = strlen(name);
    char namenew[47];
    for(int i = 0 ;i <namelen;i++)
    {
        if(isupper(name[i]))
        {
            namenew[i] = tolower(name[i]);
            printf("%c",namenew[i]);
        }
        else
        {
           // namenew[i] = name[i];
            printf("%c",name[i]);
        }

    }
    printf("\n");
}