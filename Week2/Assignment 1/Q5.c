/* CS261- Assignment 1 - Q.5*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <assert.h>
#include <time.h>
#include <string.h>

/*converts ch to upper case, assuming it is in lower case currently*/
char toUpperCase(char ch){
     return ch-'a'+'A';
}

/*converts ch to lower case, assuming it is in upper case currently*/
char toLowerCase(char ch){
     return ch-'A'+'a';
}

void sticky(char* word){
     /*Convert to sticky caps*/
    int i;
    int toggle = 0;

    for(i = 0; i < strlen(word); i++)
    {
        toggle = rand() % 2;

        if(toggle)
        {
            if(word[i] <= 'Z' && word[i] >= 'A')
            {
                word[i] = toLowerCase(word[i]);
            }
            else if(word[i] <= 'z' && word[i] >= 'a')
            {
                word[i] = toUpperCase(word[i]);
            }
        }
    }
}

int main(){
    srand(time(NULL));
    /*Read word from the keyboard using scanf*/
    int limit = 40;
    printf("Enter a phrase, no more than %d characters.\n"
        , limit);
    char * input = malloc(sizeof(char)*(limit));
    assert(input != 0);
    
    char stickyStick[] = "Sticky Capped";

    if(fgets(input, limit, stdin)!= NULL)
    {/*Call sticky*/
        int k= 0;
        for(k = 0; k < 5; k++)
        {
            sticky(input);
            sticky(stickyStick);
            
            /*Print the new word*/
            printf("%s: %s", stickyStick, input);
        }
    }

    free(input);
   
    return 0;
}
