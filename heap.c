#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <ctype.h>
#include "heap.h"

typedef struct nodo{
   void* data;
   int priority;
}heapElem;

typedef struct Heap{
  heapElem* heapArray;
  int size;
  int capac;
} Heap;


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


   int i = 0;
   while(i < pq->capac)
   {
      if(pq->heapArray[i].priority == 0)
      {
         printf("pos: %d\n", i);
         break;         
      }
      i++;
   }

   pq->heapArray[i].data = data;
   pq->heapArray[i].priority = priority;

   pq->size++;
   printf("size: %d\n", pq->size);

   heapElem aux;
   int posAct = i;
   int parent;

   while(1)
   {
      parent = (posAct-1)/2;
      printf("parent: %d\n", parent);
      if(pq->heapArray[posAct].priority > pq->heapArray[parent].priority)
      {
         aux.data = pq->heapArray[parent].data;
         aux.priority = pq->heapArray[parent].priority;

         pq->heapArray[parent].data = pq->heapArray[posAct].data;
         pq->heapArray[parent].priority = pq->heapArray[posAct].priority;

         pq->heapArray[parent].priority = aux.priority;
         pq->heapArray[parent].data = aux.data;
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
