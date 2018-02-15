#include <cs50.h>
#include <stdio.h>

int main(void)
{
    //long long mod;
    long long number=get_long_long();
    //bool dude=true;
    for(int counter=0;counter<16;counter++)
    {
    if(number!=0)
    {

        number=number%10;
        printf("%lld",number);

    }

    }
//    printf("\n%lld",du);





}