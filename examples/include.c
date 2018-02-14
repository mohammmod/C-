#include <stdio.h>
#include <cs50.h>

int main (void)
{
    int board[9][9];
    int s,b,v;
    v=get_int();
    int tile =v*v- 1;
    for (s=0;s<v;s++)
    {
        for(b=0;b<v;b++)
        {
            board[s][b]=tile; 
            tile --;
        }
    }
    for (int f=0;f<v;f++)
    {
        for (int g=0;g<v;g++)
        {
            printf("|%2i",board[f][g]);
        }
        printf("\n");
    }
     int counter = 0;
    
    // Check each tile to ensure it's in order
    for (int i = 0; i < v; i++)
    {
        for (int j = 0; j < v; j++)
        {
            // Check if last spot and if not correct value
            if (++counter != (v * v) && board[i][j] != counter)
            {
                return false;
            }
        }
    }
    printf("%i",v*v);
    
return true;
}