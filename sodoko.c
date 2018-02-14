#include <cs50.h>
#include <stdio.h>
#include <locale.h>


bool is_solve();
bool move_Where_You_Want(char moving);
bool check_if_invaled(char moving);
char get_place();
bool check_place_if_in(char place);
bool check_if_moving(char moving,int user);


//:( sad music.
int mainArray[9][9] =
{
    {6, 2, 7,/**/ 1, 5, 4,/**/ 3, 9, 6} ,
    {9, 6, 5,/**/ 3, 2, 7,/**/ 1, 4, 8} ,
    {3, 4, 1,/**/ 6, 8, 9,/**/ 7, 5, 2} ,
    /*================================*/
    {5, 9, 3,/**/ 4, 6, 8,/**/ 2, 7, 1} ,
    {4, 7, 2,/**/ 5, 1, 3,/**/ 6, 8, 9} ,
    {6, 1, 8,/**/ 9, 7, 2,/**/ 4, 3, 5} ,
    /*================================*/
    {7, 8, 6,/**/ 2, 3, 5,/**/ 9, 1, 4} ,
    {1, 5, 4,/**/ 7, 9, 6,/**/ 8, 2, 3} ,
    {2, 3, 9,/**/ 8, 4, 1,/**/ 5, 6, 7} ,
};

int main(void)
{

    printf("a for left. \n");
    printf("s for down. \n");
    printf("d for right. \n");
    printf("w for up. \n");
    printf("x for accepting \n\n");

    bool hand = true;
    while(hand)
    {
        hand = is_solve();
        if(hand)
        {
            printf("still not solve. \n\n\n");
        }
        for(int height = 0;height<9;height++)
        {
            for(int width = 0;width<9;width++)
            {
                if(width== 3 || width ==6)
                {
                    printf(" ");
                }
                printf("|%i|",mainArray[height][width]);
            }
            if(height == 2 || height ==5)
            {
                for(int line  = 0;line<29;line++)
                {
                    if(line<1)
                    {
                        printf("\n");
                    }
                    printf("=");
                }
            }
            printf("\n");
        }
        if(hand)
        {
            char moving = get_place();
            move_Where_You_Want(moving);
        }

    }
}
////
bool move_Where_You_Want(char moving)
{
    int user = 0;
    do
    {
        user = get_int("\nNumber: ");

    }while(user>9||-1>user);
    if(moving)
    {
        check_if_moving(moving , user);
        return false;
    }
    if(moving == 'x')
    {
        return true;
    }
    return true;

}

bool is_solve()
{
    int check = 0;
    for(int height = 0 ;height <9;height++)
    {
        for(int width = 0;width<9;width++)
        {
            check = check + mainArray[height][width];
            if(check == 405)
            {
                setlocale(LC_ALL, "");
                wchar_t win = (int)0x1F389;
                printf("\n\n %lc CONGRATULATION YOU WIN %lc \n\n",win,win);
                return false;
            }
        }
    }
    return true;
}
bool check_if_invaled(char moving)
{
    return (moving == 'a' ||moving == 's'||moving=='d'||moving== 'w');
}
///
char get_place()
{

    char place = get_char("moveit: ");;
    bool hand = true;
    while(hand)
    {

        place = get_char("moveit: ");
        move_Where_You_Want(place);
        if(place == 'x')
        {
            hand = false;
        }
        else
        {
            return printf("invlad movment\n");
        }
    }
    return place;
}

bool check_place_if_in(char place)
{

    if(check_if_invaled(place))
    {
        return true;
    }
    return true;
}

bool check_if_moving(char moving,int user)
{
    int number = 0;
    int number2  =0;
    mainArray[0][0] = user;
    while (true)
    {
        if(moving == 'w')
        {
            mainArray [number - 1][number2] = user;
            printf("|%i|",mainArray [number - 1][number2]);
            return true;
        }
        if(moving == 's')
        {
             mainArray [number + 1][number2] = user;
             printf("|%i|",mainArray [number + 1][number2]);
             return true;
        }
        if(moving == 'a')
        {
            mainArray[number2][number - 1] = user;
            printf("|%i|",mainArray[number2][number - 1]);
            return true;
        }
        if(moving == 'd')
        {
             mainArray [number2][number + 1] = user;
             printf("|%i|",mainArray [number2][number + 1]);
            return true;
        }
        else
        {
            return false;
        }
    }
    return true;
}
