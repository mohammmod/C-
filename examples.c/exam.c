#include <cs50.h>
#include <stdio.h>
void GetInts(int* a, int* b);

int main(void)
{
     int x, y;
     GetInts(&x, &y);
     printf("x is %i, y is %i\n", x, y);

}
void GetInts(int* a, int* b)
{
     *a =get_int();
     *b =get_int();
}