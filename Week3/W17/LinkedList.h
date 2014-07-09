#ifndef LinkedList
#define LinkedList

#define TYPE int


struct link {
    TYPE value;
    struct link * next;
};

struct linkedListStack {
    struct link *firstLink;
};

void linkedListStackInit(struct linkedListStack* s);
void linkedListStackFree(struct linkedListStack* s);
void linkedListStackPush(struct linkedListStack* s, TYPE d);
TYPE linkedListStackTop(struct linkedListStack* s);
void linkedListStackPop(struct linkedListStack* s);
int linkedListStackIsEmpty(struct linkedListStack* s);

#endif