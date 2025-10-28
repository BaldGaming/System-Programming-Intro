#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>

/*
@File         : ex_0.c
@Date         : 17:46 25/03/2025
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

// This function calculates BMI.
int main()
{
    // Requests and assigns user values for 'w' & 'h' as integers
    printf("Please enter weight (in kg) and height (in cm), respectively: ");
    int w, h;
    double r;
    scanf("%d %d", &w, &h);

    // Convert height from cm to meters and calculate BMI correctly
    r = w / pow(h / 100.0, 2);

    // These print different messages in relation to 'r'.
    if (r < 18.5)
        printf("Underweight\n");
    else if (r < 25)
        printf("Normal weight\n");
    else if (r < 30)
        printf("Increased weight\n");
    else if (r < 40)
        printf("Obese\n");
    else
        printf("Very high obese\n");

    return 0;
}
