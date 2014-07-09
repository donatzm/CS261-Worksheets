#ifndef LinkedListQueue
#define LinkedListQueue

#define TYPE int


struct link {
    TYPE value;
    struct link * next;
};

struct listQueue {
    struct link* firstLink;
    struct link* lastLink;
};

void listQueueInit(struct listQueue* q);
void listQueueStackFree(struct listQueue* q);
void listQueueAddBack(struct listQueue* q, TYPE e);
TYPE listQueueFront(struct listQueue* q);
void listQueueRemoveFront(struct listQueue* q);
int listQueueIsEmpty(struct listQueue* q);

#endif