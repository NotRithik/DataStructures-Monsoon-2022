#include "LinkedList.h"

Node sortLinkedListWithInsertionSort(Node);

void insertChildOfNodeBBeforeChildOfNodeA(Node nodeA, Node nodeB)
{
    Node temp = nodeA->next;
    nodeA->next = nodeA->next->next;
    temp->next = nodeB->next;
    nodeB->next = temp;
}

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

    Node sortedNode;
    Node head = list;
    Node comparisonNode;

    list = sortLinkedListWithInsertionSort(list);

    printf("The LinkedList after sorting with selection sort is: ");
    printLinkedList(list);
}

Node sortLinkedListWithInsertionSort(Node list)
{
    int sortedSublistPosition, index, size = findLengthOfLinkedList(list);
    Node sortedSublistNode, indexNode;

    Node tempLinkedListHead = malloc(sizeof(Node));
    tempLinkedListHead->next = list;
    list = tempLinkedListHead;

    for (sortedSublistPosition = 0; sortedSublistPosition < size; sortedSublistPosition++)
    {
        sortedSublistNode = findElementN(list, sortedSublistPosition);
        for (index = 0; index <= sortedSublistPosition; index++)
        {
            indexNode = findElementN(list, index);
            if (sortedSublistNode->next->value > indexNode->next->value)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        insertChildOfNodeBBeforeChildOfNodeA(sortedSublistNode, indexNode);
    }

    list = list->next;

    memset(tempLinkedListHead, 0, sizeof(Node));

    return list;
}
