// Helper functions for music

#include <cs50.h>
#include <string.h>
#include <string.h>
#include <math.h>
#include <stdio.h>

#include "helpers.h"

//frequency functions
char get_octaves(string note);
char* cut_octaves_from(string note,string octave);
int check_if_note_match_With(char* note_SEmetone,string semetone_sharp[],string semetone_b[],int counter_semetone,int freqe,int Octave_NUMBER );
int if_Octaves_four( int counter_semetone);
int if_Octaves_less(int Octave_NUMBER, int counter_semetone);
int if_Octaves_more(int Octave_NUMBER, int counter_semetone);


// Converts a fraction formatted as X/Y to eighths
int duration(string fraction)
{
    int divisor=0;
    for(int counter =0;counter<strlen(fraction);counter++)
    if(strcmp(&fraction[2],"8")== 0)
    {
        divisor = atoi(&fraction[0]);
        break;
    }
    else if(strcmp(&fraction[2],"4")==0)
    {
        divisor = atoi(&fraction[0]);
        divisor=divisor*2;
        break;
    }
    else if(strcmp(&fraction[2],"2")==0)
    {
        divisor = atoi(&fraction[0]);
        divisor=divisor*4;
        break;
    }
    return divisor;

}

// Calculates frequency (in Hz) of a note
int frequency(string note)
{
    char octave = get_octaves(note);
    int Octave_NUMBER = atoi(&octave);
    char octaveS[2] = {octave,'\0'};
   // strncpy(octaveS, &octave, 12);
    char note_tone[12];
    strncpy(note_tone, note, 12);
    char* note_SEmetone = cut_octaves_from(note_tone, octaveS);
    char* semetone_sharp[12]=  {"C", "C#", "D","D#", "E", "F","F#","G","G#","A","A#","B"};
    char* semetone_b[12]=      {"C", "Db", "D","Eb", "E", "F","Gb","G","Ab","A","Bb","B"};
    int freqe=0;
    for(int counter_semetone =0;counter_semetone<12;counter_semetone++)
    {
        freqe = check_if_note_match_With(note_SEmetone,semetone_sharp,semetone_b,counter_semetone,freqe,Octave_NUMBER);
    }
    return freqe;
}

// Determines whether a string represents a rest
bool is_rest(string s)
{
    return strlen(s)==0;
}
char get_octaves(string note)
{
    return note[strlen(note) - 1];
}
char* cut_octaves_from(string note,string octave)
{
    char* index = strtok(note,octave);
    return index;
}
int check_if_note_match_With(char* note_SEmetone,string semetone_sharp[],string semetone_b[],int counter_semetone,int freqe,int Octave_NUMBER )
{
    if(strcmp(note_SEmetone,semetone_sharp[counter_semetone])==0  ||strcmp(note_SEmetone,semetone_b[counter_semetone])==0)
    {
        int freqnew=0;
        if(Octave_NUMBER==4)
        {
            freqnew = if_Octaves_four(counter_semetone);
        }
        if(Octave_NUMBER<4)
        {
            freqnew = if_Octaves_less(Octave_NUMBER ,counter_semetone);
        }
        if(Octave_NUMBER>4)
        {
            freqnew = if_Octaves_more(Octave_NUMBER ,counter_semetone);
        }
        if(freqe>3951)
        {
            freqe =0;
            if(Octave_NUMBER==4)
            {
                freqnew = if_Octaves_four(counter_semetone);
            }
            if(Octave_NUMBER<4)
            {
                freqnew = if_Octaves_less(Octave_NUMBER ,counter_semetone);
            }
            if(Octave_NUMBER>4)
            {
                freqnew = if_Octaves_more(Octave_NUMBER ,counter_semetone);
            }
        }
        freqe=round(freqnew);
    }
return freqe;
}

int if_Octaves_four(int counter_semetone )
{
    float freq=0.0;
    float freqnew=0.0;
    freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
    freqnew=freq;
    return freqnew;
}

int if_Octaves_less(int Octave_NUMBER, int counter_semetone)
{
    float freq=0.0;
    float freqnew=0.0;
    freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
    for(int Octave =Octave_NUMBER;Octave<4;Octave++)
    {
        counter_semetone=counter_semetone-counter_semetone-counter_semetone;
        //freq=freq + 1.00;
        //freq = freq/2;
        //freqnew= freqnew-freq;
    }
    freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
    return freq;
}

int if_Octaves_more(int Octave_NUMBER, int counter_semetone)
{
    float freq=0.0;
    float freqnew=0.0;
    freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
    for(int Octave=Octave_NUMBER; Octave>4;Octave--)
    {
        freqnew=freqnew+ freq*2;
    }
    return freqnew;
}
