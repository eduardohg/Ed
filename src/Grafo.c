#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>
#include "Grafo.h"

#define INFINITY 9999999

typedef struct grafo_{
  Hash vertices;
  int tam;
}grafo;

typedef struct vertice_{
  char *id;
  double x,y;
  double dist;
  Lista arestas;
  struct vertice_ *ant;
}vertice;

typedef struct aresta_{
  char *nome;
  char *ldir;
  char *lesq;
  double cmp,vm;
  double Pdist,Ptempo;
  vertice *destino;
}aresta;

Grafo criarGrafo(int n){
  grafo *g;
  g = malloc(sizeof(grafo));
  g->tam = n;
  g->vertices = createHash(n);

  return (Grafo)g;
}

Vertice criarVertice(char *id,double x,double y){
  vertice *v;

  v = malloc(sizeof(vertice));
  v->id = (char *)malloc((strlen(id)+1)*sizeof(char));
  strcpy(v->id,id);
  v->x = x;
  v->y = y;
  v->arestas = createList();
  return (Vertice)v;
}

Aresta criarAresta(char *nome,char *ldir,char *lesq,double cmp,double vm){
  aresta *a;
  a = malloc(sizeof(aresta));
  a->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
  strcpy(a->nome,nome);

  a->ldir = (char *)malloc((strlen(ldir)+1)*sizeof(char));
  strcpy(a->ldir,ldir);

  a->lesq = (char *)malloc((strlen(lesq)+1)*sizeof(char));
  strcpy(a->lesq,lesq);

  a->cmp = cmp;
  a->vm = vm;
  a->Pdist = cmp;

  if(vm != 0)
    a->Ptempo = cmp/vm;
  else
    a->Ptempo = 0;

  a->destino = NULL;
  return (Aresta)a;
}

Vertice getVertice(Grafo Gr,char *id){
  grafo *g;
  vertice *v;
  g = (grafo *)Gr;

  v = getRegInfo(g->vertices,id);

  return (Vertice)v;
}

Lista getAllVertices(Grafo Gr){
  grafo *g;
  Lista list;

  g = (grafo *) Gr;
  list = createList();
  list = getAllRegInfo(g->vertices);
  return list;
}

Aresta getAresta(Grafo Gr,Vertice v1,Vertice v2){
  grafo *g;
  aresta *a;
  vertice *ve1,*ve2;
  Posic p;

  g = (grafo *)Gr;
  ve1 = (vertice *)v1;
  ve2 = (vertice *)v2;

  if(verificaAdjacente(Gr,v1,v2)){
    p = getFirst(ve1->arestas);
    while(p!=NULL){
      a = (aresta *)get(ve1->arestas,p);
      if((vertice *)a->destino == ve2){
        return (Aresta)a;
      }
      p = getNext(ve1->arestas,p);
    }
  }
  return NULL;
}

void insereVertice(Grafo Gr,Vertice v1){
  grafo *g;
  vertice *v;
  g = (grafo *)Gr;
  v = (vertice *)v1;

  insertRegInfo(g->vertices,v1,v->id);
}

void insereAresta(Grafo Gr,Aresta Ar,Vertice v1,Vertice v2){
  grafo *g;
  aresta *a;
  vertice *ve1,*ve2;

  g = (grafo *)Gr;
  a = (aresta *)Ar;
  ve1 = (vertice *)v1;
  ve2 = (vertice *)v2;

  a->destino = ve2;
  insert(ve1->arestas,(Aresta)a);
}

int verificaAdjacente(Grafo Gr,Vertice v1,Vertice v2){
  grafo *g;
  aresta *a;
  vertice *ve1,*ve2;
  Posic p;

  g = (grafo *)Gr;
  ve1 = (vertice *)v1;
  ve2 = (vertice *)v2;

  p = getFirst(ve1->arestas);
  while(p!=NULL){
    a = (aresta *)get(ve1->arestas,p);
    if((vertice *)a->destino == ve2){
      return 1;
    }
    p = getNext(ve1->arestas,p);
  }
  return 0;
}

Lista getAllVerticesArestas(Grafo Gr,Vertice v1){
  grafo *g;
  vertice *v;
  v = (vertice *)v1;
  return v->arestas;
}

Lista adjacentes(Grafo Gr,Vertice v1){
  grafo *g;
  vertice *v;
  aresta *a;
  Lista vertices;
  Posic p;

  g = (grafo *)Gr;
  v = (vertice *)v1;

  vertices = createList();

  p = getFirst(v->arestas);
  while(p!=NULL){
    a = (aresta *)get(v->arestas,p);
    if(a->destino != NULL){
      insert(vertices,a->destino);
    }
    p = getNext(v->arestas,p);
  }
  if(length(vertices)>0)
    return vertices;
  else{
    free(vertices);
    return NULL;
  }
}

