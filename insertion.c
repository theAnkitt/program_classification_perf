//insertionsort
#include<stdio.h>
#include<stdlib.h>
void insertion_sort(int array[], int n)
{
    int key, i, j;                                   
    for(j = 0; j < n; j++)
    {
      key = array[j];
      i = j - 1;
      while(i >= 0 && array[i] > key)
      {
         array[i + 1] = array[i];                    
         i = i - 1;
      }
      array[i + 1] = key;
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
    insertion_sort(arr, size);
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
