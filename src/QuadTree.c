#include <stdio.h>
#include <stdlib.h>
#include "QuadTree.h"

typedef struct no{
  ItemNode *coisa;
  double x,y;
  struct no *Ne;/*Nordeste*/
  struct no *Nw;/*Noroeste*/
  struct no *Se;/*Sudeste*/
  struct no *Sw;/*Sudoeste*/
}noh;

typedef struct _arvore{
  struct no *inicio;
  int tam;
  int comp;
}arvore;

Tree createArvore(){
  arvore *arv;
  arv = (arvore *)malloc(sizeof(arvore));
  arv->inicio = NULL;
  arv->tam = 0;
  arv->comp=0;

  return (Tree)arv;
}

int sizeTree(Tree arv){
  arvore *a;
  a = (arvore*)arv;
  return a->tam;
}

void insertTree(Tree arv,ItemNode obj,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;
  PosicNo *p;

  a = (arvore*)arv;
  aux = a->inicio;

  if(a->inicio != NULL)
    insertTreeAux(arv,obj,aux,x,y);
  else
    p = insertTreeInicio(arv,obj,x,y);
}

int insertTreeAux(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;

  aux = (noh*)nohArv;
  a = (arvore*)arv;

  if(aux == NULL)
    return 1;
  else if(x <= aux->x && y >= aux->y){
    a->comp++;
    insertTreeNe(a,obj,aux,x,y);
    return 0;
  }
  else if(x <= aux->x && y <= aux->y){
    a->comp++;
    insertTreeSe(a,obj,aux,x,y);
    return 0;
  }
  else if(x >= aux->x && y >= aux->y){
    a->comp++;
    insertTreeNw(a,obj,aux,x,y);
    return 0;
  }
  else if(x >= aux->x && y <= aux->y){
    a->comp++;
    insertTreeSw(a,obj,aux,x,y);
    return 0;
  }
}

int insertTreeNe(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Ne == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Ne = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Ne,x,y);
}

int insertTreeSe(Tree arv,ItemNode obj,PosicNo nohArv,double x,double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Se == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Se = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Se,x,y);
}

int insertTreeNw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Nw == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Nw = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Nw,x,y);
}

int insertTreeSw(Tree arv,ItemNode obj,PosicNo nohArv,double x, double y){
  arvore *a;
  noh *n;
  noh *aux;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(n->Sw == NULL){
    aux = (noh *)malloc(sizeof(noh));
    aux->coisa = obj;
    aux->x = x;
    aux->y = y;
    aux->Ne = NULL;
    aux->Nw = NULL;
    aux->Se = NULL;
    aux->Sw = NULL;
    n->Sw = aux;
    a->tam++;
    return 1;
  }
  else
    insertTreeAux(arv,obj,n->Sw,x,y);
}
PosicNo insertTreeInicio(Tree arv,ItemNode obj,double x, double y){
  arvore *a;
  noh *n;

  a = (arvore *)arv;
  n = (noh *)malloc(sizeof(noh));
  n->coisa = obj;
  n->Ne = NULL;
  n->Nw = NULL;
  n->Se = NULL;
  n->Sw = NULL;
  n->x = x;
  n->y = y;

  a->inicio = n;
  a->tam++;
  return (PosicNo)n;
}

ItemNode getElement(Tree arv,PosicNo nohArv){
  noh *n;
  ItemNode *forma;
  PosicNo *pos;

  pos = nohArv;
  n = (noh*)pos;
  if(n == NULL){
    printf("null getElement\n");
  }
  forma = n->coisa;
  return forma;
}

PosicNo getFirstElementTree(Tree arv){
  arvore *a;
  PosicNo *pos;
  a = (arvore*)arv;

  if(a->inicio != NULL){
    return (PosicNo*)a->inicio;
  }
  pos = NULL;
  return pos;
}

double getXQuadTree(Tree arv,PosicNo nohArv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(a->inicio == NULL){
    return 0;
  }
  else
    return n->x;
}

double getYQuadTree(Tree arv,PosicNo nohArv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(a->inicio == NULL){
    return 0;
  }
  else
    return n->y;
}

int getQuadrante(Tree arv,PosicNo nohArv,PosicNo nohArv2){
  arvore *a;
  noh *n,*n2;
  n = (noh*)nohArv;
  n2 = (noh*)nohArv2;

  if(n->Ne == n2)
    return 1;
  else if(n->Nw == n2)
    return 2;
  else if(n->Se == n2)
    return 3;
  else if(n->Sw == n2)
    return 4;
}

int removeTree(Tree arv,PosicNo nohArv){
  int q;
  arvore *a;
  noh *p=NULL,*n,*aux;

  a = (arvore*)arv;
  aux = a->inicio;
  n = (noh*)nohArv;

  if(aux != n){
    p = procurarPai(arv,aux,nohArv);
    q = getQuadrante(arv,p,n);
    if(q == 1)
      p->Ne = NULL;
    else if(q == 2)
      p->Nw = NULL;
    else if(q == 3)
      p->Se = NULL;
    else
      p->Sw = NULL;
  }
  else{
    a->inicio = NULL;
    a->tam--;
  }


  reinsere(a,n,nohArv);
  n = NULL;
  return 1;
}

