#include "header.h"

// This function recursively sorts a virtual array, a subset of the global array based on the bounds.
// It uses the quick sort method.
void quickSort(int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int pivotIndex = randomPartition(lowerBound, upperBound);

        quickSort(lowerBound, pivotIndex);
        quickSort(pivotIndex + 1, upperBound);
    }
}




// This function does operations on a virtual array, a subset of the global array based on the bounds.
// It chooses a random value in the virtual array as the pivot.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index where the values transition.
int randomPartition(int lowerBound, int upperBound) 
{
    // Generate random index
    srand(time(0));
    int randomIndex = lowerBound + rand() % (upperBound - lowerBound);

    int pivot = Globals.dataSet[randomIndex];

    return partition(pivot, lowerBound, upperBound);
}


// This function does operations on a virtual array, a subset of the global array based on the bounds.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index where the values transition.
int partition(int pivot, int lowerBound, int upperBound)
{
    int leftIndex = lowerBound - 1;
    int rightIndex = upperBound + 1;

    while (1) {

        do {
            leftIndex++;
        } while (Globals.dataSet[leftIndex] < pivot);

        do {
            rightIndex--;
        } while (Globals.dataSet[rightIndex] > pivot);

        if (leftIndex >= rightIndex)
            return rightIndex;
        if (Globals.dataSet[leftIndex] != Globals.dataSet[rightIndex])
        {
            int temp = Globals.dataSet[leftIndex];
            Globals.dataSet[leftIndex] = Globals.dataSet[rightIndex];
            Globals.dataSet[rightIndex] = temp;
            Globals.inversionCount++;
        }
    }
}
