/* CS261- Assignment 1 - Q.4*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <assert.h>

struct student{
	int id;
	int score;
};

void quickSort(struct student* students, int n);
void quickSortInternal(struct student * roster, int low, int high);
int partition(struct student * roster, int low, int high, int pivotIndex);
void PrintRoster(struct student* students, int n);
void Swap(struct student* array, int i, int j);

void quickSort(struct student* students, int n){
     /*Sort the n students based on their score*/     
    quickSortInternal(students, 0, n-1);
}

void quickSortInternal(struct student * roster, int low, int high)
{
    if(low >= high) // base case
    {
        return;
    }

    int pivotIndex = (low + high)/2;
    pivotIndex = partition(roster, low, high, pivotIndex);

    quickSortInternal(roster, low, pivotIndex - 1);
    quickSortInternal(roster, pivotIndex + 1, high);
}

int partition(struct student * roster, int low, int high, int pivotIndex)
{
    Swap(roster, low, pivotIndex);

    struct student pivot = roster[low];

    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        if(roster[i].score <= pivot.score)
        {
            i++;
        }else if(roster[j].score >= pivot.score)
        {
            j--;
        }else if(i < j)
        {
            Swap(roster, i, j);
            i++;
            j--;
        }
    }
    Swap(roster, low, i -1);
    return i - 1;
}

void PrintRoster(struct student* students, int n)
{
    int i;

    for(i = 0; i < n; i++)
    {
        printf("ID: %4d \t Score: %3d\n",
            students[i].id,
            students[i].score);
    }
}

void Swap(struct student* array, int i, int j)
{
    struct student temp = array[i];
    array[i] = array[j];
    array[j] = temp;
}

int main(){
    /*Declare an integer n and assign it a value.*/
    int n = 20;
    int i;
    srand(time(NULL));
    /*Allocate memory for n students using malloc.*/
    struct student * roster = malloc(sizeof(struct student)*n);
    assert(roster != 0);
    
    /*Generate random IDs and scores for the n students, using rand().*/

    for(i = 0; i < n; i++)
    {
        roster[i].id = rand() % 1000;
        roster[i].score = rand() % 101;
    }
    
    /*Print the contents of the array of n students.*/
    printf("UNSORTED: \n");
    PrintRoster(roster, n);

    quickSort(roster, n);

    printf("\nSORTED: \n");
    PrintRoster(roster, n);
    /*Pass this array along with n to the sort() function*/
    
    /*Print the contents of the array of n students.*/
    free(roster);
    return 0;
}
