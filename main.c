#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define OF_VECTOR 9273350
#define OF_LIST 2318340
#define SEARCHES 1
#define MATRIXSIDE 3050

typedef struct list{
  int key;
  struct list* next;
}LIST;

int randomNum(void){
  return rand() % 501;
}

//cria uma lista e adiciona n = OF_LIST numeros aleatorios nela
LIST* createList(void){
    LIST* novo = malloc(sizeof(LIST));
    novo->key = randomNum();
    novo->next = NULL;

    LIST* fstEl = novo;
    LIST* ptAux = novo;
  for(int i = 0; i < OF_LIST; i++){
    LIST* novo = malloc(sizeof(LIST));
    novo->key = randomNum();
    novo->next = NULL;

    ptAux->next = novo;
    ptAux = novo; 
  }

  return fstEl;
}

void showList(LIST* l){
  LIST *ptAux = l;

  while(ptAux != NULL){
    printf("%d ", ptAux->key);

    ptAux = ptAux->next;
  }
  printf("\n");
}

bool search(LIST* l, int value){
  LIST* ptAux = l;

  while(ptAux != NULL){
    if(ptAux->key == value){
      return true;
    }
    ptAux = ptAux->next;
  }

  return false;
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
  int* v = (int*) malloc(sizeof(int) * OF_VECTOR);

  return v;
}

void printVector(int *vector){
  for(int i = 0; i < OF_VECTOR; i++){
    printf("%d\n", vector[i]);
  }
}

int* fillVector(int* v){
  for(int i = 0; i < OF_VECTOR; i++){
    v[i] = randomNum();
  }
  
  return v;
}

int* initializeMatrix(void){
  int i = MATRIXSIDE;
  int j = MATRIXSIDE;
  
  int* m = (int*) malloc(i * j * sizeof(int));

  return m;
}

int* fillMatrix(int* m){
  for(int i = 0; i < MATRIXSIDE; i++){
    for(int j = 0; j < MATRIXSIDE; j++){
      m[i * MATRIXSIDE + j] = 1;
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

int* matrixMultiplication(int* m1, int* m2, int* result){
  for(int i = 0; i < MATRIXSIDE; i++){
    for(int j = 0; j < MATRIXSIDE; j++){
      result[i * MATRIXSIDE + j] = dotProduct(m1, m2, i, j);
    }
  }

  return result;
}

void showMatrix(int* m){
  for(int i = 0; i < MATRIXSIDE; i++){
    for(int j = 0; j < MATRIXSIDE; j++){
      printf("%d\t", m[i * MATRIXSIDE + j]);
    }
    printf("\n");
  }
  printf("\n");
}

int main(){
  srand(time(NULL));

  // int* myVector = NULL;
  LIST* myList = NULL;
  // int* matrixOne = NULL;
  // int* matrixTwo = NULL;
  // int* result = NULL;
  
  // myVector = initializeVector();
  // myVector = fillVector(myVector);
  // quicksort(myVector,0,OF_VECTOR-1);

  myList = createList();
  bool test = search(myList, 50);
  if(test){
    printf("achou\n");
  } else {
    printf("nao achou\n");
  }


  // matrixOne = initializeMatrix();
  // matrixOne = fillMatrix(matrixOne);
  // matrixTwo = initializeMatrix();
  // matrixTwo = fillMatrix(matrixTwo);

  // result = initializeMatrix();
  // result = matrixMultiplication(matrixOne, matrixTwo, result);

  return 0;
}