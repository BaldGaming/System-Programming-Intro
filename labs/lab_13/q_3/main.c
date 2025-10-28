#include "header.h"

int main()
{
    int before, value, number;
    Queue queue;

    queue.head = queue.tail = NULL;
    queue.size = 0;

    printf(ITALIC UNDERLINE LIGHT_BLUE "Question 3\n\n" R);

    printf("Enter any number to be put into a %d long queue."
                  "\nTo quit, enter literally anything but a number.\n", NUM);

    // This loops requests and pushes numbers into a queue so long as the input is a whole number.
    while (1)
    {
        printf("\nEnter any whole number: ");
        if (scanf("%d", &number) != 1)
            break;

        // Records the size of the queue before enqueue.
        before = queue.size;

        // If at capacity, first enqueue then dequeue the oldest.
        // New elements are enqueued through the tail and old ones dequeued through the head.
        if (before >= NUM)
        {
            Enqueue(&queue, number);

            // This removes the oldest element and notifies the user of remuval and addition.
            if (Dequeue(&queue, &value))
                printf("%d was " RED "dequeued out!" R " ", value);

            printf("%d was " YELLOW "queued in!" R, number);
        }
        else
        {
            // Not yet full, it enqueue only.
            Enqueue(&queue, number);
            printf("%d was " YELLOW "queued in!" R, number);
        }

        printf(" The current queue is: " GREEN);
        print_queue(&queue);
        printf(R);
    }

    // This loop pushes every slot in the queue so long as it isn't empty.
    if (queue.size == 0)
    {
        printf("\nBetter enter a number next time!");
    }

    else
    {
        printf("\nNow dequeuing all numbers from the queue...\n");
        while (queue.size > 0)
        {
            if (Dequeue(&queue, &value))
            {
                printf("%d was " RED "dequeued out!" R " The current queue is: " GREEN, value);
                print_queue(&queue);
                printf(R);
            }
        }
    }

    free_queue(&queue);
    return 0;
}