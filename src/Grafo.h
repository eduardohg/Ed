#ifndef GRAFO_H
#define GRAFO_H
#include "Pilha.h"
#include "Hash.h"
#include "Lista.h"


typedef void *Grafo;
typedef void *Vertice;
typedef void *Aresta;

/*
  -Cria um grafo de tamanho n
  -n: Tamanho
*/
Grafo criarGrafo(int n);

/*
  -Cria um vértice
  -id: Id do vértice
  -x: Ponto x
  -y: Ponto y
*/
Vertice criarVertice(char *id,double x,double y);

/*
  -Cria uma aresta
  -nome: Nome da aresta(rua)
  -ldir: Cep da quadra que está do lado direito da aresta
  -lesq: Cep da quadra que está do lado esquerdo da aresta
  -cmp: Comprimento da aresta(rua)
  -vm: Velocidade média que os carros trafegam na rua
*/
Aresta criarAresta(char *nome,char *ldir,char *lesq,double cmp,double vm);

/*
  -Retorna um vértice do grafo Gr
  -Gr: Grafo genérico
  -id: id do vértice a ser retornado
*/
Vertice getVertice(Grafo Gr,char *id);

/*
  -Retorna uma lista com todos os vértices de um grafo
  -Gr: Grafo genérico
*/
Lista getAllVertices(Grafo Gr);

/*
  -Retorna uma aresta
  -Gr: Grafo genérico
  -v1: Vértice 1
  -v2: Vértice v2
*/
Aresta getAresta(Grafo Gr,Vertice v1,Vertice v2);

/*
  -Insere um Vértice no grafo
  -Gr: Grafo genérico
  -v1: Vértice que será inserido
*/
void insereVertice(Grafo Gr,Vertice v1);

/*
  -Insere uma aresta no grafo
  -Gr: Grafo genérico
  -Ar: Aresta a ser inserida
  -v1: Vértice genérico
  -v2: Vértice genérico
*/
void insereAresta(Grafo Gr,Aresta Ar,Vertice v1,Vertice v2);

/*
  -Verifica se dois vértices são adjacentes
  -Gr: Grafo genérico
  -v1: Vértice genérico
  -v2: Vértice genérico
*/
int verificaAdjacente(Grafo Gr,Vertice v1,Vertice v2);

/*
  -Retorna uma lista com todas as arestas de um vértice
  -Gr: Grafo genérico
  -v1: Vértice onde estão as arestas
*/
Lista getAllVerticesArestas(Grafo Gr,Vertice v1);

/*
  -Retorna uma lista de adjacentes
  -Gr: Grafo genérico
  -v1: Vértice
*/
Lista adjacentes(Grafo Gr,Vertice v1);

/*
  -Retorna o id de um vértice
  -v1: Vértice que será buscado o id
*/
char *getVerticeId(Vertice v1);

/*
  -Retorna o ponto x de um vértice
  -v1: Vértice que será buscado o ponto
*/
double getVerticeX(Vertice v1);

/*
  -Retorna o ponto y de um vértice
  -v1: Vértice que será buscado o ponto
*/
double getVerticeY(Vertice v1);

/*
  -Retorna o nome de uma aresta
  -a1: Aresta que será buscado o nome
*/
char *getArestaNome(Aresta a1);

/*
  -Retorna o ldir de uma aresta
  -a1: Aresta que será buscado o lado direito
*/
char *getArestaLdir(Aresta a1);

/*
  -Retorna o lesq de uma aresta
  -a1: Aresta que será buscado o lado esquerdo
*/
char *getArestaLesq(Aresta a1);

/*
  -Retorna o comprimento de uma aresta
  -a1: Aresta que será buscado o comprimento
*/
double getArestaCmp(Aresta a1);

/*
  -Retorna a velocidade média de uma aresta
  -a1: Aresta que será buscado a velocidade média
*/
double getArestaVm(Aresta a1);

/*
  -Remove um determinado vértice
  -Gr: Grafo genérico
  -v1: Vértice a ser removido
*/
void removeVertice(Grafo Gr,Vertice v1);

/*
  -Remove uma determinada aresta
  -Gr: Grafo genérico
  -v1: Vértice genérico
  -v2: Vértice genérico
*/
void removeAresta(Grafo Gr,Vertice v1,Vertice v2);

/*
  -Acha o menor caminho entre dois vértices e retorna os pontos em uma pilha
  -Gr: Grafo genérico
  -v1: Vértice genérico
  -v2: Vértice genérico
  -weight: Peso(D ou T)
*/
Pilha menorCaminho(Grafo Gr,Vertice v1,Vertice v2,char weight);

/*
  -inicializacao algoritmo de Dijkstra
  -vertice:Lista de vértices
  -v1:Vértice genérico
*/
void inicializa(Lista vertices,Vertice v1);

/*
  -Retorna o posic da menor distancia
  -vertices: Lista de vértices
*/
Posic minDist(Lista vertices);

/*
  -Atualiza a distancia
  -Gr: Grafo genérico
  -v1: Vértice genérico
  -weight: peso(D ou T)
*/
void atualizaDist(Grafo Gr, Vertice v1, char weight);

/*
  -Retorna a direção de dois vértices(N,S,L,O)
  -v1: Vértice genérico
  -v2: Vértice genérico
*/
char getDirection(Vertice v1,Vertice v2);

#endif
