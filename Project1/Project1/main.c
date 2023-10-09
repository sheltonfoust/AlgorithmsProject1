#include "header.h"

int main()
{

    Globals.inversionCount = 0;
    int localArray[DATA_LEN] = {4, 5, 8, 9, 6 };




    for (int index = 0; index < DATA_LEN; index++)
    {
        Globals.dataSet[index] = localArray[index];
    }
    printf("quick sort:\n\r");
    printf("unsorted list: ");
   
    for (int index = 0; index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\r");
    quickSort(0, DATA_LEN - 1);

    for (int index = 0; index < DATA_LEN; index++) 
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\rInversion Count: %d\n\r", Globals.inversionCount);

    
    
    for (int index = 0; index < DATA_LEN; index++)
    {
        Globals.dataSet[index] = localArray[index];
    }
    printf("\n\rmerge sort:\n\r");
    printf("unsorted list: ");

    for (int index = 0; index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\r");
   

    mergeSort(0, DATA_LEN - 1);

    for (int index = 0; index < DATA_LEN; index++)
    {
        printf("%d ", Globals.dataSet[index]);
    }
    printf("\n\rInversion Count: %d", Globals.inversionCount);
	return 0;
}