#include <stdio.h>

#include "ArrayBagStack.h"

int main(){

    struct arrayBagStack testbag;

    initArray(&testbag);

    printf("The count is: %d\n", 
        testbag.count);
    return 0;
}