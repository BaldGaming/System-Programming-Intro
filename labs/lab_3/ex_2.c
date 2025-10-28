#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : ex_2.c
@Date         : 19:03 25/03/2025
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

void triangle(char, int);

int main()
{
    // Request and assign user values to 'ch' & 'n'.
    int n;
    char ch;
    printf("Enter a character an integer, please: ");
    scanf("%c %d", &ch, &n);

    // Sends said values to "triangle".
    triangle(ch, n);
    return 0;
}

// This function prints a triangle using 'tav' at 'num' height.
void triangle(char tav, int num)
{
    int k;
    for (; num > 0; num--)
    {
        for (k = num ; k > 0; k--)
        {
            putchar(tav);
        }
        printf("\n");
    }
}