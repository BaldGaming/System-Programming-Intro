#include "header.h"

// This function pushes elements into a queue.
void Enqueue(PQue q, int new_elem)
{
    Item *new_item;

    // Dinamically allocates memory for a new slot.
    new_item = (Item*)malloc(sizeof(Item));
    if (!new_item)
    {
        printf(RED "\nERROR:" R " Memory allocation for 'new_item' failed!");
        free_queue(q);
        exit(1);
    }

    // This initializes the new node.
    new_item->num = new_elem;
    new_item->next = NULL;

    // This inserts a new node at tail if the queue isn't empty.
    if (q->head == NULL)
        q->head = new_item;

    // This links after current tail and updates the tail pointer.
    else
        q->tail->next = new_item;

    q->tail = new_item;
    q->size++;
}

// This function pops elements from a stack.
int Dequeue(PQue q, int *del_value)
{
    Item *temp;

    // This checks for underflow.
    if (q->head == NULL)
    {
        printf(RED "\nERROR:" R " Queue underflow!");
        return 0;
    }

    // This removes the head node, retrieves it's value, and advances head to the next node.
    temp = q->head;
    *del_value = temp->num;
    q->head = q->head->next;

    // Resets tail if the head is empty.
    if (!q->head)
        q->tail = NULL;

    free(temp);
    q->size--;

    return 1;
}

// This function prints an entire queue.
void print_queue(PQue q)
{
    Item *temp = q->head;

    if (!temp)
    {
        printf("Empty\n");
        return;
    }

    while (temp)
    {
        printf("%d", temp->num);
        if (temp->next)
            printf("->");
        temp = temp->next;
    }

    printf("\n");
}

// This function frees the queue.
void free_queue(PQue q)
{
    Item* temp;

    while (q->head != NULL)
    {
        temp = q->head;
        q->head = q->head->next;
        free(temp);
    }

    q->tail = NULL;
    q->size = 0;
}