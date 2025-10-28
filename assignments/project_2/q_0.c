#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#define ITALIC     "\033[3m"
#define UNDERSCORE  "\033[4m"
#define RED        "\033[38;2;255;0;0m"
#define PINK       "\033[38;2;255;105;180m"
#define GREEN      "\033[38;2;0;255;0m"
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R          "\033[0m"

typedef struct Student
{
    char *name;
    long id;
    float grade;
    char assignment[6];
    char f_grade;
} Student;

typedef struct Uni
{
    Student* students;
    int count;
} Uni;

void transfer_info(Uni* uni, FILE* in, FILE* out);
void output(Uni* uni, FILE* out);
void final_grade(Uni* uni, FILE* out);
void failed(Uni* uni, FILE* out);
void change(Uni* uni, FILE* out);
void end(FILE* out);
int count_passed_assignments(char* assignment);
void print_student_pass_status(Uni* uni, FILE* out, int* pass_count);
void safe_exit(Uni* uni);

int main()
{
    int end_flag = 1, num, transfer_flag = 0;

    FILE *in = NULL ,*out;
    Uni university;

    // Title + Instructions.
    printf(ITALIC UNDERSCORE LIGHT_BLUE "Project 2\n\n" R
                  "This script can preform multiple Options when given student information."
                  "\nPlease select any of the following by typing the number associated with said Option.\n");

    // Prints a menu, and then requests and assigns a number to 'num'.
    printf(UNDERSCORE"\nAvailable Options:" R
                           "\n 1 - Store the student info from input file into the script."
                           "\n 2 - Update the output file using the stored info."
                           "\n 3 - Calculate the final grade."
                           "\n 4 - Update the \"Failure list\"."
                           "\n 5 - Change student assignment status."
                           "\n 6 - Exit.\n");

    out = fopen("output.txt", "w");
    if (out == NULL)
    {
        printf("\nThere was a" RED " problem" R " with the output file in 'main'.");
        safe_exit(&university);
        exit(1);
    }

    // Opens a switch that loops so long as 'num' does not equal to 6.
    while (end_flag != 0)
    {
        printf("\nSelect Option: ");
        while (scanf("%d", &num) != 1)
        {
            rewind(stdin);
            printf(RED RED "ERROR:" R " Only select the options listed above.\nTry again: ");
        }

        // Each case handles a different option that the script can preform.
        switch(num)
        {
            case 1:
                if (transfer_flag)
                    printf(RED "ERROR:" R " Student data already transferred.\n");
                else
                    { transfer_info(&university, in, out); transfer_flag = 1; }
            break;

            case 2:
                if (!transfer_flag)
                    printf(RED "ERROR:" R " Transfer data first (1).\n");
                else
                    { output(&university, out); }
            break;

            case 3:
                if (!transfer_flag)
                    printf(RED "ERROR:" R " Transfer data first (1).\n");
                else
                    { final_grade(&university, out); }
            break;

            case 4:
                if (!transfer_flag)
                    printf(RED "ERROR:" R " Transfer data first (1).\n");
                else
                    { failed(&university, out); }
            break;

            case 5:
                if (!transfer_flag)
                    printf(RED "ERROR:" R " Transfer data first (1).\n");
                else

                    { change(&university, out); }
            break;

            case 6:
                end(out);
                end_flag = 0;
            break;

            default:
                printf(RED "ERROR:" R " %d doesn't seem to be a number you can choose..\n", num);
            break;
        }
    }
    fclose(out);
    safe_exit(&university);
    printf(UNDERSCORE PINK "\nThank you for using our script! <3");
    return 0;
}

// This function loads info from the input file into the 'Uni' structure.
void transfer_info(Uni* uni, FILE* in, FILE* out)
{
    Student* temp;

    uni->students = NULL;
    uni->count = 0;

    in = fopen("input.txt", "r");
    if (in == NULL)
    {
        printf("\nThere was a" RED " problem" R " with the input file in 'transfer_info'.");
        safe_exit(uni);
        exit( 2);
    }

    // This loop scans said info and dynamically reallocates memory for the 'students' structure.
    while (1)
    {
        // Adds an aditional student to the dynamic array.
        temp = realloc(uni->students, (uni->count + 1) * sizeof *uni->students);
        if (temp == NULL)
        {
            printf("Memory reallocation " RED "failed." R);
            safe_exit(uni);
            fclose(in);
            exit(3);
        }
        uni->students = temp;

        // This allocates memory to be put into the structure.
        uni->students[uni->count].name = malloc(101);
        if (uni->students[uni->count].name == NULL)
        {
            printf("Name allocation " RED "failed." R);
            safe_exit(uni);
            fclose(in);
            exit(4);
        }

        // This populates the structure with the info from the input file.
        if (fscanf(in, "%s %ld %f %s",
                uni->students[uni->count].name,
                &uni->students[uni->count].id,
                &uni->students[uni->count].grade,
                uni->students[uni->count].assignment) != 4)
        {
            free(uni->students[uni->count].name);
            break;
        }

        // This determains the final grade status.
        uni->students[uni->count].f_grade = count_passed_assignments(uni->students[uni->count].assignment) >= 3 ? '1' : '0';

        // Updates the number of students found in the input file.
        uni->count++;
    }
    // Prints a feedback message and closes the input file.
    fprintf(out, "Option 1:\nInput accepted.\n\n");
    fclose(in);
    printf("The info of %d student(s) was " GREEN "successfully" R " loaded from the input file.\n", uni->count);
}

