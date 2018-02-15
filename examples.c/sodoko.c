#include <stdio.h>

#include <cs50.h>



bool isNotSolvedYet();



int ** initialiseTempAarray();

int ** findtheArray(size_t row, size_t column);

void freeTempArray(int ** arrayToBeFreed);



bool findNumberInArray(int num, int ** arr);

bool checkNumInRow (int row , int num);

bool checkNumInColumn (int column , int num);



void finishThisRow(int row);

void finishThisColumn(int column);

void finishThisBox(int numOfBox);



void useUrBrainForThisOne(int row, int column);



void printall();



int mainArray[9][9] =

{

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    /*================================*/

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    /*================================*/

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

    {0, 0, 0,/**/ 0, 0, 0,/**/ 0, 0, 0} ,

};



int main(void)

{

    while (isNotSolvedYet())

    {

        for (int i = 0; i < 9; i++)

        {

            finishThisRow(i);

            finishThisColumn(i);

            finishThisBox(i);

            for (int j = 0; j < 9; j++)

            {

                if (mainArray[i][j] == 0)

                {

                    useUrBrainForThisOne(i, j);

                }

            }

        }

    }

    printall();

}



bool isNotSolvedYet()

{

    for (int i = 0; i < 9; i++)

    {

        for (int j = 0; j < 9; j++)

        {

            if(mainArray[i][j] == 0)

            {

                return true;

            }

        }

    }

    return false;

}



bool findNumberInArray(int num, int ** arr)

{

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            if(arr[i][j] == num)

            {

                return true;

            }

        }

    }

    return false;

}



int ** initialiseTempAarray()

{

    int ** array = malloc(3 * sizeof(int *));

    for (int i = 0; i < 3; i++)

    {

        array[i] = malloc(3 * sizeof(int));

    }

    return array;

}



int ** findtheArray(size_t row, size_t column)

{

    int ** array = initialiseTempAarray();

    int adjustingVariableForRow = 0;

    int adjustingVariableForColumn = 0;

    switch (row)

    {

        case 3 ... 5:

            adjustingVariableForRow = 3;

            break;

        case 6 ... 8:

            adjustingVariableForRow = 6;

            break;

        default:

            break;

    }

    switch (column)

    {

        case 3 ... 5:

            adjustingVariableForColumn = 3;

            break;

        case 6 ... 8:

            adjustingVariableForColumn = 6;

            break;

        default:

            break;

    }

    for (int i = 0; i < 3; i++)

    {

        for (int j = 0; j < 3; j++)

        {

            array[i][j] = mainArray[adjustingVariableForRow+i][adjustingVariableForColumn+j];

        }

    }

    return array;

}



void freeTempArray(int ** arrayToBeFreed)

{

    for (int i = 0; i < 3; ++i)

    {

        free(arrayToBeFreed[i]);

    }

    free(arrayToBeFreed);

}



void printall()

{

    for (int row = 0; row <= 8; row++)

    {

        if (row % 3 == 0)

        {

            printf(" ==================================\n");

        }

        for (int column = 0; column <= 8; column++)

        {

            if (column % 3 == 0)

            {

                printf(" || %i", mainArray[row][column]);

            }

            else

            {

                if (column == 8)

                {

                    printf("  %i||", mainArray[row][column]);

                }

                else

                {

                    printf("  %i", mainArray[row][column]);

                }

            }

        }

        printf("\n");

        if (row == 8)

        {

            printf(" ==================================\n");

        }

    }

}



void finishThisRow(int row)

{

    bool onlyOnePossibility = false;

    int columnOfThisOnePossibility = -1;

    for (int currentColumn = 0; currentColumn < 9; currentColumn++)

    {

        if (mainArray[row][currentColumn] == 0)

        {

            if (columnOfThisOnePossibility == -1)

            {

                onlyOnePossibility = true;

                columnOfThisOnePossibility = currentColumn;

            }

            else

            {

                onlyOnePossibility = false;

                break;

            }

        }

    }

    if (onlyOnePossibility)

    {

        int numberToBeSet = 45;

        for (int column = 0; column < 9; column++)

        {

            numberToBeSet -= mainArray[row][column];

        }

        mainArray[row][columnOfThisOnePossibility] = numberToBeSet;

    }

}



void finishThisColumn(int column)

