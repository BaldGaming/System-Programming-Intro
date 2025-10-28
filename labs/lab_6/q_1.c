// Declarations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#endif

// Constant Definitions
#if 1
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
@File         : q_1.c
@Date         : 19:32 27/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

double *inputArithmetic(double *a1, double *d, int *n);
double setArithmetic(double a1, double d, double *arr, int n);

int main()
{
    double *a1 = NULL, *d = NULL, *arr = NULL;
    int *n = NULL;

    printf(UNDERLINE LIGHT_BLUE "Question 2\n\n" R);

    // Dynamically allocate memory for 'a1', 'd' and 'n'
    a1 = (double*)malloc(sizeof(double));
    d = (double*)malloc(sizeof(double));
    n = (int*)malloc(sizeof(int));

    if (a1 == NULL || d == NULL || n == NULL) {
        printf("Memory allocation failed for a1, d, or n.\n");
        exit(1);
    }

    while (1)
    {
        printf("Enter a1, d, and n respectively, please: ");

        // Stops the program if 'n''s value is lesser or equals 0.
        arr = inputArithmetic(a1, d, n);
        if (arr == NULL)
        {
            printf("Thank you for exploring arithmetic sequences and dynamic allocations of arrays.\n");
            break;
        }

        printf("\nThe " YELLOW "sum" R " of the sequence elements is: " GREEN "%.6f" R, setArithmetic(*a1, *d, arr, *n));
        printf("\n\n");

        // Free memory after use
        free(arr);
    }

    // Free a1, d, and n
    free(a1); free(d); free(n);

    return 0;
}


double *inputArithmetic(double *a1, double *d, int *n)
{
    double *arr = NULL;

    // Request and assign user input into pointers.
    while (1)
    {
        if (scanf("%lf %lf %d", a1, d, n) == 3) break;
        rewind(stdin);
        printf("\nSomething went wrong.. Try again: ");
    }

    // Free memory if 'n''s value is lesser or equal to 0.
    if (*n <= 0) return NULL;

    // Dynamically allocates memory for 'arr'.
    arr = (double*)malloc(*n * sizeof(double));
    if (arr == NULL)
    {
        printf("\nMemory allocation for 'arr' failed.");
        exit(2);
    }

    return arr;
}

double setArithmetic(double a1, double d, double *arr, int n)
{
    int i;
    double sum = 0;

    printf("\n");

    // This loop prints and sums of all the numbers in the sequence.
    for (i = 0; i < n; i++)
    {
        arr[i] = a1 + i * d;
        sum += arr[i];
        printf("%11.6f", arr[i]);
        // Prints a new line after every 5 numbers except at the end.
        if ((i + 1) % 5 == 0 && i < n - 1) printf("\n");
    }
    return sum;
}