#include <stdio.h>
#include <stdlib.h>
#include <time.h>

void merge(int *array, int start, int mid, int end){

  int *aux = malloc((end - start + 1) * sizeof(int));

  int i = start, j=mid+1, k=0;
  while(i<=mid && j<=end){
    if(array[i] <=array[j]){
      aux[k++] = array[i++];
    } else {
      aux[k++] = array[j++];
    }
  }

  while(i<=mid){ aux[k++] = array[i++]; } 
  while(j<=end){ aux[k++] = array[j++]; }

  for(i=start, k=0; i<=end; i++, k++){
    array[i] = aux[k];
  }

  free(aux);
}

void merge_sort(int* array, int start, int end){
    if(start<end){
        int mid = (end+start)/2;
        merge_sort(array, start, mid);
        merge_sort(array, mid+1, end);
        merge(array, start, mid, end);
    }
}

int main(){

  int arraySize;
  printf("Tamanho do vetor a ser ordenado: ");
  scanf("%d", &arraySize);
  int array[arraySize];

  // Setting random values ​​for all vector positions:  
  srand(time(NULL));
  for(int i = 0; i < arraySize; i++) {
    array[i] = rand();
  }

  printf("Ordenando %d numeros\n", arraySize);
  clock_t start = clock();  
  merge_sort(array, 0, arraySize-1);  
  clock_t end = clock();
  double time = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("Lista ordenada em %lf segundos\n", time);  

  for(int i = 0; i<arraySize; i++){
    printf("%d,", array[i]);
  }

  printf("\n");

}