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

typedef struct Student
{
    char name[7];
    char department[5];
    char grade_1[4];
    char grade_2[4];
    float f_grade;
}Student;

void Error_Msg(char* str);
void output(FILE *in, FILE *out);

int main()
{
    FILE *in,*out;

    if((in=fopen("Students.txt","r")) == NULL)
        Error_Msg("Something went " RED "wrong" R " with the input file.");
    if((out=fopen("StudentsNew.txt","w")) == NULL)
        Error_Msg("Something went " RED "wrong" R " with the output file.");

    output(in, out);

    fclose(in);
    fclose(out);
    return 0;
}

void Error_Msg(char* str)
{
    printf("%s",str);
    exit(1);
}

// This function populates an output .txt file.
void output(FILE *in, FILE *out)
{
    Student temp;
    int flag;

    // This loop runs so long as it has text to read, and it updates the output file when the conditions are met.
    while (fgets(temp.name, 7, in) != NULL)
    {
        flag = 0;

        if (fgets(temp.department, 5, in) == NULL)
            break;
        if (strcmp(temp.department, "Comp") == 0)
            flag = 1;

        if (fgets(temp.grade_1, 4, in) == NULL || fgets(temp.grade_2, 4, in) == NULL)
            break;

        // Updates the output file if 'flag' is true.
        if (flag)
        {
            temp.f_grade = (atof(temp.grade_1) + atof(temp.grade_2))/2;
            fprintf(out, "%s %.2f\n", temp.name, temp.f_grade);
        }
    }
}