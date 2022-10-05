#include <stdio.h>
#include <stdlib.h>

// Create LinkedList structure
struct LinkedList {
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList Node; // Define type Node

void main()
{
    Node *nodeA = malloc(sizeof(Node));
    nodeA->value = 13;

    nodeA->next = malloc(sizeof(Node));
    nodeA->next->value = 69;

    nodeA->next->next = NULL;

    while (nodeA != NULL)
    {
        printf("%d\n", nodeA->value);
        nodeA = nodeA->next;
    }
}
