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
Node *createLinkedList(int *, int);
Node *reverseLinkedList(Node *);

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

    int n = 2, something[n];
    for (int i = 0; i < n; i++)
    {
        something[i] = i + 1;
    }

    Node *somethingLinkedList = createLinkedList(something, n);
    Node *head = somethingLinkedList;
    while (somethingLinkedList != NULL)
    {
        printf("%d, ", somethingLinkedList->value);
        somethingLinkedList = somethingLinkedList->next;
    }

    somethingLinkedList = head;

    somethingLinkedList = reverseLinkedList(somethingLinkedList);
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

    if (list->next->next == NULL) { // If 2 elements
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