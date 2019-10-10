#include <stdio.h>
#include "boolean.h"
#define ARRAYSIZE 8

/**
 *  quicksort algorithm is one of divide conquer methods
 *  @develop_kimdoyoung
*/

// function prototype
void quickSort(const int low, const int high, int array[]);
void partition(const int low, const int high, int pivotpoint, int array[]);


void quickSort(const int low, const int high, int array[]) {
    int pivotpoint = low;
    if(high > low) {
        // divide sections based on pivotpoint
        partition(low, high, pivotpoint, array);

        // execute data sorting from low to (pivotpoint - 1)
        quickSort(low, pivotpoint - 1, array);

        // sorting array values from (pivotpoint + 1) to high
        quickSort(pivotpoint + 1, high, array);
    }
}

// divide sections based on pivotpoint
void partition(const int low, const int high, int pivotpoint, int array[]) {

    int temp = 0;
    for(int i = low + 1; i <= high; i++) {
        // if array[pivotpoint] is higher than array[i], then exchange array[i] to array[pivotpoint]
        if(array[i] < array[low]) {
            pivotpoint++;
            temp = array[i];
            array[i] = array[pivotpoint];
            array[pivotpoint] = temp;
        }
    }

    // exchange array[pivotpoint] to array[low] 
    temp = array[low];
    array[low] = array[pivotpoint];
    array[pivotpoint] = temp;
}

int main() {
    int array[ARRAYSIZE] = {0, };

    // input array values
    for(int i = 0; i < ARRAYSIZE; i++) {
        scanf("%d", &array[i]);
    }

    // check unsorting value
    printf("unsorting array value : ");
    for(int i = 0; i < ARRAYSIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    // call function of quickSort()
    quickSort(0, ARRAYSIZE - 1, array);
    printf("quicksort is complete!!\n");

    printf("sorting array value : ");
    for(int i = 0; i < ARRAYSIZE; i++) {
        printf("%d ", array[i]);
    }
    printf("\n");

    return 0;
}