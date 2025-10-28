#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define LEN 50


/*
@File         : q_2.c
@Date         : 14:22 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 

*/
int avr(int a[], len);

int main()
{
    int arr[LEN] = {0}, n, j = 0, people = 0;
    float average = 0;

    printf("Please enter the salary of all 50 workers: ");

    while (j<LEN)
    {
        if (scanf("%d", &n) != 1 || n < 0)
        {
            printf("I literally hate you so much rn..");
            return 1;
        }
        arr[j]=n;
        j++;
    }

    average, people = avr(arr, LEN);

    printf("The average salary is: %.2f"
                 "\nAnd there are %d people whom earn more than the average salary.",average, people);
    return 0;
}

int avr(int a[],int len)
{
    float avg = 0;
    int sum = 0, i, peop = 0;

    for (i = 0; i < len; i++)
        sum += a[i];

    avg = sum / len;

    for (i = 0; i < len; i++)
    {
        if (a[i] > avg)
            peop++;
    }
    return avg, peop;
}