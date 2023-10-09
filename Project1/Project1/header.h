#ifndef HEADER_H
#define HEADER_H

#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define DATA_LEN 10

typedef struct _GlobalStruct
{
	int inversionCount;
	int dataSet[DATA_LEN];
} GlobalStruct;

void mergeSort(int lowerBound, int upperBound);
void merge(int lowerBound, int midPoint, int upperBound);
void quickSort(int lowerBound, int upperBound);
int randomPartition(int lowerBound, int upperBound);
int partition(int lowerBound, int upperBound);




GlobalStruct Globals;

#endif
