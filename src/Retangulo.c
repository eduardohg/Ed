#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Retangulo.h"

struct reg{
  int id;
  double w;
  double h;
  double x;
  double y;
  char* cor;
};
typedef struct reg retangulo;



Retangulo criarRetangulo(int id,double w,double h,double x,double y,char *cor){
  int tam=0;
  retangulo *novoRetangulo;
  novoRetangulo = (retangulo *)malloc(sizeof(retangulo));
  novoRetangulo->id = id;
  novoRetangulo->w = w;
  novoRetangulo->h = h;
  novoRetangulo->x = x;
  novoRetangulo->y = y;

  tam = strlen(cor);
  novoRetangulo->cor = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novoRetangulo->cor,cor);

  return novoRetangulo;
}

int getRetanguloId(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->id;
}

double getRetanguloW(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->w;
}

double getRetanguloH(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->h;
}

double getRetanguloX(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->x;
}

double getRetanguloY(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->y;
}

char* getRetanguloCor(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  return r->cor;
}

void liberaRetangulo(Retangulo ret){
  retangulo *r;
  r = (retangulo*) ret;

  free(r->cor);
  free(r);
}
