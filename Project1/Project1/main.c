#include "header.h"

int main()
{
    printf("quick sort:\n\r");
    Globals.inversionCount = 0;

    int localArray[DATA_LEN] = { 3, 2, 9, 2, 9, 1, 3, 4, 8};

    for (int index = 0; index < DATA_LEN; index++) 
    {
        Globals.dataSet[index] = localArray[index];
    }

    quickSort(0, DATA_LEN - 1);

    for (int index = 0; index < DATA_LEN; index++) 
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\rInversion Count: %d\n\r", Globals.inversionCount);




    printf("\n\rmerge sort:\n\r");
    for (int index = 0; index < DATA_LEN; index++)
    {
        Globals.dataSet[index] = localArray[index];
    }

    mergeSort(0, DATA_LEN - 1);

    for (int index = 0; index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\rInversion Count: %d", Globals.inversionCount);
	return 0;
}