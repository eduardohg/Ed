#ifndef ENVOLTORIOCONVEXO_H
#define ENVOLTORIOCONVEXO_H
#include "Vetor.h"
#include "Lista.h"
#include "Pilha.h"
#include "Quicksort.h"

/*
  -calculaCoordenada é uma função genérica que calcula a coordenada polar de dois void* e retorna o angulo
*/
typedef double (* calculaCoordenada)(void*,void*);

/*
  -Função que calcula a orientacao de três pontos, e retorna um inteiro representando o sentido horário, anti-horario ou colinear
*/
typedef int (*orientacao)(void*,void*,void*);


/*
  -Calcula o primeiro passo antes do convexHull(coordenadas polares,etc)
  -vet: vetor que será utilizado nos procedimentos
  -comparaY: Função que compara o Y de varios equipamentos urbanos
  -comparaPolar: Função que compara a coordenada polar de equipamentos urbanos
  -comparaAng: Função que compara o angulo de equipamentos urbanos
*/

Vetor PrimeiroPasso(Vetor vet,compara comparaY,calculaCoordenada comparaPolar,compara comparaAng);

/*
  -Calcula a Envoltoria convexa e retorna uma pilha com o conjunto de pontos
  -vet: Vetor que é utilizado
  -orientation: Orientação dos equipamentos(horario,anti-horario,colinear)
  -finalHeap: Pilha final com os elementos do convexHull
  -restHeap: Pilha de resto com os elementos de fora do convexHull
*/
Pilha calculaEnvoltoria(Vetor vet,orientacao orientaton,Pilha finalP,Pilha resto);

/*
  -Função que calcula a coordenada polar de um addElemento
  -calc: Função que retorna o angulo de cada equipamento
*/
Vetor calculaCoordPolar(Vetor vet,calculaCoordenada calc);



#endif
