#ifndef ARQQRY_H
#define ARQQRY_H
#include "Lista.h"
#include "Hidrante.h"
#include "Torre.h"
#include "Cidade.h"
#include "QuadTree.h"
#include "Circulo.h"
#include "EnvoltorioConvexo.h"
#include "Dicionario.h"
#include "Pessoa.h"
#include "EstabelecimentoComercial.h"
#include "Grafo.h"
#include "Procedimentos.h"
/*
 -Menu de funções recebidas no arquivo.geo
 -cid:cidade genérica
 -circ:lista de circulos
 -retang:lista de retangulos
 -sobrepos:lista de sobreposições
 -arq:arquivo.geo
 -svg:arquivo.svg
 -txt:arquivo.txt
 -qry:arquivo.qry
 -resum:resumo.txt
 -str:string auxiliar em procedimentos
 -testes: nome do arquivo.qry
 -pasta: diretório de entrada (-e)
 -dir:diretório de saida
 -nome:nome do arquivo.geo
 -cor:string
 -k: variável que diz se temos acc0 ou acc
 -var: variável que diz se temos -q
 -ins:variável que conta o numero de quadras inseridas
*/
void menuQry(Cidade *cid,Dicionario dic,Lista *circ,Lista *retang,Lista *sobrepos,FILE **arq,FILE **txt,FILE **qry,FILE **resum,char **str,char **testes,char **aux,char **pasta,char **dir,char **nome,char **cor,int *k,int *var,int ins,Grafo grafo);

/*
  -Lê os comandos da função ds
  -qry:arquivo.qry
  -x:ponto x
  -y:ponto y
  -w:largura
  -h:altura
*/
void lerds(FILE **qry,double *x,double *y,double *w,double *h);

/*
  -Lê os comandos da função Ds
  -qry:arquivo.qry
  -x:ponto x
  -y:ponto y
  -r:raio da forma
*/
void lerDs(FILE **qry,double *x,double *y,double *r);

void lerComandoAc(FILE **arq,double *x,double *y,double *l,double *a);

/*
  -função para remover quadra pelo comando dq
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -w:largura
  -h:altura
*/
int removedq(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt,int *del,int *cpd);

/*
  -função para remover Hidrante pelo comando dh
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -w:largura
  -h:altura
*/
int removedh(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt);
/*
  -função para remover semaforo pelo comando ds
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -w:largura
  -h:altura
*/
int removeds(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt);
/*
  -função para remover torre pelo comando dt
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -w:largura
  -h:altura
*/
int removedt(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt);
/*
  -função para remover quadra pelo comando Dq
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -r:raio da forma
*/
int removeDq(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt,int *del,int *cpd);

/*
  -função para remover hidrante pelo comando Dh
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -r:raio da forma
*/
int removeDh(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt);

/*
  -função para remover semaforo pelo comando Ds
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -r:raio da forma
*/
int removeDs(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt);

/*
  -função para remover torre pelo comando Dt
  -cid:cidade genérica
  -p:Posic
  -x:ponto x
  -y:ponto y
  -r:raio da forma
*/
int removeDt(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt);

/*
  -Percorre os equipamentos urbanos a procura do cep ou id(crd?)
  -cid:cidade genérica
  -txt:arquivo.txt
  -id:identificador do equipamento urbano
*/
void percorreCidQuadra(Cidade *cid,FILE **txt,char **id,PosicNo *n);

void percorreCidTorre(Cidade *cid,FILE **txt,char **id,PosicNo *n);

void percorreCidHidrante(Cidade *cid,FILE **txt,char **id,PosicNo *n);

void percorreCidSemaforo(Cidade *cid,FILE **txt,char **id,PosicNo *n);

/*
  -Lê o comando con(t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoCon(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando dm (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoDm(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando m (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoM(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando de (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoDe(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando lk (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoLk(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando rb (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoRb(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando ecq (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoEcq(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando dc? (t5)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -txt: Arquivo onde é feito a escrita
*/
void lerComandoDc(FILE **qry,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Lê comando @f? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryF(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores);

/*
  -Lê comando @m? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryM(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores);

/*
  -Lê comando @e? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryE(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores);

/*
  -Lê comando @g? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryG(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores);

/*
  -Lê comando @xy? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryXY(FILE **qry,Vetor registradores);

/*
  -Lê comando @tp? (t6)
  -qry: Arquivo qry
  -dic: Dicionario genérico
  -cid: Cidade genérica
  -registradores: Vetor de 10 posições
*/
void lerComandoQryTp(FILE **qry,Cidade cid,Dicionario dic,Vetor registradores);

/*
  -Lê comando @p? (t6)
  -dir: String com o diretório de saída
  -nome: Nome do arquivo .geo
  -aux: Nome do arquivo .qry
  -grafo: Grafo
  -cid: Cidade genérica
  -dic: Dicionario genérico
  -registradores: Vetor de 10 posições
*/
void lerComandoQryP(FILE **qry,char *dir,char *nome,char *aux,Grafo grafo,Cidade cid,Dicionario dic,Vetor registradores);

/*
  -Retorna o estabelecimento mais próximo de um determinado ponto x,y
  -estabelecimentos: Lista com os estabelecimentos
  -x: Ponto x
  -y: Ponto y
  -codt: Código(tipo) do estabelecimento
*/
EstabelecimentoCom encontraEstabelecimentoProx(Lista estabelecimentos, double x, double y, char *codt);

/*
  -Retorna o vértice mais próximo de um determinado ponto x,y
  -vertices: Lista com os vértices
  -x: Ponto x
  -y: Ponto y
*/
Vertice encontraVerticeProx(Lista vertices, double x, double y);

#endif
