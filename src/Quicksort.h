#ifndef QUICKSORT_H
#define QUICKSORT_H
#include "Vetor.h"

/*
  -compara é uma função genérica que compara dois void*
*/
typedef int (* compara)(void*,int,int);

/*
  -Vetor: Vetor a ser ordenado
  -inicio: posição de inicio do vetor a ser ordenado
  -fim: posição do fim do vetor a ser ordenado
  -comparaGenerico: função que compara dois equipamentos urbanos(Quadra,semaforo,etc...)
*/
void quicksort(Vetor vet,int inicio,int fim,compara comparaGenerico);

/*
  -Faz a troca de elementos do vetor
  -vet: Vetor que está sendo manipulado
  -inicio: posição de inicio do vetor a ser ordenado
  -fim: posição do fim do vetor a ser ordenado
  -comparaGenerico: função que compara dois equipamentos urbanos(Quadra,semaforo,etc...)
*/
int swap(Vetor vet,int inicio,int fim,compara comparaGenerico);

#endif
