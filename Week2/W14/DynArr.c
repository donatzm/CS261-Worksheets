#include <assert.h>
#include <stdlib.h>

#include "DynArr.h"

void _initDynArray(struct DynArray * v, int capacity){
    v->data = malloc(sizeof(TYPE)*capacity);
    assert(v->data != 0);

    v->size = 0;
    v->capacity = capacity;
}

struct DynArray* createDynArr(int cap){
    struct DynArr* r;
    assert(cap > 0);
    r = malloc(sizeofDynArr));
    assert(r != 0);

    _initDynArray(r, cap);
    return r;
}