#include "header.h"

// This function recursively sorts a virtual array, a subset of the global array based on the bounds.
// It uses the quick sort method.
void quickSort(int lowerBound, int upperBound)
{
    if (lowerBound < upperBound)
    {
        int pivot = randomPartition(lowerBound, upperBound);

        quickSort(lowerBound, pivot);
        quickSort(pivot + 1, upperBound);
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
    int random = lowerBound + rand() % (upperBound - lowerBound);

    // swaps first value in the virtual array with value at the random index
    int temp = Globals.dataSet[random];
    Globals.dataSet[random] = Globals.dataSet[lowerBound];
    Globals.dataSet[lowerBound] = temp;

    return partition(lowerBound, upperBound);
}


// This function does operations on a virtual array, a subset of the global array based on the bounds.
// It chooses the first element in the virtual array as the pivot.
// It moves the values lower than the pivot to the left part of the virtual array, moves the values
// greater than the pivot to the right part of the virtual array, and returns the index where the values transition.
int partition(int lowerBound, int upperBound)
{
    int pivot = Globals.dataSet[lowerBound];
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

        int temp = Globals.dataSet[leftIndex];
        Globals.dataSet[leftIndex] = Globals.dataSet[rightIndex];
        Globals.dataSet[rightIndex] = temp;
        Globals.inversionCount++;
    }
}
