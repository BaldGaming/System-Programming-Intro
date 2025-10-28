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


#define MAX 256

typedef struct Book
{
    char code[10];
    char *b_name;
}Book;

typedef struct Library
{
    char lib_name[MAX];
    int num_books;
    Book *lib_arr;
}Library;

int input_book(Book* B,FILE *in);
void input_library(Library *L,FILE *in);
void output_book(Book* B,FILE *out);
void output_library(Library* L,FILE *out);

int main()
{
    FILE *in,*out;
    Library Libr;
    Book B;
    int i, dummy;

    printf(UNDERLINE ITALIC LIGHT_BLUE "Question 2\n\n" R);

    in = fopen("input.txt", "r");
    if (in == NULL)
    {
        printf("There was a " RED "problem" R " opening the input file."); exit(2);
    }

    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        printf("There was a " RED "problem" R " opening the output file."); exit(3);
    }

    dummy = input_book(&B, in);

    input_library(&Libr, in);
    fclose(in);

    output_library(&Libr,out);
    fclose(out);

    for (i = 0; i < Libr.num_books; i++)
        free(Libr.lib_arr[i].b_name);
    free(Libr.lib_arr);

    return 0;
}

int input_book(Book* B,FILE *in)
{
    char buffer[MAX];
    int i = 0;
    char ch;
    B->b_name = NULL;

    // These skip over the first two lines, knowing they aren't needed for this function.
    if (fgets(buffer, sizeof(buffer), in) == NULL) {return 0;}
    if (fgets(buffer, sizeof(buffer), in) == NULL) {return 0;}

    // This loop populates the 'code' field in the book structure one character at a time.
    while (i < 9)
    {
        ch = fgetc(in);
        if (ch == ' ')
            break;

        B->code[i++] = ch;
    }
    B->code[i] = '\0';

    if (fgets(buffer, sizeof(buffer), in) == NULL)
    {
        free(B->b_name);
        return 0;
    }

    B->b_name = malloc((strlen(buffer) + 1) * sizeof(char));
    if (B->b_name == NULL)
    {
        printf("Memory allocation " RED "failed." R);
        exit(1);
    }

    strcpy(B->b_name, buffer);
}

void input_library(Library *L,FILE *in)
{

}

void output_book(Book* B,FILE *out)
{

}

void output_library(Library* L,FILE *out)
{

}