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


void LinkedListInit(struct linkedList* q);
void LinkedListFree(struct linkedList* q);
void LinkedListAddFront(struct linkedList * q, TYPE e);
void LinkedListAddBack(struct linkedList* q, TYPE e);
void LinkedListRemoveFront(struct linkedList* q);
void LinkedListRemoveBack(struct linkedList* q);
int LinkedListIsEmpty(struct linkedList* q);
void _addBefore(struct linkedList* q, struct dlink * lnk, TYPE e);
void _removeLink(struct linkedList* q, struct dlink * lnk);
TYPE LinkedListFront(struct linkedList* q);
TYPE LinkedListBack(struct linkedList* q);

#endif