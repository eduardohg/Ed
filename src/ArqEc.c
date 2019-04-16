#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArqEc.h"

void menuEc(FILE **ec,Dicionario dic){
  char comando;

  while (!feof(*ec)) {
    fscanf(*ec, "%c",&comando);
    if(feof(*ec)){
      break;
    }

    if(comando == 'e'){
      insereComandoE(ec,dic);
    }
    else if(comando == 't'){
      inserecomandoT(ec,dic);
    }
  }
}

void insereComandoE(FILE **ec,Dicionario dic){
  EstabelecimentoCom estabelecimento;
  Hash cnpjXcep, estCnpj, cepXquadra;
  Quadra quadra;
  char *cnpj,*nome,*tipo,*cep,face;
  int num;
  double x,y;

  cep = (char *)malloc(200*sizeof(char));
  nome = (char *)malloc(200*sizeof(char));
  cnpj = (char *)malloc(200*sizeof(char));
  tipo = (char *)malloc(200*sizeof(char));

  fscanf(*ec," %s",tipo);
  fscanf(*ec," %s",cep);
  fscanf(*ec," %c",&face);
  fscanf(*ec," %d",&num);
  fscanf(*ec," %s",cnpj);
  fscanf(*ec," %s",nome);

  estabelecimento = criarEstabelecimento(tipo,cep,face,num,cnpj,nome);
  estCnpj = getHashDicionario(dic, "estCnpj");
  insertRegInfo(estCnpj,estabelecimento,cnpj);

  /*
  cnpjXcep = getHashDicionario(dic, "cnpjXcep");
  insertRegInfo(cnpjXcep, cep, cnpj);
  */
  cepXquadra = getHashDicionario(dic, "cepXquadra");
  quadra = getRegInfo(cepXquadra, cep);
  insertEstabQuadra(quadra,estabelecimento);
  x = getQuadraX(quadra);
  y = getQuadraY(quadra);

  if (face == 'N') {
    setEstabelecimentoX(estabelecimento, x);
    setEstabelecimentoY(estabelecimento, y+num);
  }
  else if (face == 'S') {
    setEstabelecimentoX(estabelecimento, x);
    setEstabelecimentoY(estabelecimento, y-num);
  }
  else if (face == 'L') {
    setEstabelecimentoX(estabelecimento, x-num);
    setEstabelecimentoY(estabelecimento, y);
  }
  else if (face == 'O') {
    setEstabelecimentoX(estabelecimento, x+num);
    setEstabelecimentoY(estabelecimento, y);
  }

  free(cnpj);
  free(nome);
  free(tipo);
  free(cep);
}

void inserecomandoT(FILE **ec,Dicionario dic){
  EstabelecimentoCom e;
  Hash comercialXdescricao;
  char *tipo,*desc;

  tipo = (char *)malloc(300*sizeof(char));
  desc = (char *)malloc(500*sizeof(char));
  fscanf(*ec," %s",tipo);
  fscanf(*ec," %s",desc);

  comercialXdescricao = getHashDicionario(dic,"comercialXdescricao");
  insertRegInfo(comercialXdescricao,desc,tipo);

  free(tipo);
  free(desc);
}
