#ifndef PILHA_H
#define PILHA_H
#include "Lista.h"
/*
  Pilha é uma estrutura de dados que armazena os dados na ordem LIFO(Primeiro a entrar, ultimo a sair)
*/
typedef void* Pilha;

typedef void* ItemPilha;

typedef void* PosicPilha;

Pilha inicializacao();

int empilhar(Pilha *monte,Item *dado);

PosicPilha getTopoPilha(Pilha *monte);

PosicPilha pop(Pilha *monte);

PosicPilha getNextTopo(Pilha *monte);

PosicPilha getAnterior(Pilha *monte,PosicPilha p);

ItemPilha getElementPilha(Pilha *monte,PosicPilha p);

void removeTopo(Pilha *monte);

void removeElementoPilha(Pilha *monte, PosicPilha p);

void liberaPilha(Pilha *monte);

int tamanhoPilha(Pilha *monte);

#endif