char *getVerticeId(Vertice v1){
  vertice *v;
  v = (vertice *)v1;

  return v->id;
}

double getVerticeX(Vertice v1){
  vertice *v;
  v = (vertice *)v1;

  return v->x;
}

double getVerticeY(Vertice v1){
  vertice *v;
  v = (vertice *)v1;

  return v->y;
}

char *getArestaNome(Aresta a1){
  aresta *a;
  a = (aresta *)a1;

  return a->nome;
}

char *getArestaLdir(Aresta a1){
  aresta *a;
  a = (aresta *)a1;

  return a->ldir;
}

char *getArestaLesq(Aresta a1){
  aresta *a;
  a = (aresta *)a1;

  return a->lesq;
}

double getArestaCmp(Aresta a1){
  aresta *a;
  a = (aresta *)a1;

  return a->cmp;
}

double getArestaVm(Aresta a1){
  aresta *a;
  a = (aresta *)a1;

  return a->vm;
}

void removeVertice(Grafo Gr,Vertice v1){
  grafo *g;
  vertice *v;

  g = (grafo *)Gr;
  v = (vertice *)v1;
  /*Função clear lista*/
  free(v->id);
  free(v);
}

void removeAresta(Grafo Gr,Vertice v1,Vertice v2){
  grafo *g;
  aresta *a;
  vertice *ve1,*ve2;

  g = (grafo *)Gr;
  ve1 = (vertice *)v1;
  ve2 = (vertice *)v2;

  if(verificaAdjacente(Gr,v1,v2)){
    a = (aresta *)getAresta(Gr,v1,v2);
    a->destino = NULL;
    free(a->nome);
    free(a->ldir);
    free(a->lesq);
    remover(ve1->arestas,a);
  }
}

Pilha menorCaminho(Grafo Gr,Vertice v1,Vertice v2,char weight){
  vertice *v,*aux;
  Pilha path;
  Lista vertices;
  Posic p;

  vertices = getAllVertices(Gr);
  inicializa(vertices,v1);

  while(length(vertices)>0){
    p = minDist(vertices);
    v = get(vertices,p);
    remover(vertices,p);

    if(v == v2)
      break;

    atualizaDist(Gr,v,weight);
  }
  path = inicializacao();
  while(v != NULL){
    empilhar(path,(void*)v);
    v = v->ant;
  }
  return path;

}

void inicializa(Lista vertices,Vertice v1){
  vertice *v,*aux;
  Posic p;

  aux = (vertice *)v1;
  p = getFirst(vertices);
  while (p!=NULL) {
    v = get(vertices,p);
    v->dist = INFINITY;
    v->ant = NULL;

    p = getNext(vertices,p);
  }
  aux->dist = 0;
}

Posic minDist(Lista vertices){
  vertice *v;
  Posic p,pmin;
  double min=INFINITY;

  p = getFirst(vertices);
  pmin = p;
  while(p != NULL){
    v = get(vertices,p);
    if(v->dist < min){
      min = v->dist;
      pmin = p;
    }
    p = getNext(vertices,p);
  }
  return pmin;
}

void atualizaDist(Grafo Gr, Vertice v1, char weight) {
  grafo *g;
  vertice *v, *aux;
  aresta *a;
  Lista neighbors;
  Posic p;
  double alt;

  g = (grafo *) Gr;

  v = (vertice *) v1;

  neighbors = adjacentes(g,v);

  if (neighbors != NULL) {
    p = getFirst(neighbors);
    while (p != NULL) {
      alt = v->dist;

      aux = (vertice *) get(neighbors, p);
      a = getAresta(g, v, aux);

      if (weight == 'D')
      alt += a->Pdist;
      else if (weight == 'T')
      alt += a->Ptempo;

      if (alt < aux->dist) {
        aux->dist = alt;
        aux->ant = v;
      }

      p = getNext(v->arestas, p);
    }
  }
}

char getDirection(Vertice v1,Vertice v2){
  vertice *aux1,*aux2;
  aux1 = (vertice *)v1;
  aux2 = (vertice *)v2;

  if(aux1->x > aux2->x)
    return 'L';
  else if(aux1->x < aux2->x)
    return 'O';
  else if(aux1->y > aux2->y)
    return 'N';
  else if(aux1->y < aux2->y)
    return 'S';
}
