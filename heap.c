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


   int i = 0;
   while(i < pq->capac)
   {
      if(pq->heapArray[i].priority == 0)
         break;         
      i++;
   }

   pq->heapArray[i].data = data;
   pq->heapArray[i].priority = priority;

   pq->size++;

   heapElem aux;
   int posAct = i;
   int parent = 0;

   while(1)
   {
      parent = (posAct-1)/2;
      if(pq->heapArray[posAct].priority > pq->heapArray[parent].priority)
      {
         //aux.data = pq->heapArray[parent].data;
        /* aux.priority = pq->heapArray[parent].priority;

         pq->heapArray[parent].data = pq->heapArray[posAct].data;
         pq->heapArray[parent].priority = pq->heapArray[posAct].priority;

         pq->heapArray[posAct].priority = aux.priority;
         pq->heapArray[posAct].data = aux.data;*/
         _swap(&(pq->heapArray[posAct]), &(pq->heapArray[parent]));
      } else {
         break;
      }
      posAct = parent;
   }
   
}


void heap_pop(Heap* pq){
/*
   pq->heapArray[0].data = pq->heapArray[pq->size-1].data;
   pq->heapArray[0].priority = pq->heapArray[pq->size-1].priority;

   pq->heapArray[pq->size-1].priority = 0;
   pq->size--;

   int childAPos, childBPos, currentPos;

   currentPos = 0;

   heapElem aux;

   while(1)
   {
      childAPos = (currentPos * 2) + 1;
      childBPos = (currentPos * 2) + 2;

      if(childAPos > pq->size || childBPos > pq->size)
         break;

      if(pq->heapArray[childAPos].priority > pq->heapArray[childBPos].priority)
      {
         if(pq->heapArray[currentPos].priority < pq->heapArray[childAPos].priority)
         {
            aux.data = pq->heapArray[childAPos].data;
            aux.priority = pq->heapArray[childAPos].priority;

            pq->heapArray[childAPos].data = pq->heapArray[currentPos].data;
            pq->heapArray[childAPos].priority = pq->heapArray[currentPos].priority;

            pq->heapArray[currentPos].data = aux.data;
            pq->heapArray[currentPos].priority = aux.priority;

            currentPos = childAPos;
         }
      } else if (pq->heapArray[childAPos].priority < pq->heapArray[childBPos].priority) {
            aux.data = pq->heapArray[childBPos].data;
            aux.priority = pq->heapArray[childBPos].priority;

            pq->heapArray[childBPos].data = pq->heapArray[currentPos].data;
            pq->heapArray[childBPos].priority = pq->heapArray[currentPos].priority;

            pq->heapArray[currentPos].data = aux.data;
            pq->heapArray[currentPos].priority = aux.priority;

            currentPos = childBPos;
      } else {
         break;
      }
   }
  */
}

Heap* createHeap(){

   Heap* newHeap = (Heap *) malloc(sizeof(Heap));

   newHeap->capac = 3;
   newHeap->size = 0;

   newHeap->heapArray = (heapElem *) malloc(sizeof(heapElem)*3);

   return newHeap;
}
