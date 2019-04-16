#ifndef PROCEDIMENTOS_H
#define PROCEDIMENTOS_H
#include "Dicionario.h"
#include "QuadTree.h"
#include "Pessoa.h"
#include "Quadra.h"
#include "Hash.h"
#include "Cidade.h"
#include "Hidrante.h"
#include "Torre.h"
#include "Semaforo.h"
#include "Operacoes.h"
#include "Lista.h"
#include  "EstabelecimentoComercial.h"

typedef char* (* getIdEq)(void*);

typedef void* (*getTree)(void*);

/*
  -Gera o dicionário, criando todas as hash e inserindo ao dicionário
*/
Dicionario generateDictionary();

/*
  -Insere todas as quadras da cidade na hash cepXquadra
*/
void insereQuadrasHash(Dicionario dic,Cidade cid);

/*
  -Função recursiva que insere as quadras na hash cepXquadra
  -arv: Arvore de quadras
  -nohArv: Nó da árvore
  -cepXquadra: Hash que está sendo utilizada para inserção
*/
Hash QuadrasParaHash(Tree arv,PosicNo nohArv,Hash cepXquadra);

/*
  -Processa o comando con do arquivo qry
  -dic: Dicionario
  -numcel: número dado
  -cep: cep dado
  -face: face dada
  -num: numero dado
  -cid: Cidade
  -txt: Arquivo que é utilizado para a escrita
*/
double processaCon(Dicionario dic,char **numcel,char **cep,char face,int num,Cidade cid,FILE **txt);

/*
  -Processa o comando m do arquivo qry (t5)
  -dic: Dicionario
  -cep: cep dado
  -cid: Cidade
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoM(Dicionario dic,char **cep,Cidade cid,FILE **txt);

/*
  -Processa o comando dm do arquivo qry(t5)
  -cpf: Cpf dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoDm(char **cpf,Dicionario dic,FILE **txt);

/*
  -Processa o comando de do arquivo qry(t5)
  -cnpj: Cnpj dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoDe(char **cnpj,Dicionario dic,FILE **txt);

/*
  -Processa o comando lk do arquivo qry(t5)
  -id: Id dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoLk(char **id,Dicionario dic,Cidade cid,FILE **txt);

/*
  -Processa o comando rb do arquivo qry(t5)
  -numcel: Número de telefone dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoRb(char **numcel,Dicionario dic,FILE **txt);

/*
  -Processa o comando ecq? do arquivo qry(t5)
  -cep: Cep dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoEcq(char **cep,Dicionario dic,FILE **txt);

/*
  -Processa o comando dc? do arquivo qry(t5)
  -numtel: Numero de telefone dado
  -dic: Dicionario
  -txt: Arquivo que é utilizado para a escrita
*/
void processaComandoDc(char **numtel,Dicionario dic,FILE **txt);

/*
  -Calcula os pontos x,y com relação a face e o número e retorna ambos
  -x: Ponto a ser calculado e retornado
  -y: Pontoa a ser calculado e retornado
  -face: Face que é utilizada para o cálculo dos pontos
  -num: Número que é utilizado para o cálculo dos pontos
*/
void calculaPontosXY(double *x,double *y,char face,int num);

/*
  -Retorna a distância do comando con
  -dic: Dicionario
  -x: Ponto x da quadra
  -y: Ponto y da quadra
  -cid: Cidade genérica
  -op: Operadora
  -numcel: número dado
*/
double retornaDist(Dicionario dic,double x,double y,Cidade cid,char *op,char **numcel);

/*
  -Retorna a torre de menor distância
  -list: Lista de torres
  -x: Ponto x da quadra
  -y: Ponto y da quadra
  -menor: menor distância
  -op: Operadora
*/
Torre menorDistTorre(Lista list,double x,double y,double *menor,char *op);

/*
  -Retorna a Quadra de id dado
  -cid: Cidade genérica
  -id: id dado para obter a quadra
*/
Quadra retornaEquipQuadra(Cidade cid,char *id);

/*
  -Retorna o Semaforo de id dado
  -cid: Cidade genérica
  -id: id dado para obter o Semáforo
*/
Semaforo retornaEquipSemaforo(Cidade cid,char *id);

/*
  -Retorna o Hidrante de id dado
  -cid: Cidade genérica
  -id: id dado para obter o Hidrante
*/
Hidrante retornaEquipHidrante(Cidade cid,char *id);

/*
  -Retorna a Torre de id dado
  -cid: Cidade genérica
  -id: id dado para obter a torre
*/
Torre retornaEquipTorre(Cidade cid,char *id);

#endif
