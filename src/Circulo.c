#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Circulo.h"

struct reg{
  int id;
  double x;
  double y;
  double r;
  char* cor;
};

typedef struct reg circulo;

Circulo criarCirculo(int id,double r,double x,double y,char *cor){
  int tam=0;
  circulo *novoCirculo;
  novoCirculo = (circulo *)malloc(sizeof(circulo));
  novoCirculo->id = id;
  novoCirculo->x = x;
  novoCirculo->y = y;
  novoCirculo->r = r;
  tam = strlen(cor);

  novoCirculo->cor = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novoCirculo->cor,cor);

  return novoCirculo;
}

int getCirculoId(Circulo cir){
  circulo *c;
  c = (circulo*)cir;

  return c->id;
}

double getCirculoX(Circulo cir){
  circulo *c;
  c = (circulo*) cir;

  return c->x;
}

double getCirculoY(Circulo cir){
  circulo *c;
  c = (circulo*) cir;

  return c->y;
}

double getCirculoR(Circulo cir){
  circulo *c;
  c = (circulo*) cir;

  return c->r;
}

char* getCirculoCor(Circulo cir){
  circulo *c;
  c = (circulo*) cir;

  return c->cor;
}

void liberaCirculo(Circulo cir){
  circulo *c;
  c = (circulo*) cir;
  free(c->cor);
  free(c);
}

double coordPolarCirculo(Circulo c1,Circulo c2){
  double x1,x2,y1,y2;
  circulo *novoCirculo1,*novoCirculo2;
  novoCirculo1 = (circulo*)c1;
  novoCirculo2 = (circulo*)c2;

  x1 = novoCirculo1->x;
  x2 = novoCirculo2->x;
  y1 = novoCirculo1->y;
  y2 = novoCirculo2->y;

  return atan2((y2-y1),(x2-x1));
}

int orientacaoCirculo(Circulo c1,Circulo c2,Circulo c3){
  double x1,y1,x2,y2,x3,y3,result;
  circulo *novoCirculo1,*novoCirculo2,*novoCirculo3;
  novoCirculo1 = (circulo*)c1;
  novoCirculo2 = (circulo*)c2;
  novoCirculo3 = (circulo*)c3;
  x1 = novoCirculo1->x;
  x2 = novoCirculo2->x;
  x3 = novoCirculo3->x;
  y1 = novoCirculo1->y;
  y2 = novoCirculo2->y;
  y3 = novoCirculo3->y;

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
