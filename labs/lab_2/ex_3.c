#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
@File         : ex_3.c
@Date         : 21:08 24/03/2025
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

// This function solves for 'x' in 'a^x=b'.
int main()
{
    // This requests and assigns user values for 'a' & 'b'.
    printf("Given the equation a^x=b"
           "\nEnter a and b, respectively please:");
    float a,b;
    scanf("%f%f",&a,&b);

    // Solves for 'x' and prints it.
    printf("x is: %g",log(b)/log(a));
    return 0;
}