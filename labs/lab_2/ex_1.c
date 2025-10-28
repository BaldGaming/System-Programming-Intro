#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : ex_1.c
@Date         : 20:37 24/03/2025
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

// This function calculates and prints the area of a triangle.
int main()
{
    // These request and assign user values to l & d.
    printf("Enter a triangle edge and it's height respectively, please: ");
    float l,d;
    scanf("%f %f",&l,&d);

    // Prints the area of said triangle.
    printf("\nThe triangle area is %.3f", (l*d)/2);
    return 0;
}