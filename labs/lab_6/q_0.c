// Declarations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#endif

// Constant Definitions
#if 1
#define N 5
#define M 4
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
@File         : q_0.c
@Date         : 16:27 27/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program calculates the average of the 8 neighboring elements
                around any given matrix and a set of 'i', 'j' coordinates.
*/

double average(int Matrix[][M], int Rows,int Cols, int r, int c);

int is_legal(int current_i, int current_j, int neighbor_i, int neighbor_j);

int main()
{
    int i, j, m[N][M], r, c;
    double avg;

    printf(UNDERLINE LIGHT_BLUE "Question 1\n\n" R);
    printf("This program calculates the " YELLOW "average" R " of the 8 neighboring elements around any given coordinate in a matrix.\n");

    // These populate matrix 'm[][]'.
    for (i = 0; i < N; i++)
    {
        printf("Enter " GREEN "%d" R " numbers for row[%d]: ", M, i+1);
        for (j = 0; j < M; j++)
        {

            if (scanf("%d", &m[i][j]) != 1)
            {
                printf("\nPlease make sure to only enter " UNDERLINE "whole" R " numbers."); return 1;
            }
        }
    }

    // This requests and assigns user coordinates into 'r' and 'c'.
    printf("\nPlease enter the coordinates of an element you wish to inspect: ");
    while (1)
    {
        if (scanf("%d %d", &r, &c) != 2 || r < 0 || r >= N || c < 0 || c >= M)
        {
            rewind(stdin);
            printf("\n" RED "Invalid coordinates!" R "\nMake sure row is between " UNDERLINE "0-%d" R " and column is between " UNDERLINE "0-%d" R ".\nTry again: ", N - 1, M - 1);
        }
        else break;
    }

    // Sends values to "Average" for calculations.
    avg = average(m, N, M, r, c);

    // These print the matrix and 'average'.
    printf("\nThe entered matrix is:\n");
    for (i = 0; i < N; i++)
    {
        for (j = 0; j < M; j++)
        {
            if (j == 0) printf(GREEN "[%3d" R, m[i][j]);
            if (j != 0) printf(GREEN "%3d" R, m[i][j]);
            if (j < M - 1) printf(GREEN "," R);
        }
        printf(GREEN "]\n" R);
    }

    printf("And the " YELLOW "average" R " of all the elements that surround (%d,%d) is: " GREEN "%.2f" R, r, c, avg);



    return 0;
}

double average(int Matrix[][M], int Rows,int Cols, int r, int c)
{
    int i, j, sum = 0, count = 0;

    for (i = 0; i < Rows; i++)
    {
        for (j = 0; j < Cols; j++)
        {
            if (is_legal(r, c, i, j))
            {
                sum += Matrix[i][j];
                count++;
            }
        }
    }

    if (count == 0) return 0;
    return (double)sum / count;
}

// This function checks if the coordinates (neighbor_i, neighbor_j) are neighbors of (current_i, current_j).
int is_legal(int target_i, int target_j, int i, int j)
{
    return ( (i >= target_i -1) && (i <= target_i +1) ) && // 1. Checks if row is within 1 step (above or below).
           ( (j >= target_j -1) && (j <= target_j +1) ) && // 2. Checks if column is within 1 step (left or right).
           ( (i != target_i   ) || (j != target_j   ) );   // 3. Make sure it's not the element itself.
}