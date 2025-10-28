#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : ex_0.c
@Date         : 17:01 31/03/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program can find the midpoint of a line given two endpoints.
*/


// This function calculates said midpoint.
void Set_Mid(double x1, double y1, double x2, double y2, double *p_mx, double *p_my);


int main()
{
    // Instructions.
    printf("This program can find the midpoint of a line given two endpoints.\n"
           "Please enter coordinates for (x1, y1) and (x2, y2).\n");

    // These request and assign user values for the two endpoints.
    double x1, y1, x2, y2, p_mx, p_my;

    printf("\n(x1, y1): ");
    if (scanf("%lf %lf", &x1, &y1) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    printf("(x2, y2): ");
    if (scanf("%lf %lf", &x2, &y2) != 2)
    {
        printf("Invalid input.\n");
        return 1;
    }

    // Sends said points to "Set_Mid" for calculations and memory allocation.
    Set_Mid(x1, y1, x2, y2, &p_mx, &p_my);
    printf("\nThe midpoint is: (%g, %g).\n", p_mx, p_my);

    return 0;
}

// This function calculates said midpoint.
void Set_Mid(double x1, double y1, double x2, double y2, double *p_mx, double *p_my)
{
    // Pointer to p_mx & p_my that change their values.
    *p_mx = (x1 + x2) / 2;
    *p_my = (y1 + y2) / 2;
}