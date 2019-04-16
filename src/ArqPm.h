#ifndef ARQPM_H
#define ARQPM_H
#include "Dicionario.h"
#include "Hash.h"
#include "Pessoa.h"
#include "Quadra.h"

/*
  -Menu de comandos do Arquivo .pm
  -pm: Arquivo
  -dic: Dicionario
*/
void menuPm(FILE **pm, Dicionario dic);

/*
  -Leitura e inserção do comando p
  -pm: Arquivo
  -dic: Dicionario
*/
void insereComandoP(FILE **pm,Dicionario dic);

/*
  -Leitura e inserção do comando m
  -pm: Arquivo
  -dic: Dicionario
*/
void insereComandoM(FILE **pm,Dicionario dic);


#endif
