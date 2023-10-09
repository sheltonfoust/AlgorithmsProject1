#include <stdio.h>
#include <stdlib.h>
#include <time.h>
//
#define DATA_LEN 10

int inversionCount;
int dataSet[DATA_LEN];

// This function does operations on a virtual array, a subset of the data set based on the bounds.
// It chooses the first element in the virtual array as the pivot.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index where the values transition.
int partition(int lowerBound, int upperBound)
{
    int pivot = dataSet[lowerBound];
    int leftIndex = lowerBound - 1;
    int rightIndex = upperBound + 1;

    while (1) {

        do {
            leftIndex++;
        } while (dataSet[leftIndex] < pivot);

        do {
            rightIndex--;
        } while (dataSet[rightIndex] > pivot);

        if (leftIndex >= rightIndex)
            return rightIndex;

        int temp = dataSet[leftIndex];
        dataSet[leftIndex] = dataSet[rightIndex];
        dataSet[rightIndex] = temp;
        inversionCount++;
    }
}



// This function does operations on a virtual array, a subset of the data set based on the bounds.
// It chooses a random value in the virtual array as the pivot.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index where the values transition.
int randomPartition(int lowerBound, int upperBound) 
{
    // Generate random index
    srand(time(0));
    int random = lowerBound + rand() % (upperBound - lowerBound);

    // swaps first value in the virtual array with value at the random index
    int temp = dataSet[random];
    dataSet[random] = dataSet[lowerBound];
    dataSet[lowerBound] = temp;

    return partition(lowerBound, upperBound);
}



// This function sorts a virtual array, a subset of the data set based on the bounds.
void quickSort(int lowerBound, int upperBound) 
{
    if (lowerBound < upperBound) 
    {
        int pivot = randomPartition(lowerBound, upperBound);

        quickSort(lowerBound, pivot);
        quickSort(pivot + 1, upperBound);
    }
}

/*
int main() {
    
    int localArray[DATA_LEN] = { 0, 1, 3, 5, 8, 9, 2, 9, 1, 1 };
    for (int i = 0; i < DATA_LEN; i++) 
    {
        dataSet[i] = localArray[i];
    }

    quickSort(0, DATA_LEN - 1);

    printf("Data Set: ");
    for (int i = 0; i < DATA_LEN; i++)
    {
        printf("%d ", dataSet[i]);
    }

    printf("\n\rNumber of inversions: %d", inversionCount);


    return 0;
}
*/