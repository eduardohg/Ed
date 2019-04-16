#include <stdio.h>
#include <stdlib.h>
#include "Quicksort.h"

void quicksort(Vetor vet,int inicio,int fim,compara comparaGenerico){
  int pivo;

  if(fim > inicio){
    pivo = swap(vet,inicio,fim,comparaGenerico);
    quicksort(vet,inicio,pivo-1,comparaGenerico);
    quicksort(vet,pivo+1,fim,comparaGenerico);
  }
}

int swap(Vetor vet,int inicio,int fim,compara comparaGenerico){
  int esq,dir,pivo;

  esq = inicio-1;
  dir = inicio;
  pivo = fim;
  while (dir < fim) {
    if(comparaGenerico(vet,pivo,dir) == 1){
      esq++;
      troca(vet,esq,dir);
    }
    dir++;
  }
  esq++;
  troca(vet,esq,fim);

  return esq;
}
