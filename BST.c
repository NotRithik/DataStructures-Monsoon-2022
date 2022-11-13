#include "BST.h"

BinaryTreeNode createBinaryTreeNode(int value)
{
    BinaryTreeNode newNode = malloc(sizeof(BinaryTreeNode));
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

BinaryTreeNode createBinaryTreeFromArray(int *array, int size)
{
    if (size < 1)
    {
        return createBinaryTreeNode(NULL);
    }

    int *sortedArray = malloc(sizeof(int) * size); // Create new array and sort it,
                                                   // so as to not modify the inputted array

    for (int i = 0; i < size; i++) // Copy all values into new array
    {
        sortedArray[i] = array[i];
    }

    quickSort(sortedArray, 0, size);

    BinaryTreeNode newTree = createBinaryTreeNode(sortedArray[0]);
    BinaryTreeNode indexNode = newTree;

    for (int i = 1; i < size; i++)
    {
        indexNode->right = createBinaryTreeNode(sortedArray[i]);
        indexNode = indexNode->right;
    }

    return newTree;
}

void printBinaryTree(BinaryTreeNode tree)
{
    if (tree == NULL) // If the tree points to nothing, just return
    {
        return;
    }
    else // Else, print the smaller elements first, then print the node's value, then print the bigger elements
    {
        printBinaryTree(tree->left);
        printf("%d ", tree->value);
        printBinaryTree(tree->right);
    }
}

void quickSort(int *array, int startPos, int endPos)
{

    if (endPos <= startPos)
    {
        return;
    }

    int partition = startPos;

    for (int i = startPos; i < endPos; i++)
    {
        if (array[i] < array[partition])
        {
            moveElemAtXtoPosY(array, i, partition);
            partition += 1;
        }
    }

    quickSort(array, startPos, partition);
    quickSort(array, partition + 1, endPos);
}

void moveElemAtXtoPosY(int *array, int x, int y)
{
    int temp = array[x];
    for (int index = x; index > y; index--)
    {
        array[index] = array[index - 1];
    }
    array[y] = temp;
}