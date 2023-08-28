#include <stdio.h>
#include<stdio.h>
// Function to perform Bubble Sort on an array
void bubbleSort(int arr[], int n) {
    int temp, swapped;
    do {
        swapped = 0;
        for (int i = 1; i < n; ++i) {
            if (arr[i - 1] > arr[i]) {
                // Swap elements if they are in the wrong order
                temp = arr[i - 1];
                arr[i - 1] = arr[i];
                arr[i] = temp;
                swapped = 1;
            }
        }
        n--; // The largest element is now at its correct position
    } while (swapped);
}

int main() {
    FILE *inputFile, *outputFile;
    inputFile = fopen("tenLinput.txt", "r");

    if (inputFile == NULL) {
        printf("Error opening the input file.\n");
        return 1;
    }

    int MAX_SIZE = 1000000; // Maximum number of elements in the array
    int arr[MAX_SIZE];
    int numElements = 0;

    // Read numbers from the input file
    while (fscanf(inputFile, "%d", &arr[numElements]) == 1) {
        numElements++;
    }

    fclose(inputFile);

    // Perform Bubble Sort on the array
    bubbleSort(arr, numElements);

    outputFile = fopen("output.txt", "w");

    if (outputFile == NULL) {
        printf("Error opening the output file.\n");
        return 1;
    }

    // Output the sorted array to the output file
    for (int i = 0; i < numElements; ++i) {
        fprintf(outputFile, "%d\n", arr[i]);
    }

    fclose(outputFile);

    printf("Sorted array has been written to output.txt\n");

    return 0;
}

