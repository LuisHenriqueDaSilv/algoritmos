#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int partition(int *v, int left, int right){
  int pivot = v[right];
  while(left < right){
    while(left < right && v[left] <= pivot){left++;}
    while(left < right && v[right] > pivot){right--;}
    int aux = v[left];
    v[left] = v[right];
    v[right] = aux;
  }
  return left;
}

void quickSort(int *v, int left, int right){
  if(left < right){
    int pos = partition(v, left, right);
    // Divide and conquer
    quickSort(v, left, pos-1);
    quickSort(v, pos, right);
  }
}


int main(){

  int arraySize;
  printf("Tamanho do vetor a ser ordenado: ");
  scanf("%ld", &arraySize);
  int array[arraySize];

  // Setting random values ​​for all vector positions:  
  srand(time(NULL));
  for(int i = 0; i < arraySize; i++) {
    array[i] = rand();
  }

  printf("Ordenando %d numeros\n", arraySize);
  clock_t start = clock();  
  quickSort(array, 0, arraySize-1);  
  clock_t end = clock();
  double time = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("Lista ordenada em %lf segundos", time);  

}