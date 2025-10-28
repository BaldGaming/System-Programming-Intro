// Declarations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include <time.h>
#endif

// Constant Definitions
#if 1
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
#define R "\033[0m"
#endif
#endif

#define NUM 3

// This defines a Complex structure to store real and imaginary parts of a complex number.
typedef struct Complex { double r, i; } Complex;

double CRadius(Complex c);
Complex *Cmax(Complex a[], int n);

int main()
{
    int i;
    Complex arr[NUM], *max_complex;

    printf(UNDERLINE LIGHT_BLUE "Question 3\n\n" R);

    // Requests and assigns user values into a complex number array.
    printf("Enter %d " YELLOW "complex" R " numbers:\n",NUM);
    for (i = 0; i < NUM; )
    {
        if (scanf("%lf %lf", &arr[i].r, &arr[i].i) != 2)
        {
            printf("Some of your inputs may be " RED "incorrect.." R "\n\nTry again: ");
            while (getchar() != '\n');
        }
        else i++;
    }

    max_complex = Cmax(arr, NUM);

    printf("\nThe max " YELLOW "complex" R " number is: " GREEN " %.2f%+.2fi\n" R, max_complex->r, max_complex->i);
    printf("The " YELLOW "radius" R " of the max number is: " GREEN " %.2f" R, CRadius(*max_complex));
    return 0;
}

// This function calculates the radius of any given complex number.
double CRadius(Complex c)
{
    return sqrt(pow(c.r,2) + pow(c.i,2));
}

// This function returns a pointer for the largest complex number based off of its radius.
Complex *Cmax(Complex a[], int n)
{
    Complex *max = &a[0];
    int i;

    for (i = 0; i < n; i++)
    {
        if (CRadius(a[i]) > CRadius(*max))
            max = &a[i];
    }
    return max;
}