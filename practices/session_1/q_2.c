#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
@File         : q_2.c
@Date         : 12:48 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int main()
{
    float grade_sum= 0, temp = 0, res = 0;
    int sum = 0;

    printf("To end the program, type 999."
                 "\nPlease enter the grades: ");

    while (temp != 999)
    {
        if (scanf("%f", &temp) != 1)
            printf("Invalid grade number.");

        if (temp == 999)
            break;

        grade_sum = grade_sum + temp;
        sum++;
    }

    res = grade_sum / sum;
    printf("The average score is: %.2g",res);

    return 0;
}