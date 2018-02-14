#include <cs50.h>
#include <stdio.h>

void swap (int *a,int *b);

int main (void)
{
    int x = 1;
    int y = 2;
    
    printf("x is %i",x);
    printf("y is %i",y);
    printf("swaping ....\n");
    swap(&x, &y);
    printf("swaped\n");
    printf("x is %i",x);
    printf("y is %i",y);
}

void swap (int *a,int *b);
{
    int tmp= *a;
    *a=*b;
    *b=tmp;
}
