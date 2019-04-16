#ifndef ARQVIA_H
#define ARQVIA_H
#include "Grafo.h"

/*
  -Menu de comandos do Arquivo .via
  -via: Arquivo
  -grafo: Grafo
  -boolean: char com 't' para true e permissão para ler parâmetros ou 'f' para apenas contar qnt de vértices
*/
int menuVia(FILE **via, Grafo grafo, char boolean);

/*
  -Leitura e inserção do comando v
  -via: Arquivo
  -grafo: Grafo
  -boolean: char com 't' para true e permissão para ler parâmetros ou 'f' para apenas contar qnt de vértices
*/
void comandoV(FILE **via, Grafo grafo, char boolean);

/*
  -Leitura e inserção do comando e
  -via: Arquivo
  -grafo: Grafo
  -boolean: char com 't' para true e permissão para ler parâmetros ou 'f' para apenas contar qnt de vértices
*/
void comandoE(FILE **via, Grafo grafo, char boolean);


#endif
