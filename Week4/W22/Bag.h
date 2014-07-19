#ifndef Bag
#define Bag

#define TYPE int

#include "LinkedListDeque.h"

void BagAdd(struct linkedList* lst, TYPE e);
int BagContains(struct linkedList* lst, TYPE e);
void BagRemove(struct linkedList* lst, TYPE e);

#endif