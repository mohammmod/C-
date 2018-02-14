#include <cs50.h>
#include <stdio.h>
#include <ctype.h>
#include <string.h>

int main(int number_of_keys,char*the_key[])
{
    if(number_of_keys!=2)
    {
        printf("worng using try agian\n");
        return 1;
    }
    char* theUser_key=the_key[1];
    for (int counter=0,length=strlen(theUser_key);counter<length;counter++)
    {
        if(!isalpha(theUser_key[counter]))
        {
            printf("./vigenere keyword\n");
            return 1;
        }
    }
    int counter=0;
    printf("plaintext:  ");
    string plainText=get_string();
    printf("ciphertext: ");
    for(int i=0;i<strlen(plainText);i++)
    {
        if(isalpha(plainText[i]))
        {

        counter=i%strlen(theUser_key);
        if(islower (theUser_key[counter]))
        {
            if(islower(plainText[i]))
            {
                plainText[i]=((plainText[i]-'a')-(theUser_key[counter]-'a'))%26;
                plainText[i]=plainText[i]+'a';
                printf("%c",plainText[i]);
            }
            else if(isupper(plainText[i]))
            {
                plainText[i]=((plainText[i]-'A')-(theUser_key[counter]-'a'))%26;
                plainText[i]=plainText[i]+'A';
                printf("%c",plainText[i]);
            }

        }
        else if(isupper(theUser_key[counter]))
        {
            if(islower(plainText[i]))
            {
                plainText[i]=((plainText[i]-'a')-(theUser_key[counter]-'A'))%26;
                plainText[i]=plainText[i]+'a';
                printf("%c",plainText[i]);
            }
            else if(isupper(plainText[i]))
            {
                plainText[i]=((plainText[i]-'A')-(theUser_key[counter]-'A'))%26;
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