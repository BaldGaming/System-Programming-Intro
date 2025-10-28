#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


/*
@File         : q_5.c
@Date         : 20:09 23/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int is_num_there(int a[], int n, int num);

int main()
{
    int n, num, i = 0, res;

    printf("How long would you want the array to be?");

    printf("\nEnter any natural number: ");
    while (1)
    {
        if (scanf("%d", &n) == 1 && n >= 0) break;

        printf("Try again: ");
        rewind(stdin);
    }

    int a[n];

    printf("\n");
    for (i ; i < n; )
    {
        printf("Enter a number for slot [%d]: ", i);
        if (scanf("%d", &a[i]) == 0) printf("Wrong input, try again.");
        else i++;
    }

    printf("\nWhich whole number would you like to check? (it may be as long as you'd like): ");
    while (1)
    {
        if (scanf("%d", &num) == 1 && num >= 0) break;

        printf("Try again:");
        rewind(stdin);
    }

    res = is_num_there(a, n, num);
    (res == 1) ? printf("\nYES!!!!")
               : printf("\nNO!!!!");
    return 0;
}

int is_num_there(int a[], int n, int num)
{
    int i, digit;

    for (i = n-1; i >= 0; i--)
    {
        digit = num % 10;

        if (a[i] == digit)
        {
            num /= 10;
        }
    }

    if (num == 0) return 1;
    else return 0;
}