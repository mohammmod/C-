#include <stdio.h>
#include <cs50.h>

void print();
//int convert_char();

//#define SIZE_OF_NODE sizeof(Node)

typedef struct Node
{
    bool value;
    char next[27];
}
Node;

Node * root = NULL;

int main(void)
{
    if (root == NULL)
    {
        root = malloc(sizeof(char));
    }

    Node * ptr = root;

    for (int i = 0; i < 3; i++)
    {
        //int index = convert_char();
        if (ptr->next[0] == 0 )
        {
            //char A = 'A';
            ptr->next[0]= 'A';
            ptr->next[0] = malloc(sizeof(char));
        }
        ptr = ptr->next[0];
    }

    ptr->value = true;
    print();
}

void print()
{
    Node * ptr = root;

    for (int i = 0; i < 3; i++)
    {
        ptr = ptr->next[0];

    }
    printf("%c\n",ptr->next[0]);
    printf("this value is %d\n", ptr->value);
}
//int convert_char()
//{
    //char a,A;
    //for (a = 'a';a<='z';a++)
    //{
      //  a = a - 97;
    //}
    //for (A = 'A';A<='Z';A++)
    //{
      //  A=A - 65;
    //    return A;
  //  }
//    return A;
  //  return a;

//}
