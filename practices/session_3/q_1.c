#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h> - 
#include <string.h> -
#include <stdlib.h> -
#include <math.h> -
#include <time.h> -

/*
@File         : q_1.c
@Date         : 17:08 24/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program swaps characters in any given string such that
                their reordered by occurences. for example, bakbbkxabm -> bbbaakkmx
*/

void reoder_by_amount(char *str);

int main()
{
    int n;
    // Instructions.
    printf("This program swaps characters in any given string such that"
                  "\ntheir reordered by occurences. for example, bakbbkxabm -> bbbaakkmx");

    // Requests and assigns 'n' that will act as the lenght of 'user_str'.
    printf("\n\nHow long would you want the string to be?: ");
    while (1)
    {
        if (scanf("%d", &n) == 1 && n > 0) break;

        printf("Try again: ");
    }
    char user_str[n+1];
    getchar();

    // Requests and assigns a string to 'user_str'.
    printf("\nPlease type any string that's atleast %d long,"
                  "\nand that contains atleast 2 capital lettrs: ",n);
    fgets(user_str, n+1, stdin);
    rewind(stdin);

    reoder_by_amount(user_str);
    return 0;
}

void reoder_by_amount(char *str)
{
    int a[26] = {0};
    int i = 0;

    for (i; str[i] != '\0'; i++)
        a[str[i] - 97]++, counter++;

    char *p = a[0];

    for (i = 0; i < counter; i++, *p++)
    {
        while (&p != 0)
        {
            printf("%c",*p);
        }
    }
}