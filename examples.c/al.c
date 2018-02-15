#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>


//functions;
char* get_user_text();
void check_lenth_of_string_and_encipher_it_print_it (char* key,char*text);
void convert_letter_to_right_number_and_print_it (char* key,char*text[]);
void enchipher_string (char* key,char*text);



//mean programm
int main(int number_of_argument,char* arugment_vecto[])
{
    if(number_of_argument != 2)
    {
        printf("worng user try again\n");
        return 1;
    }
    char*key=arugment_vecto[1];
    for(int steps=0,length=strlen(key);steps<length;steps++)
    {
        if(!isalpha(arugment_vecto[steps]))
        {
            printf("./vigenere key word\n");
            return false;
        }
    }
    char* user_text = get_user_text();
    check_lenth_of_string_and_encipher_it_print_it (key,user_text);
}


//funktions
char* get_user_text()
{
    printf("plaintext:  ");
    return get_string();
}

void check_lenth_of_string_and_encipher_it_print_it (char* key,char*text)
{
    printf("ciphertext: ");
    enchipher_string(key,text);
    printf("\n");
}

void enchipher_string (char* key,char*text)
{

    for(int counter = 0 ,int counter1=0, notStackInLoop = strlen(text) ; notStackInLoop > counter ; counter++;counter1++)
    {
         if(isupper(text[counter]))
         {
            char cipher_letter=((text[counter]-'A')+key[counter1] )%26;
            cipher_letter=(cipher_letter + 'A');
            printf("%c",cipher_letter);

         }
         else if(islower(text[counter]))
         {
             char cipher_letter_small=((text[counter]-'a')+key[counter1])%26;
            cipher_letter_small=(cipher_letter_small + 'a');
            printf("%c",cipher_letter_small);
         }
         else
         {
             printf("%c",text[counter]);
         }
    }
    }
}