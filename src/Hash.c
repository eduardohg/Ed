#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Hash.h"
#include "Lista.h"

typedef struct hash_{
  int size;
  Lista *vetor;
}hash;

typedef struct reg_Info{
  char* key;
  void* info;
}regInfo;

Hash createHash(int size){
  hash *h;
  int i;
  h = (hash*)malloc(sizeof(hash));
  h->vetor = (Lista) malloc(size*sizeof(Lista));

  h->size = size;
  for(i=0;i<size;i++){
    h->vetor[i] = createList();
  }

  return (Hash)h;
}

int getTamanhoHash(Hash ha){
  hash *h;
  h = (hash *)ha;

  if(h != NULL)
    return h->size;
  else
    return 0;
}

void liberaHash(Hash ha){
  hash *h;
  int i;
  h = (hash*)ha;
  if(h != NULL){
    for(i=0;i<h->size;i++){
      if(h->vetor[i] != NULL)
        free(h->vetor[i]);
    }
    free(h->vetor);
    free(h);
  }
}

int encontraIndice(Hash ha,char *key){
  hash *h;
  int i,valor = 0,tam,j=0;
  int primos[25] = {2, 3, 5, 7, 11, 13, 17, 19, 23, 29, 31, 37, 41, 43, 47, 53, 59, 61, 67, 71, 73, 79, 83, 89, 97};
  h = (hash *)ha;
  tam = strlen(key);

  for(i=0;i<tam;i++){
    valor += (int)key[i]*primos[j];
    j++;
    if(j>=25)
      j=0;
  }
  return valor%h->size;
}

int insertRegInfo(Hash ha,RegInfo r,char* key){
  char* chave;
  int tam=0,pos;
  hash *h;
  regInfo *reg;
  h = (hash*)ha;

  if(h != NULL){
    reg = (regInfo *)malloc(sizeof(regInfo));
    tam = strlen(key);
    reg->key = (char *)malloc((tam+1)*sizeof(char));
    strcpy(reg->key,key);
    reg->info = r;
    pos = encontraIndice(ha,key);
    insert(h->vetor[pos],(RegInfo)reg);


    return 1;
  }
  return 0;
}

void removeRegInfo(Hash ha,char *key){
  hash *hashTable;
  regInfo *registro;
  RegInfo reg;
  Posic p;
  int index, logic;

  hashTable = (hash *) ha;

  index = encontraIndice(ha, key);

  logic = existeChave(ha, key);

  if (logic == 1) {
    p = getFirst(hashTable->vetor[index]);
    while (p != NULL) {
      registro = (regInfo *) get(hashTable->vetor[index], p);
      if (strcmp(registro->key, key) == 0) {
        free(registro->key);
        break;
      }

      p = getNext(hashTable->vetor[index], p);
    }
    remover(hashTable->vetor[index], p);
    free(registro);
  }
}

void *getRegInfo(Hash ha,char *key){
  int pos;
  hash *h;
  Posic *p;
  RegInfo r;
  regInfo *reg;

  h = (hash *)ha;
  if(h != NULL){
    if(existeChave(h,key) == 1){
      pos = encontraIndice(h,key);
      r = searchVetorLists(h->vetor[pos],key);
      if (r != NULL) {
        reg = (regInfo *) r;
        return reg->info;
      }
    }
  }
  return NULL;
}

RegInfo searchVetorLists(Lista vetor[], char *key) {
  Posic p;
  Item info;
  regInfo *registro;

  p = getFirst(vetor);
  while (p != NULL) {
    info = get(vetor, p);
    registro = (regInfo *) info;

    if (strcmp(key, registro->key) == 0) {
      return (RegInfo) registro;
      break;
    }

    p = getNext(vetor, p);
  }

  return NULL;
}

int existeChave(Hash ha,char *key){
  int verif=0,pos;
  Posic *p;
  hash *h;
  regInfo *reg;

  h = (hash *)ha;
  pos = encontraIndice(ha,key);
  p = getFirst(h->vetor[pos]);
  while(p != NULL){
    reg = (regInfo *) get(h->vetor[pos],p);
    if(strcmp(reg->key,key)==0){
      return 1;
    }
    p = getNext(h->vetor[pos],p);
  }
  return verif;
}

Lista getAllRegInfo(Hash h){
  hash *hashTable;
  regInfo *registro;
  RegInfo reg;
  Lista list;
  Posic p;
  int i, size;

  hashTable = (hash *) h;

  list = createList();

  size = hashTable->size;
  for (i=0; i<size; i++) {
    p = getFirst(hashTable->vetor[i]);

    while (p != NULL) {
      registro = (regInfo *) get(hashTable->vetor[i], p);

      insert(list, registro->info);

      p = getNext(hashTable->vetor[i], p);
    }
  }

  return list;
}
