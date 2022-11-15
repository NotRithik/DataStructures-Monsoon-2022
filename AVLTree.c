#include "AVLTree.h"

AVLTreeNode insertValueIntoAVLTree(AVLTreeNode root, int value)
{
    if (root == NULL)
        return NULL;

    if (value < root)
    {
        // Insert into left side
        AVLTreeNode newLeft = malloc(sizeof(struct AVLTreeStruct));
        newLeft->parent = root;
        newLeft->height = root->left->height + 1;
        newLeft->left = root->left;
        newLeft->right = NULL;
        newLeft->value = value;
        root->left = newLeft;
        root->height = root->height + 1;
        // Now balance the tree
        return balanceAVLTree(root);
    }
    else
    {
        // Insert into right side
        AVLTreeNode newRight = malloc(sizeof(struct AVLTreeStruct));
        newRight->parent = root;
        newRight->height = root->right->height + 1;
        newRight->right = root->right;
        newRight->right = NULL;
        newRight->value = value;
        root->right = newRight;
        root->height = root->height + 1;
        // Now balance the tree
        return balanceAVLTree(root);
    }
}

AVLTreeNode createAVLTreeFromArray(int *array, int size)
{
    if (size < 1)
        return;

    AVLTreeNode root = malloc(sizeof(struct AVLTreeStruct));
    root->value = array[0];
    root->height = 0;
    root->left = NULL;
    root->right = NULL;
    root->parent = NULL;

    for (int i = 0; i < size; i++)
    {
        root = insertValueIntoAVLTree(root, array[i]);
    }

    return root;
}

int setHeights(AVLTreeNode node) // Recursively calculate, set and
// return the height of a node and it's child nodes
{
    if (node == NULL)
        return 0;
    node->height = max(setHeights(node->left), setHeights(node->right)) + 1;
    return node->height;
}

int getBalance(AVLTreeNode node) // See if the tree is heavy towards the right or the left
// and if so, by how much. Positive value indicates right heavienss and negative value indicates left
// heaviness
{
    if (node == NULL)
        return 0;

    int leftChildHeight = 0, rightChildHeight = 0;
    if (node->left != NULL)
    {
        leftChildHeight = node->left->height;
    }
    if (node->right != NULL)
    {
        rightChildHeight = node->right->height;
    }

    return rightChildHeight - leftChildHeight;
}

AVLTreeNode balanceAVLTree(AVLTreeNode node)
{
    setHeights(node);
    if (getBalance(node) < -1) // If left heavy by more than 1, then rotate right
    {
        // Rotate right
        rotateRight(node);
    }

    if (getBalance(node) > 1) // If right heavy by more than 1, then rotate left
    {
        // Rotate left
        rotateLeft(node);
    }
}

AVLTreeNode rotateRight(AVLTreeNode node)
// Rotates and returns the node that is now in the position
// where the initially passed node used to be
{
    // To rotate right, we need to ensure that the left child is either balanced
    // Or is also left heavy
    // So if it is right heavy, left rotate it
    if (getBalance(node->left) > 0)
    {
        rotateLeft(node->left);
    }

    // Now perform the right rotation
    if (node->parent != NULL) // Check if the current node has a parent node
    {
        if (node == node->parent->right) // If node is the right child of its parent
        {
            node->parent->right = node->left;
            node->parent->right->right = node;
        }
        else // If node is the left child of its parent
        {
            node->parent->left = node->left;
            node->parent->left->right = node;
        }
        node->left = node->left->right;
    }

    else // If current node is the root node
    {
        node->parent = node->left;
        node->parent->parent = NULL;
        node->left = node->parent->right;
        node->parent->right = node;
    }

    assignParentsToAllNodes(node->parent);
    AVLTreeNode tempNode = node->parent;
    while (tempNode->parent != NULL)
    {
        tempNode = tempNode->parent;
    }
    setHeights(tempNode);
    return node->parent;
}

AVLTreeNode rotateLeft(AVLTreeNode node)
// Rotates and returns the node that is now in the position
// where the initially passed node used to be
{
    // To rotate left, we need to ensure that the right child is either balanced
    // Or is also right heavy
    // So if it is left heavy, right rotate it
    if (getBalance(node->right) < 0)
    {
        rotateRight(node->right);
    }

    // Now perform the left rotation
    if (node->parent != NULL) // Check if the current node has a parent node
    {
        if (node == node->parent->right) // If node is the right child of its parent
        {
            node->parent->right = node->right;
            node->parent->right->left = node;
        }
        else // If node is the left child of its parent
        {
            node->parent->left = node->right;
            node->parent->left->left = node;
        }
        node->right = node->right->left;
    }

    else // If current node is the root node
    {
        node->parent = node->right;
        node->parent->parent = NULL;
        node->right = node->parent->left;
        node->parent->left = node;
    }

    assignParentsToAllNodes(node->parent);
    AVLTreeNode tempNode = node->parent;
    while (tempNode->parent != NULL)
    {
        tempNode = tempNode->parent;
    }
    setHeights(tempNode);
    return node->parent;
}

void assignParentsToAllNodes(AVLTreeNode tree)
{
    if (tree == NULL)
    {
        return;
    }

    if (tree->left != NULL)
    {
        assignParentsToAllNodes(tree->left);
        tree->left->parent = tree;
    }

    if (tree->right != NULL)
    {
        assignParentsToAllNodes(tree->right);
        tree->right->parent = tree;
    }
}

AVLTreeNode findElementInAVLTree(AVLTreeNode tree, int value)
{
    if (tree == NULL)
        return NULL;

    if (tree->value == value)
    {
        return tree;
    }

    if (value > tree->value)
    {
        return findElementInAVLTree(tree->right, value);
    }
    else
    {
        return findElementInAVLTree(tree->left, value);
    }
}