#include <stdio.h>
#include <stdlib.h>
#include <time.h>
#include <stdbool.h>

#define OVERFLOW 20
#define SEARCHES 20
#define MATRIXSIDE 3163

typedef struct list{
  int key;
  struct list* next;
}LIST;

int randomNum(void){
  return rand() % 101;
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
  int middleIndex = (start + end)/2;
  int lastIndex = end;

  if((vector[firstIndex] >= vector[middleIndex]) ^ (vector[firstIndex] >= vector[lastIndex])){
    return firstIndex;
  }

  else if((vector[middleIndex] >= vector[firstIndex]) ^ (vector[middleIndex] >= vector[lastIndex])){
    return middleIndex;
  }

  else{
    return lastIndex;
  }
}

int lomuto(int *vector, int start, int end){

  int pivot = vector[start];
  int swapPosition = start-1;

  for(int i = start; i <= end; i++){
    if(vector[i] <= pivot){
      swapPosition++;
      swap(&vector[i], &vector[swapPosition]);
    }
  }
  
  swap(&vector[start], &vector[swapPosition]);

  return swapPosition;
}

void quicksort(int *vector, int start, int end){

  if(end > start){
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
  int* m = (int*) malloc(sizeof(int) * MATRIXSIDE);

  for(i = 0; i < MATRIXSIDE; i++){

    m[i]

  }
  return m;
}

int main(){
  srand(time(NULL));

  //int* myVector = NULL;
  //LIST* myList = NULL;
  //int *myMatrix = NULL;
  
  //myVector = initializeVector();
  //myVector = fillVector(myVector);
  //quicksort(myVector,0,OVERFLOW-1);

  //myList = fillList(myList);
  //int test = makeRandomSearch(myList);
  //printf("hits: %d\n", test);

  return 0;
}
