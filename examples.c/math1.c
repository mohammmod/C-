#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int number =get_int();
    number = number -number - number;
    printf("%i\n",number);
}