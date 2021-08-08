#include "qsort.h"
#include <stdio.h>
#include <string.h>
#include <stdlib.h>

void swap(int* a, int* b)
{
    int temp = *a;
    *a = *b;
    *b = temp;

}
int* QuickSort(int inp[] , int low, int high){
    if(low<high){
    int pivot = inp[high];
    int i = low-1; //last smaller
    int j= low;
    for(j;j<high;j++)
    {
        if(inp[j]<=pivot){
            i++;
            swap(&inp[i],&inp[j]);
        }
    }
    swap(&inp[i+1],&inp[j]);
    printf("\n");
    QuickSort(inp,low,i);
    QuickSort(inp,i+2,high);
    }
     
}