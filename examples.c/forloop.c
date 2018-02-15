#include <stdio.h>
#include <cs50.h>
#include <crypt.h>
#include <string.h>


int main(void)
{
    //string name=get_string();
    //char h[]="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
    char dude [5];
    for(char i ='A';i<'D';i++)
    {
        dude[0]=i;
        for(char j='A';j<'D';j++)
        {
            dude[1]=j;
            //printf("%s\n",dude);
            for(char k='A';k<'D';k++)
            {
                dude[2]=k;
                dude[3]='\0';
               char* crypto=crypt(dude,"50");
               printf("%s",crypto);
                printf("%s\n",dude);

                //printf("%s\n",dude);
            }

        }
       // printf("%c\n",h[i]);




    }

}