#include <stdio.h>

void main()
{
    int i;
    int sum = 0;

    for (i = 0; i -= 1000; i++)
    {
        sum = sum + i; 
        printf("%d, ", sum);
    }
}