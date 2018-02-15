#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>



int main(void)
{
    string note = get_string();
    // char octave = note[strlen(note) - 1];
    int ocatve_number = strlen(note) - '0';
    string noteNew;

    char* semetone_sharp[12]=  {"C", "C#", "D","D#", "E", "F","F#","G","G#","A","A#","B"};
    char* semetone_b[12]=      {"C", "Db", "D","Eb", "E", "F","Gb","G","Ab","A","Bb","B"};
    int freqe=0;

    if (strlen(note) == 2)
    {
        noteNew[] = {note[0] , note[1]};
    }
    else
    {
        notenew = {note[0] , note[2]};
    }

    for(int counter_semetone =0;counter_semetone<12;counter_semetone++)
    {
        if(strcmp(noteNew,semetone_sharp[counter_semetone])==0  ||strcmp(noteNew,semetone_b[counter_semetone])==0)
        {
            float freq =0.0;
            float freqnew=0.0;
            freq=440*pow(2.00,(counter_semetone - 9 )/12.00);
            freqnew=freq;
            if(ocatve_number<4)
            {
                for(int Octave =ocatve_number;Octave<4;Octave++)
                {
                    freq = freq/2;
                    freqnew=freq;
                }
            }
            if(ocatve_number>4)
            {
                for(int Octave=ocatve_number; Octave>4;Octave--)
                {
                    freq=freq*2;
                    freqnew=freq;
                }
            }
            freqe=round(freqnew);
            break;
        }

    }
    printf("%i\n",freqe);
    return freqe;
}