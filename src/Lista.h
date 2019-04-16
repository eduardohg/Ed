#ifndef LISTA_H
#define LISTA_H

/*
  Lista é um tipo que possibilita a criação de uma Lista com equipamentos urbanos ou formas(circulo,retangulo).
*/
typedef void* Lista;

/*
  Posic é um nó que aponta para um determinado tipo.
*/
typedef void* Posic;

/*
 Item é um determinado equipamento urbano ou forma
*/
typedef void* Item;

/*
  Cria uma Lista
*/
Lista createList();

/*
  Retorna o tamanho de uma lista
  -list:lista para consulta do tamanho
*/
int length(Lista list);

/*
  Insere um elemento na Lista
  -list:lista genérica
  -obj: Item que será inserido
*/
Posic insert(Lista list,Item obj);

/*
  Remove um elemento da Lista
  -list:lista genérica
  -p:nó que será removido da lista
*/
void remover(Lista list,Posic p);

/*
  Retorna um elemento da Lista
  -list:lista genérica
  -p:nó que será retornado
*/
Item get(Lista list,Posic p);

/*
  Insere um elemento na Lista antes do nó p
  -list:lista genérica
  -p: nó
  -obj: Item que será inserido
*/
Posic insertBefore(Lista list,Posic p,Item obj);

/*
  Insere um elemento na Lista após o nó p
  -list:lista genérica
  -p:nó
  -obj:Item que será inserido
*/
Posic insertAfter(Lista list,Posic p,Item obj);

/*
  Retorna o primeiro elemento da Lista
  -list:lista genérica
*/
Posic getFirst(Lista list);

/*
  Retorna o elemento da Lista após o nó p
  -list:lista genérica
  -p: nó
*/
Posic getNext(Lista list,Posic p);

/*
  Retorna o ultimo elemento da Lista
  -list:lista genérica
*/
Posic getLast(Lista list);

/*
  Retorna o elemento antes do nó p
  -list:lista genérica
  -p:nó
*/
Posic getPrevious(Lista list,Posic p);

/*
  Converte a lista em um vetor de elementos
*/

#endif
