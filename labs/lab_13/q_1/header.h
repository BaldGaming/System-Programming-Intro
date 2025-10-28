#ifndef HEADER_H
#define HEADER_H

#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define RED        "\033[38;2;255;0;0m"
#define YELLOW     "\033[38;2;255;255;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"
#define NUM 5

typedef struct Item
{
    int num;
    struct Item *next;
} Item;

typedef struct Stack
{
    Item *head;
    int size;
} Stack, *PStack;

void Push(PStack s, int new_elem);
int Pop(PStack s, int *del_value);
void print_stack(PStack s);
void free_stack(PStack s);

#endif //HEADER_H