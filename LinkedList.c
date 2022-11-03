#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>

// Create LinkedList structure
struct LinkedList
{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList Node; // Define type Node

void addNodeNext(int, Node *);
void delNextNode(Node *);
Node *createLinkedList(int *, int);
Node *reverseLinkedList(Node *);
Node *chunkReverseLinkedList(Node *, int, int);
Node *reverseChunk(Node *, int);
Node *findElementN(Node *, int);

void main()
{
    int n = 10, something[n];
    for (int i = 0; i < n; i++)
    {
        something[i] = i;
    }

    Node *somethingLinkedList = createLinkedList(something, n);
    Node *head = somethingLinkedList;
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }

    somethingLinkedList = head;

    // somethingLinkedList = reverseLinkedList(somethingLinkedList);
    // while (somethingLinkedList != NULL)
    // {
    //     printf("%d, ", somethingLinkedList->value);
    //     somethingLinkedList = somethingLinkedList->next;
    // }

    printf("\n");

    somethingLinkedList = reverseChunk(somethingLinkedList, 5);
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }
}

void addNodeNext(int value, Node *node)
{
    if (node->next != NULL)
    {
        Node *temp = node->next;
        node->next = malloc(sizeof(Node));
        node->next->next = temp;
        node->next->value = value;
    }
    else
    {
        node->next = malloc(sizeof(Node));
        node->next->next = NULL;
        node->next->value = value;
    }
}

void delNextNode(Node *node)
{
    Node *temp = node->next->next;
    memset(node->next, 0, sizeof(Node));
    node->next = temp;
}

Node *createLinkedList(int *array, int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    Node *head = malloc(sizeof(Node));
    head->next = NULL;
    head->value = array[0];

    Node *temp = head;

    int i = 1;
    temp = head;

    while (i < size)
    {
        addNodeNext(array[i], temp);
        temp = temp->next;
        i++;
    }

    return head;
}

Node *reverseLinkedList(Node *list)
{

    if (list == NULL || list->next == NULL) // If 0 or 1 element
    {
        return list;
    }

    if (list->next->next == NULL)
    { // If 2 elements
        Node *temp = list->next;
        list->next->next = list;
        list->next = NULL;
        return temp;
    }

    Node *secPrev = list;
    Node *prev = list->next;
    Node *current = list->next->next;

    secPrev->next = NULL;

    while (current != NULL)
    {
        prev->next = secPrev;

        secPrev = prev;
        prev = current;

        current = current->next;
    }

    return current;
}

Node *chunkReverseLinkedList(Node *list, int chunkSize, int listSize)
{
    if (list == NULL)
    {
        return NULL;
    }

    int index;

    Node *chunkHead = list, *oldChunkTail = list;
    Node *newHead = findElementN(list, chunkSize);

    // Check if there are chunkSize number of elements in the list or not
    Node *tempNode = list;
    bool flag = 1;

    int iteration = 0;

    while (flag)
    {
        for (int i = 0; i < chunkSize; i++)
        {
            if (tempNode != NULL)
            {
                tempNode = tempNode->next;
            }
            else
            {
                // set flag
                flag = 0;
            }
        }

        tempNode = tempNode->next;

        // If no, just reverse the entire list. If yes, then reverse a chunk then
        if (!flag)
        {
            chunkHead = reverseLinkedList(oldChunkTail->next);
            oldChunkTail->next = chunkHead;
        }
        else
        {
            Node *temp = chunkHead;
            chunkHead = reverseChunk(oldChunkTail->next, chunkSize);
            oldChunkTail->next = tempNode;
            oldChunkTail = temp;
        }
    }
    // Keep reversing list

    return newHead;
}

Node *reverseChunk(Node *list, int chunkSize) // Reverse chunk and return new head
{
    Node *oldHead = list;

    Node *secPrev = list;
    Node *prev = list->next;
    Node *current = list->next->next;

    secPrev->next = NULL;

    int i = 0;

    while (i < chunkSize - 1)
    {
        prev->next = secPrev;

        secPrev = prev;
        prev = current;

        current = current->next;

        i++;
    }

    oldHead->next = prev;

    return secPrev;
}

Node *findElementN(Node *list, int n)
{

    if (list == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n && list->next != NULL; i++)
    {
        list = list->next;
    }

    return list;
}