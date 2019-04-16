#ifndef CALCULOS_H
#define CALCULOS_H
#include "Lista.h"
#include "Vetor.h"
#include "Torre.h"
#include "Circulo.h"
#include "Cidade.h"
#include "Quadra.h"
#include "Hidrante.h"
#include "Semaforo.h"

double calculaAreaPoligno(Vetor torre);

void calcularPontosCirculo(Vetor vet,double pX,double pY,double raio,int n);

#endif
