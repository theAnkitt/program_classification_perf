#include <stdio.h>
#include <stdlib.h>

// Node for the bucket linked list
struct Node {
    int value;
    struct Node* next;
};

// Function to insert a value into the bucket linked list
void insert(struct Node** bucket, int value) {
    struct Node* newNode = (struct Node*)malloc(sizeof(struct Node));
    newNode->value = value;
    newNode->next = NULL;

    if (*bucket == NULL) {
        *bucket = newNode;
    } else {
        struct Node* current = *bucket;
        while (current->next != NULL) {
            current = current->next;
        }
        current->next = newNode;
    }
}

// Function to print the sorted numbers into the output file with each value in a new line
void printSortedNumbers(FILE* output_file, struct Node* bucket) {
    struct Node* current = bucket;
    while (current != NULL) {
        fprintf(output_file, "%d\n", current->value); // Print each value in a new line
        current = current->next;
    }
}

// Function to perform bucket sort
void bucketSort(int arr[], int n, int num_buckets) {
    struct Node** buckets = (struct Node**)malloc(num_buckets * sizeof(struct Node*));
    for (int i = 0; i < num_buckets; i++) {
        buckets[i] = NULL;
    }

    for (int i = 0; i < n; i++) {
        int bucket_index = arr[i] * num_buckets / (n + 1); // Map the value to the corresponding bucket
        insert(&buckets[bucket_index], arr[i]);
    }

    FILE* output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Failed to open output file.\n");
        return;
    }

    for (int i = 0; i < num_buckets; i++) {
        // Sort the individual buckets using any sorting algorithm (e.g., insertion sort)
        // Here, we will use bubble sort for simplicity
        for (struct Node* current = buckets[i]; current != NULL; current = current->next) {
            for (struct Node* next = current->next; next != NULL; next = next->next) {
                if (current->value > next->value) {
                    int temp = current->value;
                    current->value = next->value;
                    next->value = temp;
                }
            }
        }
        // Print the sorted bucket values to the output file
        printSortedNumbers(output_file, buckets[i]);
    }

    fclose(output_file);

    // Free the memory used for the buckets
    for (int i = 0; i < num_buckets; i++) {
        struct Node* current = buckets[i];
        while (current != NULL) {
            struct Node* temp = current;
            current = current->next;
            free(temp);
        }
    }
    free(buckets);
}

int main() {
    int num_buckets = 10; // Number of buckets (can be adjusted based on the data distribution)
    int arr[500000]; // Assuming a maximum of 1000 numbers in the input file

    FILE* input_file = fopen("input.txt", "r");
    if (input_file == NULL) {
        printf("Failed to open input file.\n");
        return 1;
    }

    int num_elements = 0;
    while (fscanf(input_file, "%d", &arr[num_elements]) == 1) {
        num_elements++;
    }

    fclose(input_file);

    bucketSort(arr, num_elements, num_buckets);

    printf("Numbers have been sorted and stored in 'output.txt'.\n");

    return 0;
}

