#ifndef ARQTM_H
#define ARQTM_H
#include "Dicionario.h"
#include "Hash.h"
#include "Pessoa.h"

/*
  -Menu de comandos do Arquivo .tm
  -tm: Arquivo
  -dic: Dicionario
*/
void menuTm(FILE **tm,Dicionario dic);

/*
  -Leitura e inserção do comando su
  -tm: Arquivo
  -dic: Dicionario
*/
void insereComandoSu(FILE **tm,Dicionario dic);

/*
  -Leitura e inserção do comando um
  -tm: Arquivo
  -dic: Dicionario
*/
void insereComandoUm(FILE **tm,Dicionario dic);


#endif
