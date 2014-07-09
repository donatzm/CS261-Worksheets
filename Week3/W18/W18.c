#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedListQueue.h"
void PrintQueue(struct listQueue* q);

int main(){
    srand(time(NULL));

    struct listQueue * lqueue = malloc(sizeof(struct listQueue));

    listQueueInit(lqueue);

    for(int i = 0; i < 100; i++)
    {
        int random = rand() % 2;
        int value = rand() % 100;
        switch(random)
        {
            case 0:
                printf("Added %d to the back of the queue.\n", value);
                listQueueAddBack(lqueue, value);
                break;
            case 1:
                if(!listQueueIsEmpty(lqueue))
                    {
                        printf("Removed %d from the front of the queue.\n",
                            listQueueFront(lqueue));
                        listQueueRemoveFront(lqueue);
                    }
                break;
            default:
                printf("nada\n");
        }

        PrintQueue(lqueue);

    }

    free(lqueue);
    
    return 0;
}

void PrintQueue(struct listQueue* q)
{
    struct link * alink = q->firstLink->next;
    printf("Linked Queue : ");
    while(alink != NULL)
    {
        printf("%3d ", alink->value);
        alink = alink->next;
    }
    printf("\n\n");
}