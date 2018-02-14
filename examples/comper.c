#include <cs50.h>
#include <stdio.h>
#include <string.h>


int main(void)
{
    string e = "1950";
    printf("s: ");
    char *s = e;
    printf("when ended the secound world war?");
    char *t = get_string();
     if (s!= NULL && t!= NULL)
     {
         if(strcmp(s,t)==0)
         {
             printf("same");
         }
         else
         {
             printf("different");
         }
     }
    printf("\n");
}