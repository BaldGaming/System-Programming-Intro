#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
#define BOLD       "\033[1m"
#define ITALIC     "\033[3m"
#define UNDERLINE "\033[4m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"

double sum_square(int m, int n, float(*f)(int a));
float func1(int x);
float func2(int x);

int main()
{
    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 1\n\n" R);

    printf("The sum of func2 is: " GREEN "%.5f\n" R, sum_square(2, 13, func2));
    printf("The sum of func1 is: " GREEN "%.5f\n" R, sum_square(1, 10000, func1));

    return 0;
}

// This function sums the squares of f(i) for i from m to n.
double sum_square(int m, int n, float(*f)(int a))
{
    int i;
    double sum = 0;

    for (i = m; i <= n; i++)
        sum += pow( f(i), 2.0);

    return sum;
}

// This function returns 'x' divided by 5.0.
float func2(int x) { return x / 5.0; }

// This function returns the reciprocal of 'x'.
float func1(int x) { return 1.0 / x; }