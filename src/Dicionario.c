#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Dicionario.h"


typedef struct lista_elemento{
  void* hash;
  char* id;
  struct lista_elemento *prox;
	struct lista_elemento *ant;
}lista;

typedef struct dic{
  int tamanho;
  struct lista_elemento *primeiro;
  struct lista_elemento *ultimo;
}dicionario;

Dicionario createDicionario(){
  dicionario *dicionarioNew;

	dicionarioNew = (dicionario *)malloc (sizeof(dicionario));
	dicionarioNew->tamanho = 0;
	dicionarioNew->primeiro = NULL;
	dicionarioNew->ultimo = NULL;

	return (Dicionario)dicionarioNew;
}

int lenghtDicionario(Dicionario dic){
  dicionario *dicionarioNew;
  dicionarioNew = (dicionario *)dic;

  return dicionarioNew->tamanho;
}

void insertDicionario(Dicionario dic,Hash obj,char* id){
  int tam=0;
  lista *novoElemento;
  dicionario *novoDicionario;
  lista *aux;


	novoDicionario = (dicionario*) dic;

	novoElemento = (lista *)malloc(sizeof(lista));
	novoElemento->hash = obj;

  tam = strlen(id);
  novoElemento->id = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novoElemento->id,id);

	novoElemento->prox = NULL;
	novoElemento->ant = NULL;


	if(novoDicionario->tamanho == 0){
		novoDicionario->primeiro = novoElemento;
	}else{

		aux = novoDicionario->ultimo;

		aux->prox = novoElemento;
		novoElemento->ant = aux;
	}
	novoDicionario->tamanho++;
	novoDicionario->ultimo = novoElemento;

}

void removerDicionario(Dicionario dic,PosicD p) {
	dicionario *novoDicionario;

	lista *aux1, *aux2;

	novoDicionario = (dicionario *) dic;

	aux1 = (lista *) p;
	if (aux1->ant == NULL) {
		/*Quando o Posic for o único elemento existente na lista (último e primeiro ao mesmo tempo)*/
		if (aux1->prox == NULL) {
			novoDicionario->primeiro = NULL;
			novoDicionario->ultimo = NULL;
		}
		/*Quando o Posic aponta para o primeiro elemento*/
		else {
			aux2 = aux1->prox;
			aux2->ant = NULL;
			novoDicionario->primeiro = aux2;
		}
	}
	else {
		/*Quando o Posic aponta para o último elemento*/
		if (aux1->prox == NULL) {
			aux2 = aux1->ant;
			aux2->prox = NULL;
			novoDicionario->ultimo = aux2;
		}
		/*Quando o Posic aponta para qualquer elemento no meio da lista*/
		else {
			aux2 = aux1->ant;
			aux2->prox = aux1->prox;
		 	aux2 = aux2->prox;
		 	aux2->ant = aux1->ant;
		}
	}
  free(aux1);
  aux1 = NULL;


	novoDicionario->tamanho--;
}

PosicD getFirstDicionario(Dicionario d){
  dicionario *novoDicionario;
  PosicD *p;
  novoDicionario = (dicionario *)d;
  if(novoDicionario->tamanho == 0){
    return NULL;
  }
  else
    p = (PosicD *)novoDicionario->primeiro;

    return p;
}

void* getHashDicionario(Dicionario dic,char* id){
  dicionario *novoDicionario;
  lista *list;
  novoDicionario = (dicionario *)dic;
  list = (lista *)novoDicionario;

  if(novoDicionario->tamanho != 0){
    list = (lista *)novoDicionario->primeiro;
    while(list != NULL){
      if(strcmp(id,list->id)!=0){
        list = list->prox;
      }
      else
        return list->hash;
    }
  }
  return NULL;
}

void* getPosicHashDicionario(Dicionario dic,PosicD p){
  void* forma;
  dicionario *novoDicionario;
  lista *aux;
  PosicD *pos;

  novoDicionario = (dicionario *)dic;


  pos = p;

  aux = (lista *)pos;
  forma = aux->hash;

  return forma;

}
