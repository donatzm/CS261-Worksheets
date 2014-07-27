#include <bst.h>

int compare(TYPE left, TYPE right)
{
    struct data* dataL;
    struct data* dataR;


    if(dataL->value == dataR->value)
    {
        return 0;
    }
    else if(dataL->value < dataR->value)
    {
        return - 1;
    }
    else if(dataL->value > dataR->value)
    {
        return 1;
    }
}
void initBST(struct BinarySearchTree* tree)
{
    tree->size = 0;
    tree->root = NULL;
}

void addBST(struct BinarySearchTree* tree, TYPE newValue)
{
    tree->root = _nodeAddBST(tree->root, newValue);
    tree->size++;
}

int sizeBST(struct BinarySearchTree* tree)
{
    return tree->size;
}

struct Node* _nodeAddBST(struct Node* current, TYPE newValue)
{
    if(current == NULL)
    {
        struct Node* newNode = malloc(sizeof(struct Node));
        assert(newNode != NULL);

        newNode->value = newValue;
        newNode->left = NULL;
        newNode->right = NULL;
        return newNode;
    }

    if(compare(newValue, current->value) == -1)
    {
        current->left = _nodeAddBST(current->left, newValue);
    }
    else if(compare(newValue, current->value) == 1)
    {
        current->right = _nodeAddBST(current->right, newValue);
    }

    return current;
}

int containsBST(struct BinarySearchTree* tree, TYPE value)
{
    struct Node* currentNode;
    currentNode = tree->root;

    while(currentNode != NULL)
    {
        if(compare(currentNode->value, value) == 0)
        {
            return 1;
        }
        else if (compare(currentNode->value, value) == -1)
        {
            currentNode = currentNode->left;
        }
        else if(compare(currentNode->value, value) == 1)
        {
            currentNode = currentNode->right;
        }
    }

    return 0;
}

void removeBST(struct BinarySearchTree* tree, TYPE value)
{
    if(containsBST(tree, value))
    {
        tree->root = _nodeReMoveBST(tree->root, value);
        tree->size--;
    }
}

TYPE _leftmostChild(struct Node* current)
{
    if(current->left = NULL)
    {
        return current->value;
    }
    else
    {
        return _leftmostChild(current->left);
    }
}

struct Node* _removeLeftmostChild(struct Node* current)
{
    if(current->left == NULL)
    {
        free(current);
        return NULL;
    }
    else
    {
        current->left = _removeLeftmostChild(current->left);
    }
}