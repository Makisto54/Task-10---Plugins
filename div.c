#include "functions.h"

void divide()
{
    int a = 0;
    int b = 0;

    printf("Input first number - ");
    scanf("%d", &a);
    printf("Input second number - ");
    scanf("%d", &b);

    if (0 == b)
    {
        printf("FALSE ARGUMENT\n");
    }
    else
    {
        printf("Result - %d\n", a / b);
    }
}