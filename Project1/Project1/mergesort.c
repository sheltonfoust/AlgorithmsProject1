#include "header.h"

// This function recursively sorts a virtual array, a subset of the global array based on the bounds.
// It uses the merge sort method.
void mergeSort(int lowerBound, int upperBound)
{
	if (lowerBound < upperBound) 
	{
		int midpoint = (lowerBound + upperBound) / 2;

		mergeSort(lowerBound, midpoint);
		mergeSort(midpoint + 1, upperBound);

		merge(lowerBound, midpoint, upperBound);
	}

}


// This function does operations on two consecutive virtual arrays, subsets of the global array based on their bounds.
// It merges the two sorted virtual arrays into one sorted virtual array by interleaving their values.
void merge(int lowerBound, int midPoint, int upperBound)
{

	int leftArrayLen = midPoint - lowerBound + 1;
	int rightArrayLen = upperBound - midPoint;


	int leftArray[DATA_LEN], rightArray[DATA_LEN];

	for (int index = 0; index < leftArrayLen; index++)
	{
		leftArray[index] = Globals.dataSet[lowerBound + index];
	}
	for (int index = 0; index < rightArrayLen; index++)
	{
		rightArray[index] = Globals.dataSet[midPoint + 1 + index];
	}

	int leftIndex = 0;
	int rightIndex = 0;
	int dataSetIndex = lowerBound;

	while (leftIndex < leftArrayLen && rightIndex < rightArrayLen)
	{
		if (leftArray[leftIndex] <= rightArray[rightIndex])
		{
			Globals.dataSet[dataSetIndex] = leftArray[leftIndex];
			leftIndex++;
		}
		else
		{
			if (Globals.dataSet[dataSetIndex] != rightArray[rightIndex])
			{
				Globals.dataSet[dataSetIndex] = rightArray[rightIndex];
				Globals.inversionCount++;
			}
			rightIndex++;
		}
		dataSetIndex++;
	}

	while (leftIndex < leftArrayLen)
	{
		Globals.dataSet[dataSetIndex] = leftArray[leftIndex];
		leftIndex++;
		dataSetIndex++;
	}

	while (rightIndex < rightArrayLen)
	{
		Globals.dataSet[dataSetIndex] = rightArray[rightIndex];
		rightIndex++;
		dataSetIndex++;
	}


}