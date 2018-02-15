#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int calcuat_freq(int semetoneCounter);
char get_octave(char* note);
int more_less_octave(int octave_number,int MH,int semetoneCounter);

int main (void)
{
    char* note =get_string();
    char octave=get_octave(note);
    char* semetone ="CcDdEFfGgAaB";
    int octave_number =atoi(&octave);
    printf("octiv is %i\n",octave_number);
    int notes = strlen(semetone);
    int MH=0;
    for(int semetoneCounter=0;semetoneCounter<notes;semetoneCounter++)
    {
        //check for the shap semetone.
        if((note[1]=='#') && ((semetone[semetoneCounter])))
        {
            //for the sharp.
            if((semetone[semetoneCounter]=='c')&&((note[0])==('C')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("semetone %i\n",semetoneCounter);
                printf("MH :%i\n",MH);
            }
            //for the flag
            if((semetone[semetoneCounter]=='d')&&((note[0])==('D')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);
            }
            if((semetone[semetoneCounter]=='f')&&((note[0])==('F')))
            {
               MH=calcuat_freq(semetoneCounter);
               MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);
            }
            if((semetone[semetoneCounter]=='g')&&((note[0])==('G')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);

            }
            //check for the sharp semetone.
            if((semetone[semetoneCounter]=='a')&&((note[0])==('A')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);

            }

        }
            //check for the flage semetone.
        if((note[1]=='b') && ((semetone[semetoneCounter])))
        {
            if((semetone[semetoneCounter]=='c')&&((note[0])==('D')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);
            }
            //for the flag
            if((semetone[semetoneCounter]=='d')&&((note[0])==('E')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);
            }
            if((semetone[semetoneCounter]=='f')&&((note[0])==('G')))
            {
               MH=calcuat_freq(semetoneCounter);
               MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);
            }
            if((semetone[semetoneCounter]=='g')&&((note[0])==('A')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);

            }
            if((semetone[semetoneCounter]=='a')&&((note[0])==('B')))
            {
                MH=calcuat_freq(semetoneCounter);
                MH=more_less_octave(octave_number,MH,semetoneCounter);
                printf("MH :%i\n",MH);

            }
        }
        if((semetone[semetoneCounter]==note[0])&&(isdigit(note[1])))
        {
            MH=calcuat_freq(semetoneCounter);
            MH=more_less_octave(octave_number,MH,semetoneCounter);
            printf("MH :%i\n",MH);

            //printf("%c  MH :%i\n",semetone[semetoneCounter],MH);
        }

    }
    printf("finall %i\n",MH);
}
char get_octave(char* note)
{
    return note[strlen(note) - 1];
}
int calcuat_freq(int semetoneCounter)
{

    float freqe = 440*pow(2.00,(semetoneCounter - 9)/12.00);
    int freqeNew=round(freqe);
    return freqeNew;
}
int more_less_octave(int octave_number,int MH,int semetoneCounter)
{
    int freqnew =0;
    if(octave_number==4)
    {
        freqnew=calcuat_freq(semetoneCounter);
    }
    if(octave_number>4)
    {
        for(int Octave=octave_number; Octave>4;Octave--)
        {
            freqnew=freqnew+ MH + MH;
        }
    }
    if(octave_number<4)
    {
        for(int Octave =octave_number;Octave<4;Octave++)
        {
        freqnew= MH;
        MH = MH/2;
        freqnew= freqnew- MH;
        }
    }
    return freqnew;
}