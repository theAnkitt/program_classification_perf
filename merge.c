//mergesort
#include<stdio.h>
#include<stdlib.h>
#include<math.h>
void merge(int A[], int l, int q, int r){
    int n1 = q - l + 1;
    int n2 = r - q;
    int *L = (int*)malloc(n1 * sizeof(int));;
    int *R = (int*)malloc(n2 * sizeof(int));;
    for(int i = 0; i < n1; i++){
        L[i] = A[l + i];
    }
    for(int j = 0; j < n2; j++){
        R[j] = A[q + j + 1];
    }
    int i = 0, j = 0, k = l;
    while (i < n1 && j < n2) {
        if (L[i] <= R[j])
            A[k] = L[i++];
        else
            A[k] = R[j++];
        k++;
    }
    while (i < n1) {
        A[k] = L[i++];
        k++;
    }
    while (j < n2) {
        A[k] = R[j++];
        k++;
    }
    free(L);
    free(R);
}
void merge_sort(int A[], int l, int r){
    if(l < r){
        int q = l + (r - l) / 2;
        merge_sort(A, l, q);
        merge_sort(A, q + 1, r);
        merge(A, l, q, r);
    }
}  
int main()
{                                     
    const int size = 500000;
    int num, count = 0;
    int *arr = (int*) malloc(size * sizeof(int));
    FILE *fp = fopen("Random.txt", "r");
    if(fp == NULL){
        printf("Error accessing requested file!\n");
        return 1;
    }
    while(fscanf(fp, "%d", &num) == 1 && count < size){
        arr[count] = num;
        count++;
    }
    fclose(fp);
    merge_sort(arr, 0, count - 1);
    fp = fopen("Rand.txt", "w");
    if(fp == NULL){
        printf("Failed to open the file for writing.\n");
        free(arr);
        return 1;
    }
    for(int i = 0; i < count; i++){
        fprintf(fp, "%d \n", arr[i]);
    }
    fclose(fp);
    free(arr);
    return 0;
}
