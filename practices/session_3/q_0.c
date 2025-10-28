#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <math.h>


/*
@File         : q_0.c
@Date         : 16:17 24/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : This program turns lowercase letters into uppercase ones such that all lowercase letters
                that will swap must be within uppercase ones. For example, abCdeFgh -> abCDEFgh.
*/

void capital_between(char *str);

int main()
{
    int n;

    // Instructions.
    printf("This program turns lowercase letters into uppercase ones such that all lowercase letters,"
                  "\nthat will swap must be within uppercase ones, for example: abCdeFgh -> abCDEFgh.");

    // Requests and assigns 'n' that will act as the lenght of 'user_str'.
    printf("\n\n\nHow long would you want the string to be?: ");
    while (1)
    {
        if (scanf("%d", &n) == 1 && n > 0) break;

        printf("Try again: ");
    }
    char user_str[n+1];
    getchar();

    // Requests and assigns a string to 'user_str'.
    printf("\nPlease type any string that's atleast %d long: ",n);
    fgets(user_str, n+1, stdin);
    rewind(stdin);

    // Sends said string to "capital_between" and prints the result.
    printf("\nYour string post-change is: %s", (capital_between(user_str), user_str));
    return 0;
}

void capital_between(char *str)
{
    int i = 0, final_upper = 0;

    // This loop detects the point where the first and last capital letters are found.
    for (i ; str[i] != '\0'; i++)
    {
        if (str[i] >= 65 && str[i] <= 90)
        {
            // Tallies up the counter untill it hits 2, at which point it breaks.
            final_upper++;
            if (final_upper == 2) break;
        }

        // This converts lowercase letters into uppercase ones, while ignoring empty spaces.
        else if (final_upper == 1 && str[i] >= 97 && str[i] <= 122)
        {
            str[i] = str[i] - 32;
        }
    }
}