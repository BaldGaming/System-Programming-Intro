#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
@File         : temp.c
@Date         : 18:58 24/03/2025
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

// Defines the function Main.
int main()
{
    // These request and assign user value to num.
    printf("Enter number: ");
    int num;
    scanf("%d", &num);

    // These print out a table of following numbers with their power varients up to 3.
    printf("\nNumber   Square   Cube\n");
    printf("%4d %8d %8d\n", num, (int)pow(num, 2), (int)pow(num, 3));
    printf("%4d %8d %8d\n", num + 1, (int)pow(num + 1, 2), (int)pow(num + 1, 3));
    printf("%4d %8d %8d\n", num + 2, (int)pow(num + 2, 2), (int)pow(num + 2, 3));
    printf("%4d %8d %8d\n", num + 3, (int)pow(num + 3, 2), (int)pow(num + 3, 3));
    printf("%4d %8d %8d\n", num + 4, (int)pow(num + 4, 2), (int)pow(num + 4, 3));

    return 0;
}