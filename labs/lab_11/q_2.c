#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define YELLOW     "\033[38;2;255;255;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"
#define N 5

typedef struct Item
{
    int num;
    struct Item* next;
} *PItem;

void Error_Msg(char*);
void CreateListFromArray(PItem*,PItem*,int *);
void DeleteList(PItem *);
void ListDisplay(PItem );
int ListLength(PItem);

int main()
{
    int Arr[N] = {3,4,1,0,8};
    PItem list = NULL, tail = NULL;

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 2\n\n" R);

    CreateListFromArray(&list,&tail,Arr);
    printf("The length of the list is " YELLOW "%d" R " members\n",ListLength(list));
    printf("\nThe list is:\n");
    ListDisplay(list);

    DeleteList(&list);
    tail = NULL;
    return 0;
}

void Error_Msg(char*msg)
{
    printf("\n%s",msg);
    exit(1);
}

void CreateListFromArray(PItem* head,PItem* tail,int *Arr)
{
    int i;
    PItem temp;
    for(i = 0; i < N; i++)
    {
        temp=(PItem)malloc(sizeof(struct Item));
        if(temp == NULL)
        {
            DeleteList(head);
            Error_Msg("Memmory!");
        }

        temp->num = Arr[i];
        temp->next = NULL;
        if(*head == NULL)
            *head = temp;
        else
            (*tail)->next = temp;
        *tail = temp;
    }
}

void DeleteList(PItem *head)
{
    PItem tmp = *head;
    while(*head)
    {
        tmp=*head;
        *head=(*head)->next;
        free(tmp);
    }
}

int ListLength(PItem q)
{
    if (q != NULL)
        return 1 + ListLength(q->next);
    return 0;
}

void ListDisplay(PItem q)
{
    if (q != NULL)
    {
        if (q->next != NULL)
        {
            printf(GREEN "%d" R " --> ", q->num);
            ListDisplay(q->next);
        }
        else
        {
            printf(GREEN "%d" R, q->num);
            ListDisplay(q->next);
        }
    }
}