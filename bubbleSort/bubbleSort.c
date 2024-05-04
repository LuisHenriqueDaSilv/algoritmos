#include <stdio.h>
#include <time.h>
#include <stdlib.h>

void bubbleSort(int *v, int size){
  for(int i=0; i<size; i++){
    int changes = 0;

    for(int k=0; k<size-i-1; k++){

      if(v[k] > v[k+1]){
        int aux = v[k+1];
        v[k+1] = v[k];
        v[k] = aux;
        changes++;
      }
    }
    if(changes == 0)break;
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

  bubbleSort(array, arraySize);
  
  clock_t end = clock();
  double time = ((double)(end-start))/CLOCKS_PER_SEC;
  printf("Lista ordenada em %lf segundos", time);  
}