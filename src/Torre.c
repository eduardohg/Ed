#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "Torre.h"

struct reg{
  char* id;
  double x,y,raio;
  char* corp;
  char* corb;
  char *operadora;
  Lista *celulares;
};

typedef struct reg torre;

Torre criarTorre(char* id,double x,double y,char* corp,char* corb){
  int tam=0;

  torre *novaTorre;
  novaTorre = (torre *)malloc(sizeof(torre));
  tam = strlen(id);
  novaTorre->id = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novaTorre->id,id);
  novaTorre->x = x;
  novaTorre->y = y;
  novaTorre->raio = 0;
  tam = strlen(corp);

  novaTorre->corp = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novaTorre->corp,corp);
  tam = strlen(corb);
  novaTorre->corb = (char *)malloc((tam+1)*sizeof(char));
  strcpy(novaTorre->corb,corb);
  novaTorre->operadora = NULL;
  novaTorre->celulares = createList();

  return novaTorre;
}

void setRaioTorre(Torre t,double r){
  torre *novaTorre;
  novaTorre = (torre*)t;
  novaTorre->raio = r;
}

void setOperadoraTorre(Torre t,char *op){
  torre *novaTorre;
  novaTorre = (torre *)t;
  novaTorre->operadora = (char *)malloc((strlen(op)+1)*sizeof(char));
  strcpy(novaTorre->operadora,op);
}

char* getTorreId(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;

  return novaTorre->id;
}

double getTorreX(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;

  return novaTorre->x;
}

double getTorreY(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;

  return novaTorre->y;
}

double getTorreRaio(Torre t){
  torre *novaTorre;
  novaTorre = (torre*)t;

  return novaTorre->raio;
}

char* getTorreCorP(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;

  return novaTorre->corp;
}

char* getTorreCorB(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;

  return novaTorre->corb;
}

char* getTorreOp(Torre t){
  torre *novaTorre;
  novaTorre = (torre*)t;

  return novaTorre->operadora;
}

void insertCelTorre(Torre t,char *tel){
  torre *novaTorre;
  novaTorre = (torre*)t;
  insert(novaTorre->celulares,(void*)tel);
}

Lista getListaCelTorre(Torre t){
  torre *novaTorre;
  novaTorre = (torre*)t;
  return novaTorre->celulares;
}

int comparaTorre(Torre t1,Torre t2){
  torre *novaTorre1;
  torre *novaTorre2;

  novaTorre1 = (torre*)t1;
  novaTorre2 = (torre*)t2;

  if(novaTorre1->y < novaTorre2->y){
    return -1;
  }
  else if(novaTorre1->y > novaTorre2->y){
    return 1;
  }
  else
    return 0;
}

void escreveTorre(FILE **arq,Torre t){
  torre *novaTorre;

  novaTorre = (torre*)t;
  fprintf(*arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" stroke=\"%s\"/>\n",novaTorre->x,novaTorre->y,novaTorre->corp,novaTorre->corb);
  fprintf(*arq, "<text text-anchor=\"middle\" x=\"%lf\" y=\"%lf\" font-size=\"5\">T</text>\n",novaTorre->x,novaTorre->y);

}

void escreveTorreRaio(FILE **arq,Torre t){
  torre *novaTorre;

  novaTorre = (torre*)t;
  fprintf(*arq, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" opacity=\"0.25\" stroke=\"%s\"/>\n",novaTorre->x,novaTorre->y,novaTorre->raio,"hotpink","magenta");

}

int orientacaoTorre(Torre t1,Torre t2,Torre t3){
  double x1,y1,x2,y2,x3,y3,result;
  torre *novaTorre1,*novaTorre2,*novaTorre3;

  novaTorre1 = (torre*)t1;
  novaTorre2 = (torre*)t2;
  novaTorre3 = (torre*)t3;
  x1 = novaTorre1->x;
  x2 = novaTorre2->x;
  x3 = novaTorre3->x;
  y1 = novaTorre1->y;
  y2 = novaTorre2->y;
  y3 = novaTorre3->y;

  result = (y2-y1)*(x3-x2)-(x2-x1)*(y3-y2);

  /*Horário*/
  if(result > 0)
    return 1;
  /*Anti-horário*/
  else if(result < 0)
    return -1;
  /*Colinear*/
  else
    return 0;

}

double coordPolarTorre(Torre t1,Torre t2){
  double x1,x2,y1,y2;
  torre *novaTorre1,*novaTorre2;
  novaTorre1 = (torre*)t1;
  novaTorre2 = (torre*)t2;

  x1 = novaTorre1->x;
  x2 = novaTorre2->x;
  y1 = novaTorre1->y;
  y2 = novaTorre2->y;

  return atan2((y2-y1),(x2-x1));
}

void liberaTorre(Torre t){
  torre *novaTorre;
  novaTorre = (torre*) t;
  free(novaTorre->id);
  free(novaTorre->corp);
  free(novaTorre->corb);
  free(novaTorre);
}
