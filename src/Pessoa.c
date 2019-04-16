#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Pessoa.h"

typedef struct pessoa_{
  char* cpf;
  char* nome;
  char* sobrenome;
  char sexo;
  char* nasc;
  char* cep;
  char face;
  char* compl;
  char* numTel;
  char *op;
  int num;
  double x,y;
}pessoa;

Pessoa criarPessoa(char *cpf,char *nome,char *sobrenome,char sexo,char *nasc){
  int tam=0;
  pessoa *p;
  p = (pessoa *)malloc(sizeof(pessoa));
  tam = strlen(cpf);
  p->cpf = (char *)malloc((tam+1)*sizeof(char));
  strcpy(p->cpf,cpf);
  tam = strlen(nome);
  p->nome = (char *)malloc((tam+1)*sizeof(char));
  strcpy(p->nome,nome);
  tam = strlen(sobrenome);
  p->sobrenome = (char *)malloc((tam+1)*sizeof(char));
  strcpy(p->sobrenome,sobrenome);
  tam = strlen(nasc);
  p->nasc = (char *)malloc((tam+1)*sizeof(char));
  strcpy(p->nasc,nasc);
  p->sexo = sexo;
  p->numTel = NULL;
  p->op = NULL;

  return p;
}

char* getPessoaCpf(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->cpf;
}

char* getPessoaNome(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->nome;
}

char* getPessoaSobrenome(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->sobrenome;
}

char* getPessoaNomeCompleto(Pessoa p){
  pessoa *carinha;
  char *fullName;
  int tamNome=0,tamSobre=0;
  carinha = (pessoa*)p;
  tamNome = strlen(carinha->nome);
  tamSobre = strlen(carinha->sobrenome);
  fullName = (char *)malloc((tamNome+tamSobre+2)*sizeof(char));
  sprintf(fullName, "%s %s",carinha->nome,carinha->sobrenome);

  return fullName;
}

char getPessoaSexo(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->sexo;
}

char* getPessoaNasc(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->nasc;
}

double getPessoaX(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa *)p;
  return carinha->x;
}

double getPessoaY(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa *)p;
  return carinha->y;
}

void setMorador(Pessoa p,char *cep,char face, char* comp,int num){
  int tam=0;
  pessoa *carinha;
  carinha = (pessoa*)p;
  tam = strlen(cep);
  carinha->cep = (char*)malloc((tam+1)*sizeof(char));
  strcpy(carinha->cep,cep);
  tam = strlen(comp);
  carinha->compl = (char*)malloc((tam+1)*sizeof(char));
  strcpy(carinha->compl,comp);
  carinha->face = face;
  carinha->num = num;
}

void setPessoaX(Pessoa p,double x){
  pessoa *carinha;
  carinha = (pessoa *)p;
  carinha->x = x;
}

void setPessoaY(Pessoa p,double y){
  pessoa *carinha;
  carinha = (pessoa *)p;
  carinha->y = y;
}

void setPessoaNumTel(Pessoa p,char *tel){
  pessoa *carinha;
  carinha = (pessoa *)p;
  carinha->numTel = (char *)malloc((strlen(tel)+1)*sizeof(char));
  strcpy(carinha->numTel,tel);
}

void setPessoaOp(Pessoa p,char *op){
  pessoa *carinha;
  carinha = (pessoa *)p;
  carinha->op = (char *)malloc((strlen(op)+1)*sizeof(char));
  strcpy(carinha->op,op);
}

char* getPessoaOp(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa *)p;
  return carinha->op;
}

char* getPessoaNumTel(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa *)p;
  return carinha->numTel;
}

char* getMoradorCep(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->cep;
}

char getMoradorFace(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->face;
}

char* getMoradorCompl(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa*)p;

  return carinha->compl;
}

int getMoradorNum(Pessoa p){
  pessoa *carinha;
  carinha = (pessoa *)p;
  return carinha->num;
}
