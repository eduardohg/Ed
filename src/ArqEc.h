#ifndef ARQEC_H
#define ARQEC_H
#include "EstabelecimentoComercial.h"
#include "Dicionario.h"
#include "Hash.h"
#include "Quadra.h"

/*
  -Menu de comandos do Arquivo .ec
  -ec: Arquivo
  -dic: Dicionario
*/
void menuEc(FILE **ec,Dicionario dic);

/*
  -Leitura e inserção do comando e
  -ec: Arquivo
  -dic: Dicionario
*/
void insereComandoE(FILE **ec,Dicionario dic);

/*
  -Leitura e inserção do comando T
  -ec: Arquivo
  dic: Dicionario
*/
void inserecomandoT(FILE **ec,Dicionario dic);

#endif
