#include <crypt.h>
#include <cs50.h>
#include <stdio.h>
#define _XOPEN_SOURCE
#include <unistd.h>

int main(void)
{
    string dude = get_string("write something to get the hash: ");
    char*man = crypt(dude,"50");
    printf("the hash is :%s\n",man);
}