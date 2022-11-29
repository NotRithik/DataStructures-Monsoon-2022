#include "SkipList.h"

void addNodeNext(Node nodeToAddTo, int value)
{
    Node nodeToAdd = malloc(sizeof(struct SkipList));
    nodeToAddTo->next = nodeToAdd;

    nodeToAdd->value = value;
    nodeToAdd->next = NULL;
    nodeToAdd->nextK = NULL;
}

Node createSkipList(int *array, int size, int k)
{
    if (size <= 0)
    {
        return NULL;
    }

    Node head = malloc(sizeof(struct SkipList));
    head->next = NULL;
    head->nextK = NULL;
    head->value = array[0];

    Node temp = head;

    for (int i = 1; i < size; i++)
    {
        addNodeNext(temp, array[i]);
        temp = temp->next;
    }

    temp = head;

    int tempCount = 0;
    while (temp != NULL)
    {
        temp->nextK = temp;
        if (tempCount % k == 0)
        {
            for (int i = 0; i < k; i++)
            {
                if (temp->nextK != NULL)
                    temp->nextK = temp->nextK->next;
                // else
                //     break;
            }
        }
        else
        {
            temp->nextK = NULL;
        }
        temp = temp->next;
        tempCount++;
    }

    return head;
}