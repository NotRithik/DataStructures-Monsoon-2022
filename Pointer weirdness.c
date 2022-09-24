#include <stdio.h>

void main()
{
    int x = 10, *pointerToX;
    pointerToX = &x;

    long long int y = 258;
    char *pointerToLongLong;
    pointerToLongLong = &y;

    double someDouble = 10;
    char *pointerToDouble;
    pointerToDouble = &someDouble;

    printf("value at pointerToX, %d\n", *++pointerToX);
    printf("incrementing and printing pointerToX, %d\n", *--pointerToX);

    printf("\nUsing the pointer as an array %d\n", pointerToX[0]);

    printf("\nsize of long: %d, int: %d, float: %d, char: %d, double: %d\n",
           sizeof(long), sizeof(int), sizeof(float), sizeof(char), sizeof(double));
    printf("Size of long long: %d, long int: %d, long long int: %d\n",
           sizeof(long long), sizeof(long int), sizeof(long long int));

    printf("double printed as chars: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", pointerToDouble[i]);
    }
    printf("\n");

    printf("long printed as chars: ");
    for (int i = 0; i < 8; i++)
    {
        printf("%d ", pointerToLongLong[i]);
    }
    printf("\n");
}