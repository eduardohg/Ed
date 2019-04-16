#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "EstabelecimentoComercial.h"

typedef struct _estabelecimento{
  char *tipo;
  char *cep;
  char face;
  int num;
  char *cnpj;
  char *nome;
  double x,y;
}estabelecimento;

EstabelecimentoCom criarEstabelecimento(char *tipo,char *cep,char face,int num,char *cnpj,char *nome){
  estabelecimento *e;
  e = (estabelecimento *)malloc(sizeof(estabelecimento));
  e->tipo = (char *)malloc((strlen(tipo)+1)*sizeof(char));
  strcpy(e->tipo,tipo);
  e->cep = (char *)malloc((strlen(cep)+1)*sizeof(char));
  strcpy(e->cep,cep);
  e->face = face;
  e->num = num;
  e->cnpj = (char *)malloc((strlen(cnpj)+1)*sizeof(char));
  strcpy(e->cnpj,cnpj);
  e->nome = (char *)malloc((strlen(nome)+1)*sizeof(char));
  strcpy(e->nome,nome);

  return e;
}

void setEstabelecimentoX(EstabelecimentoCom e,double x){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  e1->x = x;
}

char* getEstabelecimentoCodt(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->tipo;
}

char* getEstabelecimentoNome(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->nome;
}

char getEstabelecimentoFace(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->face;
}

int getEstabelecimentoNum(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->num;
}

char* getEstabelecimentoCep(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->cep;
}

char* getEstabelecimentoCnpj(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->cnpj;
}

void setEstabelecimentoY(EstabelecimentoCom e,double y){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  e1->y = y;
}

double getEstabelecimentoX(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->x;
}

double getEstabelecimentoY(EstabelecimentoCom e){
  estabelecimento *e1;
  e1 = (estabelecimento *)e;
  return e1->y;
}
