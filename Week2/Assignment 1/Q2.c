/* CS261- Assignment 1 - Q.2*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

int foo(int* a, int* b, int c){
    /*Set a to double its original value*/
    *a *= 2;
    /*Set b to half its original value*/
    *b *=.5;
    /*Assign a+b to c*/
    c = *a + *b;
    /*Return c*/

    return c;
}

int main(){
    /*Declare three integers x,y and z and initialize them to 5, 6, 7 respectively*/
    int x = 5;
    int y = 6;
    int z = 7;

    /*Print the values of x, y and z*/

    printf("x, y, and z are %d, %d, and %d respectively.\n",
        x, y, z);
    
    /*Call foo() appropriately, passing x,y,z as parameters*/
    
    /*Print the value returned by foo*/
    printf("foo() returned a value of %d.\n",
        foo(&x, &y, z));
    /*Print the values of x, y and z again*/
    printf("x, y, and z are %d, %d, and %d respectively.\n",
        x, y, z);

    /*Is the return value different than the value of z?  Why?*/
    /* Yes.  we modified x and y by passing in their addresses, 
    but left z alone and only modified the local variable c*/
    return 0;
}
    
    
