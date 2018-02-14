#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int board[9][9];
    int d=get_int();
    int tile = d * d - 1;

    // row
    for (int row = 0; row < d; row++)
    {
        // col
        for (int col = 0; col < d; col++) 
        {
            /*if (tile == 0) {
                tile = atoi(placeholder);
            }*/
                board[row][col] = tile;
                tile --;
        }
    }
    
     // swap 1 and 2 if # of tiles is odd
     if (d*d %2 > 0) {
        board[d-1][d-3] = 1;
        board[d-1][d-2] = 2;
     }
     for (int row = 0;row<d;row++)
     {
         for (int col=0;col<d;col++)
         {
             printf("|%2d",board[row][col]);
         }
         printf("\n");
     }

}