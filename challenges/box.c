#include <cs50.h>
#include <stdio.h>

int main (void)
{
    int sizeBox =get_int ("size : ");
    for(int height = 0; height<sizeBox;height++)
    {
        for(int width = 0;width<sizeBox;width++)
        {
            if(height == 0||height == sizeBox - 1)
            {
                printf("#");
            }
            else if(width == 0||width ==sizeBox - 1)
            {
                printf("#");
            }
            else
            {
                printf(" ");
            }

        }
        printf("\n");
    }
}