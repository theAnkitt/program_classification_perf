//radixsort
#include<stdio.h>
#include<stdlib.h>
int getMax(int arr[], int n){
    int max = arr[0];
    for(int i = 1; i < n; i++){
        if(arr[i] > max){
            max = arr[i];
        }
    }
    return max;
}
void countingSort(int arr[], int n, int exp) {
    int *output = (int*)malloc(n * sizeof(int));
    int count[10] = {0};
    for (int i = 0; i < n; i++){
        count[(arr[i] / exp) % 10]++;
    }
    for (int i = 1; i < 10; i++){
        count[i] += count[i - 1];
    }
    for (int i = n - 1; i >= 0; i--){
        output[count[(arr[i] / exp) % 10] - 1] = arr[i];
        count[(arr[i] / exp) % 10]--;
    }
    for (int i = 0; i < n; i++){
        arr[i] = output[i];
    }
    free(output);
}
void radix_sort(int arr[], int n, int max){
    for(int exp = 1; max / exp > 0; exp *= 10){
        countingSort(arr, n, exp);
    }
}
int main()
{
    const int size = 500000;
    int num, count = 0;
    int *arr = (int*) malloc(size * sizeof(int));
    FILE * fp = fopen("Random.txt", "r");
    if(fp == NULL){
        printf("Error accessing requested file!\n");
        return 1;
    }
    while(fscanf(fp, "%d", &num) == 1 && count < size) {
        arr[count] = num;
        count++;
    }    
    fclose(fp);
    int max = getMax(arr, count);
    radix_sort(arr, count, max);
    fp = fopen("Rand.txt", "w");
    if(fp == NULL){
        printf("Failed to open the file for writing.\n");
        free(arr);
        return 1;
    }
    for(int i = 0; i < count; i++) {
        fprintf(fp, "%d \n", arr[i]);
    }
    fclose(fp);
    free(arr);
    return 0;
}
