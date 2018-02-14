#include <cs50.h>
#include <stdio.h>
#include <stdlib.h>

int main (int argc,string argv[])
{
    if(argc != 2)
    {
        printf("sorry it didnt work \n");
        
    }
    int s = atoi(argv[1]);
    for (int k=0;k<s;k++)
    {
        for (int j=0;j<s-k;j++)
        printf("%d",[j][k]);
        printf("#");
    }
    printf("\n");
}