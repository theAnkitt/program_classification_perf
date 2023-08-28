#include <stdio.h>
#include <stdlib.h>

#define MAX_WEIGHT 1000

void fractional_knapsack(int n, int *v, int *c, FILE *output_file) {
    int i, maxi;

    int W = MAX_WEIGHT; // Hardcoded maximum weight

    int current_weight;
    float total_value;
    int total_weight = 0; // Variable to store the total weight of items selected
    int *used = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the 'used' array
    if (used == NULL) {
        printf("Memory allocation error.\n");
        return;
    }

    for (i = 0; i < n; ++i)
        used[i] = 0; /* I have not used the ith object yet */

    current_weight = W;
    while (current_weight > 0) { /* while there's still room*/
        /* Find the best object */
        maxi = -1;
        for (i = 0; i < n; ++i)
            if ((used[i] == 0) &&
                ((maxi == -1) || ((v[i] * c[maxi]) > (v[maxi] * c[i]))))
                maxi = i;

        used[maxi] = 1; /* mark the maxi-th object as used */
        if (current_weight >= c[maxi]) {
            total_value += v[maxi];
            total_weight += c[maxi]; // Add the weight of the selected item to the total_weight
            current_weight -= c[maxi];
            fprintf(output_file, "Object %d included.\n", maxi + 1);
        } else {
            float fraction = (float)current_weight / c[maxi];
            total_value += fraction * v[maxi];
            total_weight += current_weight; // Add the remaining weight of the item
            fprintf(output_file, "Included %d%%  of object %d in the bag.\n", (int)(fraction * 100), maxi + 1);
            current_weight = 0;
        }
    }

    fprintf(output_file, "Total profit of items included is %.2f.\n", total_value);
    fprintf(output_file, "Total weight of items selected is %d.\n", total_weight); // Print the total weight to the output file

    free(used); // Free dynamically allocated memory
}

int main() {
    int n = 500000; // Hardcoded total number of items
    int *v = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the 'v' array
    int *c = (int *)malloc(n * sizeof(int)); // Dynamically allocate memory for the 'c' array
    if (v == NULL || c == NULL) {
        printf("Memory allocation error.\n");
        free(v); // Free dynamically allocated memory
        free(c); // Free dynamically allocated memory
        return 1;
    }

    // Read the values and capacities from the input file
    FILE *input_file = fopen("knapinput.txt", "r");
    if (input_file == NULL) {
        printf("Error opening the input file.\n");
        free(v); // Free dynamically allocated memory
        free(c); // Free dynamically allocated memory
        return 1;
    }

    for (int i = 0; i < n; i++) {
        if (fscanf(input_file, "%d%d", &v[i], &c[i]) != 2) {
            printf("Error reading values and capacities from the input file.\n");
            fclose(input_file);
            free(v); // Free dynamically allocated memory
            free(c); // Free dynamically allocated memory
            return 1;
        }
    }

    fclose(input_file);

    // Open the output file for writing
    FILE *output_file = fopen("output.txt", "w");
    if (output_file == NULL) {
        printf("Error opening the output file.\n");
        free(v); // Free dynamically allocated memory
        free(c); // Free dynamically allocated memory
        return 1;
    }

    fractional_knapsack(n, v, c, output_file);
    fclose(output_file);
    free(v); // Free dynamically allocated memory
    free(c); // Free dynamically allocated memory
    return 0;
}

