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

#define N 4

// This defines a Complex structure to store real and imaginary parts of a complex number.
typedef struct Complex
{
    double r, i;
}Complex;

double CRadius(Complex c);
void Error_Msg(char* str);
void InputAndWriteToFile(FILE *f);
int CheckFile(FILE *f,float m);

int main()
{
    FILE *f;
    int res;

    printf(UNDERLINE LIGHT_BLUE "Question 3\n\n" R);
    
    f = fopen("complex_number.txt", "w+");
    if (f == NULL)
    {Error_Msg("There was a " RED "problem" R " opening one of the files."); return 1;}

    InputAndWriteToFile(f);

    res = CheckFile(f, 4);
    res == 1 ? printf("\nThere is " GREEN "%d" R " big number.\n", res)
             : printf("\nThere are " GREEN "%d" R " big numbers.\n", res);
    return 0;
}

// This function writes the coordinates of a complex number, and it's radius into any given file.
void InputAndWriteToFile(FILE *f)
{
    int i = 0;
    Complex c;

    printf("Enter " YELLOW "%d" R " complex numbers:\n", N);

    while (i < N)
    {
        if (scanf("%lf %lf", &c.r, &c.i) != 2)
        {
            printf("Coordinate number %d may have been " RED "incorrect.." R "\n\nTry again:\n", i+1);
            while (getchar() != '\n');
        }
        else
        {
            if (i == N - 1) fprintf(f, "%.1lf %.1lf %.1lf", c.r, c.i, CRadius(c));
            else            fprintf(f, "%.1lf %.1lf %.1lf\n", c.r, c.i, CRadius(c));
            i++;
        }
    }
}
// This function prints an error message and quits the script.
void Error_Msg(char* str)
{
    printf("\n%s",str);
    exit(69);
}

// This function calculates the radius of any given complex number.
double CRadius(Complex c)
{ return sqrt(pow(c.r,2) + pow(c.i,2)); }

// This function returns the number of radii that are larger than 'm'.
int CheckFile(FILE *f,float m)
{
    int j, count = 0;
    double r, i, rad;
    rewind(f);

    // This loop goes over 'N' rows and checks if the radius is larger than 'm'.
    for (j = 0; j < N; j++)
    {
        if (fscanf(f, "%lf %lf %lf", &r, &i, &rad) == 3)
            if (rad > m) count++;
    }
    return count;
}