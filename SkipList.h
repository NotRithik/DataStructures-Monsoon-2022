#include <stdio.h>
#include <stdlib.h>

struct SkipList
{
    int value;
    struct SkipList *next;
    struct SkipList *nextK; // pointer to k'th element
};

typedef struct SkipList *Node; // Typedef the SkipList Node

Node createSkipList(int *array, int size, int k);

void addNodeNext(Node nodeToAddTo, int value);