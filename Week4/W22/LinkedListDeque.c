#include <stdlib.h>
#include <assert.h>
#include <stdio.h>

#include "LinkedListDeque.h"

void LinkedListInit(struct linkedList* q)
{
    q->frontSentinel = malloc(sizeof(struct dlink));
    assert(q->frontSentinel != 0);

    q->backSentinel = malloc(sizeof(struct dlink));
    assert(q->backSentinel != 0);

    q->frontSentinel->next = q->backSentinel;
    q->frontSentinel->prev = NULL;

    q->backSentinel->prev = q->frontSentinel;
    q->backSentinel->next = NULL;

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

    free(q);
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
    assert(!LinkedListIsEmpty(q));
    _removeLink(q, q->frontSentinel->next);
}

void LinkedListRemoveBack(struct linkedList* q)
{
    assert(!LinkedListIsEmpty(q));
    _removeLink(q, q->backSentinel->prev);
}

int LinkedListIsEmpty(struct linkedList* q)
{
    return q->size == 0;
}

void _addBefore(struct linkedList* q, struct dlink * lnk, TYPE e)
{
    assert(lnk != 0);
    struct dlink * previous = lnk->prev;
    struct dlink * newlink = malloc(sizeof(struct dlink));
    assert(newlink != 0);

    newlink->value = e;
    newlink->prev = previous;
    newlink->next = lnk;

    previous->next = newlink;
    lnk->prev = newlink;

    q->size++;

}

void _removeLink(struct linkedList* q, struct dlink * lnk)
{
    struct dlink * previous = lnk->prev;
    struct dlink * following = lnk->next;

    previous->next = following;
    following->prev = previous;

    lnk->prev = NULL;
    lnk->next = NULL;

    free(lnk);
    q->size--;
}

TYPE LinkedListFront(struct linkedList* q)
{
    TYPE front = 0;

    front = q->frontSentinel->next->value;

    return front;
}

TYPE LinkedListBack(struct linkedList* q)
{
    TYPE back = 0;

    back = q->backSentinel->prev->value;
    return back;
}