#include <cs50.h>
#include <stdio.h>
#include <time.h>

string pick_up_name(int number_of_argument,string argument_vector[]);
int main (int number_of_argument,string argument_vector[])
{
    string random_name=pick_up_name(number_of_argument,argument_vector);
    printf("%s defuse the boomb\n",random_number);
}
string pick_up_name(int number_of_argument,string argument_vector[])
{
    srand(time(NULL));
    int random_number=(rand()%(number_of_argument - 1))+ 1;
    string random_name=argument_vector[random_number];
    return random_name;
}