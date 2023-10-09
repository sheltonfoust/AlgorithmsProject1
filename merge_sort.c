// C program for Merge Sort 
#include <stdio.h> 
#include <stdlib.h> 

//create a global variable for inversion count 
int inversionCount = 0;

// merges two subarrays of arr[]. 
// first subarray is arr[l..m] 
// second subarray is arr[m+1..r] 
void merge(int arr[], int l, int m, int r) 
{ 
	int i, j, k; 
	int n1 = m - l + 1; 
	int n2 = r - m; 
	

	// create temp arrays 
	int L[n1], R[n2]; 

	// copy data to temp arrays 
	// l[] and r[] 
	for (i = 0; i < n1; i++) 
		L[i] = arr[l + i]; 
	for (j = 0; j < n2; j++) 
		R[j] = arr[m + 1 + j]; 

	// merge the temp arrays back 
	// into arr[l..r] 
	// initial index of first subarray 
	i = 0; 

	// initial index of second subarray 
	j = 0; 

	// initial index of merged subarray 
	k = l; 
	while (i < n1 && j < n2) { 
		if (L[i] <= R[j]) { 
			arr[k] = L[i]; 
			i++; 
		} 
		else { 
			arr[k] = R[j];
			inversionCount += n1 - i; 
			j++; 
		} 
		k++; 
	} 

	// copy the remaining elements 
	// of L[], if there are any 
	while (i < n1) { 
		arr[k] = L[i]; 
		i++; 
		k++; 
	} 

	// copy the remaining elements of 
	// R[], if there are any 
	while (j < n2) { 
		arr[k] = R[j];
		j++; 
		k++; 
	} 

	
} 

// l is for left index and r is 
// right index of the sub-array 
// of arr to be sorted 
void mergeSort(int arr[], int l, int r) 
{ 
	

	if (l < r) { 
		// Same as (l+r)/2, but avoids 
		// overflow for large l and h 
		int m = l + (r - l) / 2; 

		// Sort first and second halves 
		mergeSort(arr, l, m); 
		mergeSort(arr, m + 1, r); 

		merge(arr, l, m, r); 
	} 
	
} 

// function to print an array 
/*void printArray(int A[], int size) 
{ 
	int i; 
	for (i = 0; i < size; i++) 
		printf("\n %d ", A[i]);  
} */

int main() 
{ 
	
	FILE *file;
    int count = 0; // total number counter 
    int fileNumber = 0; //allow the user to open 1 of 5 txt files 
    int num; // To store a integer read from file
 
    // Get file name from user
    printf("Enter a number to choose a text file (1-5): ");
    scanf("%d", &fileNumber);

    //using the number we collected from the user we will open the correct file that needs to be open
    switch (fileNumber) {
        case 1: 
            file = fopen("source1.txt", "r");
            break;
        case 2:
            file = fopen("source2.txt", "r");
            break;
        case 3: 
            file = fopen("source3.txt", "r");
            break;
        case 4:
            file = fopen("source4.txt", "r");
            break;
        case 5:
            file = fopen("source5.txt", "r");
            break;
        default: //we use this case to end the program if the user doesn't enter a valid option
            printf("Invalid input. Please enter a number between 1 and 5.\n");
            return 1; // Exit the program with an error code
    }

    //if the file we read is empty we tell the user and end the program
    if (file == NULL) {
        printf("File number %d is empty please try again with a different file. ", fileNumber);
        return 0;
    }

    //find how many ints are in the file so we can create an array that is properly sized 
    while(fscanf(file, "%d", &num) == 1) {
        count++;
    }

	//we have to use rewind so we can go back and loop through the text file so we can store into the array
    rewind(file);

    //initalize an array
    int numArr[count];

    // Read and store the integers in the array
    for (int i = 0; i < count; i++){
        fscanf(file, "%d,", &numArr[i] );
    }

    // Close the file
    fclose(file);

	//find size of the array
    int arr_size = sizeof(numArr) / sizeof(numArr[0]); 

	//run merge sort
	mergeSort(numArr, 0, arr_size - 1);

	//print out result
	printf("\nTotal inversion count: %d", inversionCount);

	//printArray(numArr,arr_size);


	return 0; 
}
