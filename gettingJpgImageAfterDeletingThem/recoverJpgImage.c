#include <cs50.h>
#include <stdio.h>
#include <string.h>


#define BLOCK_SIZE 512

void check_if_invaled(int files_number);
void recover_photos(FILE * filename);
FILE* WritePic(bool closeFile,int counter,unsigned char BYTESNumber[],FILE * filename);

    //my comments for today shere it with friends if u like it  .
int main (int files_number,char* file_name[])
{
    check_if_invaled(files_number);
    FILE * filename = fopen(file_name[1],"r");
    //photos_recover.
    recover_photos(filename);
}

void check_if_invaled(int files_number)
{
    if(files_number!=2)
    {
       fprintf(stderr, "./recover filename\n");
       exit(1);
    }
}

void recover_photos(FILE * filename)
{
    bool closeFile =false;
    int counter =0;
    unsigned char BYTESNumber[BLOCK_SIZE];
    //write pic
    FILE*outfile = WritePic(closeFile,counter,BYTESNumber,filename);
    fclose (outfile);
    fclose (filename);
}

FILE* WritePic (bool closeFile,int counter,unsigned char BYTESNumber[],FILE * filename)
{
    FILE*outFile;
    char picname [8] ;
    //read untile the end of the pic .
    while(fread(BYTESNumber, BLOCK_SIZE, 1, filename)> 0)
    {
        //look at the first header .
        if(BYTESNumber[0] == 0Xff&& BYTESNumber[1]==0xd8 &&BYTESNumber[2]==0xff&&(BYTESNumber[3]& 0xf0)== 0xe0)
        {
            if (closeFile)
            {
                fclose(outFile);
            }
            else
            {
                closeFile = true;
            }
            sprintf(picname, "%03i.jpg", counter);
            outFile = fopen(picname,"w");
            counter++;
        }
        if(closeFile)
        {
            fwrite(BYTESNumber, BLOCK_SIZE , 1 ,outFile);
        }
    }
    return outFile;
}
