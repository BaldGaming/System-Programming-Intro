#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define N 6

/*
@File         : q_1.c
@Date         : 19:21 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :

*/

int f(int A[], int n);
int no_repetition(int A[], int n, int current_k);

int main() {
    int i, arr[N];

    printf("Please enter 6 whole numbers.\n");
    for (i = 0; i < N;)
    {
        printf("Enter an integer for slot %d: ", i + 1);
        rewind(stdin);
        if (scanf("%d", &arr[i]) != 1) printf("Invalid input.. Try again.\n\n");
        else i++;
    }

    printf("%d", f(arr, N));
    return 0;
}

int f(int A[], int n) {
    int k, count, flag = 1;

    for (k = 0; k < n; k++)
    {
        count = no_repetition(A, n, A[k]);

        if (((A[k] % 2 == 0) && (count % 2 != 0)) || ((A[k] % 2 == 1) && (count % 2 == 0)))
            flag = 0; break;
    }
    return flag;
}

int no_repetition(int A[], int n, int current_k)
{
    int seen_list[10] = {0};
    int count = 0;

    for (int i = 0; i < n; i++)
    {
        if (A[i] < current_k && seen_list[A[i]] == 0)
            seen_list[A[i]] = 1; count++;
    }
    return count;
}