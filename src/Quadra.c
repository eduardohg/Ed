#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Quadra.h"

struct reg{
    double x,y,larg,alt;
    char* cep;
    char* corp;
    char* corb;
    Lista *moradores;
    Lista *estabelecimentos;
};

typedef struct reg quadra;

Quadra criarQuadra(double x,double y, double larg,double alt, char* cep,char *corp,char* corb){
    int tam = 0;
    quadra *novaQuadra;
    novaQuadra = (quadra *)malloc(sizeof(quadra));
    tam = strlen(cep);
    novaQuadra->cep = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novaQuadra->cep,cep);
    novaQuadra->x = x;
    novaQuadra->y = y;
    novaQuadra->larg = larg;
    novaQuadra->alt = alt;
    tam = strlen(corp);
    novaQuadra->corp = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novaQuadra->corp,corp);

    tam = strlen(corb);
    novaQuadra->corb = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novaQuadra->corb,corb);
    novaQuadra->moradores = createList();
    novaQuadra->estabelecimentos = createList();

    return novaQuadra;

}

char* getQuadraCep(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra *) q;

    return novaQuadra->cep;
}

double getQuadraX(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra*) q;

    return novaQuadra->x;
}

double getQuadraY(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra*) q;

    return novaQuadra->y;
}

double getQuadraLarg(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra*) q;

    return novaQuadra->larg;
}

double getQuadraAlt(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra*) q;

    return novaQuadra->alt;
}

char* getQuadraCorP(Quadra q){
  quadra *novaQuadra;
  novaQuadra = (quadra*) q;

  return novaQuadra->corp;
}

char* getQuadraCorB(Quadra q){
    quadra *novaQuadra;
    novaQuadra = (quadra*) q;

    return novaQuadra->corb;
}


int comparaQuadra(Quadra q1,Quadra q2){
  quadra *novaQuadra;
  quadra *novaQuadra2;

  novaQuadra = (quadra*)q1;
  novaQuadra2 = (quadra*)q2;

  if(novaQuadra->y < novaQuadra2->y){
    return -1;
  }
  else if(novaQuadra->y > novaQuadra2->y){
    return 1;
  }
  else{
    return 0;
  }
}

void escreveQuadra(FILE **arq,Quadra q){
  quadra *novaQuadra;
  novaQuadra = (quadra*)q;

  fprintf(*arq, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" stroke=\"%s\" />\n",novaQuadra->x,novaQuadra->y,novaQuadra->larg,novaQuadra->alt,novaQuadra->corp,novaQuadra->corb);

}

double coordPolarQuadra(Quadra q1,Quadra q2){
  double x1,x2,y1,y2;
  quadra *novaQuadra1,*novaQuadra2;
  novaQuadra1 = (quadra*)q1;
  novaQuadra2 = (quadra*)q2;

  x1 = novaQuadra1->x;
  x2 = novaQuadra2->x;
  y1 = novaQuadra1->y;
  y2 = novaQuadra2->y;

  return atan2((y2-y1),(x2-x1));
}

int orientacaoQuadra(Quadra q1,Quadra q2,Quadra q3){
  double x1,y1,x2,y2,x3,y3,result;
  quadra *novaQuadra1,*novaQuadra2,*novaQuadra3;

  novaQuadra1 = (quadra*)q1;
  novaQuadra2 = (quadra*)q2;
  novaQuadra3 = (quadra*)q3;
  x1 = novaQuadra1->x;
  x2 = novaQuadra2->x;
  x3 = novaQuadra3->x;
  y1 = novaQuadra1->y;
  y2 = novaQuadra2->y;
  y3 = novaQuadra3->y;

  result = (y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);

  /*Horário*/
  if(result > 0)
    return 1;
  /*Anti-horário*/
  else if(result < 0)
    return -1;
  /*Colinear*/
  else
    return 0;

}

void liberaQuadra(Quadra q){
  quadra *novaQuadra;
  novaQuadra = (quadra*) q;
  free(novaQuadra->corp);
  free(novaQuadra->corb);
  free(novaQuadra->cep);
  free(novaQuadra);
}

void insertMoradorQuadra(Quadra q,void* pessoa){
  quadra *novaQuadra;
  novaQuadra = (quadra *)q;
  if(q == NULL){
    printf("quadra null\n");
  }
  if(pessoa == NULL){
    printf("null\n");
  }

  insert(novaQuadra->moradores,pessoa);
}

void insertEstabQuadra(Quadra q,void* est){
  quadra *novaQuadra;
  novaQuadra = (quadra *)q;

  insert(novaQuadra->estabelecimentos,est);
}

Lista getListaEstabQuadra(Quadra q){
  quadra *novaQuadra;
  novaQuadra = (quadra *)q;

  return (Lista)novaQuadra->estabelecimentos;
}

Lista getListaMoradoresQuadra(Quadra q){
  quadra *novaQuadra;
  novaQuadra = (quadra *)q;

  return (Lista)novaQuadra->moradores;
}
