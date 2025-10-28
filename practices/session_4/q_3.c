// Declerations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#endif

// Constant Definitions
#define MAX 21

// Text formatting
#if 1
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#endif

// Colors
#if 1
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define BLUE "\033[38;2;0;0;255m"
#define YELLOW "\033[38;2;255;255;0m"
#define PURPLE "\033[38;2;128;0;128m"
#endif

// Text format reset
#define R "\033[0m"
#endif

/*
@File         : q_3.c
@Date         : 16:41 26/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :

*/

char* char_remover(char* a, char c);

int main()
{

    char input[MAX];
    char* whole_arr;
    char* result;
    int input_len, whole_len = 0, ch;

    // Instructions.
    printf("This program can " RED "remove" R " any given character from strings you combine."
                  "\nFor example, if you type 'Fruit', '" YELLOW "a" R "pple', 'm" YELLOW "a" R "rio' and the character '" YELLOW "a" R "', it will print 'Fruitpplemrio'."
                  "\nEach string may only be 20 characters long (type 'stop' to quit).\n");

    // This loop requests strings and populates an array with them.
    while (1)
    {
        // Requests and assigns string.
        printf("\nEnter a string: ");
        fgets(input, MAX, stdin);
        rewind(stdin);

        // This ends the loop.
        if (strcmp(input, "stop\n") == 0) break;

        input_len = strlen(input);
        if (input[input_len - 1] == '\n') input[input_len - 1] = '\0';

        // Reallocates aditional space for the next input.
        char* temp = (char*)realloc(whole_arr, (whole_len + input_len + 1) * sizeof(char));
        if (temp == NULL)
        {
            free(whole_arr);
            printf("Memory allocation failed!\n");
            exit(69);
        }
        whole_arr = temp;

        // Concatenate the new input and updates the length of 'whole_len'.
        // Uses "strcpy" if it's the first input.
        if (whole_len == 0)
            strcpy(whole_arr, input);
        else
            strcat(whole_arr, input);
        whole_len += input_len;

        printf("Current array: %s\n", whole_arr);
    }

    printf("\nCool beans, now type a single character you'd like to delete: ");
    ch = getchar();

    result = char_remover(whole_arr, ch);

    printf("\nYour brand spanking new string after " RED "deleting" R " " YELLOW "%c" R " is: %s",ch, result);

    // Dumpster.
    free(whole_arr);
    free(result);
    return 0;
}

// This function dynamically rebuilds 'whole_arr' without 'ch'.
char* char_remover(char* a, char c)
{
    int i, j = 0, len = strlen(a);
    char* new_arr = (char*)malloc(len + 1);
    if (new_arr == NULL)
    {
        printf("Memory allocation failed!\n");
        exit(420);
    }

    // This loop copies over every character except for 'ch'.
    for (i = 0; i < len; i++)
    {
        if (a[i] != c)
        {
            new_arr[j] = a[i];
            j++;
        }
    }

    // Adds '\0' and returns the new array.
    new_arr[j] = '\0';
    return new_arr;
}