#include <cs50.h>
#include <stdio.h>
#include <string.h>
int main(void)
{
char* alpha ="abcdefghijklmnopqrstuvwxyzABCDEFGHIJKLMNOPQRSTUVWXYZ";
char*alpha1;
for(int i=0;i<strlen(alpha);i++)
{
    alpha1 = i % strlen(alpha);
    for(int j=0;j<strlen(alpha1);i++)
    {
        printf("%c",alpha1[i]);

    }
}
}
