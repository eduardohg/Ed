#ifndef QUADRA_H
#define QUADRA_H
#include "Lista.h"

/*
  Quadra é um tipo que possibilita a criação e manipulação de quadras.
*/
typedef void* Quadra;

/*
  -Cria uma Quadra
  -cep = identificador
  -x,y:pontos do plano cartesiano, corp:cor do preenchimento da Quadra, corb: cor da borda da Quadra, larg: largura da Quadra, alt: altura da quadra
*/
Quadra criarQuadra(double x,double y, double larg,double alt, char* cep,char* corp,char* corb);

/*
  -Retorna o cep de uma Quadra
  -q: Quadra genérica
*/
char* getQuadraCep(Quadra q);

/*
  -Retorna o ponto x de uma Quadra
  -q: Quadra genérica
*/
double getQuadraX(Quadra q);

/*
  -Retorna o ponto y de uma Quadra
  -q: Quadra genérica
*/
double getQuadraY(Quadra q);

/*
  -Retorna a largura de uma Quadra
  -q: Quadra genérica
*/
double getQuadraLarg(Quadra q);

/*
  -Retorna a altura de uma Quadra
  -q: Quadra genérica
*/
double getQuadraAlt(Quadra q);

/*
  -Retorna a cor de preenchimento de uma Quadra
  -q: Quadra genérica
*/
char* getQuadraCorP(Quadra q);

/*
  -Retorna a cor da borda de uma Quadra
  -q: Quadra genérica
*/
char* getQuadraCorB(Quadra q);

/*
  -Compara o ponto y de duas quadras
*/

int comparaQuadra(Quadra q1,Quadra q2);

/*
  -Escreve uma determinada quadra em um arquivo
  -arq: Arquivo que será imprimido a quadra
  -q: Quadra a ser impressa
*/
void escreveQuadra(FILE **arq,Quadra q);

/*
  -Calcula a coordenada polar de duas Quadra
  -q1: Quadra genérica
  -q2: Quadra genérica
*/
double coordPolarQuadra(Quadra q1,Quadra q2);

/*
  -Retorna a orientação de três quadras(horário,anti-horário)
  -q1: Quadra genérica
  -q2: Quadra genérica
  -q3: Quadra genérica
*/
int orientacaoQuadra(Quadra q1,Quadra q2,Quadra q3);

/*
  -Insere um morador na lista de moradores da quadra
  -q: Quadra
  -pessoa: Morador que será inserido na lista de moradores da quadra q
*/
void insertMoradorQuadra(Quadra q,void* pessoa);

/*
  -Insere um estabelecimento na lista de estabelecimentos da quadra
  -q: Quadra
  -est: Estabelecimento que será inserido na lista de estabelecimentos da quadra q
*/
void insertEstabQuadra(Quadra q,void* est);

/*
  -Retorna a lista de estabelecimentos de uma Quadra
  -q: Quadra
*/
Lista getListaEstabQuadra(Quadra q);

/*
  -Desaloca a memória utilizada por um Quadra
  -q:quadra genérica que será desalocada
*/
void liberaQuadra(Quadra q);

/*
  -Retorna a lista de moradores de uma quadra
  -q: Quadra
*/
Lista getListaMoradoresQuadra(Quadra q);

#endif
