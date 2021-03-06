/* CS261- Assignment 1 - Q. 0*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>

void fooA(int* iptr){
     /*Print the value pointed to by iptr*/
    printf("The value of iptr is %d\n",
        *iptr);
     
     /*Print the address pointed to by iptr*/
    printf("iptr points to the address %p\n",
        iptr);
     
     /*Print the address of iptr itself*/
    printf("the address of iptr is %p\n",
        &iptr);
}

int main(){
    
    /*declare an integer x*/
    int x = 27;
    
    /*print the address of x*/
    printf("The address of x is %p\n",
        &x);
    
    /*Call fooA() with the address of x*/
    fooA(&x);
    
    /*print the value of x*/

    printf("The value of x is %d\n",
        x);
    
    return 0;
}
