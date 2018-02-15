#include <cs50.h>
#include <stdio.h>

int main(void)
{
    int unser_input=0;
    do{
        printf("Height: ");
        unser_input=get_int();

    }while (unser_input<0||unser_input>23);


    for (int Mcounter=0;Mcounter<unser_input;Mcounter++)
    {
        for (int Scounter=0;Scounter<unser_input-Mcounter-1;Scounter++)
        {
        printf(" ");
        }
        for (int Hcounter=0;Hcounter<Mcounter+1;Hcounter++)
        {
        printf("#");
        }
        printf("  ");
        for (int counter_space2=0;counter_space2<Mcounter-unser_input;counter_space2++)
        {
            printf(" ");
        }
        for (int counterh=0;counterh<Mcounter+1;counterh++)
        {
            printf("#");
        }
        printf("\n");

    }

}