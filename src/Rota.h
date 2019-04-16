#ifndef ROTA_H
#define ROTA_H
#include "Cidade.h"
#include "Dicionario.h"
#include "Hash.h"
#include "Grafo.h"
#include "Pilha.h"
#include "Lista.h"
#include "Operacoes.h"

/*
  -representacaoPictorica do trajeto
*/
void representacaoPictorica(Cidade cid,Dicionario dic,Grafo grafo,Vertice origem,Vertice destino,char peso,char *nomeSvg,char *cor);

/*
  -Desenha a rota no arquivo SVG
*/
void fazerRota(FILE **arq,Cidade cid,Grafo grafo,Dicionario dic,Pilha pilha,char *cor);

/*
  -representacao Textual do trajeto
*/
void describe(Grafo grafo,Vertice origem,Vertice destino,char peso,char *nomeTxt);

/*
  -Escreve a rota no arquivo txt
*/
void writeRoute(FILE **arq,Grafo grafo,Pilha pilha);

#endif
