#include<stdio.h>

void main() {
    float x;
    int numberTimesRan = 0;
    printf("with x<0.1:\n");
    for (x=0.0f; x<0.1f; x=x+0.01f) {
        printf("Ran %d number of times, %f\n", numberTimesRan, x);
        numberTimesRan += 1;
    }

    numberTimesRan = 0;
    printf("\nwith x<0.01:\n");
    for (x=0.0f; x<0.01f; x=x+0.001f) {
        printf("Ran %d number of times, %f\n", numberTimesRan, x);
        numberTimesRan += 1;
    }

    numberTimesRan = 0;
    printf("\nwith x<<<<0.01:\n");
    for (x=0.0f; x<0.000000000000000000000000000000000000000001f; x=x+0.0000000000000000000000000000000000000000001f) {
        printf("Ran %d number of times, %.100f\n", numberTimesRan, x);
        numberTimesRan += 1;
    }
}