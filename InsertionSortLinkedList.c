#include "LinkedList.h"

void insertChildOfNodeBBeforeChildOfNodeA(Node nodeA, Node nodeB)
{
    Node temp = nodeB->next;
    nodeB->next = nodeB->next->next;
    temp->next = nodeA->next;
    nodeA->next = temp;
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

    printf("The LinkedList after sorting with selection sort is: ");

    Node sortedNode;
    Node head = list;
    Node comparisonNode;

    for (sortedNode = head; sortedNode->next->next != NULL; sortedNode = sortedNode->next)
    {
        for (comparisonNode = head; comparisonNode->next != sortedNode->next; sortedNode = sortedNode->next)
        {
            if (sortedNode->next->next->value > comparisonNode->next->value)
            {
                continue;
            }
            else
            {
                break;
            }
        }
        insertChildOfNodeBBeforeChildOfNodeA(sortedNode->next, comparisonNode);
    }

    // insertChildOfNodeBBeforeChildOfNodeA(list, list->next->next->next);

    while (list != NULL)
    {
        printf("%d ", list->value);
        list = list->next;
    }
}
