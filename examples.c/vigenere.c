#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>

//int convert_theUser_key(string get_theUser_key);
char* check_if_invaled(int number_of_keys,char*the_key[]);
char* get_the_plainText();
void cipher_with_vigenere(char* theUser_key);

int main(int number_of_keys,char*the_key[])
{
    char* theUser_key = check_if_invaled(number_of_keys,the_key);
    cipher_with_vigenere(theUser_key);
}

char* check_if_invaled(int number_of_keys,char*the_key[])
{
    if(number_of_keys!=2)
    {
        printf("worng using try agian\n");
        exit(1);
    }
    char* theUser_key=the_key[1];
    int length=strlen(theUser_key);
    for (int counter=0;counter<length;counter++)
    {
        if(!isalpha(theUser_key[counter]))
        {
            printf("./vigenere keyword\n");
            exit(1);
        }
    }
    return theUser_key;

}
void cipher_with_vigenere(char*theUser_key)
{
    int counterkey= 0;
    char* plainText=get_the_plainText();
    printf("ciphertext: ");
    int length = strlen(plainText);
    for(int index = 0;index<length;index++)
    {

            counterkey = index % strlen(theUser_key);
        if(isalpha(plainText[index]))
        {
        if(islower (theUser_key[counterkey]))
        {
            if(islower(plainText[index]))
            {
                plainText[index]=((plainText[index]-'a')+(theUser_key[counterkey]-'a'))%26;
                plainText[index]=plainText[index]+'a';
                printf("%c",plainText[index]);
            }
            else if(isupper(plainText[index]))
            {
                plainText[index]=((plainText[index]-'A')+(theUser_key[counterkey]-'a'))%26;
                plainText[index]=plainText[index]+'A';
                printf("%c",plainText[index]);
            }

        }
        else if(isupper(theUser_key[counterkey]))
        {
            if(islower(plainText[index]))
            {
                plainText[index]=((plainText[index]-'a')+(theUser_key[counterkey]-'A'))%26;
                plainText[index]=plainText[index]+'a';
                printf("%c",plainText[index]);
            }
            else if(isupper(plainText[index]))
            {
                plainText[index]=((plainText[index]-'A')+(theUser_key[counterkey]-'A'))%26;
                plainText[index]=plainText[index]+'A';
                printf("%c",plainText[index]);
            }
        }
        }

        else
        {
            printf("%c",plainText[index]);
        }
    }
    printf("\n");
    exit(0);
}

char* get_the_plainText()
{
    printf("plaintext: ");
    return get_string();
}