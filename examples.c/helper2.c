#include <cs50.h>
#include <stdio.h>
#include <crypt.h>
#include <string.h>

int main(int argc,char*argv[])
{
     if(argc!=2)
    {
        printf("Usage: ./carck hash \n");
        return 1;
    }
   // char place;
    char*challenge="abcdefghijklmnopqrstuvwxyz";
    char*alpha="ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char*lol=argv[1];
    for(int counter=0;counter<strlen(challenge);counter++)
    {
        //char*=get_string();
        char* placed2=crypt(&alpha[counter],"50");
        char *placed = crypt(&challenge[counter],"50");
        if(strcmp(lol,placed)==0)
        {
            printf("%c\n",challenge[counter]);
            return 0;
        }
        else if(strcmp(placed2,lol)==0)
        {
            printf("%c\n",alpha[counter]);
            printf("flase;\n");
        }
        printf("%s\n",placed);
        printf("%s\n",placed2);

    }

       // printf("%s",moh1);





    //printf("%s",moh);


    printf("%s\n",lol);

}
