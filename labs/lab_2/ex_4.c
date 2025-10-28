#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
@File         : ex_4.c
@Date         : 21:23 24/03/2025
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

// This function calculates a certain equation based on user value 'x'.
int main()
{
    // These request and assign user value for 'x'.
    printf("Enter x please: ");
    float x;
    scanf("%f", &x);

    // This assigns user value for the solved equation.
    double y = x+pow((1.0/3.0)*pow(x,4)+2*pow(x,0.5),(0.2));

    // These print out the same equation using a different numbering format.
    printf("Output using %%lf format with 2 digits after dot.");
    printf("\n x+(1/3x^3+2x^(1/2))^(1/5) = %.2lf+(1/3*%.2lf^3+2*%.2lf^(1/2))^(1/5) = %.2lf",x,x,x,y);

    printf("\n\nOutput using %%g format: ");
    printf("\n x+(1/3x^3+2x^(1/2))^(1/5) = %g+(1/3*%g^3+2*%g^(1/2))^(1/5) = %g",x,x,x,y);
    return 0;
}