// This function writes all student data from 'uni' to the output file 'out',
// while marking students who submitted at least 3 assignments with '1', else '0'.
void output(Uni* uni, FILE* out)
{
    int pass_count = 0;

    fprintf(out, "Option 2:\n");

    print_student_pass_status(uni, out, &pass_count);

    // Prints a feedback message and preps a new line for the next Option.
    fprintf(out,"\n");
    printf("The info of %d students was " GREEN "successfully" R " written into the output file,"
                  "\nwhile %d students submitted more than 3 assignments.\n", uni->count, pass_count);
}

// This function calculates the final grade for each student and then appends them.
void final_grade(Uni* uni, FILE* out)
{
    int i, pass_flag, pass_count = 0;
    float final;

    // Prints the info without the final grade.
    fprintf(out, "Option 3:\nBEFORE:\n");
    print_student_pass_status(uni, out, &pass_count);

    // Prints the info but with the final grade.
    fprintf(out, "\nAFTER:\n");
    for (i = 0; i < uni->count; i++)
    {
        pass_flag = uni->students[i].f_grade == '1';

        if (uni->students[i].grade < 55)
            final = uni->students[i].grade;
        else
            final = uni->students[i].grade*0.85 + pass_flag*15;

        fprintf(out, "Student %d: %s %ld %.2f %c final : %.2f\n",
            i + 1, uni->students[i].name, uni->students[i].id, uni->students[i].grade, uni->students[i].f_grade, final);
    }

    fprintf(out, "\n");
    printf("%d final grades were " GREEN "successfully" R " calculated and appended.\n", uni->count);
}

// This function appends students with fewer than 3 passed assignments.
void failed(Uni* uni, FILE* out)
{
    int i, found_flag = 0;

    fprintf(out, "Option 4:\nNo hw submissions:");

    for (i = 0; i < uni->count; i++)
            if (count_passed_assignments(uni->students[i].assignment) < 3)
            {
                fprintf(out,"\n%s %ld", uni->students[i].name, uni->students[i].id);
                found_flag = 1;
            }

    // Prints a feedback message and preps a new line for the next Option.
    // The 'found_flag' is used for a cleaner output file.
    if (!found_flag)
        fprintf(out,"\nOh, wait! Every student has submitted at least 3 assignments, great!\n\n");

    printf("\"Failure list\" was " GREEN "successfully" R " appended.\n");
    fprintf(out, "\n\n");
}

// This function changes any given student assignment to either 1 or 0.
void change(Uni* uni, FILE* out)
{
    char name_buffer[256];
    int i, len;
    int appeal_assignment, appeal_status;
    int pass_count = 0, student_found = 0;

    fprintf(out, "Option 5:\n");

    // Requests student name.
    printf("Enter the name of the student that wishes to appeal their assignment status: ");
    while (getchar() != '\n'){ }
    fgets(name_buffer, sizeof(name_buffer), stdin);

    len = strlen(name_buffer);
    if (len > 0 && name_buffer[len - 1] == '\n')
        name_buffer[--len] = '\0';

    // Requests assignment number.
    printf("Which assignment is %s appealing? (1 through 5): ", name_buffer);
    if (scanf("%d", &appeal_assignment) != 1 || appeal_assignment < 1 || appeal_assignment > 5)
    {
        printf(RED "ERROR:"R " There are only 5 assignments. You may choose 1 through 5.\n");
        while (getchar() != '\n') { }
        return;
    }
    while (getchar() != '\n') { }

    // Requests new status.
    printf("To what status should %s's assignment be changed to? (0 or 1): ", name_buffer);
    if (scanf("%d", &appeal_status) != 1 || (appeal_status != 0 && appeal_status != 1))
        {
        printf(RED "ERROR:" R " '%d' must be 0 or 1.\n", appeal_status);
        while (getchar() != '\n') { }
        return;
        }

    while (getchar() != '\n') { }
    // locate and update the student's assignment status
    for (i = 0; i < uni->count; i++)
    {
        if (strcmp(uni->students[i].name, name_buffer) == 0)
        {
            student_found = 1;
            uni->students[i].assignment[appeal_assignment - 1] = (char)('0' + appeal_status);
            uni->students[i].f_grade = count_passed_assignments(uni->students[i].assignment) >= 3 ? '1' : '0';

            printf("%s's assignment number %d was " GREEN "successfully" R " changed to %d.\n",
                   name_buffer, appeal_assignment + 1, appeal_status);
            break;
        }
    }

    if (!student_found)
    {
        printf(RED "ERROR:" R " There doesn't seem to be a student named %s in the input file.\n", name_buffer);
        return;
    }

    // re-print full pass status for all students under Option 5
    print_student_pass_status(uni, out, &pass_count);
    fprintf(out, "\n");
}

// This function marks the end of the program.
void end(FILE* out)
{
    fprintf(out, "Option 6:\nEnd Of Program.");
}

// This function returns the number of passed assignments.
int count_passed_assignments(char* assignment)
{
    int i, count = 0;

    for (i = 0; i < 6; i++)
        if (assignment[i] == '1')
            count++;

    return count;
}

// This function prints student info into the output file with '1' or '0' for at least 3 assignments passed.
void print_student_pass_status(Uni* uni, FILE* out, int* pass_count)
{
    int i;
    for (i = 0; i < uni->count; i++)
    {
        if (count_passed_assignments(uni->students[i].assignment) >= 3)
        {
            fprintf(out, "Student %d: %s %ld %.2f %s\n", i + 1, uni->students[i].name, uni->students[i].id, uni->students[i].grade, "1");
            (*pass_count)++;
        }
        else
            fprintf(out, "Student %d: %s %ld %.2f %s\n", i + 1, uni->students[i].name, uni->students[i].id, uni->students[i].grade, "0");
    }
}

// This function releases all dynamically allocated memory, including student names and the array.
void safe_exit(Uni* uni)
{
    int i;

    for (i = 0; i < uni->count; i++)
        free(uni->students[i].name);

    free(uni->students);
}