#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define YELLOW     "\033[38;2;255;255;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"

typedef struct Item
{
    int num;
    struct Item* next;
} Item;

typedef struct List
{
    Item *head;
    Item *tail;
    int count;
} List;

void Error_Msg(char*);
void AddAsFirst(Item* ,List* );
void AddAsLast(Item* ,List* );
void MoveToAnotherList(List* ,List* ,List* );
void CreateList(List* ,FILE *);
void PrintItem(Item* );
void PrintList(List* ,char*);
void DeleteList(List*);

int main()
{
    List L, Posit, Negat;
    FILE *in = fopen("ThreeLists.txt","rt");

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 1\n" R);

    if (in == NULL)
        Error_Msg("input file is wrong");
    L.head = NULL;
    L.tail = NULL;
    L.count = 0;

    Posit.head = NULL;
    Posit.tail = NULL;
    Posit.count = 0;

    Negat.head = NULL;
    Negat.tail = NULL;
    Negat.count = 0;

    CreateList(&L,in);
    PrintList(&L,"\nMy List:\n");
    MoveToAnotherList(&L,&Posit,&Negat);
    PrintList(&Posit,"\n\nThe Positive List:\n");
    PrintList(&Negat,"\n\nThe Negative List:\n");

    fclose(in);
    DeleteList(&Posit);
    DeleteList(&Negat);
    return 0;
}

void Error_Msg(char* msg)
{
    printf("\n%s", msg);
    exit(1);
}

void CreateList(List* L, FILE *f)
{
    int value;
    Item *temp;
    while(fscanf(f, "%d", &value) ==1)
    {
        temp = (Item*)malloc(sizeof(struct Item));
        if (temp == NULL)
        {
            DeleteList(L);
            Error_Msg("Memory!");
        }

        temp->num = value;
        temp->next = NULL;
        if (L->head == NULL)
            L->head = temp;
        else
            L->tail->next = temp;
        L->tail = temp;
        L->count++;
    }
}

void AddAsFirst(Item* new_node, List* List)
{
    // Points 'new_node' to the current head, and updates the head to 'new_node'.
    new_node->next = List->head;
    List->head = new_node;

    // This sets a tail to 'new_node' is the list is empty.
    if (List->tail == NULL)
        List->tail = new_node;

    // Increment the count of nodes in the list.
    List->count++;
}

void AddAsLast(Item* new_node, List* List)
{
    new_node->next = NULL;

    // Handles a scenario where the list is void of nodes.
    if (List->head == NULL)
        List->head = new_node;

    // Appends 'new_node' to the end of the list.
    else
        List->tail->next = new_node;

    // Updates the tail and increases the count of nodes in the list.
    List->tail = new_node;
    List->count++;
}

void MoveToAnotherList(List* Origin, List* Posit ,List* Negat)
{
    Item *temp;

    while (Origin->head != NULL)
    {
        temp = Origin->head;
        Origin->head = Origin->head->next;
        
        if (temp->num >= 0)
            AddAsLast(temp, Posit);
        else
            AddAsFirst(temp, Negat);

        Origin->count--;
    }
    Origin->tail = NULL;
}

void PrintItem(Item* node)
{
    if (node->next != NULL)
        printf(GREEN "%d" R " --> ", node->num);
    else
        printf(GREEN "%d" R, node->num);
}

void PrintList(List* L, char* title)
{
    Item* temp = L->head;
    printf("%s", title);
    while (temp)
    {
        PrintItem(temp);
        temp = temp->next;
    }
    printf("\nThere are " YELLOW "%d" R " items in the list", L->count);
}

void DeleteList(List *List)
{
    Item* temp;

    while (List->head != NULL)
    {
        temp = List->head;
        List->head = List->head->next;
        free(temp);
    }

    // Resets the rest of the pointers.
    List->tail = NULL;
    List->count = 0;
}