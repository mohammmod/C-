#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

char get_octaves(string note);
char* cut_octaves_from(string note,char octave);
int check_if_note_match_With(string note_SEmetone,string semetone_sharp[],string semetone_b[],int counter_semetone,int freqe,int Octave_NUMBER );
int if_Octaves_four(int Octave_NUMBER, int counter_semetone);
int if_Octaves_less(int Octave_NUMBER, int counter_semetone);
int if_Octaves_more(int Octave_NUMBER, int counter_semetone);

int main(void)
{
    string note =get_string("semtone: ");
    char octave = get_octaves(note);
    int Octave_NUMBER = atoi(&octave);
    printf("octiv is %i\n",Octave_NUMBER);
    string note_SEmetone = cut_octaves_from( note, octave);
    string semetone_sharp[12]=  {"C", "C#", "D","D#", "E", "F","F#","G","G#","A","A#","B"};
    string semetone_b[12]=      {"C", "Db", "D","Eb", "E", "F","Gb","G","Ab","A","Bb","B"};
    int freqe=0;
    for(int counter_semetone =0;counter_semetone<12;counter_semetone++)
    {
        freqe=check_if_note_match_With(note_SEmetone,semetone_sharp,semetone_b,counter_semetone,freqe,Octave_NUMBER);
        printf("%s\n",semetone_sharp[counter_semetone]);
        printf("%i\n",freqe);
    }
}
char get_octaves(string note)
{
    return note[strlen(note) - 1];
}
char* cut_octaves_from(string note,char octave)
{

    return strtok(note,&octave);
}
int check_if_note_match_With(string note_SEmetone,string semetone_sharp[],string semetone_b[],int counter_semetone,int freqe,int Octave_NUMBER )
{
    if(strcmp(note_SEmetone,semetone_sharp[counter_semetone])==0  ||strcmp(note_SEmetone,semetone_b[counter_semetone])==0)
    {
        //printf("%s\n\n",semetone_sharp[counter_semetone]);

        int freqnew=0;
        if(Octave_NUMBER==4)
        {
            freqnew = if_Octaves_four(Octave_NUMBER ,counter_semetone);
        }
        if(Octave_NUMBER<4)
        {
            freqnew = if_Octaves_less(Octave_NUMBER ,counter_semetone);
        }
        if(Octave_NUMBER>4)
        {
            freqnew = if_Octaves_more(Octave_NUMBER ,counter_semetone);
        }
        freqe=round(freqnew);
    }
return freqe;
}
int if_Octaves_four(int Octave_NUMBER,int counter_semetone )
{
    float freq=0.0;
    if(Octave_NUMBER==4)
    {
         freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
    }
    return freq;
}
int if_Octaves_less(int Octave_NUMBER, int counter_semetone)
{
    float freq=0.0;
    float freqnew=0.0;
     if(Octave_NUMBER<4)
    {
        freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
        for(int Octave =Octave_NUMBER;Octave<4;Octave++)
        {
            printf("far from a :%i\n",counter_semetone);
            freq = freq/2;
            freqnew=freq;
        }
    }
    return freqnew;
}
int if_Octaves_more(int Octave_NUMBER, int counter_semetone)
{
    float freq=0.0;
    float freqnew=0.0;
    if(Octave_NUMBER>4)
    {
        freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
        for(int Octave=Octave_NUMBER; Octave>4;Octave--)
        {
            printf("far from A :%i\n",counter_semetone);
            freqnew=freqnew+ freq*2;
        }
    }
    return freqnew;
}
