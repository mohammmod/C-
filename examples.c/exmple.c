#include <stdio.h>
#include <cs50.h>
int main(void)
{
    int lol;
    long long number=get_long_long();
    for (int counter =0;counter<16;counter++)
    {
    lol=(number/10)%10;
    printf("%i",lol);
    }
}