#ifndef HASH_H
#define HASH_H
#include "Lista.h"

typedef void* Hash;

typedef void* RegInfo;

/*
  -Cria uma Hash e retorna
  -size: Tamanho do vetor que será criado dentro da Hash
*/

Hash createHash(int size);

/*
  -Retorna o tamanho da hash
  -ha: Hash genérica
*/
int getTamanhoHash(Hash ha);
/*
  -Libera o espaço alocado pela Hash
  -ha: Hash genérica
*/
void liberaHash(Hash ha);

/*
  -Calcula o hashcode
  -key: String para converter
*/
int encontraIndice(Hash ha,char *key);
/*
  -Insere um valor na Hash
  -ha: Hash genérica
  -r: Valor que será inserido
*/
int insertRegInfo(Hash ha,RegInfo r,char *key);

/*
  -Exclui um determinado valor da Hash
  -ha: Hash genérica
  -key: chave do elemento que será excluido
*/
void removeRegInfo(Hash ha,char *key);

/*
  -Retorna um elemento da Hash
  -ha: Hash genérica
  -key: chave do elemento que será retornado
*/
void *getRegInfo(Hash ha,char *key);

/*
  -Verifica se existe uma chave
  -ha: Hash genérica
  -key: chave
*/
int existeChave(Hash ha,char *key);

/*
  -Retorna em lista todos os infos de uma hash
  -h: Hash genérica
*/
Lista getAllRegInfo(Hash h);

RegInfo searchVetorLists(Lista vetor[], char *key);

#endif
