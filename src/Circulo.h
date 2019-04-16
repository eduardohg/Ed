#ifndef CIRCULO_H
#define CIRCULO_H
#include <math.h>

/*
  Circulo é um tipo que possibilita a criação e manipulação de circulos.
*/
typedef void* Circulo;

/*
  -Cria um Circulo com id,raio,ponto (x,y),cor e retorna um Ponteiro para o Circulo
*/
Circulo criarCirculo(int id,double r,double x,double y,char *cor);

/*
  -Retorna o id do circulo
  -cir:Circulo genérico
*/
int getCirculoId(Circulo cir);

/*
  -Retorna o ponto x do circulo
  -cir:Circulo genérico
*/
double getCirculoX(Circulo cir);

/*
  -Retorna o ponto y do circulo
  -cir:Circulo genérico
*/
double getCirculoY(Circulo cir);

/*
  -Retorna o raio do circulo
  -cir:Circulo genérico
*/
double getCirculoR(Circulo cir);

/*
  -Retorna a cor do circulo
  -cir:Circulo genérico
*/
char* getCirculoCor(Circulo cir);

/*
  -Desaloca a memória utilizada por um Circulo
  -cir:Circulo genérico que será desalocado
*/
void liberaCirculo(Circulo cir);

double coordPolarCirculo(Circulo c1,Circulo c2);

int orientacaoCirculo(Circulo h1,Circulo h2,Circulo h3);


#endif
