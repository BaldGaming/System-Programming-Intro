#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>

/*
@File         : q_3.c
@Date         : 18:29 18/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program reverses and extracts digits from a user-input string, forming a number.
                
*/

int TEMP(char charArr[], int n);

int main()
{
    int n, pass_flag = 1, res;

    // Requests and assigns user value for 'n'.
    printf("Please enter the length of the array: ");

    // This loop makes sure that the user has entered a valid number.
    while (pass_flag == 1)
    {
        rewind(stdin);
        if (scanf("%d", &n) != 1 || n<=0) printf("Please make sure to input a natural number.\n\nTry again: ");
        else pass_flag = 0;
    }

    char charArr[n + 1];

    // Requests and assigns user string into 'charArr[]'.
    printf("Please enter a string to be put into an array: ");
    scanf("%s", charArr);
    strcpy(charArr, charArr);


    // Sends both values to 'TEMP'.
    res = TEMP(charArr, n);

    //These loops print different messages in relation to 'res'.
    if (res == 0)
    {
        printf("\nNo numbers were found in ");
        for (int i = 0; i < n; i++)
            printf("%c", charArr[i]);

        printf("...\n");
        return 0;
    }

    printf("\nThe number that was found in '");
    for (int i = 0; i < n; i++)
        printf("%c", charArr[i]); printf("' (in reversed order)");

    printf(", is: %d\n", res);
    return 0;
}

// This function detects numbers in 'charArr[]' and puts them together in reverse order.
int TEMP(char charArr[], int n)
{
    int i, num = 0;

    // This loop goes in reverse.
    for (i = n-1; i >= 0; i--)
        // Detects numbers and puts then into 'num'.
        if (charArr[i] >= '0' && charArr[i] <= '9') num = num*10 + charArr[i] - '0';

    return num;
}