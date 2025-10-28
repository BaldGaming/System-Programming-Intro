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

typedef struct
{
    char name[20];
    int grades[3];
}student;

void Error_Msg(char*);
int InputData(student **, FILE*);
void OutputData(int, student*, FILE*);
int highest_grade(int index, student* arr);

int main()
{
    FILE *fp;
    student * arr;
    int size;

    if((fp=fopen("Students.txt","r")) == NULL)
        Error_Msg("The input file is wrong");

    size = InputData(&arr,fp);
    fclose(fp);

    if ((fp = fopen("Students.txt", "w")) == NULL)
    {
        free(arr);
        Error_Msg("The output file is wrong");
    }

    OutputData(size,arr,fp);
    fclose(fp);

    return 0;
}

// This function populates the 'student' structure dynamically.
int InputData(student ** p_array, FILE * fp)
{
    student* arr, *temp;
    int i = 1;

    // Dynamically creates an array that holds structures of student info.
    arr = (student*)malloc(sizeof(student));

    // This loop populates the fields in each structure in 'arr', and reallocates more memory to it if needed.
    while (fscanf(fp, "%s %d %d %d", arr[i - 1].name, &arr[i - 1].grades[0], &arr[i - 1].grades[1], &arr[i - 1].grades[2]) != EOF)
    {
        i++;
        temp = (student*)realloc(arr, i * sizeof(student));
        if (temp == NULL)
        {
            free(arr);
            Error_Msg("Memory reallocation failed.");
        }
        arr = temp;
    }

    // Resizes the array to the final size after all data is read.
    temp = (student*)realloc(arr, (i - 1) * sizeof(student));
    if (temp == NULL)
    {
        free(arr);
        Error_Msg("Memory reallocation failed.");
    }
    arr = temp;

    // Passes 'arr' back to the main and returns the number of students.
    *p_array = arr;
    return i - 1;
}

// This program rewrites the file with the highest grades.
void OutputData(int arr_size, student *arr, FILE* fp)
{
    int i = 0;
    int max;

    // This loop goes over the size of the array and does as per writen in the function notation.
    for (i = 0; i < arr_size; i++)
    {
        max = highest_grade(i, arr);
        if (i == arr_size - 1) fprintf(fp, "%s's highest grade is: %d", arr[i].name, max);
        else                   fprintf(fp, "%s's highest grade is: %d\n", arr[i].name, max);
    }
}

// This function prints an error message and quits the script.
void Error_Msg(char* msg)
{ printf("\n%s",msg); exit(420); }

// This function returns the highest grade per student.
int highest_grade(int index, student* arr)
{
    int max_grade = arr[index].grades[0], i;

    for (i = 1; i < 3; i++)
        if (arr[index].grades[i] > max_grade)
            max_grade = arr[index].grades[i];
    return max_grade;
}