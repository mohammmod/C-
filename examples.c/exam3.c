 #include <stdio.h>
 #include <cs50.h>
 void PrintGrid(int width, int height);

 int main(void)
 {
     int height = get_int("height: ");
     int width = get_int("width: ");
     PrintGrid(width, height);

 }



 void PrintGrid(int width, int height)
 {
     for(int i = 0;i<height;i++)
     {
         for(int j =0;j<width;j++)
         {
             printf("#");
         }
         printf("\n");
     }
 }