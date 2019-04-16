#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Hidrante.h"

struct reg{
    char* id;
    double x,y,r,vazao;
    char* corp;
    char* corb;
};

typedef struct reg hidrante;

Hidrante criarHidrante(char* id,double x,double y,char* corp,char* corb){
    int tam = 0;

    hidrante *novoHidrante;
    novoHidrante = (hidrante *)malloc(sizeof(hidrante));
    tam = strlen(id);
    novoHidrante->id = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoHidrante->id,id);

    novoHidrante->x = x;
    novoHidrante->y = y;
    tam = strlen(corp);

    novoHidrante->corp = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoHidrante->corp,corp);

    tam = strlen(corb);
    novoHidrante->corb = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoHidrante->corb,corb);

    return novoHidrante;
}

void setVazaoHidrante(Hidrante h,double vazao){
  hidrante *novoHidrante;
  novoHidrante = (hidrante*)h;
  novoHidrante->vazao = vazao; 
}

char* getHidranteId(Hidrante h){
    hidrante *novoHidrante;
    novoHidrante = (hidrante*) h;

    return novoHidrante->id;
}

double getHidranteX(Hidrante h){
    hidrante *novoHidrante;
    novoHidrante = (hidrante*) h;

    return novoHidrante->x;
}

double getHidranteY(Hidrante h){
    hidrante *novoHidrante;
    novoHidrante = (hidrante*) h;

    return novoHidrante->y;
}

char* getHidranteCorP(Hidrante h){
  hidrante *novoHidrante;
  novoHidrante = (hidrante*) h;

  return novoHidrante->corp;
}

char* getHidranteCorB(Hidrante h){
    hidrante *novoHidrante;
    novoHidrante = (hidrante*) h;

    return novoHidrante->corb;
}

int comparaHidrante(Hidrante h1,Hidrante h2){
  hidrante *novoHidrante1;
  hidrante *novoHidrante2;
  novoHidrante1 = (hidrante*)h1;
  novoHidrante2 = (hidrante*)h2;

  if(novoHidrante1->y < novoHidrante2->y){
    return -1;
  }
  else if(novoHidrante1->y > novoHidrante2->y){
    return 1;
  }
  else
    return 0;
}

void escreveHidrante(FILE **arq,Hidrante h){
  hidrante *novoHidrante;

  novoHidrante = (hidrante*)h;
  fprintf(*arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" stroke=\"%s\"/>\n",novoHidrante->x,novoHidrante->y,novoHidrante->corp,novoHidrante->corb);

}

double coordPolarHidrante(Hidrante h1,Hidrante h2){
  double x1,x2,y1,y2;
  hidrante *novoHidrante1,*novoHidrante2;
  novoHidrante1 = (hidrante*)h1;
  novoHidrante2 = (hidrante*)h2;

  x1 = novoHidrante1->x;
  x2 = novoHidrante2->x;
  y1 = novoHidrante1->y;
  y2 = novoHidrante2->y;

  return atan2((y2-y1),(x2-x1));
}

int orientacaoHidrante(Hidrante h1,Hidrante h2,Hidrante h3){
  double x1,y1,x2,y2,x3,y3,result;
  hidrante *novoHidrante1,*novoHidrante2,*novoHidrante3;

  novoHidrante1 = (hidrante*)h1;
  novoHidrante2 = (hidrante*)h2;
  novoHidrante3 = (hidrante*)h3;
  x1 = novoHidrante1->x;
  x2 = novoHidrante2->x;
  x3 = novoHidrante3->x;
  y1 = novoHidrante1->y;
  y2 = novoHidrante2->y;
  y3 = novoHidrante3->y;

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

void liberaHidrante(Hidrante h){
  hidrante *novoHidrante;
  novoHidrante = (hidrante*) h;
  free(novoHidrante->id);
  free(novoHidrante->corp);
  free(novoHidrante->corb);
  free(novoHidrante);
}
