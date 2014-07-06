/* CS261- Assignment 1 - Q.3*/
/* Name:
 * Date:
 * Solution description:
 */
 
#include <stdio.h>
#include <time.h>
#include <stdlib.h>
#include <assert.h>

void quickSort(int* number, int n);
void quickSortInternal(int* number, int low, int high);
int partition(int* number, int low, int high, int pivot);
void printArray(int * array, int n);
void swap(int* number, int indexA, int indexB);


void quickSort(int* number, int n){
     /*Sort the given array number , of length n*/    
     quickSortInternal(number, 0, n-1); 
}

void quickSortInternal(int* number, int low, int high)
{
    if(low >= high) // base case
    {
        return;
    }

    int pivotIndex = (low + high)/2;
    pivotIndex = partition(number, low, high, pivotIndex);

    quickSortInternal(number, low, pivotIndex - 1);
    quickSortInternal(number, pivotIndex+1, high);
}

int partition(int* number, int low, int high, int pivotIndex)
{
    swap(number, low, pivotIndex);

    int pivot = number[low];

    int i = low + 1;
    int j = high;

    while(i <= j)
    {
        if(number[i] <= pivot)
        {
            i++;
        }else if(number[j] >= pivot)
        {
            j--;
        }else if(i < j)
        {
            swap(number,i,j);
            i++;
            j--;
        }
    }
    swap(number, low, i - 1);
    return i - 1;
}

void swap(int* number, int indexA, int indexB)
{
    int temp = number[indexA];
    number[indexA] = number[indexB];
    number[indexB] = temp;
}

void printArray(int* array, int n)
{
    int i = 0;

    for(i = 0; i < n; i ++)
    {
        printf("%3d ", array[i]);
    }
    printf("\n");
}

int IsSorted(int* number, int size)
{
    int i = 0;

    if(size <= 1)
    {
        return 1;
    }

    for(i = 0; i < size-1; i++)
    {
        if(number[i+1] - number[i] < 0)
        {
            return 0;
        }
    }

    return 1;
}

int main(){
    /*Declare an integer n and assign it a value of 20.*/
    int n = 20;
    int i = 0;

    /*Allocate memory for an array of n integers using malloc.*/

    int* array = malloc(sizeof(int)*n);
    /*Fill this array with random numbers, using rand().*/
    assert(array != 0);

    srand(time(NULL));
    for(i = 0; i < n; i++)
    {
        array[i] = rand()%100;
    }
    
    /*Print the contents of the array.*/
    printf("%10s",
        "Unsorted: ");
    printArray(array, n);
    /*Pass this array along with n to the sort() function of part a.*/
    quickSort(array,n);
    /*Print the contents of the array.*/ 
    printf("%10s",
        "Sorted: ");   
    printArray(array, n);

    free(array);
    return 0;
}
