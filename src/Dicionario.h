#ifndef DICIONARIO_H
#define DICIONARIO_H
#include "Hash.h"


typedef void* Dicionario;

typedef void* PosicD;

/*
  -Cria um Dicionario
*/
Dicionario createDicionario();

/*
  -Retorna o tamanho de um Dicionario
  -dic: Dicionario genérico
*/
int lenghtDicionario(Dicionario dic);

/*
  -insere uma hash ao dicionario
*/
void insertDicionario(Dicionario dic,Hash obj,char *id);

void removerDicionario(Dicionario dic,PosicD p);

/*
  -Retorna uma hash que está no dicionario
*/
void* getHashDicionario(Dicionario dic,char* id);

void* getPosicHashDicionario(Dicionario dic,PosicD p);


#endif
