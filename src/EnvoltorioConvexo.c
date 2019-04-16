#include <stdio.h>
#include <stdlib.h>
#include "EnvoltorioConvexo.h"



Vetor PrimeiroPasso(Vetor vet,compara comparaY,calculaCoordenada comparaPolar,compara comparaAng){
  int tamanho = getTamanhoVetor(vet);
  quicksort(vet,0,tamanho-1,comparaY);

  vet = calculaCoordPolar(vet,comparaPolar);

  quicksort(vet,0,tamanho-1,comparaAng);
  return vet;

}

Pilha calculaEnvoltoria(Vetor vet,orientacao orientation,Pilha finalP,Pilha resto){
  ItemPilha topo, meio, aux;
  int tam, i;

  tam = getTamanhoVetor(vet);

  if (tam > 0) {
    empilhar(finalP, getElemento(vet, 0));
    if (tam > 1) {

      empilhar(finalP, getElemento(vet, 1));

      if (tam >= 3) {
        for (i=2; i<tam; i++) {
          aux = getElemento(vet, i);
          meio = pop(finalP);
          topo = pop(finalP);

          if (orientation(topo, meio, aux) == -1) {
            empilhar(finalP, topo);
            empilhar(finalP, meio);
            empilhar(finalP, aux);
          }
          else {
            empilhar(resto, meio);
            empilhar(finalP, topo);
            empilhar(finalP, aux);

            while(tamanhoPilha(finalP) >= 3) {
              aux = pop(finalP);
              meio = pop(finalP);
              topo = pop(finalP);

              if (orientation(topo, meio, aux) >= 0) {
                empilhar(resto, meio);
                empilhar(finalP, topo);
                empilhar(finalP, aux);
              }
              else {
                empilhar(finalP, topo);
                empilhar(finalP, meio);
                empilhar(finalP, aux);
                break;
              }
            }
          }
        }
      }
    }
  }

  return finalP;
}

Vetor calculaCoordPolar(Vetor vet,calculaCoordenada calc){
  int tam,i;
  void *obj,*aux;
  double ang;
  tam = getTamanhoVetor(vet);
  obj = getElemento(vet,0);
  for(i=0;i<tam;i++){
    aux = getElemento(vet,i);
    ang = calc(obj,aux);
    addAng(vet,i,ang);
  }

  return vet;
}
