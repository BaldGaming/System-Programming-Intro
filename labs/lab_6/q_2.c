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
@File         : q_2.c
@Date         : 8:16 29/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

void set_2d(float** a, int m, int n);
void print_2d(float** a, int m, int n);

int main()
{
    int m, n, i;
    float** a;

    printf(UNDERLINE LIGHT_BLUE "Question 3\n" R);

    printf("\nenter m and n, for m*n array: \n");
    if (scanf("%d %d", &m, &n) != 2)
    {
        printf("\nInvalid input."); return 1;
    }

    // This dynamically allocates memory for 'm' pointers of size float.
    a = (float**)malloc(m * sizeof(float*));
    if (a == NULL)
    {
        printf("\nMemory allocation pointers failed.\n");
        exit (1);
    }

    // This dynamically allocates memory for 'n' columns (of size float) for 'm' rows.
    for (i = 0;i < m;i++)
    {
        a[i] = (float*)malloc(sizeof(float) * n);

        // If there is not enough memory
        if (a[i] == NULL)
        {
            printf("\nMemory allocation within the matrix failed.\n");
            for (i = 0; i < m;i++)
              free(a[i]);

            free(a);
            exit(2);
        }
    }

    // These send said variables for matrix population and prints the result.
    set_2d(a,m,n);
    print_2d(a,m,n);

    // Memory dumpster.
    for (i = 0; i < m; i++)
        free(a[i]);
    free(a);

    return 0;
}

// This function populates matrix 'a' with sequential natural numbers.
void set_2d(float **a, int m, int n)
{
    int i, j, k = 1;

    for (i = 0; i < m; i++)
        for (j = 0; j < n; j++)
            a[i][j] = k++;
}

// This function prints said matrix.
void print_2d(float** a, int m, int n)
{
    int i, j;

    for (i = 0; i < m; i++)
    {
        for (j = 0; j < n; j++)
            printf(GREEN "  %5.1f" R, a[i][j]);
        printf("\n");
    }
}