#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
} heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;

void _swap(heapElem* x, heapElem* y)
{
   heapElem aux;

   aux.data = x->data;
   aux.priority = x->priority;

   x->data = y->data;
   x->priority = y->priority;

   y->priority = aux.priority;
   y->data = aux.data;
}

void* heap_top(Heap* pq){
   if(pq->size == 0) return NULL;
   return pq->heapArray[0].data;
}

void heap_push(Heap* pq, void* data, int priority){
   if(pq->capac == pq->size)
   {
      pq->heapArray = (heapElem *) realloc(pq->heapArray, sizeof(heapElem)*((pq->capac*2)+1));
      pq->capac = (pq->capac*2)+1;
   }

   pq->heapArray[pq->size].data = data;
   pq->heapArray[pq->size].priority = priority;
   pq->size++;

   int posAct = pq->size-1;
   int parent = 0;

   while(1)
   {
      parent = (posAct-1)/2;
      if(pq->heapArray[posAct].priority > pq->heapArray[parent].priority) {
         _swap(&(pq->heapArray[posAct]), &(pq->heapArray[parent]));
      } else {
         break;
      }
      posAct = parent;
   }
}

void heap_pop(Heap* pq){

}

Heap* createHeap(){

   Heap* newHeap = (Heap *) malloc(sizeof(Heap));

   newHeap->capac = 3;
   newHeap->size = 0;

   newHeap->heapArray = (heapElem *) malloc(sizeof(heapElem)*3);

   return newHeap;
}
