#include <cs50.h>
#include <stdio.h>
#include <string.h>


int get_hash(string soso);


int main(void)
{
    int hash1,hash2;
    char* array [3] = {"thear","yezen","mhd"};
    string soso =get_string("give me name: ");
    hash2 = get_hash(soso);
    for(int i =0;i<3;i++)
    {
        hash1 = get_hash(array[i]);
        if(hash1 ==hash2)
        {
            printf("found\n");
            return 0;
        }

    }
    printf("hash 1 is %i , and hash 2 is %i\n",hash1,hash2);
    printf("\n%p\n",array[1]);
}
int get_hash(string soso)
{
    int hash = 0;
    int len = strlen(soso);
    for(int i = 0 ;i<len;i++)
    {
         hash = i * 12 *(soso[i]) ;
         if(hash == 0 )
         {
             hash ++;
             if(hash ==1)
             {
                 printf("%i\n",hash);
                 hash = hash *(soso[i]);
             }
         }
    }
    return hash;
}