#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#define N 6


/*
@File         : q_2.c
@Date         : 16:06 16/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :

*/

int distance(char A[], char B[]);

int main()
{
    char arr_1[N], arr_2[N];
    int res;

    // Instructions for user.
    printf("Please enter any string to be put into two different arrays, 6 values long at max.");

    printf("\nEnter the first string: ");
    fgets(arr_1, N, stdin);
    rewind(stdin);

    printf("\nEnter the second string: ");
    fgets(arr_2, N, stdin);


    // Sends both arrays into "distance"
    res = distance(arr_1, arr_2);

    if (res == -1) printf("\nThe two strings are of the same length.");
    else printf("\nThe distance between the first and second array is: %d\n", res);

    return 0;
}

// This function calculated the "distance" between the unique values in 'A[]' and 'B[]'.
int distance(char A[], char B[])
{
    int count = 0, i;

    // Checks an edge case where the lengths are unequal.
    if (strlen(A) != strlen(B)) return -1;

    // This loop counts the number of values that differ from each other.
    for (i = 0; i < A[i] != '\0'; i++)
        if (A[i] != B[i]) count++;

    return count;
}