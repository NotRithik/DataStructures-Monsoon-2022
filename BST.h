#include <stdio.h>
#include <stdbool.h>

struct BinaryTreeNodeStruct
{
    int value;                          // Value at current node
    struct BinaryTreeNodeStruct *left;  // Pointer to left child
    struct BinaryTreeNodeStruct *right; // Pointer to right child
};

typedef BinaryTreeNodeStruct *BinaryTreeNode;

BinaryTreeNode createBinaryTreeNode(int value);
BinaryTreeNode createBinaryTreeFromArray(int *array, int size);
void printBinaryTree(BinaryTreeNode tree);

void quickSort(int *array, int startPos, int endPos); // Compile with QuickSort.c or this function won't work
