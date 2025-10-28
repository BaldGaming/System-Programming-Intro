// Declarations
#if 1
// Library Definitions
#if 1
#define _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <math.h>
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
#define LIGHT_BLUE "\033[38;2;150;150;255m"
#define R "\033[0m"
#endif
#endif

typedef struct Point
{
    float x,y;
} Point;

typedef struct Circle
{
    Point c;
    float r;
}Circle;

int in_or_out(Point p, Circle c);

int main()
{
    printf(UNDERLINE LIGHT_BLUE "Question 1\n\n" R);

    Point point;
    Circle circle;

    // Requests and assigns user values to a point.
    printf("Enter the coordinates of your point: ");
    while (1)
    {
        if (scanf("%f%f", &point.x, &point.y) != 2)
        {
            printf("Please make sure to only input numbers..\n\nTry again: ");
            while (getchar() != '\n');
        }
        else break;
    }

    // Requests and assigns user values to the center of the circle and its radius.
    printf("\nEnter the radius and the center of your circle: ");
    while (1)
    {
        if (scanf("%f%f%f", &circle.r, &circle.c.x, &circle.c.y) != 3)
        {
            printf("Please make sure to only input numbers..\n\nTry again: ");
            while (getchar() != '\n');
        }
        else break;
    }

    in_or_out(point, circle) == 1 ? printf("\nThe point " GREEN "is" R " included in the circle")
                                  : printf("\nThe point " RED "is not" R " included in the circle");
    return 0;
}

// This function determines whether a given point is within a given circle or not.
int in_or_out(Point p, Circle c)
{
    return sqrt(pow(p.x - c.c.x,2) + pow(p.y - c.c.y,2)) < c.r;
}