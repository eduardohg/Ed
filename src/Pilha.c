#include <stdio.h>
#include <stdlib.h>
#include "Pilha.h"

typedef struct lista{
  ItemPilha *dado;
  struct lista *proximo;
  struct lista *anterior;
}listaPilha;

typedef struct _pilha{
  struct lista *topo;
  int tamanho;
}pilha;

Pilha inicializacao(){
  pilha *monte;
  monte = (pilha *)malloc(sizeof(pilha));
  monte->topo = NULL;
  monte->tamanho = 0;

  return (Pilha)monte;
}

int tamanhoPilha(Pilha *monte){
  pilha *novoMonte;
  novoMonte = (pilha*)monte;

  return novoMonte->tamanho;
}

int empilhar(Pilha *monte,ItemPilha *dado){
  listaPilha *novoElemento;
  pilha *novaLista;
  listaPilha *aux;


	novaLista = (pilha*) monte;

	novoElemento = (listaPilha *)malloc(sizeof(listaPilha));
	novoElemento->dado = dado;
	novoElemento->proximo = NULL;
	novoElemento->anterior = NULL;


	if(novaLista->tamanho == 0){
		novaLista->topo = novoElemento;
	}else{

		aux = novaLista->topo;

		aux->proximo = novoElemento;
		novoElemento->anterior = aux;
	}
	novaLista->tamanho++;
	novaLista->topo = novoElemento;

  return 1;
}

PosicPilha getTopoPilha(Pilha *monte){
  pilha *novoMonte;
  listaPilha *novo_elemento;
  PosicPilha *p;

  novoMonte = (pilha *)monte;
  if(novoMonte->tamanho == 0){
      p = NULL;
  }
  else
    p = (PosicPilha *)novoMonte->topo;
  return p;
}

ItemPilha pop(Pilha *monte){
  ItemPilha *i;
  pilha *novoMonte;
  listaPilha *novo_elemento,*novo_elemento2;

  novoMonte = (pilha *)monte;
  if(novoMonte->tamanho == 0){
    printf("Pilha vazia!\n");
  }
  else{
    novo_elemento = novoMonte->topo;
    if(novo_elemento->anterior != NULL){
      i = novo_elemento->dado;
      novo_elemento2 = novo_elemento->anterior;
      novo_elemento2->proximo = NULL;
      novoMonte->topo = novo_elemento2;
    }
    else{
      i = novo_elemento->dado;
    }
    free(novo_elemento);
    novo_elemento = NULL;
    novoMonte->tamanho--;
  }
  return i;
}

PosicPilha getNextTopo(Pilha *monte){
  PosicPilha *p;

  p = getTopoPilha(monte);
  p = getAnterior(monte,p);

  return p;
}

PosicPilha getAnterior(Pilha *monte,PosicPilha p){
	pilha *novoMonte;
	PosicPilha *pos;
	listaPilha *aux;

	novoMonte = (pilha *)monte;

	pos = p;
	aux = (listaPilha *)pos;

	if(aux->anterior == NULL){
		pos = NULL;
	}else{
		aux = aux->anterior;
		pos = (PosicPilha *)aux;
	}

	return pos;
}

ItemPilha getElementPilha(Pilha *monte,PosicPilha p){
  pilha *novoMonte;
  listaPilha *novo_elemento;
  PosicPilha *pos;
  ItemPilha *forma;

  novoMonte = (pilha *)monte;
  if(p == NULL){
    printf("null essa poha\n");
  }


	pos = p;

	novo_elemento = (listaPilha *)pos;

	forma = novo_elemento->dado;

	return forma;
}

void removeTopo(Pilha *monte){
  pilha *novoMonte;
  listaPilha *novo_elemento,*novo_elemento2;

  novoMonte = (pilha*)monte;
  novo_elemento = novoMonte->topo;
  printf("REmove\n");
  if(novo_elemento->proximo == NULL){
    printf("removetopo\n");
    novo_elemento2 = novo_elemento->anterior;
    novo_elemento2->proximo = NULL;

    novoMonte->topo = novo_elemento2;
  }
  /*
  free(novo_elemento);
  novo_elemento = NULL;
*/
  novoMonte->tamanho--;
}

void removeElementoPilha(Pilha *monte, PosicPilha p) {
	pilha *novoMonte;

	listaPilha *aux1, *aux2;

	novoMonte = (pilha *) monte;

	aux1 = (listaPilha *) p;

		/*Quando o Posic aponta para o último elemento*/
		if (aux1->proximo == NULL) {
			aux2 = aux1->anterior;
			aux2->proximo = NULL;
			novoMonte->topo = aux2;
		}
		/*Quando o Posic aponta para qualquer elemento no meio da lista*/
		else {
			aux2 = aux1->anterior;
			aux2->proximo = aux1->proximo;
		 	aux2 = aux2->proximo;
		 	aux2->anterior = aux1->anterior;
		}
  free(aux1);
  aux1 = NULL;


	novoMonte->tamanho--;
}

void liberaPilha(Pilha *monte){
  pilha *novoMonte;
  listaPilha *novoElemento;

  novoMonte = (pilha *)monte;
  if(novoMonte->tamanho != 0){
    novoElemento = novoMonte->topo;
    free(novoElemento->dado);
    free(novoElemento);
    novoMonte->tamanho--;
  }
}
