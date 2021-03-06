#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include <math.h>
#include <assert.h>
#include "dynamicArray.h"


/* param: s the string
   param: num a pointer to double
   returns: true (1) if s is a number else 0 or false.
   postcondition: if it is a number, num will hold
   the value of the number
*/
int isNumber(char *s, double *num)
{
	char *end;
	double returnNum;      

	if(strcmp(s, "0") == 0)
	{
		*num = 0;
		return 1;
	}
	else 
	{
		returnNum = strtod(s, &end);
		/* If there's anythin in end, it's bad */
		if((returnNum != 0.0) && (strcmp(end, "") == 0))
		{
			*num = returnNum;
			return 1;
		}
	}
	return 0;  //if got here, it was not a number
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their sum is pushed back onto the stack.
*/
void add (struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
	TYPE num2 = topDynArr(stack);
    popDynArr(stack);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, num1 + num2);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their difference is pushed back onto the stack.
*/
void subtract(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
	TYPE num2 = topDynArr(stack);
    popDynArr(stack);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, num1 - num2);
}

/*	param: stack the stack being manipulated
	pre: the stack contains at least two elements
	post: the top two elements are popped and 
	their quotient is pushed back onto the stack.
*/
void divide(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
	TYPE num2 = topDynArr(stack);
    popDynArr(stack);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, num1 / num2);
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void multiply(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    TYPE num2 = topDynArr(stack);
    popDynArr(stack);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, num1 * num2);
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void power(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 2);
    TYPE num2 = topDynArr(stack);
    popDynArr(stack);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, pow(num1,num2));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void squared(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, pow(num1,2));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void cubed(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, pow(num1,3));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void absval(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, fabs(num1));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void squarert(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, sqrt(num1));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void etox(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, exp(num1));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void natlog(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, log(num1));
}

/*  param: stack the stack being manipulated
    pre: the stack contains at least two elements
    post: the top two elements are popped and 
    their quotient is pushed back onto the stack.
*/
void logb10(struct DynArr *stack)
{
    assert(sizeDynArr(stack) >= 1);
    TYPE num1 = topDynArr(stack);
    popDynArr(stack);

    pushDynArr(stack, log10(num1));
}

double calculate(int numInputTokens, char **inputString)
{
	int i;
	double result = 0.0;
	char *s;
	struct DynArr *stack;

	//set up the stack
	stack = createDynArr(20);

	// start at 1 to skip the name of the calculator calc
	for(i=1;i < numInputTokens;i++) 
	{
		s = inputString[i];

		// Hint: General algorithm:
		// (1) Check if the string s is in the list of operators.
		//   (1a) If it is, perform corresponding operations.
		//   (1b) Otherwise, check if s is a number.
		//     (1b - I) If s is not a number, produce an error.
		//     (1b - II) If s is a number, push it onto the stack

		if(strcmp(s, "+") == 0)
			add(stack);
		else if(strcmp(s,"-") == 0)
			subtract(stack);
		else if(strcmp(s, "/") == 0)
			divide(stack);
		else if(strcmp(s, "x") == 0)
			multiply(stack);
		else if(strcmp(s, "^") == 0)
			power(stack);
		else if(strcmp(s, "^2") == 0)
			squared(stack);
		else if(strcmp(s, "^3") == 0)
			cubed(stack);
		else if(strcmp(s, "abs") == 0)
			absval(stack);
		else if(strcmp(s, "sqrt") == 0)
			squarert(stack);
		else if(strcmp(s, "exp") == 0)
			etox(stack);
		else if(strcmp(s, "ln") == 0)
			natlog(stack);
		else if(strcmp(s, "log") == 0)
			logb10(stack);
		else 
		{
			TYPE num = 0;
            
            if(strcmp(s, "e") == 0)
            {
                TYPE e = 2.7182818;
                pushDynArr(stack, e);
            }
            else if(strcmp(s, "pi") == 0)
            {
                TYPE pi = 3.14159265;
                pushDynArr(stack, pi);
            }
            else if(isNumber(s, &num))
            {
                pushDynArr(stack, num);
            }
            else
            {
                printf("ERROR: Did not recognize the parameter %s\n", 
                    s);
                return 0;
            }
			
		}
	}	//end for 

	/* FIXME: You will write this part of the function (2 steps below) 
	 * (1) Check if everything looks OK and produce an error if needed.
	 * (2) Store the final value in result and print it out.
	 */
    if(sizeDynArr(stack) != 1)
    {
        printf("You have some leftover parameters!\n");
    }

    result = topDynArr(stack);
    popDynArr(stack);

    assert(sizeDynArr(stack) == 0);
	
    printf("The result is: %.3f\n", result);
	return result;
}

int main(int argc , char** argv)
{
	// assume each argument is contained in the argv array
	// argc-1 determines the number of operands + operators
	if (argc == 1)
		return 0;

	calculate(argc,argv);
	return 0;
}
