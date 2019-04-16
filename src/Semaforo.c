#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Semaforo.h"

struct reg{
    char* id;
    double x,y,tempo;
    char* corp;
    char* corb;
};
typedef struct reg semaforo;

Semaforo criarSemaforo(char* id,double x,double y,char* corp,char* corb){
    int tam = 0;

    semaforo *novoSemaforo;
    novoSemaforo = (semaforo *)malloc(sizeof(semaforo));
    tam = strlen(id);
    novoSemaforo->id = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoSemaforo->id,id);
    novoSemaforo->x = x;
    novoSemaforo->y = y;
    tam = strlen(corp);
    novoSemaforo->corp = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoSemaforo->corp,corp);
    tam = strlen(corb);
    novoSemaforo->corb = (char *)malloc((tam+1)*sizeof(char));
    strcpy(novoSemaforo->corb,corb);

    return novoSemaforo;
}

void setSemaforoTempo(Semaforo s,double tempo){
  semaforo *novoSemaforo;
  novoSemaforo = (semaforo*)s;

  novoSemaforo->tempo = tempo;
}

char* getSemaforoId(Semaforo s){
    semaforo *novoSemaforo;
    novoSemaforo = (semaforo*) s;

    return novoSemaforo->id;
}

double getSemaforoX(Semaforo s){
    semaforo *novoSemaforo;
    novoSemaforo = (semaforo*) s;

    return novoSemaforo->x;
}

double getSemaforoY(Semaforo s){
    semaforo *novoSemaforo;
    novoSemaforo = (semaforo*) s;

    return novoSemaforo->y;
}

char* getSemaforoCorP(Semaforo s){
  semaforo *novoSemaforo;
  novoSemaforo = (semaforo*) s;

  return novoSemaforo->corp;
}

char* getSemaforoCorB(Semaforo s){
    semaforo *novoSemaforo;
    novoSemaforo = (semaforo*) s;

    return novoSemaforo->corb;
}

int comparaSemaforo(Semaforo s1,Semaforo s2){
  semaforo *novoSemaforo1;
  semaforo *novoSemaforo2;

  novoSemaforo1 = (semaforo*)s1;
  novoSemaforo2 = (semaforo*)s2;

  if(novoSemaforo1->y < novoSemaforo2->y){
    return -1;
  }
  else if(novoSemaforo1->y > novoSemaforo2->y){
    return 1;
  }
  else
    return 0;
}

void escreveSemaforo(FILE **arq,Semaforo s){
  semaforo *novoSemaforo;

  novoSemaforo = (semaforo*)s;
  fprintf(*arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" stroke=\"%s\"/>\n",novoSemaforo->x,novoSemaforo->y,novoSemaforo->corb,novoSemaforo->corp);

}

double coordPolarSemaforo(Semaforo s1,Semaforo s2){
  double x1,x2,y1,y2;
  semaforo *novoSemaforo1,*novoSemaforo2;
  novoSemaforo1 = (semaforo*)s1;
  novoSemaforo2 = (semaforo*)s2;

  x1 = novoSemaforo1->x;
  x2 = novoSemaforo2->x;
  y1 = novoSemaforo1->y;
  y2 = novoSemaforo2->y;

  return atan2((y2-y1),(x2-x1));
}

int orientacaoSemaforo(Semaforo s1,Semaforo s2,Semaforo s3){
  double x1,y1,x2,y2,x3,y3,result;
  semaforo *novoSemaforo1,*novoSemaforo2,*novoSemaforo3;

  novoSemaforo1 = (semaforo*)s1;
  novoSemaforo2 = (semaforo*)s2;
  novoSemaforo3 = (semaforo*)s3;
  x1 = novoSemaforo1->x;
  x2 = novoSemaforo2->x;
  x3 = novoSemaforo3->x;
  y1 = novoSemaforo1->y;
  y2 = novoSemaforo2->y;
  y3 = novoSemaforo3->y;

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

void liberaSemaforo(Semaforo s){
  semaforo *novoSemaforo;
  novoSemaforo = (semaforo*) s;
  free(novoSemaforo->id);
  free(novoSemaforo->corp);
  free(novoSemaforo->corb);
  free(novoSemaforo);
}
