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

typedef struct Person
{
    char ID[10];
    char F_name[11];
    char L_name[16];
    int Age;
    char Addr[51];
}Person;

void Error_Msg(char*);

int main()
{
    Person temp;
    FILE *in,*out;
    char* msg = "There was a" RED " problem" R " opening one of the files.";

    in = fopen("the_first.txt", "r");
    if (in == NULL)  {Error_Msg(msg);}
    out = fopen("the_second.txt", "w");
    if (out == NULL) {Error_Msg(msg);}

    // This reads data from the input file.
    fscanf(in,"%s %s %s %d %s", temp.ID, temp.F_name, temp.L_name, &temp.Age, temp.Addr);

    // These write data to the output file.
    fprintf(out,"ID: %s\n", temp.ID);
    fprintf(out,"Full name: %s %s\n", temp.F_name, temp.L_name);
    fprintf(out,"Age: %d\n", temp.Age);
    fprintf(out,"Address: %s", temp.Addr);

    // Closes the files.
    fclose(in); fclose(out);
    return 0;
}

// This function prints an error message and quits the script.
void Error_Msg(char* msg)
{ printf("\n%s",msg); exit(1); }