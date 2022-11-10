#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create LinkedList structure
struct LinkedList
{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList * Node; // Define type Node

void printLinkedList(Node list);
void addNodeNext(int value, Node);
void delNextNode(Node);
Node createLinkedList(int *array, int size);
Node reverseLinkedList(Node list);
Node chunkReverseLinkedList(Node list, int chunkSize);
Node reverseChunk(Node list, int chunkSize);
Node findElementN(Node list, int index);
void swapNodes(Node nodeA, Node nodeB);
int findLengthOfLinkedList(Node list);