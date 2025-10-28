#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : q_4.c
@Date         : 19:22 23/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : The program counts unique digits in a given natural number.
*/

int different_digits(int x, int c);

int main()
{
    int num, counter = 0;

    printf("Enter any natural number: ");
    while (1)
    {
        if (scanf("%d", &num) == 1 && num >= 0) break;

        printf("Try again:");
        rewind(stdin);
    }

    printf("The number %d has %d unique numbers.",num ,different_digits(num, counter));

    return 0;
}

int different_digits(int x, int c)
{
    int digits[10] = {0}, digit, i;

    for (i ; x > 0; x /= 10)
    {
        digit = x % 10;
        if (digits[digit] == 0)
        {
            digits[digit] = 1;
            c++;
        }
    }
    return c;
}