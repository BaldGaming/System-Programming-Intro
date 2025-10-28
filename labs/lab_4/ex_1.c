#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>

/*
@File         : ${NAME}.c
@Date         : ${TIME} ${DATE}
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :

*/


int InputThree(int *p1, int *p2, int *p3);

void SortTwo(int *p1, int *p2);

void SortThree(int *q1, int *q2, int *q3);

int main()
{
    int p1, p2, p3;

    // This loop requests and sorts user values until the user fails to provide 3 integers.
    while (InputThree(&p1, &p2, &p3))
    {

        // Sends said values to "SortThree".
        SortThree(&p1, &p2, &p3);
        printf("Sorted Values: %d, %d, %d\n", p1, p2, p3);
    }

    printf("FINISH\n");
    return 0;
}

// This function requests three integer inputs and assigns them to '*p1', '*p2', and '*p3'.
int InputThree(int *p1, int *p2, int *p3)
{
    printf("Input three integer values: ");

    // Returns 0 if the input is invalid, otherwise returns 1.
    if (scanf("%d %d %d", p1, p2, p3) != 3)
        return 0;
    return 1;
}

// This function swaps the values of 'p1' & 'p2' only if 'p1' is greater than 'p2'.
void SortTwo(int *p1, int *p2)
{
    int temp;

    if (*p1 > *p2)
    {

        temp = *p1;
        *p1 = *p2;
        *p2 = temp;
    }
}

// This function sorts three integers in ascending order by calling "SortTwo".
void SortThree(int *q1, int *q2, int *q3)
{
    SortTwo(q1, q2);
    SortTwo(q1, q3);
    SortTwo(q2, q3);
}