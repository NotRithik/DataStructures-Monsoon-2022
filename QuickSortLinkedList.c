#include "LinkedList.h"

void insertChildOfNodeBBeforeChildOfNodeA(Node nodeA, Node nodeB);
Node quickSortLinkedList(Node list, int startPos, int endPos);

void main()
{

    printf("Enter the size of the list: ");
    int n;
    scanf("%d", &n);

    int array[n];
    printf("Enter the elements of the list:\n");
    for (int i = 0; i < n; i++)
    {
        scanf("%d", array + i);
    }

    Node list = createLinkedList(array, n);

    list = quickSortLinkedList(list, 0, findLengthOfLinkedList(list));

    printf("The LinkedList after sorting with QuickSort is: ");
    printLinkedList(list);
}

Node quickSortLinkedList(Node list, int startPos, int endPos)
{
    Node tempListHead = malloc(sizeof(Node));
    tempListHead->next = list;

    if (endPos <= startPos)
    {
        return list;
    }

    int partition = startPos;

    for (int i = startPos; i < endPos; i++)
    {
        if (findElementN(list, i)->value < findElementN(list, partition)->value)
        {
            insertChildOfNodeBBeforeChildOfNodeA(findElementN(tempListHead, i), findElementN(tempListHead, partition));
            partition += 1;
        }
    }

    memset(tempListHead, 0, sizeof(Node));

    list = quickSortLinkedList(list, startPos, partition);
    list = quickSortLinkedList(list, partition + 1, endPos);

    return list;
}

void insertChildOfNodeBBeforeChildOfNodeA(Node nodeA, Node nodeB)
{
    Node temp = nodeA->next;
    nodeA->next = nodeA->next->next;
    temp->next = nodeB->next;
    nodeB->next = temp;
}