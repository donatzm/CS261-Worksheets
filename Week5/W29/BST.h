#ifndef BST
#define BST

#define TYPE void*


struct Node{
    TYPE value;
    struct Node* left;
    struct Node* right;
};

struct BinarySearchTree{
    struct Node* root;
    int size;
};



#endif