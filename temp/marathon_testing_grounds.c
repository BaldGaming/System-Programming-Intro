#define  _CRT_SECURE_NO_WARNINGS
#include <stdio.h>
#include <stdlib.h>

void shit(FILE *, FILE*);

int main()
{
    FILE *one, *two;
    one = fopen("one.txt","r+");
    two = fopen("two.txt","r+");

    shit(one, two);
    fclose(one); fclose(two);
    return 0;
}


void shit ( FILE * one , FILE * two )
{
    int l1, l2;
    char st[3];

    fseek(one, 0, 2);
    l1 = ftell(one);
    fseek(two, 0, 2);
    l2 = ftell(two);

    if (l1 > l2)
    {
        fseek(one, 2, 0);
        fseek(two, 0, 0);

        while (fgets(st, 3, two) != NULL)
        {
            fputs(st, one);
            fseek(one, 2, 1);
        }
    }
    else
    {
        fseek(two, 2, 0);
        fseek(one, 0, 0);

        while (fgets(st, 3, one) != NULL)
        {
            fputs(st, two);
            fseek(two, 2, 1);
        }
    }
}