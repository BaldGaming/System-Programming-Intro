#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>
#define YELLOW "\033[38;2;255;255;0m"
#define R "\033[0m"

/*
@File         : q_1.c
@Date         : 19:08 25/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  :
*/

char* new_str(char* str, char c, int len);

int main()
{
    char* user_str;
    char ch;
    int n;

    printf("This program builds a dynamic string that's based on the occurrence of any given character."
                  "\nFor example, given the string H" YELLOW "o" R "w are y" YELLOW "o" R "u and the character '" YELLOW "o" R "', it would print the new string '" YELLOW "oo" R "'.\n");

    // Requests and assigns user value to the length of 'user_str'.
    printf("\nHow long would you like your string to be?: ");
    while (1)
    {
        if (scanf("%d", &n) == 1 && n > 2) break; rewind(stdin);
        printf("\nMake sure it's at least 3 characters long..\nTry again: ");
    }

    // Allocates memory to 'user_str'.
    user_str = (char*)malloc((n + 1) * sizeof(char));
    if (!user_str)
    {
        printf("\n! MEMORY ALLOCATION FAILED !");
        exit(1);
    }

    // This populates said memory.
    printf("Please enter your %d long string: ", n);
    scanf(" %[^\n]%*c", user_str);

    // Requests and assigns a variable for 'ch'.
    printf("Enter any single letter: ");
    scanf(" %c", &ch);

    // Print the result by calling "new_str()"
    char* result = new_str(user_str, ch, n);
    printf("Your string '" YELLOW "%s" R "' turns into -> '" YELLOW "%s" R "'\n", user_str, result);

    // Memory dumpster.
    free(user_str);
    free(result);
    return 0;
}

char* new_str(char* str, char c, int len)
{
    int i, counter = 0;
    char* new_str;

    // Count occurrences of 'c' in 'str'
    for (i = 0; i < len; i++)
    {
        if (str[i] == c)
            counter++;
    }

    // Allocate memory for the new string based on the count of 'c'
    new_str = (char*)malloc((counter + 1) * sizeof(char));
    if (!new_str)
    {
        printf("\n! MEMORY ALLOCATION FAILED !");
        exit(2);
    }

    // Populate the new string with 'c' based on the count
    for (i = 0; i < counter; i++)
    {
        new_str[i] = c;
    }
    new_str[counter] = '\0';

    return new_str;
}
