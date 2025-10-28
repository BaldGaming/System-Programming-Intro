#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE "\033[4m"
#define RED        "\033[38;2;255;0;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"
#define N 5

void Int_Sum(void *sum, void *num);
void Int_Sub(void *sum, void *num);
void Init(void *p);
int Int_Comp(void *a, void *b);
int Do_It(void *sum, void** array, void (*p_Init)(void *), void (*p_Sum)(void*, void*), void (*p_Sub)(void*, void*), int (*p_Comp)(void*, void*));

int main()
{
    int num[] = { 5, 8, 23, 20, 23 }, i, answer;
    void *p_num[N];

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 3\n\n" R);

    for (i = 0; i < N; i++)
        p_num[i] = &num[i];


    if (Do_It( &answer, p_num, Init, Int_Sum, Int_Sub, Int_Comp ))
        printf("The answer is '" GREEN "Yes" R "'");

    else
        printf("The answer is '" RED   "No"  R "'");

    return 0;
}

int Do_It( void *sum, void** array, void (*p_Init)(void *), void(*p_Sum)(void*, void*), void(*p_Sub)(void*,void*), int(*p_Comp)(void*,void*) )
{
    int i;

    // Initializes the sum to the first element in the array.
    p_Init(sum);

    // This loop runs through the entire array starting from index 1.
    // It compares the current sum to the element in slot 'i'.
    for (i = 0; i < N; i++)
    {
        if (p_Comp(sum, array[i]))
            return 1;

        // This updates the current sum by adding or subtracting.
        // It decides to add or subtract based on 'i''s evenness.
        (i % 2) ? p_Sub(sum, array[i]) : p_Sum(sum, array[i]);
    }
    return 0;
}

// This function sets the sum to 0.
void Init(void *p)
{ *(int*)p = 0; }

// This function adds numbers with even indexes.
void Int_Sum(void *sum, void *num)
{ *(int*)sum += *(int*)num; }

// This function subtracts numbers with even indexes.
void Int_Sub(void *sum, void *num)
{ *(int*)sum -= *(int*)num; }

// This function compares between the sum and any number in an arary.
int Int_Comp(void *a, void *b)
{ return *(int*)a == *(int*)b; }