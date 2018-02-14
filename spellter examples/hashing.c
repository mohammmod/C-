#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <ctype.h>



unsigned long hash (const char* word)
{
    unsigned long hash = 0;
    for (int i = 0 ; word[i] != '\0' ; i++)
    {
        if(isupper(word[i]))
        {
            hash = (31*hash + 32) + word[i];
        }
        else
        {
            hash = (31*hash )+ word[i];
        }
    }
    return hash % 98317;
}

int main(void)
{
    const char *hasho =get_string("somthing to hash: ");
    int len = strlen(hasho);
    char hashing[8]={0};
    for(int i = 0; i<len;i++)
    {
        hashing [i] = hasho[len];
        printf("%lu\n", hash(hashing));
        printf("%lu\n", hash(hasho));
    }
}

