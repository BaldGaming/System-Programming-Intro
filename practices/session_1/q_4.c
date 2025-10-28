#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>


/*
@File         : q_4.c
@Date         : 13:41 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int main() {
    float a, q;
    int n, i = 0;

    printf("Please enter the first element, ratio and index n in that order: ");
    if (scanf("%f %f %d", &a, &q, &n) != 3)
    {
        printf("FUCK YOU !");
        return 1;
    }

    for (i = 0; i < n; i++)
    {
        printf("%.2f\n", a * pow(q, i));
    }
    return 0;
}