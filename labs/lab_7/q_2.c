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

// Declares a structure for keeping track of a student name, 4 grades and the average of said grades.
typedef struct stud
{
    char *name;
    int marks[4];
    float avg;
}student;

student* Create_Class(int size);
void Print_One(student *);
void Avg_Mark(student *);

int main()
{
    printf(UNDERLINE LIGHT_BLUE "Question 2\n\n" R);

    int size, i;
    student *arr;
    printf("Enter the number of students: ");
    while (1)
    {
        if (scanf("%d", &size) != 1)
        {
            printf("Some of your inputs may be " RED "incorrect.." R "\n\nTry again: ");
            while (getchar() != '\n');
        }
        else break;
    }

    arr = Create_Class(size);

    // This prints student information if their average score is above 85.
    for (i = 0; i < size; i++)
    {
        if (arr[i].avg >= 85)
            Print_One(&arr[i]);
    }

    // Memory dumpster.
    for (i = 0; i < size; i++)
        free(arr[i].name);
    free(arr);

    return 0;
}

// This function prints the details of a single student, including their name and average marks.
void Print_One(student* s)
{
    printf( "\nThe average of " YELLOW "%s" R " is " GREEN "%.1f" R, s->name, s->avg);
}

// This function calculates the average all 4 marks of every student.
void Avg_Mark(student* s)
{
    int i;
    s->avg = 0;

    for (i = 0; i < 4; i++)
        s->avg += s->marks[i];
    s->avg /= 4;
}

// This function allocates memory for an array of students and populates their details.
student* Create_Class(int size)
{
    char str[50];
    int i, j;

    student *arr = malloc(size * sizeof(student));
    if (arr == NULL)
    {
        printf("Memory allocation for the array failed.\n");
        exit(1);
    }

    for (i = 0; i < size; i++)
    {
        printf("\nEnter your name: ");
        scanf("%s", str);
        arr[i].name = (char*)malloc(strlen(str) + 1);
        if (arr[i].name == NULL)
        {
            printf("Not enough memory");
            for(j=0; j<i; j++)
                free(arr[j].name);
            free(arr);
            exit(2);
        }
        strcpy(arr[i].name, str);

        // Requests and assigns the marks of the student.
        printf("Enter " YELLOW "%s's" R " marks: ",arr[i].name);
        for (j = 0; j < 4;)
        {
            if (scanf("%d", &arr[i].marks[j]) != 1)
            {
                printf("Input number %d is " RED "incorrect.." R "\n\nTry again: ", j+1);
                while (getchar() != '\n');
            }
            else j++;
        }
        Avg_Mark(&arr[i]);
    }
    return arr;
}