{

    bool onlyOnePossibility = false;

    int rowOfThisOnePossibility = -1;

    for (int currentRow = 0; currentRow < 9; currentRow++)

    {

        if (mainArray[currentRow][column] == 0)

        {

            if (rowOfThisOnePossibility == -1)

            {

                onlyOnePossibility = true;

                rowOfThisOnePossibility = currentRow;

            }

            else

            {

                onlyOnePossibility = false;

                break;

            }

        }

    }

    if (onlyOnePossibility)

    {

        int numberToBeSet = 45;

        for (int row = 0; row < 9; row++)

        {

            numberToBeSet -= mainArray[row][column];

        }

        mainArray[rowOfThisOnePossibility][column] = numberToBeSet;

    }

}



void finishThisBox(int numOfBox)

{

    int adjustingVariableForColumn = 0;

    int adjustingVariableForRow = 0;

    switch (numOfBox)

    {

        case 1:

            adjustingVariableForColumn = 3;

            adjustingVariableForRow = 0;

            break;

        case 2:

            adjustingVariableForColumn = 6;

            adjustingVariableForRow = 0;

            break;

        case 3:

            adjustingVariableForColumn = 0;

            adjustingVariableForRow = 3;

            break;

        case 4:

            adjustingVariableForColumn = 3;

            adjustingVariableForRow = 3;

            break;

        case 5:

            adjustingVariableForColumn = 6;

            adjustingVariableForRow = 3;

            break;

        case 6:

            adjustingVariableForColumn = 0;

            adjustingVariableForRow = 6;

            break;

        case 7:

            adjustingVariableForColumn = 3;

            adjustingVariableForRow = 6;

            break;

        case 8:

            adjustingVariableForColumn = 6;

            adjustingVariableForRow = 6;

            break;

        default:

            break;

    }



    int ** findMeThisArr = findtheArray(adjustingVariableForRow, adjustingVariableForColumn);



    bool onlyOnePossibility = false;

    int locationThisOnePossibility[2] = { -1, -1 };

    for (int row = 0; row < 3; row++)

    {

        if (!onlyOnePossibility && locationThisOnePossibility[0] != -1)

        {

            break;

        }

        for (int column = 0; column < 3; column++)

        {

            if (findMeThisArr[row][column] == 0)

            {

                if (locationThisOnePossibility[0] == -1 && locationThisOnePossibility[1] == -1)

                {

                    onlyOnePossibility = true;

                    locationThisOnePossibility[0] = row;

                    locationThisOnePossibility[1] = column;

                }

                else

                {

                    onlyOnePossibility = false;

                    break;

                }

            }

        }

    }

    if (onlyOnePossibility)

    {

        int numberToBeSet = 45;

        for (int row = 0; row < 3; row++)

        {

            for (int column = 0 ; column < 3; column++)

            {

                numberToBeSet -= findMeThisArr[row][column];

            }

        }

        mainArray[locationThisOnePossibility[0] + adjustingVariableForRow][locationThisOnePossibility[1] + adjustingVariableForColumn] = numberToBeSet;

    }

    freeTempArray(findMeThisArr);

}



void useUrBrainForThisOne(int row, int column)

{

    bool numbersThatExist[9] = { false, false, false, false, false, false, false, false, false };

    int ** thisArray = findtheArray(row, column);

    for (int numberToCheck = 1; numberToCheck <= 9; numberToCheck++)

    {

        if (checkNumInRow(row, numberToCheck) || checkNumInColumn(column, numberToCheck) || findNumberInArray(numberToCheck, thisArray))

        {

            numbersThatExist[numberToCheck-1] = true;

        }

    }

    freeTempArray(thisArray);

    int numberOfPossibilities = 0;

    for (int x = 0; x < 9; x++)

    {

        if(!numbersThatExist[x])

        {

            numberOfPossibilities++;

        }

    }

    if (numberOfPossibilities == 1)

    {

        for (int x = 0; x < 9; x++)

        {

            if(!numbersThatExist[x])

            {

                mainArray[row][column] = x + 1;

                break;

            }

        }

    }

}



bool checkNumInRow (int row , int num)

{

    for (int i = 0; i < 9; i++)

    {

        if(mainArray[row][i] == num)

        {

            return true;

        }

    }

    return false;

}



bool checkNumInColumn (int column , int num)

{

    for (int i = 0; i < 9; i++)

    {

        if(mainArray[i][column] == num)

        {

            return true;

        }

    }

    return false;

}



