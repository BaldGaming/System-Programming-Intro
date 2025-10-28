// Declarations
#if 1
// Library Definitions
#if 1
#define  _CRT_SECURE_NO_WARNINGS
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
#define BOLD      "\033[1m"
#define ITALIC    "\033[3m"
#define UNDERLINE "\033[4m"
#endif

// Colors
#if 1
#define RED        "\033[38;2;255;0;0m"
#define PINK       "\033[38;2;255;105;180m"
#define YELLOW     "\033[38;2;255;255;0m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define BLUE       "\033[38;2;0;0;255m"
#define PURPLE     "\033[38;2;128;0;128m"
#define R          "\033[0m"
#endif
#endif


int Bit_Count(unsigned int x);
void Bin_Print(unsigned int x);

int main()
{
    unsigned int x;

    printf(UNDERLINE ITALIC LIGHT_BLUE "Question 3\n\n" R);

    printf("Enter a number: ");
    scanf("%d",&x);
    printf("There are " GREEN "%d" R " bits equal to one in %d\n", Bit_Count(x),x);
    printf("The binary representation of %d is ",x);
    Bin_Print(x);

    return 0;
}

// This function counts the number of bits set to 1.
int Bit_Count(unsigned int x)
{
    int i, count = 0;
    unsigned int mask;

    for (i = 31; i >= 0; i--)
    {
        mask = 1 << i;
        if ((x & mask) != 0)
            count++;
    }
    return count;
}

// This function prints the 32-bit binary form of 'x'.
void Bin_Print(unsigned int x)
{
    int i;
    unsigned int mask;

    for (i = 31; i >= 0; i--)
    {
        mask = 1 << i;
        printf(GREEN "%d" R, (x & mask) ? 1 : 0);
    }
}