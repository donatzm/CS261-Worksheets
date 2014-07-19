#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#include "Bag.h"

void PrintBag(struct linkedList* q);

int main()
{   
    srand(time(NULL));

    struct linkedList * bag = malloc(sizeof(struct linkedList));

    LinkedListInit(bag);

    for(int i = 0; i < 100; i++)
    {
        int random = rand() % 3;
        int value = rand() % 10;
        switch(random)
        {
            case 0:
                printf("Added %d to the bag.\n", value);
                BagAdd(bag, value);
                break;
            case 1:
                if(BagContains(bag, value))
                {
                    printf("Removed %d from the bag.\n", value);
                    BagRemove(bag, value);
                }
                else
                {
                    printf("Cannot remove non-existent %d from the bag.\n", value);
                }
                break;
            case 2:
                if(BagContains(bag, value))
                {
                    printf("The bag contains %d.\n", value);
                }
                else
                {
                    printf("The bag does not have %d.\n", value);
                }
                break;
            default:
                printf("nada\n");
        }

        PrintBag(bag);

        if(LinkedListIsEmpty(bag) == 1)
        {
            printf("The bag is now empty.\n\n");
        }
        else
        {
            printf("There are %d elements left in the bag.\n\n",
                bag->size);
        }
    }

    free(bag);
    
    return 0;
}

void PrintBag(struct linkedList* q)
{
    struct dlink * link = q->frontSentinel->next;
    printf("Bag : ");
    while(link->next != NULL)
    {
        printf("%3d ", link->value);
        link = link->next;
    }
    printf("\n");
}