#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArqTm.h"

void menuTm(FILE **tm,Dicionario dic){
  char *comando;

  comando = (char *)malloc(10*sizeof(char));

  while (!feof(*tm)) {
    fscanf(*tm, "%s",comando);
    if(feof(*tm)){
      break;
    }

    if(strcmp(comando,"su")==0){
      insereComandoSu(tm,dic);
    }
    else if(strcmp(comando,"um")==0){
      insereComandoUm(tm,dic);
    }
  }
}

void insereComandoSu(FILE **tm,Dicionario dic){
  Hash SUnumcelXpessoa, pessoaCpf;
  Pessoa pessoa;
  char *pCpf, *pNumcel, *cpf, *numcel;

  pCpf = (char *) malloc(1000*sizeof(char));
  pNumcel = (char *) malloc(1000*sizeof(char));

  fscanf(*tm, " %s %s ", pCpf, pNumcel);

  cpf = (char *) malloc((strlen(pCpf)+1)*sizeof(char));
  strcpy(cpf, pCpf);

  numcel = (char *) malloc((strlen(pNumcel)+1)*sizeof(char));
  strcpy(numcel, pNumcel);

  SUnumcelXpessoa = getHashDicionario(dic, "SUnumcelXpessoa");
  pessoaCpf = getHashDicionario(dic, "pessoaCpf");

  pessoa = getRegInfo(pessoaCpf, cpf);

  if(pessoa != NULL){
    setPessoaNumTel(pessoa,numcel);
    setPessoaOp(pessoa,"SercomtUEL");
    insertRegInfo(SUnumcelXpessoa, pessoa, numcel);
  }

  free(pCpf);
  free(pNumcel);
  free(cpf);
  free(numcel);
}

void insereComandoUm(FILE **tm,Dicionario dic){
  Hash UMnumcelXpessoa, pessoaCpf;
  Pessoa pessoa;
  char *pCpf, *pNumcel, *cpf, *numcel;

  pCpf = (char *) malloc(1000*sizeof(char));
  pNumcel = (char *) malloc(1000*sizeof(char));

  fscanf(*tm, " %s %s ", pCpf, pNumcel);

  cpf = (char *) malloc((strlen(pCpf)+1)*sizeof(char));
  strcpy(cpf, pCpf);

  numcel = (char *) malloc((strlen(pNumcel)+1)*sizeof(char));
  strcpy(numcel, pNumcel);

  UMnumcelXpessoa = getHashDicionario(dic, "UMnumcelXpessoa");
  pessoaCpf = getHashDicionario(dic, "pessoaCpf");

  pessoa = getRegInfo(pessoaCpf, cpf);
  setPessoaNumTel(pessoa,numcel);
  setPessoaOp(pessoa,"UELMobile");
  insertRegInfo(UMnumcelXpessoa, pessoa, numcel);

  free(pCpf);
  free(pNumcel);
  free(cpf);
  free(numcel);
}
