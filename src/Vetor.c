#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Vetor.h"
#include "Circulo.h"
#include "Retangulo.h"

typedef struct reg{
  void *obj;
  double ang,x,y;
  int tam;
}vetor;

Vetor criaVetor(int qtd){
  vetor *vet;
  vet = malloc(qtd*sizeof(vetor));
  vet->tam = 0;
  return(Vetor *) vet;

}

void addElemento(Vetor vet,int i,void *forma,double x,double y){
  vetor *v;
  v = (vetor *) vet;
  v->tam++;
  v[i].obj = (vetor *) forma;
  v[i].x = x;
  v[i].y = y;

}

Vetor *getElemento(Vetor vet,int i){
  vetor *v;
  v = (vetor*)vet;

  return v[i].obj;
}

int getTamanhoVetor(Vetor vet){
  vetor *v;
  v = (vetor*)vet;

  return v->tam;
}

double getAng(Vetor vet,int i){
  vetor *v;
  v = (vetor*)vet;

  return v[i].ang;
}

double getVetorX(Vetor vet,int i){
  vetor *v;
  v = (vetor*)vet;

  return v[i].x;
}

double getVetorY(Vetor vet,int i){
  vetor *v;
  v = (vetor*)vet;

  return v[i].y;
}

void addAng(Vetor vet,int i,double angulo){
  vetor *v;
  v = (vetor*)vet;

  v[i].ang = angulo;

}

int comparaY(Vetor vet,int i, int j){
  vetor *v;
  v = (vetor*)vet;
  if(v[i].y < v[j].y)
    return -1;
  else if(v[i].y > v[j].y)
    return 1;
  else
    return 0;
}

int comparaX(Vetor vet,int i,int j){
  vetor *v;
  v = (vetor*)vet;

  if(v[i].x < v[j].x)
    return -1;
  else if(v[i].x > v[j].x)
    return 1;
  else
    return 0;

}

int comparaAng(Vetor vet,int i,int j){
  vetor *v;
  v = (vetor*)vet;

  if(v[i].ang < v[j].ang){
    return -1;
  }
  else if(v[i].ang > v[j].ang){
    return 1;
  }
  else
    return 0;
}

void troca(Vetor vet,int i,int j){
  vetor *v;
  void *info;
  double xAux,yAux,angulo;

  v = (vetor*)vet;

  xAux = v[i].x;
  yAux = v[i].y;
  angulo = v[i].ang;
  info = v[i].obj;
  v[i].x = v[j].x;
  v[i].y  = v[j].y;
  v[i].ang = v[j].ang;
  v[i].obj = v[j].obj;
  v[j].x = xAux;
  v[j].y = yAux;
  v[j].ang = angulo;
  v[j].obj = info;

}

int calculaIndice(char *ind){
  char *aux;
  int a,tam;
  aux = (char *)malloc(5*sizeof(char));
  tam = strlen(ind);
  for(a=0;a<tam;a++){
    aux[a] = ind[a+1];
  }
  aux[a+1]='\0';
  a = atoi(aux);
  free(aux);
  return a;
}

/*
void liberaVetor(Vetor vet,int i){
  int n;
  vetor *v;
  v = (vetor*)vet;

  for(n=0;n<i;n++){
    if(v[n].type=='c'){
      liberaCirculo(v[n].obj);
    }
    if(v[n].type=='r'){
      liberaRetangulo(v[n].obj);
    }
  }
  free(v);
}
*/
