#include <cs50.h>
#include <stdio.h>

int main(void)
{
   int user_number= get_int("number of array: ");
   char **array=NULL;
   int size = sizeof(string)*user_number;
   for(int index = 0;index<user_number;index++)
   {
       printf("%i\n",size);
       array = realloc(array,size);
       array[index]=get_string("write name: ");
   }
   free(array);
}