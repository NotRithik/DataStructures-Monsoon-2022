#include "./LinkedList.h"

void swapNodes(Node nodeA, Node nodeB)
{
    int temp = nodeA->value;
    nodeA->value = nodeB->value;
    nodeB->value = temp;
}

int findLengthOfLinkedList(Node list)
{
    int length = 0;
    while (list != NULL)
    {
        list = list->next;
        length++;
    }
}

void addNodeNext(int value, Node node)
{
    if (node->next != NULL)
    {
        Node temp = node->next;
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

void delNextNode(Node node)
{
    Node temp = node->next->next;
    memset(node->next, 0, sizeof(Node));
    node->next = temp;
}

Node createLinkedList(int *array, int size)
{
    if (size <= 0)
    {
        return NULL;
    }

    Node head = malloc(sizeof(Node));
    head->next = NULL;
    head->value = array[0];

    Node temp = head;

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

Node reverseLinkedList(Node list)
{

    if (list == NULL || list->next == NULL) // If 0 or 1 element
    {
        return list;
    }

    if (list->next->next == NULL)
    { // If 2 elements
        Node temp = list->next;
        list->next->next = list;
        list->next = NULL;
        return temp;
    }

    Node secPrev = list;
    Node prev = list->next;
    Node current = list->next->next;

    secPrev->next = NULL;

    while (current != NULL)
    {
        prev->next = secPrev;

        secPrev = prev;
        prev = current;

        current = current->next;
    }

    prev->next = secPrev;

    secPrev = prev;

    return secPrev;
}

Node chunkReverseLinkedList(Node list, int chunkSize)
{
    Node lastElementOfCurrentChunk = findElementN(list, chunkSize - 1);

    if (lastElementOfCurrentChunk == NULL) // If list has less than chunkSize number of elements left
    {
        return reverseLinkedList(list);
    }

    Node firstElementOfNextChunk = lastElementOfCurrentChunk->next;

    Node tailOfCurrentChunk = list;
    Node headOfCurrentChunk = reverseChunk(list, chunkSize);

    if (firstElementOfNextChunk == NULL)
    {
        tailOfCurrentChunk->next == NULL;
    }
    else
    {
        tailOfCurrentChunk->next = chunkReverseLinkedList(firstElementOfNextChunk, chunkSize);
    }

    return headOfCurrentChunk;
}

Node reverseChunk(Node list, int chunkSize) // Reverse chunk and return new head
{
    // If there are less than or equal to chunkSize number of elements in the list, just reverse the list
    Node checkerNode = list;
    int i = 0;
    while (i <= chunkSize)
    {
        if (checkerNode == NULL)
        {
            return reverseLinkedList(list);
        }

        checkerNode = checkerNode->next;
        i++;
    }

    Node oldHead = list;

    Node secPrev = list;
    Node prev = list->next;
    Node current = list->next->next;

    secPrev->next = NULL;

    i = 0;

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

Node findElementN(Node list, int n)
{

    if (list == NULL)
    {
        return NULL;
    }

    for (int i = 0; i < n; i++)
    {
        if (list == NULL)
            return NULL;
        list = list->next;
    }

    return list;
}