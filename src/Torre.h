#ifndef TORRE_H
#define TORRE_H
#include <math.h>
#include "Lista.h"

/*
  Torre é um tipo que possibilita a criação e manipulação de torres de rádio.
*/
typedef void* Torre;

/*
  -Cria uma Torre
  -id = identificador
  -x,y:pontos do plano cartesiano, corp:cor do preenchimento da Torre, corb: cor da borda da Torre
*/
Torre criarTorre(char* id,double x,double y,char* corp,char* corb);

/*
  -Adiciona o raio da torre
  t: torre genérica
  r: raio
*/
void setRaioTorre(Torre t,double r);

/*
  -Adiciona a operadora da torre
  -t: Torre genérica
  -op: Operadora
*/
void setOperadoraTorre(Torre t,char *op);

/*
  -Retorna o id de uma Torre
  -t: Torre genérica
*/
char* getTorreId(Torre t);

/*
  -Retorna o ponto x de uma Torre
  -t: Torre genérica
*/
double getTorreX(Torre t);

/*
  -Retorna o ponto y de uma Torre
  -t: Torre genérica
*/
double getTorreY(Torre t);

/*
  -Retorna o raio de uma torre
  -t: torre genérica
*/
double getTorreRaio(Torre t);

/*
  -Retorna a cor de preenchimento de uma Torre
  -t: Torre genérica
*/
char* getTorreCorP(Torre t);

/*
  -Retorna a cor da borda de uma Torre
  -t: Torre genérica
*/
char* getTorreCorB(Torre t);

char* getTorreOp(Torre t);

void insertCelTorre(Torre t,char *tel);

Lista getListaCelTorre(Torre t);
/*
  -Compara o ponto y de duas torres
*/
int comparaTorre(Torre t1,Torre t2);

/*
  -Escreve uma torre no Arquivo svg
  -arq: Arquivo que contém as torres
  -t: torre genérica a ser impressa
*/
void escreveTorre(FILE **arq,Torre t);

/*
  -Escreve uma torre com seu raio de cobertura no arquivo svg
  -arq: Arquivo que contém as torres
  -t: torre genérica a ser impressa
*/
void escreveTorreRaio(FILE **arq,Torre t);

/*
  -Retorna a orientação de tres torres (horaria,anti-horaria ou colinear)
  -t1,t2,t3 torres a serem comparadas
*/
int orientacaoTorre(Torre t1,Torre t2,Torre t3);

/*
  -Calcula a coordenada polar de duas Torres
  -t1,t2 torres utilizadas
*/
double coordPolarTorre(Torre t1,Torre t2);

/*
  -Desaloca a memória utilizada por uma Torre
  -t:torre genérica que será desalocada
*/
void liberaTorre(Torre t);

#endif
