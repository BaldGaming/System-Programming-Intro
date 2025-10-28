#include "header.h"

// This function pushes elements into a stack.
void Push(PStack s, int new_elem)
{
    Item *new_item;

    // Dinamically allocates memory for a new slot.
    new_item = (Item*)malloc(sizeof(Item));
    if (!new_item)
    {
        printf(RED "\nERROR:" R " Memory allocation for 'new_item' failed!");
        free_stack(s);
        exit(1);
    }

    // Pushing algorithm.
    new_item->num = new_elem;
    new_item->next = s->head;
    s->head = new_item;
    s->size++;
}

// This function pops elements from a stack.
int Pop(PStack s, int *del_value)
{
    Item *temp;

    if (s->head == NULL)
    {
        printf("\nThe stack is empty!");
        return 0;
    }

    // Popping algorithm.
    temp = s->head;
    *del_value = temp->num;
    s->head = s->head->next;

    free(temp);

    s->size--;
    return 1;
}

// This function prints an entire stack.
void print_stack(PStack s)
{
    Item* temp = s->head;

    if (!temp)
    {
        printf("Empty\n");
        return;
    }

    while (temp)
    {
        printf("%d", temp->num);
        if (temp->next)
            printf("<-");
        temp = temp->next;
    }

    printf("\n");
}

// This function frees the stack.
void free_stack(PStack s)
{
    Item* temp;

    while (s->head != NULL)
    {
        temp = s->head;
        s->head = temp->next;
        free(temp);
    }

    s->size = 0;
}