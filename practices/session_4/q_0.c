#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

#define N 4
#define COLOR_S "\033[38;2;0;255;50m"
#define COLOR_E "\033[0m"

/*
@File         : q_0.c
@Date         : 17:23 25/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/

int matrix_check(int a[][N], int n);

int main()
{
    int i, j;
    int matrix[N][N];

    printf("This program can detect if any given matrix is a \033[1;33mLatin Square.\033[0m\n\n");

    // These populate the matrix.
    for (i = 0; i < N; i++)
    {
        printf("Enter %d elements for row number %d: ", N, i+1);
        for (j = 0; j < N; j++)
        {
            if (scanf("%d", &matrix[i][j]) != 1)
            {
                printf("Make sure to input natural numbers.");
                exit (1);
            }
        }
    }

    // These print the matrix.
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < N; j++)
        {
            if (j == 0) printf(COLOR_S "[%2d" COLOR_E, matrix[i][j]);
            if (j != 0) printf(COLOR_S "%2d" COLOR_E, matrix[i][j]);
            if (j < N - 1)
                printf(COLOR_S ", " COLOR_E);
        }
        printf(COLOR_S "]\n" COLOR_E);
    }

    (matrix_check(matrix, N) == 1) ? printf("Hurray! Your matrix is a Latin Square! :D")
                                         : printf("Darn, maybe you should try again with different numbers,"
                                                         "because that ain't no \033[1;33mLatin Square..\033[0m");
    return 0;
}

int matrix_check(int a[][N], int n)
{
    int i, j;
    int seen_row[n], seen_col[n];

    for (i = 0; i < n; i++)
    {
        memset(seen_row, 0, n * sizeof(int));
        memset(seen_col, 0, n * sizeof(int));

        for (j = 0; j < n; j++)
        {
            seen_row[a[i][j] - 1]++;
            seen_col[a[j][i] - 1]++;
        }

        for (j = 0; j < n; j++)
        {
            if (seen_row[j] != 1 || seen_col[j] != 1)
                return 0;
        }
    }
    return 1;
}