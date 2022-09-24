#include<stdio.h>

void printbin(unsigned n);

void main()
{
    char x = 0b1;
    char y = ~(0b0);
    char z;
    x=x<<2;

    z = x ^ y;

    printbin(x);
    printf("\n");
    printbin(y);
    printf("\n");
    printbin(z);
}

void printbin(unsigned n)
{
    unsigned i;
    for (i = 1 << 31; i > 0; i = i / 2)
        (n & i) ? printf("1") : printf("0");
}