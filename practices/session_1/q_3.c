#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : q_3.c
@Date         : 13:30 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int main()
{
    float l, h, a = 0;

    printf("Enter the lenght and height of the triangle, in that order: ");

    if (scanf("%f %f", &l, &h) != 2)
    {
        printf("Stinky!"
                     "\nTry again.");
        return 1;
    }

    a = (l * h)/2;
    printf("The area of the triangle is: %.3f",a);

    return 0;
}