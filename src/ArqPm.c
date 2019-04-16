#include <stdio.h>
#include <stdlib.h>
#include "ArqPm.h"

void menuPm(FILE **pm, Dicionario dic) {
  char comando,*sexo;
  char *cpf,*nome,*sobrenome,*nasc;


  while (!feof(*pm)) {
    fscanf(*pm, "%c", &comando);
    if(feof(*pm)){
      break;
    }
    if(comando == 'm'){
      insereComandoM(pm,dic);
    }
    else if(comando == 'p'){
      insereComandoP(pm,dic);
    }
  }
}

void insereComandoP(FILE **pm,Dicionario dic){
  Pessoa pessoa;
  Hash pessoaCpf;
  char *cpf,*nome,*sobrenome,*nasc,sexo;
  cpf = (char *)malloc(200*sizeof(char));
  nome = (char *)malloc(200*sizeof(char));
  sobrenome = (char *)malloc(200*sizeof(char));
  nasc = (char *)malloc(200*sizeof(char));

  fscanf(*pm," %s",cpf);
  fscanf(*pm," %s",nome);
  fscanf(*pm," %s",sobrenome);
  fscanf(*pm," %c",&sexo);
  fscanf(*pm," %s",nasc);
  pessoa = criarPessoa(cpf,nome,sobrenome,sexo,nasc);
  pessoaCpf = getHashDicionario(dic, "pessoaCpf");
  insertRegInfo(pessoaCpf,pessoa,cpf);

  free(cpf);
  free(nome);
  free(sobrenome);
  free(nasc);
}

void insereComandoM(FILE **pm,Dicionario dic){
  Hash cpfXcep, pessoaCpf, cepXquadra;
  Pessoa pessoa;
  Quadra quadra;
  char *cpf,*cep,face,*compl;
  int num;
  double x,y;

  cpf = (char *)malloc(200*sizeof(char));
  cep = (char *)malloc(200*sizeof(char));
  compl = (char *)malloc(200*sizeof(char));

  fscanf(*pm," %s",cpf);
  fscanf(*pm," %s",cep);
  fscanf(*pm," %c",&face);
  fscanf(*pm," %d",&num);
  fscanf(*pm," %s",compl);

  pessoaCpf = getHashDicionario(dic, "pessoaCpf");
  pessoa = getRegInfo(pessoaCpf, cpf);

  if(pessoa != NULL){
    cpfXcep = getHashDicionario(dic, "cpfXcep");
    insertRegInfo(cpfXcep, cep, cpf);

    setMorador(pessoa,cep,face,compl,num);

    cepXquadra = getHashDicionario(dic, "cepXquadra");
    quadra = getRegInfo(cepXquadra, cep);
    insertMoradorQuadra(quadra, pessoa);

    x = getQuadraX(quadra);
    y = getQuadraY(quadra);
    if (face == 'N') {
      setPessoaX(pessoa, x);
      setPessoaY(pessoa, y+num);
    }
    else if (face == 'S') {
      setPessoaX(pessoa, x);
      setPessoaY(pessoa, y-num);
    }
    else if (face == 'L') {
      setPessoaX(pessoa, x-num);
      setPessoaY(pessoa, y);
    }
    else if (face == 'O') {
      setPessoaX(pessoa, x+num);
      setPessoaY(pessoa, y);
    }

  }
  free(cpf);
  free(cep);
  free(compl);


}
