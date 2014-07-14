#include <stdlib.h>
#include <stdio.h>
#include <assert.h>

#include "ArrayBagStack.h"

void initArray(struct arrayBagStack * b){
    b = (struct arrayBagStack *) malloc(sizeof(struct arrayBagStack));

    assert(b != 0);

    b->count = 0;
    free(b);
}

void addArray(struct arrayBagStack * b, TYPE v){
    
}