PosicNo procurarPai(Tree arv,PosicNo inicio,PosicNo nohArv){
  noh *aux=NULL;

  if(leafNe(arv,inicio) == 1){
    if(getNe(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getNe(arv,inicio),nohArv);
  }

  if(leafNw(arv,inicio) == 1){
    if(getNw(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getNw(arv,inicio),nohArv);
  }

  if(leafSe(arv,inicio) == 1){
    if(getSe(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getSe(arv,inicio),nohArv);
  }

  if(leafSw(arv,inicio) == 1){
    if(getSw(arv,inicio) == nohArv){
      aux = inicio;
      return aux;
    }
    if(aux == NULL)
      aux = procurarPai(arv,getSw(arv,inicio),nohArv);
  }
  return aux;

}

void reinsere(Tree arv,PosicNo nohArv,PosicNo nohArv2){
  arvore *a;
  noh *n;
  ItemNode obj;
  double x,y;

  a = (arvore*)arv;
  n = (noh*)nohArv;
  if(leafNe(arv,nohArv) == 1){
    reinsere(arv,n->Ne,nohArv2);
  }

  if(leafNw(arv,nohArv) == 1){
    reinsere(arv,n->Nw,nohArv2);
  }

  if(leafSe(arv,nohArv) == 1){
    reinsere(arv,n->Se,nohArv2);
  }

  if(leafSw(arv,nohArv) == 1){
    reinsere(arv,n->Sw,nohArv2);
  }

  if(n != (noh*)nohArv2){
    obj = n->coisa;
    x = n->x;
    y = n->y;
    insertTree(arv,obj,x,y);
  }
  free(n);
  a->tam--;
}

PosicNo getNe(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo *pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Ne == NULL){
    pos = NULL;
  }
  else{
    n = n->Ne;
    pos = (PosicNo *)n;
  }
  return pos;
}

PosicNo getNw(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo *pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Nw == NULL){
    pos = NULL;
  }
  else{
    n = n->Nw;
    pos = (PosicNo *)n;
  }
  return pos;
}

PosicNo getSe(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo *pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Se == NULL){
    pos = NULL;
  }
  else{
    n = n->Se;
    pos = (PosicNo *)n;
  }
  return pos;
}

PosicNo getSw(Tree arv,PosicNo nohArv){
  noh *n;
  PosicNo *pos;
  pos = nohArv;

  n = (noh*)pos;
  if(n->Sw == NULL){
    pos = NULL;
  }
  else{
    n = n->Sw;
    pos = (PosicNo *)n;
  }
  return pos;
}

int isLeaf(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n->Ne == NULL && n->Nw == NULL && n->Se == NULL && n->Sw){
    return 1;
  }
  else{
    return 0;
  }
}

int leafNe(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){
    return 0;
  }
  else if(n->Ne == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leafNw(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;

  if(n == NULL){
    return 0;
  }
  else if(n->Nw == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leafSe(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;

  if(n == NULL){
    return 0;
  }
  else if(n->Se == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int leafSw(Tree arv,PosicNo nohArv){
  noh *n;

  n = (noh*)nohArv;
  if(n == NULL){
    return 0;
  }
  else if(n->Sw == NULL){
    return 0;
  }
  else{
    return 1;
  }
}

int getComp(Tree arv){
  arvore *a;
  noh *n;

  a = (arvore*)arv;
  return a->comp;
}

Lista treeParaLista(Tree arv,PosicNo nohArv,Lista subArv){
  noh *n;
  n = (noh*)nohArv;

  if(leafNe(arv,n) == 1){
    treeParaLista(arv,n->Ne,subArv);
  }

  if(leafNw(arv,n) == 1){
    treeParaLista(arv,n->Nw,subArv);
  }

  if(leafSe(arv,n) == 1){
    treeParaLista(arv,n->Se,subArv);
  }

  if(leafSw(arv,n) == 1){
    treeParaLista(arv,n->Sw,subArv);
  }
  insert(subArv,n);
  return (Lista*)subArv;

}

void desmatamento(Tree arv){
  arvore *a;
  noh *n;
  a = (arvore*)arv;
  n = a->inicio;
  freeTree(a,n);
}

void freeTree(Tree arv,PosicNo nohArv){
  noh *n;
  n = (noh*)nohArv;

  if(leafNe(arv,n) == 1){
    freeTree(arv,n->Ne);
  }

  if(leafNw(arv,n) == 1){
    freeTree(arv,n->Nw);
  }

  if(leafSe(arv,n) == 1){
    freeTree(arv,n->Se);
  }

  if(leafSw(arv,n) == 1){
    freeTree(arv,n->Sw);
  }
  free(n);
  n = NULL;
}
