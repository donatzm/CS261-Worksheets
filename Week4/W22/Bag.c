#include <stdlib.h>
#include <assert.h>
#include <stdio.h>


#include "LinkedListDeque.h"
#include "Bag.h"


void BagAdd(struct linkedList* lst, TYPE e)
{
    if(!BagContains(lst, e))
    {
        LinkedListAddFront(lst, e);
    }
}

int BagContains(struct linkedList* lst, TYPE e)
{
    struct dlink* cursor = lst->frontSentinel->next;

    while(cursor != lst->backSentinel)
    {
        if(cursor->value == e)
        {
            return 1;
        }
        cursor = cursor->next;
    }

    return 0;
}

void BagRemove(struct linkedList* lst, TYPE e)
{
    struct dlink* cursor = lst->frontSentinel->next;

    while(cursor != lst->backSentinel)
    {
        if(cursor->value == e)
        {
            _removeLink(lst, cursor);
        }
        return;
    }
}


