#include <cs50.h>
#include <stdio.h>

int main (void)
{
    printf("what is your name \n");
    
    char* s=get_string();
    
    printf("hallo %s\n",s);
}