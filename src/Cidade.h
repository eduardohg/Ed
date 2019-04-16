#ifndef CIDADE_H
#define CIDADE_H
#include "Quadra.h"
#include "Semaforo.h"
#include "Hidrante.h"
#include "Torre.h"
#include "QuadTree.h"
#include "Lista.h"

/*
  Cidade é um tipo que possibilita a criação de uma Cidade com equipamentos urbanos.
*/
typedef void* Cidade;

typedef void (* Escrever)(FILE**,void*);

typedef void (* Liberar)(void*);

/*
  -Cria uma Cidade
*/
Cidade criaCidade();

/*
 -Insere uma quadra na cidade
 -c:cidade genérica
 -q:quadra genérica
*/
int insereQuadra(Cidade c,Quadra q,double x,double y);

/*
 -Insere um semáforo na cidade
 -c:cidade genérica
 -s:semaforo genérico
*/
int insereSemaforo(Cidade c,Semaforo s,double x,double y);

/*
 -Insere um Hidrante na cidade
 -c:cidade genérica
 -h:hidrante genérico
*/
int insereHidrante(Cidade c,Hidrante h,double x,double y);

/*
 -Insere uma torre na cidade
 -c:cidade genérica
 -t:torre genérica
*/
int insereTorre(Cidade c,Torre t,double x,double y);

/*
 -Retorna uma quadra da cidade
 -c:cidade genérica
*/
Quadra getQuadra(Cidade c);

/*
 -Retorna um hidrante da cidade
 -c:cidade genérica
*/
Hidrante getHidrante(Cidade c);

/*
 -Retorna um semaforo da cidade
 -c:cidade genérica
*/
Semaforo getSemaforo(Cidade c);

/*
 -Retorna uma torre da cidade
 -c:cidade genérica
*/
Torre getTorre(Cidade c);

/*
 -Remove uma Quadra
 -c:cidade genérica
 -cep:cep da Quadra
*/
int removeQuadra(Cidade c,char* cep);

/*
 -Remove um hidrante
 -c:cidade genérica
 -id:identificador do hidrante
*/
int removeEquip(Cidade c,PosicNo *nohArv,Liberar liberarEquip,Tree arv);

/*
 -Remove um semaforo
 -c:cidade genérica
 -id:identificador do semaforo
*/
int removeSemaforo(Cidade c,char* id);

/*
 -Remove uma torre
 -c:cidade genérica
 -id:identificador da torre
*/
int removeTorre(Cidade c,char* id);

/*
 -Desaloca a cidade
 -c:cidade genérica
*/
void apocalypse(Cidade c);

int processarTree(Cidade c,Tree arv,PosicNo nohArv,Escrever escreverEquip,FILE **arq);

#endif
