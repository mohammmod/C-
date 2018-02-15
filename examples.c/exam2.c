#include <cs50.h>
#include <ctype.h>
#include <stdio.h>

 char f(char c)
 {
  if (isalpha(c))
 {
     return c & 0xdf;
 }
 else
 {
  return c;

 }

 }
 int main(void)
 {
  printf("%c\n", f('A'));

 }