#include<stdio.h>
#include <cs50.h>
 
int main() {
   int a[10][10], b[10][10], c[10][10], i, j, k;
   int sum = 0;
   printf("enter the number that u want :");
   int s = get_int();
   
 
   printf("\nEnter First Matrix : n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         scanf("%d", &a[i][j]);
      }
   }
 
   printf("\nEnter Second Matrix:n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         scanf("%d", &b[i][j]);
      }
   }
 
   printf("The First Matrix is: \n");
   for (i = 0; i < s; i++) {
      for (j = 0; j < s; j++) {
         printf(" %d ", a[i][j]);
      }
      printf("\n");
   }
 
   printf("The Second Matrix is : \n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf(" %d ", b[i][j]);
      }
      printf("\n");
   }
 
   //Multiplication Logic
   for (i = 0; i <= 2; i++) {
      for (j = 0; j <= 2; j++) {
         sum = 0;
         for (k = 0; k <= 2; k++) {
            sum = sum + a[i][k] * b[k][j];
         }
         c[i][j] = sum;
      }
   }
 
   printf("\nMultiplication Of Two Matrices : \n");
   for (i = 0; i < 3; i++) {
      for (j = 0; j < 3; j++) {
         printf(" %d ", c[i][j]);
      }
      printf("\n");
   }
 
   return (0);
}