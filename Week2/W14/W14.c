#include <stdio.h>

#include "DynArr.h"

int main(){

    struct DynArray* test;

    test = createDynArray(10);

    printf("capacity is %d\n", test->size);
    return 0;
}