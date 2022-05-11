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
   printf("pos2: %d\n", i);
   pq->heapArray[i].data = data;
   pq->heapArray[i].priority = priority;

   pq->size++;
   printf("size: %d\n", pq->size);

   int posAct = i;
   heapElem aux;

   while(posAct > 0)
   {
      if(pq->heapArray[posAct].priority > pq->heapArray[posAct-3].priority)
      {
         aux.data = pq->heapArray[posAct-3].data;
         aux.priority = pq->heapArray[posAct-3].priority;

         pq->heapArray[posAct-3].data = pq->heapArray[posAct].data;
         pq->heapArray[posAct-3].priority = pq->heapArray[posAct].priority;

         pq->heapArray[posAct].priority = aux.priority;
         pq->heapArray[posAct].data = aux.data;
         if((posAct - 3) < 0)
      {
         posAct = posAct - 2;
      } else {
      posAct = posAct - 3;}
      }
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
