#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>

struct AVLTreeStruct
{
    int value;                    // Value at current node
    struct AVLTreeStruct *left;   // Pointer to left child
    struct AVLTreeStruct *right;  // Pointer to right child
    struct AVLTreeStruct *parent; // Pointer to parent
    int height;                   // Height of current node
};

typedef struct AVLTreeStruct *AVLTreeNode;

AVLTreeNode insertValueIntoAVLTree(AVLTreeNode root, int value);
int setHeights(AVLTreeNode node);
int getBalance(AVLTreeNode node);
AVLTreeNode rotateRight(AVLTreeNode node);
AVLTreeNode rotateLeft(AVLTreeNode node);
AVLTreeNode balanceAVLTree(AVLTreeNode node);
AVLTreeNode createAVLTreeFromArray(int *array, int size);
void assignParentsToAllNodes(AVLTreeNode tree);
AVLTreeNode findElementInAVLTree(AVLTreeNode tree, int value);
