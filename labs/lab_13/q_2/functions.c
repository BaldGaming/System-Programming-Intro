#include "Stack_Header_Array.h"

// This function initializes the stack with a dynamic array of the given size.
void InitStack(PStack s, int size)
{
    int *temp;
    temp = (int*)malloc(sizeof(int) * size);
    if (!temp)
    {
        printf(RED "ERROR:" R " Memory allocation for a new slot failed.");
        return;
    }

    s->Array = temp;
    s->size = size;
    s->top = -1;
    s->count = 0;
}

// This function pushes a new element onto the stack, while updating its structure.
void Push(PStack s, int new_elem)
{
    if (s->count >= s->size)
    {
        printf("\nThe Stack is full\n");
        return;
    }

    // This inserts said element into each slot of the array.
    s->top++;
    s->Array[s->top] = new_elem;
    s->count++;
}

// This function pops the top element from the stack, updates its structure, and returns the value.
int Pop(PStack s, int *del_value)
{
    if (s->count == 0)
    {
        printf("The Stack is empty");
        return 0;
    }

    *del_value = s->Array[s->top];
    s->Array[s->top] = 0;
    s->top--;
    s->count--;

    return 1;
}