#include <cs50.h>
#include <string.h>
#include <stdio.h>
#include <crypt.h>
#include <unistd.h>
#define _XOPEN_SOURCE

int main (int argc,string argv[])
{
    if(argc!=2)
    {
        printf("./crack hash: ");
    }
    char* hash =argv[1];
    string key ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    int letter =strlen(key);
    char salt[3] = {0};
    salt [0]= argv[1][0];
    salt [1]= argv[1][1];
    salt [2] = '\0';
    char password [6];
    char*crypto;
    for(int counter=0;counter< letter;counter++)
    {
        password[0]=key[counter];
        password[1]='\0';
        crypto=crypt(password,salt);

        if(strcmp(crypto,hash)==0)
        {
                printf("%s\n",password);
                return 0;
        }
    }
    for(int counter=0;counter< letter;counter++)
    {
        password[0]=key[counter];
        for(int counter1=0;counter1< letter;counter1++)
        {
            password[1]=key[counter1];
            password[2]='\0';
            crypto=crypt(password,salt);

            if(strcmp(crypto,hash)==0)
            {
                printf("%s\n",password);
                return 0;
            }
        }
    }
    for(int counter=0;counter< letter;counter++)
    {
        password[0]=key[counter];
        for(int counter1=0;counter1< letter;counter1++)
        {
            password[1]=key[counter1];
            for(int counter2=0;counter2< letter;counter2++)
            {
            password[2]=key[counter2];
            password[3]='\0';
            crypto=crypt(password,salt);

            if(strcmp(crypto,hash)==0)
            {
                printf("%s\n",password);
                return 0;
            }
            }
        }
    }
    for(int counter=0;counter< letter;counter++)
    {
        password[0]=key[counter];
        for(int counter1=0;counter1< letter;counter1++)
        {
            password[1]=key[counter1];
            for(int counter2=0;counter2< letter;counter2++)
            {
                password[2]=key[counter2];
                for(int counter3=0;counter3< letter;counter3++)
                {
                    password[3]=key[counter3];
                    password[4]='\0';
                    crypto=crypt(password,salt);
                    if(strcmp(crypto,hash)==0)
                    {
                        printf("%s\n",password);
                        return 0;
                    }
                }
            }
        }
    }
    for(int counter=0;counter< letter;counter++)
    {
        password[0]=key[counter];
        for(int counter1=0;counter1< letter;counter1++)
        {
            password[1]=key[counter1];
            for(int counter2=0;counter2< letter;counter2++)
            {
                password[2]=key[counter2];
                for(int counter3=0;counter3< letter;counter3++)
                {
                    password[3]=key[counter3];
                    for(int counter4=0;counter4< letter;counter4++)
                    {
                        password[4]=key[counter4];

                        password[5]='\0';
                        crypto=crypt(password,salt);
                        if(strcmp(crypto,hash)==0)
                        {
                            printf("%s\n",password);
                            return 0;
                        }
                    }
                }
            }
        }
    }
}