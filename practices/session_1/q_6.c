#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
@File         : q_6.c
@Date         : 13:56 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int main()
{
    int a, b, a_temp, b_temp;
    int count = 0;

    printf("Please enter two whole numbers: ");
    if (scanf("%d%d", &a, &b) != 2)
    {
        printf("Enter correct numbers, dumbass.");
        return 1;
    }

    a_temp = a;
    b_temp = b;

    while (a_temp != 0 && b_temp != 0)
    {
        if (a_temp%10 == b_temp%10)
            count++;

        a_temp = a_temp/10;
        b_temp = b_temp/10;
    }

    printf("Both %d and %d share %d matching number(s).", a, b, count);
    return 0;
}