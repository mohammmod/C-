#include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>
#include <crypt.h>

int main(int argc,char*argv[])
{
    if(argc!=2)
    {
        printf("wrong user try again \n");
        return 1;
    }
    char * dude = "a";
    char salt[3] = {0};
    salt [0]= argv[1][0];
    salt [1]= argv[1][1];
    salt [2] = '\0';
    char*man = crypt(dude,salt);
    printf("%s\n",salt);
    printf("%s\n",man);

}