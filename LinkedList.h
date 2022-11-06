#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create LinkedList structure
struct LinkedList
{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList *Node; // Define type Node

void addNodeNext(int, Node);
void delNextNode(Node);
Node createLinkedList(int *, int);
Node reverseLinkedList(Node);
Node chunkReverseLinkedList(Node, int);
Node reverseChunk(Node, int);
Node findElementN(Node, int);