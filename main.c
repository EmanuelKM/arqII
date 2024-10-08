#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define OVERFLOW 9273345
#define SEARCHES 1
#define MATRIXSIDE 3046

typedef struct list{
  int key;
  struct list* next;
}LIST;

int randomNum(void){
  return rand() % 1001;
}

LIST* append(LIST* l, int value){ 
  LIST* novo = (LIST*) malloc(sizeof(LIST));
  novo->key = value;
  novo->next = NULL;

  if(l == NULL){
    return novo;
  }

  else{
    LIST *ptAux = l;

    while(ptAux->next != NULL){
      ptAux = ptAux->next;
    }

    ptAux->next = novo;

    return l;
  }
}

void showList(LIST* l){
  LIST *ptAux = l;

  while(ptAux != NULL){
    printf("%d\n", ptAux->key);

    ptAux = ptAux->next;
  }
}

int search(LIST* l, int value){
  LIST* ptAux = l;

  while(ptAux != NULL){
    if(ptAux->key == value){
      return true;
    }
    ptAux = ptAux->next;
  }

  return false;
}

int makeRandomSearch(LIST* l){
  int n = -1, hits = 0;

  for(int i = 0; i < SEARCHES; i++){
    n = randomNum();

    if(search(l, n)){
      hits++;
    }
  }

  return hits;
}

LIST* fillList(LIST* l){
  int n = -1;

  for(int i = 0; i < OVERFLOW; i++){
    n = randomNum();
    l = append(l, n);
  }

  return l;
}

void swap(int* a, int* b) {
  if(*a != *b){
    int aux = *a;
    *a = *b;
    *b = aux;
  }
}

int median(int* vector, int start, int end){
  int firstIndex = start;
  int middleIndex = (start + end) / 2;
  int lastIndex = end;

  if ((vector[firstIndex] >= vector[middleIndex]) != (vector[firstIndex] >= vector[lastIndex])) {
    return firstIndex;
  } else if ((vector[middleIndex] >= vector[firstIndex]) != (vector[middleIndex] >= vector[lastIndex])) {
    return middleIndex;
  } else {
    return lastIndex;
  }
}

int lomuto(int *vector, int start, int end){
  int pivot = vector[start];
  int swapPosition = start;

  for(int i = start + 1; i <= end; i++){
    if(vector[i] <= pivot){
      swapPosition++;
      swap(&vector[i], &vector[swapPosition]);
    }
  }
  
  swap(&vector[start], &vector[swapPosition]);

  return swapPosition;
}

void quicksort(int *vector, int start, int end){
  if(start < end){
    int pivotIndex = median(vector, start, end);
    swap(&vector[start], &vector[pivotIndex]);

    int partitionIndex = lomuto(vector, start, end);

    quicksort(vector, start, partitionIndex-1);
    quicksort(vector, partitionIndex+1, end);
  }
}

int *initializeVector(void){
  int* v = (int*) malloc(sizeof(int) * OVERFLOW);

  return v;
}

void printVector(int *vector){
  for(int i = 0; i < OVERFLOW; i++){
    printf("%d\n", vector[i]);
  }
}

int* fillVector(int* v){
  for(int i = 0; i < OVERFLOW; i++){
    v[i] = randomNum();
  }
  
  return v;
}

int* initializeMatrix(void){
  int i, j = MATRIXSIDE;
  
  int* m = (int*) malloc(i * j * sizeof(int));

  return m;
}

int* fillMatrix(int* m){
  for(int i = 0; i < MATRIXSIDE; i++){
    for(int j = 0; j < MATRIXSIDE; j++){
      m[i * MATRIXSIDE + j] = i * MATRIXSIDE + j;
    }
  }
  
  return m;
}

int dotProduct(int* m1, int* m2, int row, int column){
  int result = 0;

  for(int k = 0; k < MATRIXSIDE; k++){
    result += m1[row * MATRIXSIDE + k] * m2[k * MATRIXSIDE + column];
  }

  return result;
}

int* matrixMultiplication(int* m1, int* m2){
  int* result = initializeMatrix();
  
  for(int i = 0; i < MATRIXSIDE; i++){
    for(int j = 0; j < MATRIXSIDE; j++){
      result[i * MATRIXSIDE + j] = dotProduct(m1, m2, i, j);
    }
  }

  return result;
}

int main(){
  srand(time(NULL));

  int* myVector = NULL;
  //LIST* myList = NULL;
  //int* matrixOne = NULL;
  //int* matrixTwo = NULL;
  //int* result = NULL;
  
  myVector = initializeVector();
  myVector = fillVector(myVector);
  quicksort(myVector,0,OVERFLOW-1);

  //myList = fillList(myList);
  //int test = makeRandomSearch(myList);
  
  //matrixOne = initializeMatrix();
  //matrixOne = fillMatrix(matrixOne);

  //matrixTwo = initializeMatrix();
  //matrixTwo = fillMatrix(matrixTwo);

  //result = matrixMultiplication(matrixOne, matrixTwo);

  return 0;
}
