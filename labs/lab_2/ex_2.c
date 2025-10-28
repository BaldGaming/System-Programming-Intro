#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : ex_2.c
@Date         : 20:51 24/03/2025
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

// This function prints the ascii value of 'ch' and it's uppercase varient.
int main()
{
    // These request and assign user value to 'ch'.
    char ch;
    printf("Enter an English  lower case letter, please: ");
    scanf("%c", &ch);

    // This assigns the uppercase version of 'ch'.
    char n_ch = (char)(ch - 32);

    printf("The ascii code of  '%c' is %d",ch, ch);
    printf("\nThe ascii code of  '%c' is %d",n_ch, n_ch);
    return 0;
}