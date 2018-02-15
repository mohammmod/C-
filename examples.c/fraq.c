#include <cs50.h>
#include <stdio.h>
#include <math.h>

int main(void)
{
    printf("number: ");
    int dude =get_int();
    float freq=493.883/pow(2.00,dude/12.00);
    int freqe=round(freq);
    printf("%i\n",freqe);
}
 char helpers;
    helpers = note[strlen(note) - 1]; //B#5

    int man = atoi(&helpers);
    printf("octiv is %i\n",man);
    int freqe=0;
    string note0 =strtok(note,&helpers);
    string semetone[12]=   {"C", "C#", "D","D#", "E", "F", "F#", "G","G#", "A", "A#","B"};
    string semetonesss[12]={"C", "Db", "D","Eb", "E", "F", "Gb", "G", "Ab","A", "Bb", "B"};
    for(int i =0;i<12;i++)
    {
         //   printf("semetone %s",semetone[i]);
            if(strcmp(note0,semetone[i])==0  ||strcmp(note0,semetonesss[i])==0)
            {
               // i=i - 2;
                float freq,freqwe=0;
                //function
                if(man==4)
                {
                    printf("dude");
                }

                if(man<4)
                {
                    freq=440/pow(2.00,(i - 9 )/12.00);
                    freqwe = 440;
                    for(int j=man;j<4;j++)
                    {
                        printf("far from a :%i\n",i);
                        freq = freq/2;
                        freqwe= freqwe-freq;
                    }
                }
                //function
                if(man>4)
                {
                freq=440*pow(2.00,(i - 9 )/12.00);
                    for(int h=man; h>4;h--)
                    {
                        printf("far from A :%i\n",i);
                        freqwe=freqwe+ freq*2;
                    }
                }
                //function
                freqe=round(freqwe);
                printf("MH :%i\n",freqe);
      //          return 0;
            }
    }