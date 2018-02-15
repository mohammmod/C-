#include <cs50.h>
#include <stdio.h>

int swap_those_values_print(int number,int number2);
int main(void)
{
    int number=get_int();
    int number2=get_int();
    swap_those_values_print(number,number2);
    printf("%i,%i",number,number2);
}
int swap_those_values_print(int number,int number2)
{
    int tmp=0;
    tmp=number;
    number = number2;
    number2=tmp;
    return number,number2;
}