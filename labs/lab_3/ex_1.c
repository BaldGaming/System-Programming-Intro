#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
@File         : ex_1.c
@Date         : 18:24 25/03/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
Function name: 
Input(s): 
Output(s): 
Sent Value(s): 
Recieved Value(s): 
Return Value(s): 
Description: 
*/

int main()
{
    int i, num, res, count = 0;
    // Assigns user values to 'num', while defining 'i', 'count' & 'res'.
    printf("Enter an integer number, please: ");
    scanf("%d", &num);
    res = abs(num);

    // This checks for an edge case where 'num' equate to 0.
    if (num == 0)
    {
        printf("Infinity");
        return 0;
    }

    // This loop prints all of 'num''s dividers while counting them.
    for (i = 1; i < res; i++)
    {
        if ((res % i) == 0)
        {
            count++;
            printf("%d ", i);
        }

    }

    // This handles a negative 'num'.
    if (num < 0)
    {
        count++;
        printf("%d", res);
    }

    printf("\ncount=%d", count);
    return 0;
}