#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedListDeque.h"
void PrintDeque(struct linkedList* q);

int main(){
    srand(time(NULL));

    struct linkedList * lldeque = malloc(sizeof(struct linkedList));

    LinkedListInit(lldeque);

    for(int i = 0; i < 100; i++)
    {
        int random = rand() % 4;
        int value = rand() % 100;
        switch(random)
        {
            case 0:
                printf("Added %d to the front of the deque.\n", value);
                LinkedListAddFront(lldeque, value);
                break;
            case 1:
                printf("Added %d to the back fo the deque.\n", value);
                LinkedListAddBack(lldeque, value);
                break;
            case 2:
                
                if(lldeque->size > 0)
                    {
                        printf("Removed %d from the front of the deque.\n",
                            LinkedListFront(lldeque));
                        LinkedListRemoveFront(lldeque);
                    }
                break;
            case 3:
                
                if(lldeque->size > 0)
                    {
                        printf("Removed %d from the back of the deque.\n",
                            LinkedListBack(lldeque));
                        LinkedListRemoveBack(lldeque);
                    }
                break;
            default:
                printf("nada\n");
        }

        PrintDeque(lldeque);

        if(LinkedListIsEmpty(lldeque) == 1)
        {
            printf("The deque is now empty.\n\n");
        }
        else
        {
            printf("There are %d elements left in the list.\n\n",
                lldeque->size);
        }
    }

    free(lldeque);
    
    return 0;
}

void PrintDeque(struct linkedList* q)
{
    struct dlink * link = q->frontSentinel->next;
    printf("Linked List : ");
    while(link->next != NULL)
    {
        printf("%3d ", link->value);
        link = link->next;
    }
    printf("\n");
}