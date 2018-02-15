#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(void)
{
   // char moh1;
    int counter=0;
    char* moh=get_string();
    string plainText=get_string();
    for(int i=0;i<strlen(plainText);i++)
    {
        if(isalpha(plainText[i]))
        {

        counter=i%strlen(moh);
        if(islower (moh[counter]))
        {
            if(islower(plainText[i]))
            {
                plainText[i]=((plainText[i]-'a')+(moh[counter]-'a'))%26;
                plainText[i]=plainText[i]+'a';
                printf("%c",plainText[i]);
            }
            else if(isupper(plainText[i]))
            {
                plainText[i]=((plainText[i]-'A')+(moh[counter]-'a'))%26;
                plainText[i]=plainText[i]+'A';
                printf("%c",plainText[i]);
            }

        }
        else if(isupper(moh[counter]))
        {
            if(islower(plainText[i]))
            {
                plainText[i]=((plainText[i]-'a')+(moh[counter]-'A'))%26;
                plainText[i]=plainText[i]+'a';
                printf("%c",plainText[i]);
            }
            else if(isupper(plainText[i]))
            {
                plainText[i]=((plainText[i]-'A')+(moh[counter]-'A'))%26;
                plainText[i]=plainText[i]+'A';
                printf("%c",plainText[i]);
            }

        }

        }
        else
        {
            printf("%c",plainText[i]);
        }
    }

    printf("\n");
}
