/* CS261- Assignment 1 - Q.1*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <assert.h>
#include <time.h>

struct student{
	int id;
	int score;
};

int NUM_STUDENTS = 10;

struct student* allocate(){
     /*Allocate memory for ten students*/
    struct student * students = malloc(sizeof(struct student)*NUM_STUDENTS);

    assert(students != 0);

    return students;

     
     /*return the pointer*/
}

void generate(struct student* students){
     /*Generate random ID and scores for ten students, ID being between 1 and 10, scores between 0 and 100*/
    srand(time(NULL));
    int i = 0;

    for(i = 0; i < NUM_STUDENTS; i ++)
    {
        students[i].id = rand() % 10 + 1;
        students[i].score = rand() % 101;
    }
}

void output(struct student* students){
     /*Output information about the ten students in the format:
              ID1 Score1
              ID2 score2
              ID3 score3
              ...
              ID10 score10*/
    int i = 0;

    for(i = 0; i < NUM_STUDENTS; i ++)
    {
        printf("ID: %d \tScore: %d\n",
            students[i].id, students[i].score);
    }
}

void summary(struct student* students){
     /*Compute and print the minimum, maximum and average scores of the ten students*/
    int min=students[0].score;
    int max=students[0].score;
    int sum=students[0].score;

    double avg=0;

    int i = 0;
    int tmpScore = 0;

    for(i = 1; i < NUM_STUDENTS; i++)
    {
        tmpScore = students[i].score;

        if(tmpScore < min)
        {
            min = tmpScore;
        }
        if(tmpScore > max)
        {
            max = tmpScore;
        }

        sum += tmpScore;
    }

    avg = (double) sum/NUM_STUDENTS;

    printf("\nThe minimum score is: %d\n", min);
    printf("The maximum score is: %d\n", max);
    printf("The average score is: %.2f\n", avg);

}

void deallocate(struct student* stud){
     /*Deallocate memory from stud*/
    free(stud);
}

int main(){
    struct student* stud = NULL;
    
    /*call allocate*/
    stud = allocate();
    /*call generate*/
    generate(stud);
    /*call output*/
    output(stud);
    /*call summary*/
    summary(stud);
    /*call deallocate*/
    deallocate(stud);

    return 0;
}
