// Declarations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#endif

// Constant Definitions
#if 1
#define NUMELEMS 7
#endif

// Text formatting
#if 1
#define BOLD "\033[1m"
#define ITALIC "\033[3m"
#define UNDERLINE "\033[4m"
#endif

// Colors
#if 1
#define RED "\033[38;2;255;0;0m"
#define GREEN "\033[38;2;0;255;0m"
#define BLUE "\033[38;2;0;0;255m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define YELLOW "\033[38;2;255;255;0m"
#define PURPLE "\033[38;2;128;0;128m"
#endif

// Text format reset
#define R "\033[0m"
#endif

/*
@File         : q_3.c
@Date         : 8:55 29/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program returns the lexicographically smallest element in any given array.
*/


char* findMin(char** arrP,int arrSize);

int main()
{
    char *a[] = {"Amos","Nir","Alona","Yosef","alice","Amina","bob"};
    int i;

    printf(UNDERLINE LIGHT_BLUE "Question 4\n\n" R);

    for(i=0; i<NUMELEMS; i++)
        printf("%s\n", a[i]);
    printf(GREEN "\n%s\n" R, findMin(a, NUMELEMS));

    return 0;
}

// This function finds the lexicographically smallest element in any 'NUMELEMS' sized array.
char* findMin(char** arrP,int arrSize)
{
    char *min = arrP[0];
    int i;

    // This loop uses "strcmp" to evaluate the current smallest element against the rest of the array.
    for (i = 1; i < arrSize; i++)
    {
        if (strcmp(arrP[i], min) < 0)
        {
            min = arrP[i];
        }
    }
    return min;
}