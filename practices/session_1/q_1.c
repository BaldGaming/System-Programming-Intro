#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>


/*
@File         : q_1.c
@Date         : 12:27 15/04/2025
@Author       : Itay Rosen :^)
@Contact      : Itay.Rosen@e.braude.ac.il
@Description  : 
                
*/
int grade_checker(float grade, float average_lab, float average_home);

int main()
{
    float grade, average_lab, average_home;

    printf("Please enter your grade: ");
    scanf("%f", &grade);

    printf("Please enter your average lab score: ");
    scanf("%f", &average_lab);

    printf("Please enter your average home score: ");
    scanf("%f", &average_home);

    int res = grade_checker(grade, average_lab, average_home);

    return 0;
}

int grade_checker(float grade, float average_lab, float average_home)
{
    float final;
    int passed = 0;

    final = 0.7*grade + 0.2*average_lab + 0.1*average_home;
    if (final > 55)
        passed = 1;
    printf("The final grade is %.2f,"
                 "\nThe student %s the corse", final, (passed==1)?"passed" : "didn't pass");
    return passed;
}