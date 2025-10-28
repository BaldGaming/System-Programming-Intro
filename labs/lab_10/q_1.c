#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#define RED        "\033[38;2;255;0;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"
#define N 5

typedef struct Item
{
    int code;
    char name[11];
    struct Item* next;
}Item;

int main()
{
    int i;
    Item *Head = NULL, *temp;

    printf(UNDERLINE ITALIC LIGHT_BLUE "Question 1\n\n" R);

    // This loop dinamically allocates N nodes, then it requests and assigns a code and a name to each node.
    // It adds new nodes to the head of the linked list.
    for(i = 1; i <= N; i++)
    {
        temp = (Item*)malloc(sizeof(Item));
        if (temp == NULL)
        {
            printf("\nThere was a " RED "problem" R " with allocating memory.");
            return 1;
        }

        // Requests and assigns said info.
        printf("Enter a new code and name: ");
        while (scanf("%d %s", &temp->code, temp->name) != 2)
        {
            printf(RED "\nERROR:" R " Some of the input might be incorrect.\nTry again: ");
            rewind(stdin);
        }

        // Inserts new nodes to the beggining of the linked list.
        temp->next = Head;
        Head = temp;
    }

    // Resets 'i' to be used as a flag when printing the nodes.
    i = 1;

    // Prints the order of each node's contents from last to first.
    printf("\nThe list is: ");
    temp = Head;
    while(temp != NULL)
    {
        // Prints said content.
        i == N ? printf(GREEN "%d %s" R, temp->code, temp->name)
               : printf(GREEN "%d %s" R " --> ", temp->code, temp->name);
        i++;
        temp = temp->next;
    }

    // This loop frees said nodes.
    while (Head != NULL)
    {
        temp = Head;
        Head = Head->next;
        free(temp);
    }
    return 0;
}