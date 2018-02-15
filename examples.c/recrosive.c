#include <cs50.h>
#include <stdio.h>

void do_recro_man(int recrosive);

int main(void)
{
    int recrosive =get_int();
    do_recro_man(recrosive);
}

void do_recro_man(int recrosive)
{
    if(recrosive > 0)
    {
        printf("hello ,world\n");
        return do_recro_man(recrosive - 1 );
    }
}