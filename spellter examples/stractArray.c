#include <stdio.h>
#include <cs50.h>
#include <string.h>
#include <stdlib.h>

#define GREEN true
#define RED false

typedef struct
{
    string name;
    bool checked_in;
}
PARTICIPANT;

int main(void)
{

    int number_of_participants;
    do
    {
        number_of_participants = get_int("Number of participants: ");
    } while(number_of_participants < 1);


    PARTICIPANT participants[number_of_participants];

    printf("** Asking for names\n" );
    for(int index = 0; index < number_of_participants; index++)
    {
        printf("%i - ", index + 1);
        participants[index].name = get_string("Write a name: ");
        participants[index].checked_in = RED;
    }

    printf("\n\n** Check in one participant\n" );
    int participant_number = get_int("Write participant number: ");

    participants[participant_number - 1].checked_in = GREEN;

    printf("\n\n** Display names\n" );
    for(int index = 0; index < number_of_participants; index++)
    {
        printf("%i - %s\n", index + 1, participants[index].name);
        printf("%i - %i\n", index + 1, participants[index].checked_in);
    }
}