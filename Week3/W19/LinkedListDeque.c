#include <stdlib.h>
#include <assert.h>

#include "LinkedListDeque.h"

void LinkedListInit(struct linkedList* q)
{
    struct dlink * frontSntl = malloc(sizeof(struct dlink));
    assert(frontSntl != 0);

    struct dlink * backSntl = malloc(sizeof(struct dlink));
    assert(backSntl != 0);

    frontSntl->prev = NULL;
    frontSntl->next = q->backSentinel;
    
    backSntl->prev = q->frontSentinel;
    backSntl->next = NULL;

    q->frontSentinel = frontSntl;
    q->backSentinel = backSntl;
    q->size = 0;
}

void LinkedListFree(struct linkedList* q)
{
    while(q->size > 0)
    {
        LinkedListRemoveFront(q);
    }

    free(q->frontSentinel);
    free(q->backSentinel);

    q->frontSentinel = NULL;
    q->backSentinel = NULL;
}

void LinkedListAddFront(struct linkedList * q, TYPE e)
{
    struct dlink * frontSntl = q->frontSentinel;

    _addBefore(q, frontSntl->next, e);
}

void LinkedListAddBack(struct linkedList* q, TYPE e)
{
    struct dlink * backSntl = q->backSentinel;

    _addBefore(q, backSntl, e);
}

void LinkedListRemoveFront(struct linkedList* q)
{
    assert(!linkedListIsEmpty(q));
    _removeLink(q, q->frontSentinel->next);
}

void LinkedListRemoveBack(struct linkedList* q)
{
    assert(!linkedListIsEmpty(q));
    _removeLink(q, q->backSentinel->prev);
}

int LInkedListIsEmpty(struct linkedList* q)
{
    return q->size == 0;
}

void _addBefore(struct linkedList* q, struct dlink * lnk, TYPE e)
{

}

void _removeLink(struct linkedList* q, struct dlink * lnk)
{

}

TYPE LinkedListFront(struct linkedList* q)
{
    TYPE front = 0;

    return front;
}

TYPE LinkedListBack(struct linkedList* q)
{
    TYPE back = 0;

    return back;
}