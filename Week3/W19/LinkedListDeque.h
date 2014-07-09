#ifndef LinkedListDeque
#define LinkedListDeque

#define TYPE int


struct dlink {
    TYPE value;
    struct dlink * next;
    struct dlink * prev;
};

struct linkedList {
    int size;
    struct dlink * frontSentinel;
    struct dlink * backSentinel;
};




#endif