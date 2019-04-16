#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Calculos.h"
#include "Circulo.h"
#include "Torre.h"

#define PI 3.141592653589793

double calculaAreaPoligno(Vetor torre){
  int i;
  double soma=0,soma2=0,result=0;
  for(i=0;i<getTamanhoVetor(torre);i++){

    if((i+1) != getTamanhoVetor(torre)){
      soma += (getCirculoX(getElemento(torre,i))*getCirculoY(getElemento(torre,i+1)));
    }
    else{
      soma += (getCirculoX(getElemento(torre,i))*getCirculoY(getElemento(torre,0)));
    }
  }
  for(i=0;i<getTamanhoVetor(torre);i++){
    if(i+1 != getTamanhoVetor(torre)){
      soma2 += (getCirculoY(getElemento(torre,i))*getCirculoX(getElemento(torre,i+1)));
    }
    else{
      soma2 += (getCirculoY(getElemento(torre,i))*getCirculoX(getElemento(torre,0)));

    }
  }
  result = ((soma-soma2)/2);
  if(result < 0)
    result *=(-1);
  return result;
}

void calcularPontosCirculo(Vetor vet,double pX,double pY,double raio,int n){
	Circulo circulo;
	double x=0, y=0, aux=0;
	int i, size;

	size = getTamanhoVetor(vet);
	aux = 2*PI/n;
	for (i=0; i<n; i++) {
		x = cos(aux)*raio + pX;
		y = sin(aux)*raio + pY;
  	circulo = criarCirculo(i*10, 0.2, x, y, "red");
		addElemento(vet,size,circulo,x,y);
		size++;
		aux += 2*PI/n;
	}
}

void escrevePoligono(FILE **svg,Vetor vet,Cidade cid,Lista l){
  Posic p;
  int i;

  fprintf(*svg, "<svg>\n");
  processarTree(cid,getQuadra(cid),getFirstElementTree(getQuadra(cid)),escreveQuadra,svg);
  processarTree(cid,getHidrante(cid),getFirstElementTree(getHidrante(cid)),escreveHidrante,svg);
  processarTree(cid,getTorre(cid),getFirstElementTree(getTorre(cid)),escreveTorre,svg);
  processarTree(cid,getSemaforo(cid),getFirstElementTree(getSemaforo(cid)),escreveSemaforo,svg);

  p = getFirst(l);
  for(i=0;i<length(l);i++){
    escreveTorreRaio(svg,get(l,p));
    p = getNext(l,p);
  }

  fprintf(*svg, "<polygon opacity=\"0.75\" points=\" ");
  for(i=0;i<getTamanhoVetor(vet);i++){
    fprintf(*svg, "%lf,%lf ",getCirculoX(getElemento(vet,i)),getCirculoY(getElemento(vet,i)));
  }
  fprintf(*svg, "\" style=\"fill:none; stroke:%s; stroke-width:3; \" />\n","black");
  fprintf(*svg, "</svg>\n");
}
