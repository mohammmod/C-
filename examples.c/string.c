#include <cs50.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <ctype.h>

int main(void)
{
    string note =get_string("semtone: ");
    char helpers;
    for(int octiv=0;octiv<strlen(note);octiv++)
    {
        if(isdigit(note[octiv]))
        {
            helpers=note[octiv];
        }
    }
    int man = atoi(&helpers);
    printf("octiv is %i\n",man);

    string note0 =strtok(note,&helpers);
    string semetone[12]={"A", "A#", "B","C", "C#", "D", "D#", "E", "F","F#", "G", "G#"};
    for(int i =0;i<12;i++)
    {
       // printf("note1:  %s\n",note0);
        if(strlen(note0)==1)
        {
         //   printf("semetone %s",semetone[i]);
            if(strcmp(note0,semetone[i])==0)
            {
                float freq,freqwe;
                if(man<4)
                for(int j=man;j<4;j++)
                {
                    printf("far from a :%i\n",i);
                    freq=440/pow(2.00,i/12.00);
                    freq=freq/2;
                    freqwe=freq;
                }
                if(man>4)
                for(int h=man; h>4;h--)
                {
                    printf("far from A :%i\n",i);
                    freq=440*pow(2.00,i/12.00);
                    freq=freq*2;
                    freqwe=freq;

                }
                if(man==4)
                {
                    freq=440*pow(2.00,i/12.00);
                    freqwe=freq;
                }
                int freqe=round(freqwe);
                printf("MH :%i\n",freqe);
                return 0;
            }
        }
        else if(strlen(note0)==2)
        {
            if(strcmp(note0,semetone[i])==0)
            {
                printf("far from A %i\n",i);
                float freq=440*pow(2.00,i/12.00);
                int freqe=round(freq);
                printf("MH :%i\n",freqe);
                return 0;
            }
        }
    }
}
