#include <stdio.h>
#include <stdlib.h>
#include "Lista.h"

struct lista_elemento{
  Item *elemento;
  struct lista_elemento *prox;
	struct lista_elemento *ant;
};

struct reg{
  int tamanho;
  struct lista_elemento *primeiro;
  struct lista_elemento *ultimo;
};

typedef struct lista_elemento lista;
typedef struct reg lista_aux;

Lista createList(){
  lista_aux *listaNew;

	listaNew = (lista_aux *)malloc (sizeof(lista_aux));
	listaNew->tamanho = 0;
	listaNew->primeiro = NULL;
	listaNew->ultimo = NULL;

	return (Lista)listaNew;
}

int length(Lista list){
    lista_aux *novaLista;

    novaLista = (lista_aux *)list;

    return novaLista->tamanho;
}

Posic insert(Lista list,Item obj){
  lista *novoElemento;
  lista_aux *novaLista;
  lista *aux;


	novaLista = (lista_aux*) list;

	novoElemento = (lista *)malloc(sizeof(lista));
	novoElemento->elemento = obj;
	novoElemento->prox = NULL;
	novoElemento->ant = NULL;


	if(novaLista->tamanho == 0){
		novaLista->primeiro = novoElemento;
	}else{

		aux = novaLista->ultimo;

		aux->prox = novoElemento;
		novoElemento->ant = aux;
	}
	novaLista->tamanho++;
	novaLista->ultimo = novoElemento;

  return (Posic)novoElemento;
}

void remover(Lista L, Posic p) {
	lista_aux *list;

	lista *aux1, *aux2;

	list = (lista_aux *) L;

	aux1 = (lista *) p;
	if (aux1->ant == NULL) {
		/*Quando o Posic for o único elemento existente na lista (último e primeiro ao mesmo tempo)*/
		if (aux1->prox == NULL) {
			list->primeiro = NULL;
			list->ultimo = NULL;
		}
		/*Quando o Posic aponta para o primeiro elemento*/
		else {
			aux2 = aux1->prox;
			aux2->ant = NULL;
			list->primeiro = aux2;
		}
	}
	else {
		/*Quando o Posic aponta para o último elemento*/
		if (aux1->prox == NULL) {
			aux2 = aux1->ant;
			aux2->prox = NULL;
			list->ultimo = aux2;
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


	list->tamanho--;
}


Item get(Lista list,Posic p){
  lista_aux *novaLista;
	Posic *pos;
	Item *forma;
	lista *aux;

	novaLista = (lista_aux *)list;


	pos = p;

	aux = (lista *)pos;

	forma = aux->elemento;

	return forma;
}

Posic insertBefore(Lista list,Posic p,Item obj){
	lista *novoElemento;
    lista_aux *novaLista;
    lista *aux;
    Posic *pos;

	novaLista = (lista_aux*) list;
	if(p == NULL){
		printf("A posição não é válida");
	}
	else{
		novoElemento = (lista *)malloc(sizeof(lista));
		novoElemento->elemento = obj;
		aux = (lista *)p;
		p = (Posic )novoElemento;

		if(aux == novaLista->primeiro){
			aux->ant = novoElemento;
			novoElemento->prox = aux;
			novoElemento->ant = NULL;
			novaLista->primeiro = novoElemento;
		}
		else{
			novoElemento->prox = aux;
			aux = aux->ant;
			aux->prox = novoElemento;
			novoElemento->ant = aux;
			aux = novoElemento->prox;
			aux->ant = novoElemento;
		}

		novaLista->tamanho++;
	}
	return p;
}

Posic insertAfter(Lista list,Posic p,Item obj){
	lista *novoElemento;
    lista_aux *novaLista;
    lista *aux;
	Posic *pos;


	novaLista = (lista_aux*) list;
	if(p == NULL){
		printf("A posição não é válida");
	}
	else{
		novoElemento = (lista *)malloc(sizeof(lista));
		novoElemento->elemento = obj;
		aux = (lista *)p;
		p = (Posic )novoElemento;

		if(aux == novaLista->ultimo){
			aux->prox = novoElemento;
			novoElemento->ant = aux;
			novoElemento->prox = NULL;
			novaLista->ultimo = novoElemento;
		}
		else{
			novoElemento->ant = aux;
			aux = aux->prox;
			novoElemento->prox = aux;
			aux->ant = novoElemento;
			aux = novoElemento->ant;
			aux->prox = novoElemento;
		}
	}

	novaLista->tamanho++;

	return (Posic)novoElemento;
}


Posic getFirst(Lista list){
	lista_aux *novaLista;
	Posic *pos;
    novaLista = (lista_aux *)list;


	if(novaLista->tamanho == 0){
		pos = NULL;
	}else{
		pos = (Posic *)novaLista->primeiro;
	}

	return pos;
}

Posic getNext(Lista list,Posic p){
	lista_aux *novaLista;
	Posic *pos;
	lista *aux;
	novaLista = (lista_aux *)list;


	pos = p;


	aux = (lista *)pos;

	if(aux->prox == NULL){
		pos = NULL;
	}else{
		aux = aux->prox;
		pos = (Posic *)aux;
	}

	return pos;
}

Posic getLast(Lista list){
	lista_aux *novaLista;
	Posic *pos;
	novaLista = (lista_aux *)list;


	if(novaLista->tamanho == 0){
		pos = NULL;
	}else{
		pos = (Posic *)novaLista->ultimo;
	}

	return pos;
}

Posic getPrevious(Lista list,Posic p){
	lista_aux *novaLista;
	Posic *pos;
	lista *aux;

	novaLista = (lista_aux *)list;

	pos = p;
	aux = (lista *)pos;

	if(aux->ant == NULL){
		pos = NULL;
	}else{
		aux = aux->ant;
		pos = (Posic *)aux;
	}

	return pos;
}
