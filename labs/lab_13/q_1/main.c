#include "header.h"

int main()
{
    int i = 0, value, number;
    Stack stack;
    stack.head = NULL;
    stack.size = 0;

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 1\n\n" R);

    printf("Enter %d whole numbers:\n", NUM);
    // This loops requests and pushes numbers into a stack.
    while (i < NUM)
    {
        if (scanf("%d", &number) != 1)
        {
            while (getchar() != '\n')
                printf(RED "\nERROR:" R " The program accepts numbers only.\n\nTry again:\n");
        }

        else
        {
            // Sends off the number to be pushed into the stack.
            Push(&stack, number);

            // Prints the current stack.
            printf("The current stack is: " GREEN);
            print_stack(&stack);
            i++;
            printf(R);
        }
    }
    printf("The stack is full\n");


    // This loop pops every slot in the stack.
    printf("\nNow popping all of the numbers from the stack...\n");
    while (stack.size > 0)
    {
        // These pops said slots if it's not empty.
        if (Pop(&stack, &value))
        {
            printf("%d was " YELLOW "popped!" R " The current stack is: " GREEN, value);
            print_stack(&stack);
            printf(R);
        }
    }

    free_stack(&stack);
    return 0;
}