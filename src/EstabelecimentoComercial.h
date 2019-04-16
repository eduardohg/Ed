#ifndef ESTABELECIMENTOCOMERCIAL_H
#define ESTABELECIMENTOCOMERCIAL_H

typedef void* EstabelecimentoCom;

/*
  -Cria estabelecimento comercial
  -tipo: Tipo do estabelecimento
  -cep: Cep do estabelecimento
  -face: Face da quadra em que se encontra o estabelecimento
  -num: Número do estabelecimento
  -cnpj: Cnpj do estabelecimento
  -nome: Nome do estabelecimento
*/
EstabelecimentoCom criarEstabelecimento(char *tipo,char *cep,char face,int num,char *cnpj,char *nome);

/*
  -Seta o ponto x de um estabelecimento
  -e: Estabelecimento Comercial genérico
  -x: ponto a ser adicionado
*/
void setEstabelecimentoX(EstabelecimentoCom e,double x);

/*
  -Seta o ponto y de um estabelecimento
  -e: Estabelecimento Comercial genérico
  -y: ponto a ser adicionado
*/
void setEstabelecimentoY(EstabelecimentoCom e,double y);

/*
  -Retorna o código(tipo) do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
char* getEstabelecimentoCodt(EstabelecimentoCom e);

/*
  -Retorna o nome do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
char* getEstabelecimentoNome(EstabelecimentoCom e);

/*
  -Retorna o cep do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
char* getEstabelecimentoCep(EstabelecimentoCom e);

/*
  -Retorna a face do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
char getEstabelecimentoFace(EstabelecimentoCom e);

/*
  -Retorna o número do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
int getEstabelecimentoNum(EstabelecimentoCom e);

/*
  -Retorna o ponto x do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
double getEstabelecimentoX(EstabelecimentoCom e);

/*
  -Retorna o cnpj do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
char* getEstabelecimentoCnpj(EstabelecimentoCom e);

/*
  -Retorna o ponto y do estabelecimento
  -e: Estabelecimento Comercial genérico
*/
double getEstabelecimentoY(EstabelecimentoCom e);

#endif
