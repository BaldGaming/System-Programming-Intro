#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE  "\033[4m"
#define RED        "\033[38;2;255;0;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"
#define N 5

typedef enum
{
  FALSE, TRUE
} BOOL;

BOOL Int_Sum(void *, void *, void *);
BOOL Float_Sum(void *, void *, void *);
BOOL Sum(BOOL(*f)(void *,void *,void *), void **p_num, void *number);

int main()
{
    int   num[] = {3, 5, 23, 5, 6}, i, value, sum_1;
    float fnum[] = {3.5, 5.0, 2.3, 5.8, 6.2}, fvalue, sum_2;
    void *p_num[N];
    void *p_fnum[N];

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 2\n\n" R);

    for (i = 0; i < N; i++)
    {
        p_num[i] = &num[i];
        p_fnum[i] = &fnum[i];
    }

    printf("Please enter an integer number: ");
    scanf("%d", &value);

    // This checks if any two integers sum to 'value'.
    if (Sum(Int_Sum, p_num, &value) == TRUE)
        printf("There " GREEN "is" R " such sum.\n");

    else
        printf("There is " RED "no" R " such sum.\n");


    printf("\nPlease enter a float number: ");
    scanf("%f", &fvalue);

    // This checks if any two floats sum to 'fvalue'.
    if (Sum(Float_Sum, p_fnum, &fvalue) == TRUE)
        printf("There " GREEN "is" R " such sum.\n");

    else
        printf("There is " RED "no" R " such sum.\n");

    return 0;
}

// This function checks if any two numbers sum to a third number.
BOOL Sum(BOOL(*f)(void *,void *,void *), void **p_num, void *number)
{
    int i, j;

    for (i = 0; i < N; i++)
    {
        for (j = i; j < N - 1; j++)
        {
            if (f(p_num[i], p_num[j + 1], number) == TRUE)
                return TRUE;
        }
    }

    return FALSE;
}

// This function checks if the sum of two integers equals a third integer number.
BOOL Int_Sum(void *a, void *b, void *c)
{
    if( *(int*)a + *(int*)b == *(int*)c)
        return TRUE;
    return FALSE;
}

// This function checks if the sum of two floats equals a third float number.
BOOL Float_Sum(void *a, void *b, void *c)
{
    if( *(float*)a + *(float*)b == *(float*)c)
        return TRUE;
    return FALSE;
}