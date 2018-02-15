#include <cs50.h>
#include <stdio.h>


int main(void)
{
    bool man=true;
    //char*string = get_string();
    if(man==true)
    {
    char c;
    for(c='a';c<='z';++c)
    {
        char a;
        for(a='a';a<='z';++a)
        {
            char b;
            for(b='a';b<='z';b++)
            {
                char d;
                for(d='a';d<='z';d++)
                {
                    //char man[]={c+a+b+d};

                    char dude[]={c+d,b+d};

                    printf("%s\n",dude);
                    //man=false;
                }
            }


        }

    }
    }
    else
    {
        char c;
    for(c='a';c<='z';++c)
    {
        char a;
        for(a='A';a<='Z';++a)
        {
            char b;
            for(b='A';b<='Z';b++)
            {
                char d;
                for(d='A';d<='Z';d++)
                {
                 //   char man[]={c+a+b+d};
                   // char*dra=man;
                    char dude[]={c+d,b+d};
                   // char*man=dude[c][a][b][d];
                    printf("%s",dude);
                    man=true;
                }
            }


        }
    }


    //printf("%c\n",'65');
}
}
