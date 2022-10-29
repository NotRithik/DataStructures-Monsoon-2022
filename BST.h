#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
struct BinaryTreeNodeStruct
{
    int value;                          // Value at current node
    struct BinaryTreeNodeStruct *left;  // Pointer to left child
    struct BinaryTreeNodeStruct *right; // Pointer to right child
    struct BinaryTreeNodeStruct *parent;
};

typedef struct BinaryTreeNodeStruct *BinaryTreeNode;

BinaryTreeNode createBinaryTreeNode(int value);
BinaryTreeNode createBinaryTreeFromArray(int *array, int size);
BinaryTreeNode findElementInBinaryTree(BinaryTreeNode tree, int value);
BinaryTreeNode findMinimumInBST(BinaryTreeNode tree);
BinaryTreeNode findMaximumInBST(BinaryTreeNode tree);
BinaryTreeNode findSuccessorInBST(BinaryTreeNode nodeToFindSuccessorOf);
bool isLeafNode(BinaryTreeNode node);
void swapBSTNodes(BinaryTreeNode nodeX, BinaryTreeNode nodeY);
BinaryTreeNode deleteNodeInBST(BinaryTreeNode node);
void printBinaryTree(BinaryTreeNode tree);

void quickSort(int *array, int startPos, int endPos);
void moveElemAtXtoPosY(int *array, int x, int y);