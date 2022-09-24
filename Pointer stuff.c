#include<stdio.h>
void main() {
    int y = 200;
    unsigned int *x = &y;

    printf("%d\n", x);
    printf("%d", *x);
}