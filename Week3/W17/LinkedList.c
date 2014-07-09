#include <stdlib.h>
#include <assert.h>

#include "LinkedList.h"

void linkedListStackInit(struct linkedListStack* s)
{
    s->firstLink = 0;
}

void linkedListStackFree(struct linkedListStack* s)
{
    while(!linkedListStackIsEmpty(s))
    {
        linkedListStackPop(s);
    }
}

void linkedListStackPush(struct linkedListStack* s, TYPE d)
{
    struct link * newLink = (struct link *) malloc(sizeof(struct link));
    assert(newLink != 0);

    struct link* topLink = s->firstLink;

    s->firstLink = newLink;
    newLink->next = topLink;
    newLink->value = d;

}

TYPE linkedListStackTop(struct linkedListStack* s)
{
    struct link* topLink = s->firstLink;
    
    assert(topLink != 0);

    TYPE top = topLink->value;

    return top;
}

void linkedListStackPop(struct linkedListStack* s)
{
    struct link* popped = s->firstLink;

    assert(popped != 0);

    s->firstLink = popped->next;
    popped->next = 0;
    free(popped);
}

int linkedListStackIsEmpty(struct linkedListStack* s)
{
    int isEmpty = 0;

    if(s->firstLink == 0)
    {
        isEmpty = 1;
    }

    return isEmpty;
}