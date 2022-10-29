#include <stdio.h>
#include <stdlib.h>

// Create LinkedList structure
struct LinkedList
{
    int value;
    struct LinkedList *next;
};

typedef struct LinkedList Node; // Define type Node

void addNodeNext(int, Node *);
void delNextNode(Node *);
Node * createLinkedList(int *, int);

void main()
{
    // Node *nodeA = malloc(sizeof(Node)); // First element in LinkedList
    // nodeA->value = 13;

    // nodeA->next = malloc(sizeof(Node)); // Second element in LinkedList
    // nodeA->next->value = 69;

    // nodeA->next->next = NULL; // Make second element's 'next' pointer point to NULL so we know it is the end

    // addNodeNext(20, nodeA);
    // addNodeNext(20, nodeA->next);
    // delNextNode(nodeA);

    // while (nodeA != NULL)
    // {
    //     printf("%d\n", nodeA->value);
    //     nodeA = nodeA->next;
    // }

    int n = 10, something[n];
    for (int i = 0; i < n; i++)
    {
        something[i] = i+1;
    }

    Node *somethingLinkedList = createLinkedList(something, n);
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }
}

void addNodeNext(int value, Node *node)
{
    Node *temp = node->next;
    node->next = malloc(sizeof(Node));
    node->next->next = temp;
    node->next->value = value;
}

void delNextNode(Node *node)
{
    Node *temp = node->next->next;
    memset(node->next, 0, sizeof(Node));
    node->next = temp;
}

Node * createLinkedList(int *array, int size)
{
    if (size < 1)
    {
        return NULL;
    }

    Node *head = malloc(sizeof(Node));
    Node *temp;
    head->next = NULL;

    int i = 0;
    temp = head;

    while (i < size-1)
    {
        temp->value = array[i];
        temp->next = malloc(sizeof(Node));
        temp = temp->next;
        i++;
    }

    temp->value = array[i];
    temp->next = NULL;

    return head;
}