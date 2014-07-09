#include <stdlib.h>
#include <assert.h>

#include "LinkedListQueue.h"

void listQueueInit(struct listQueue* q)
{
    // lnk is the sentinel
    struct link * sntl = (struct link *) malloc(sizeof(struct link));
    assert(sntl != 0);
    sntl->next = 0;

    // set the container ends
    q->firstLink = sntl; //It should always be the case that firstLink == sntl
    q->lastLink = sntl;

}

void listQueueStackFree(struct listQueue* q)
{
    while(!listQueueIsEmpty(q))
    {
        listQueueRemoveFront(q);
    }
}

void listQueueAddBack(struct listQueue* q, TYPE e)
{
    struct link * newLink = (struct link *) malloc(sizeof(struct link));
    struct link * lastLink = q->lastLink;
    assert(newLink != 0);

    lastLink->next = newLink;
    q->lastLink = newLink;

    newLink->value = e;
    newLink->next = 0;
}

TYPE listQueueFront(struct listQueue* q)
{
    TYPE front = 0;

    struct link * sntl = q->firstLink;
    struct link * first = sntl->next;

    assert(first != 0);

    front = first->value;

    return front;
}

void listQueueRemoveFront(struct listQueue* q)
{
    struct link * sntl = q->firstLink;
    struct link * popped = sntl->next;

    assert(popped != 0);

    //IF we remove the last link in the list
    if(popped == q->lastLink)
    {
        q->lastLink = sntl;
    }

    sntl->next = popped->next;
    popped->next = 0;
    free(popped);


}

int listQueueIsEmpty(struct listQueue* q)
{
    int isEmpty = 0;

    // The firstLink is always the sentinel.  
    if(q->firstLink == q->lastLink)
    {
        isEmpty = 1;
    }

    return isEmpty;
}