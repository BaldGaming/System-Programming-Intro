#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : exercise_2.c
@Date         : 21:12 18/03/2025
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

int main() {
    printf("We are drawing a Triangle:\n");

    for (int i = 0; i < 5; i++) {
        if (i > 0) {
            printf("*");
            for (int j = i -1; j > 0; j--) {
                printf(" ");
            }
        }
        printf("*\n");
    }
    printf("******");
    return 0;
}