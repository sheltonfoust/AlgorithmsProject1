#include <stdio.h>
#include <stdlib.h>
#include <time.h>

// size of array
#define NUM 10000

// count of inversions
int count = 0;

int partition(int arr[], int low, int high) {
  int pivot = arr[low];
  int i = low - 1, j = high + 1;

  while (1) {

    do {
      i++;
    } while (arr[i] < pivot);

    do {
      j--;
    } while (arr[j] > pivot);

    if (i >= j)
      return j;

    int temp = arr[i];
    arr[i] = arr[j];
    arr[j] = temp;
    count++;
  }
}

int partition_r(int arr[], int low, int high) {
  // produce random number
  srand(time(0));
  int random = low + rand() % (high - low);

  // swaps first value in array with value at the index of random
  int temp = arr[random];
  arr[random] = arr[low];
  arr[low] = temp;

  return partition(arr, low, high);
}

void quickSort(int arr[], int low, int high) {
  if (low < high) {
    int pi = partition_r(arr, low, high);

    quickSort(arr, low, pi);
    quickSort(arr, pi + 1, high);
  }
}

int main() {
  FILE *inp;
  int arr[NUM];
  char name[20];

  printf(
      "Enter name of file with array:\n"); /*source1.txt, or source2.txt, ...*/
  scanf("%s", name);

  if ((inp = fopen(name, "r")) == NULL) {
    printf("***ERROR: File could not be opened - program ending\n");
    return 1;
  } else {
    // input values from source file to an array
    for (int i = 0; i < NUM; i++)
      fscanf(inp, "%d,", &arr[i]);

    int n = sizeof(arr) / sizeof(arr[0]);

    // sort array
    quickSort(arr, 0, n - 1);

    // print sorted array in output file (sorted.txt)
    FILE *outp;
    outp = fopen("sorted.txt", "w");
    for (int i = 0; i < NUM; i++)
      fprintf(outp, "%d\n", arr[i]);

    printf("Number of inversions: %d", count);
  }

  return 0;
}