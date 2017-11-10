#include <ctype.h>
#include <cs50.h>
#include <stdio.h>
#include <string.h>

int main(void)
{
    bool up =true;
    char* user_input=get_string();
    for(int counter=0;counter<strlen(user_input);counter++)
    {
        if(isspace(user_input[counter]))
        {
            printf(" ");
        }
        
        else
        {
            if(up)
            {
                printf("%c",toupper(user_input[counter]));
                up =false;
            }
            else
            {
                printf("%c",user_input[counter]);
                up =true;
            }
        }
    }
    printf("\n");
}


