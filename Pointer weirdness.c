#include<stdio.h>

void main() {
    int x=10, *pointerToX;
    pointerToX = &x;

    printf("value at pointerToX, %d\n", *++pointerToX);
    printf("incrementing and printing pointerToX, %d\n", *--pointerToX);

    printf("\nUsing the pointer as an array %d\n", pointerToX[0]);
}