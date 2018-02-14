#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int table[3][3] = {{2,4,6},{3,6,9},{4,8,1,}};
    for (int i = 0; i<3;i++)
    {
        
        for (int j=0; j<3;j++)
        {
          
            printf("%d",table[i][j]);
            
        }
        printf("\n");
    }

}