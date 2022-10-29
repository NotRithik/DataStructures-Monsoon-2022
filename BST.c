#include "BST.h"

BinaryTreeNode createBinaryTreeNode(int value)
{
    BinaryTreeNode newNode = malloc(sizeof(BinaryTreeNode));
    newNode->value = value;
    newNode->right = NULL;
    newNode->left = NULL;
    return newNode;
}

BinaryTreeNode _createBinaryTreeFromArrayInnerFunc(int *array, int size)
{
    if (size < 0)
    {
        return NULL;
    }

    quickSort(array, 0, size);

    int mid = (int)(size / 2);
    BinaryTreeNode root = malloc(sizeof(struct BinaryTreeNodeStruct));
    root->value = array[mid];

    root->left = _createBinaryTreeFromArrayInnerFunc(array, mid - 1);
    if (root->left != NULL)
        if (root->left->value > root->value)
        {
            memset(root->left, 0, sizeof(BinaryTreeNode));
            root->left = NULL;
        }

    root->right = _createBinaryTreeFromArrayInnerFunc(array + mid + 1, size - (mid + 1));
    if (root->right != NULL)
        if (root->right->value < root->value)
        {
            memset(root->right, 0, sizeof(BinaryTreeNode));
            root->right = NULL;
        }

    return root;
}

void _assignParentsToAllNodes(BinaryTreeNode tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->left != NULL)
    {
        _assignParentsToAllNodes(tree->left);
        tree->left->parent = tree;
    }

    if (tree->right != NULL)
    {
        _assignParentsToAllNodes(tree->right);
        tree->right->parent = tree;
    }
}

BinaryTreeNode findElementInBinaryTree(BinaryTreeNode tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (tree->value == value)
    {
        return tree;
    }

    if (value > tree->value)
    {
        return findElementInBinaryTree(tree->right, value);
    }
    else
    {
        return findElementInBinaryTree(tree->left, value);
    }
}

BinaryTreeNode createBinaryTreeFromArray(int *array, int size)
{
    BinaryTreeNode tree = _createBinaryTreeFromArrayInnerFunc(array, size - 1);
    _assignParentsToAllNodes(tree);
    tree->parent = NULL;
    return tree;
}

BinaryTreeNode findMinimumInBST(BinaryTreeNode tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    while (tree->left != NULL)
    {
        tree = tree->left;
    }

    return tree;
}

BinaryTreeNode findMaximumInBST(BinaryTreeNode tree)
{
    if (tree == NULL)
    {
        return NULL;
    }

    while (tree->right != NULL)
    {
        tree = tree->right;
    }

    return tree;
}

BinaryTreeNode findSuccessorInBST(BinaryTreeNode nodeToFindSuccessorOf)
{
    if (nodeToFindSuccessorOf == NULL)
    {
        return NULL;
    }

    if (nodeToFindSuccessorOf->right != NULL)
    {
        return findMinimumInBST(nodeToFindSuccessorOf->right);
    }

    BinaryTreeNode parent = nodeToFindSuccessorOf->parent;

    while (!(parent == NULL || nodeToFindSuccessorOf != parent->right))
    {
        nodeToFindSuccessorOf = parent;
        parent = parent->parent;
    }

    return parent;
}

bool isBinaryTreeLeafNode(BinaryTreeNode node)
{
    if (node->left == NULL && node->right == NULL)
        return true;
    else
        return false;
}

void swapBSTNodes(BinaryTreeNode nodeX, BinaryTreeNode nodeY)
{
    BinaryTreeNode temp;

    temp = nodeX->left;
    nodeX->left = nodeY->left;
    nodeY->left = temp;

    temp = nodeX->right;
    nodeX->right = nodeY->right;
    nodeY->right = temp;

    if (nodeX->right != NULL)
        nodeX->right->parent = nodeX;
    if (nodeX->left != NULL)
        nodeX->left->parent = nodeX;

    if (nodeY->left != NULL)
        nodeY->left->parent = nodeY;
    if (nodeY->right != NULL)
        nodeY->right->parent = nodeY;

    temp = nodeX;
    if (nodeX->parent != NULL)
    {
        if (nodeX->parent->left == nodeX)
        {
            nodeX->parent->left = nodeY;
        }
        else
        {
            nodeX->parent->right = nodeY;
        }
    }

    if (nodeY->parent != NULL)
    {
        if (nodeY->parent->left == nodeY)
        {
            nodeY->parent->left = temp;
        }
        else
        {
            nodeY->parent->right = temp;
        }
    }

    temp = nodeX->parent;
    nodeX->parent = nodeY->parent;
    nodeY->parent = temp;
}

BinaryTreeNode deleteNodeInBST(BinaryTreeNode node)
{
    // If Node is a leaf node, go to its parent
    // free the left or right child node, whichever one corresponds to current element
    // and set the corresponding pointer to null

    // But if the parent itself is null, that means the entire tree had just one element.
    // So free the element and return null

    if (isBinaryTreeLeafNode(node))
    {
        if (node->parent == NULL)
        {
            memset(node, 0, sizeof(BinaryTreeNode));
            return NULL;
        }

        if (node->parent->left == node)
        {
            node = node->parent;
            memset(node->left, 0, sizeof(BinaryTreeNode));
            node->left = NULL;
        }
        else
        {
            node = node->parent;
            memset(node->right, 0, sizeof(BinaryTreeNode));
            node->right = NULL;
        }
    }

    // If it is not a leaf node, check if its left node is a leaf node
    // If yes, then delete node and move the left node up to the deleted node's spot
    if (isBinaryTreeLeafNode(node->left))
    {
        // swap left node and current node
        // free left node and then make current node's left pointer to point to null
        swapBSTNodes(node, node->left);
        memset(node->left, 0, sizeof(BinaryTreeNode));
        node->left = NULL;
    }
    else if (isBinaryTreeLeafNode(node->right)) // Do the same for right node
    {
        // swap right node and current node
        // free right node and then make current node's right pointer to point to null
        swapBSTNodes(node, node->right);
        memset(node->right, 0, sizeof(BinaryTreeNode));
        node->right = NULL;
    }
    else
    {
        BinaryTreeNode temp = findMinimumInBST(node->right);
        // Swap min leafNode and node
        swapBSTNodes(node, temp);

        // We know that node is now the minimum element (so it is the left subchild)
        // Just delete this element and bring right subchild to this element's place
        node->parent->left = node->right;
        if (node->right != NULL)
            node->right->parent = node->parent;
        memset(node, 0, sizeof(BinaryTreeNode));
    }

    while (node->parent != NULL)
    {
        node = node->parent;
        return node;
    }
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