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

void BinPrint(unsigned char ch);
unsigned char check_ms(unsigned char ch);
unsigned char change_bit(unsigned char ch, int n);

int main()
{
    unsigned char num1 = 102, num2 = 58;
    int n;

    printf(UNDERLINE ITALIC LIGHT_BLUE "Question 4\n\n" R);

    printf(UNDERLINE "The first part:" R);
    printf("\nThe number is %d -> ", num1); BinPrint(num1);

    num1 = check_ms(num1);
    printf ("\nThe " GREEN "new" R " number is: %d -> ", num1);
    BinPrint(num1);

    printf(UNDERLINE "\n\nThe second part:" R);
    printf("\nThe number is %d -> ", num2); BinPrint(num2);

    printf ("\nEnter a number of the bit to change(1-8): ");
    scanf ("%d",&n);

    num2 = change_bit(num2, n);
    printf ("\nThe " GREEN "new" R " number is: %d -> ", num2); BinPrint(num2);
    return 0;
}

// This function prints the binary form of 'ch'.
void BinPrint(unsigned char ch)
{
    int i;
    unsigned int mask;

    for (i = 7; i >= 0; i--)
    {
        mask = 1 << i;
        printf("%d", (ch & mask) ? 1 : 0);
    }
}

// This function flips the MSB if it's unlit.
unsigned char check_ms(unsigned char ch)
{
    unsigned int mask = 1 << 7;

    if ((ch & mask) == 1)
        return ch;
    return ch | mask;
}

// This function flips any 'n'th bit it's given.
unsigned char change_bit(unsigned char ch, int n)
{
    unsigned int mask = 1 << 8 - n;
    ch = ch ^ mask;

    return ch;
}