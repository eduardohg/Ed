#include <stdio.h>
#include <stdlib.h>
#include "Cidade.h"
#include "QuadTree.h"

struct reg{
  Tree quadra;
  Tree hidrante;
  Tree semaforo;
  Tree torre;
};

typedef struct reg cidade;

Cidade criaCidade(){
  cidade *cid;

  cid = (cidade *)malloc(sizeof(cidade));
  cid->quadra = createArvore();
  cid->semaforo = createArvore();
  cid->hidrante = createArvore();
  cid->torre = createArvore();

  return (Cidade)cid;
}

int insereQuadra(Cidade c,Quadra q,double x,double y){
  cidade *cid;
  cid = (cidade *)c;

  insertTree(cid->quadra,q,x,y);

  return 1;
}

int insereSemaforo(Cidade c,Semaforo s,double x,double y){
  cidade *cid;

  cid = (cidade *)c;

  insertTree(cid->semaforo,s,x,y);

  return 1;
}

int insereHidrante(Cidade c,Hidrante h,double x,double y){
  cidade *cid;

  cid = (cidade *)c;
  insertTree(cid->hidrante,h,x,y);

  return 1;
}

int insereTorre(Cidade c,Torre t,double x,double y){
  cidade *cid;


  cid = (cidade *)c;
  insertTree(cid->torre,t,x,y);

  return 1;
}

Quadra getQuadra(Cidade c){
  cidade *cid;
  cid = (cidade *)c;

  return cid->quadra;
}

Hidrante getHidrante(Cidade c){
  cidade *cid;

  cid = (cidade *)c;

  return cid->hidrante;
}

Semaforo getSemaforo(Cidade c){
  cidade *cid;

  cid = (cidade *)c;

  return cid->semaforo;
}

Torre getTorre(Cidade c){
  cidade *cid;

  cid = (cidade *)c;

  return cid->torre;
}

int removeEquip(Cidade c,PosicNo *nohArv,Liberar liberarEquip,Tree arv){

  if(leafNe(arv,nohArv) == 1){
    removeEquip(c,getNe(arv,nohArv),liberarEquip,arv);
  }

  if(leafNw(arv,nohArv) == 1){
    removeEquip(c,getNw(arv,nohArv),liberarEquip,arv);
  }

  if(leafSe(arv,nohArv) == 1){
    removeEquip(c,getSe(arv,nohArv),liberarEquip,arv);
  }

  if(leafSw(arv,nohArv) == 1){
    removeEquip(c,getSw(arv,nohArv),liberarEquip,arv);
  }

  liberarEquip(getElement(arv,nohArv));
  removeTree(arv,nohArv);

  return 1;
}

void apocalypse(Cidade c){
	cidade *city;
	PosicNo p;

	city = (cidade *) c;

	p = getFirstElementTree(city->quadra);
  if(p != NULL)
    removeEquip(city,p,liberaQuadra,city->quadra);

	p = getFirstElementTree(city->hidrante);
  if(p != NULL)
    removeEquip(city,p,liberaHidrante,city->hidrante);

	p = getFirstElementTree(city->semaforo);
  if(p != NULL)
    removeEquip(city,p,liberaSemaforo,city->semaforo);

	p = getFirstElementTree(city->torre);
  if(p != NULL)
    removeEquip(city,p,liberaTorre,city->torre);

	free(city->quadra);
	free(city->hidrante);
	free(city->semaforo);
	free(city->torre);
}


int processarTree(Cidade c,Tree arv,PosicNo nohArv,Escrever escreverEquip,FILE **arq){
  ItemNode info;

  if(nohArv == NULL){
    return 0;
  }
  if(leafNe(arv,nohArv) == 1){
    processarTree(c,arv,getNe(arv,nohArv),escreverEquip,arq);
  }

  if(leafNw(arv,nohArv) == 1){
    processarTree(c,arv,getNw(arv,nohArv),escreverEquip,arq);
  }

  if(leafSe(arv,nohArv) == 1){
    processarTree(c,arv,getSe(arv,nohArv),escreverEquip,arq);
  }

  if(leafSw(arv,nohArv) == 1){
    processarTree(c,arv,getSw(arv,nohArv),escreverEquip,arq);
  }
  info = getElement(arv,nohArv);
  escreverEquip(arq,info);
}
