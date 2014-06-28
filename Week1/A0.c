#include <stdio.h>
#include <time.h>
#include <string.h>
#include <stdlib.h>

char* CheckParity(int number);

int main()
{
    srand(time(NULL));

    for(int i = 0; i < 10; i++)
    {
        int hazard = rand() % 100;

        printf("The random number %d is %s.\n",
            hazard,
            CheckParity(hazard));
    }
    return 0;
}

char* CheckParity(int number)
{
    if(number % 2 == 0)
    {
        return "even";
    }

    return "odd";
}