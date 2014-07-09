#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "LinkedList.h"
void PrintList(struct linkedListStack* q);

int main(){
    srand(time(NULL));

    struct linkedListStack * stack = malloc(sizeof(struct linkedListStack));

    linkedListStackInit(stack);

    for(int i = 0; i < 100; i++)
    {
        int random = rand() % 2;
        int value = rand() % 100;
        switch(random)
        {
            case 0:
                printf("Pushed %d ontop the stack.\n", value);
                linkedListStackPush(stack, value);
                break;
            case 1:
                if(!linkedListStackIsEmpty(stack))
                    {
                        printf("Popped %d from the stack.\n",
                            linkedListStackTop(stack));
                        linkedListStackPop(stack);
                    }
                break;
            default:
                printf("nada\n");
        }

        PrintList(stack);

    }

    free(stack);
    
    return 0;
}

void PrintList(struct linkedListStack* q)
{
    struct link * alink = q->firstLink;
    printf("Linked List Stack : ");
    while(alink != NULL)
    {
        printf("%3d ", alink->value);
        alink = alink->next;
    }
    printf("\n\n");
}