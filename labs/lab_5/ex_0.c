#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define SIZE 10

float avg(float a[], int size);

int main()
{
    // These define various variables used in the script.
    float lst[SIZE], average;
    int i, best_times = 0;

    // This prints instrutions and records user values into 'lst'.
    printf("Enter times, please: ");
    for (i = 0; i < SIZE;)
    {
        if (scanf("%f", &lst[i]) != 1)
        {
            rewind(stdin);
            printf("Some of your inputs might've been incorrect..");
            return 0;
        }
        else i++;
    }

    // Sends 'lst' & 'SIZE' to "avg" for calculations.
    average = avg(lst, SIZE);

    // This loop figures out how many runner times are below average.
    for (i = 0; i < SIZE; i++)
    {
        if (lst[i] < average) best_times++;
    }
    // This prints two different messages in relation to 'best_times'.
    (best_times == 0) ? printf("\nThere are no runners that ran below the average time! :(")
                      : printf("\nThe number of runners, running below the average time is %d.\n", best_times);
    return 0;
}

// This function calculates the average of it's given values.
float avg(float a[], int size)
{
    int i;
    float sum = 0;

    // Average algoarithm.
    for (i = 0; i < size; i++)
        sum += a[i];

    return sum / size;
}