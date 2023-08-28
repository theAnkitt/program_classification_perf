//selectionsort
#include<stdio.h>
#include<stdlib.h>
void selection_sort(int array[], int n)
{
    int i, j, small;                                 
    for(i=0;i<n-1;i++)
    {
       small=i;
       for(j=i+1;j<n;j++)
       {
          if(array[j] < array[small])                
          {
             small=j;
          }
       }
	 int temp = array[i];
	 array[i] = array[small];
	 array[small]=temp;
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
    selection_sort(arr, size);
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
