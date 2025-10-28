#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>

/*
@File         : q_2.c
@Date         : 20:40 25/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :

*/

int* reversed_str(int* str, int len);

int main()
{
    int* user_str;
    int n, i;

    printf("This program prints any given string in reverse.");

    // Requests and assigns user value to the length of 'user_str'.
    printf("\nHow long would you like your string to be?: ");
    while (1)
    {
        if (scanf("%d", &n) == 1 && n > 2) break; rewind(stdin);
        printf("\nSomething went wrong..\nTry again: ");
    }

    // Allocates memory to 'user_str'.
    user_str = (int*)malloc(n * sizeof(int));
    if (!user_str)
    {
        printf("\n! MEMORY ALLOCATION FAILED !");
        exit(1);
    }

    // Populates the array with user input.
    printf("Please enter %d integers: ", n);
    for (i = 0; i < n; i++) {
        if (scanf("%d", &user_str[i]) != 1) {
            printf("\nInvalid input. Exiting.\n");
            free(user_str);
            exit(1);
        }
    }

    int* result = reversed_str(user_str, n);

    printf("The array [");
    for (i = 0; i < n; i++) {
        printf("%d%s", user_str[i], (i == n - 1) ? "" : ", ");
    }
    printf("] in reverse is [");
    for (i = 0; i < n; i++) {
        printf("%d%s", result[i], (i == n - 1) ? "" : ", ");
    }
    printf("]\n");

    // Free allocated memory.
    free(user_str);
    free(result);

    return 0;
}

int* reversed_str(int* str, int len)
{
    int i;
    int* new_str = (int*)malloc((len) * sizeof(int));

    if (!new_str)
    {
        printf("\n! MEMORY ALLOCATION FAILED !");
        exit(1);
    }

    for (i = 0; i < len; i++)
    {
        new_str[len-i-1] = str[i];
    }
    return new_str;
}