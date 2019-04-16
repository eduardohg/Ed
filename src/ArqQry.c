#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "ArqQry.h"
#include "Operacoes.h"
#include "Calculos.h"
#include "Circulo.h"
#include "EnvoltorioConvexo.h"

void menuQry(Cidade *cid,Dicionario dic,Lista *circ,Lista *retang,Lista *sobrepos,FILE **arq,FILE **txt,FILE **qry,FILE **resum,char **str,char **testes,char **aux,char **pasta,char **dir,char **nome,char **cor,int *k,int *var,int ins,Grafo grafo){
  PosicNo p;
  Vetor registradores;
  int del=0,cpd=0,lg=0;
  char *fig,*cep,*string,caracter=' ';

  fig = (char *)malloc(10*sizeof(char));
  cep = (char *)malloc(100*sizeof(char));
  string = (char *)malloc(100*sizeof(char));
  registradores = criaVetor(11);

  while (!feof(*qry)) {

    fscanf(*qry," %s", fig);
    if(feof(*qry)){
      free(*testes);
      break;
    }
    if(strcmp(fig,"dq")==0){
      double x,y,w,h;
      lerds(qry,&x,&y,&w,&h);
      p = getFirstElementTree(getQuadra(cid));
      removedq(cid,p,x,y,w,h,txt,&del,&cpd);
    }
    else if(strcmp(fig,"dh")==0){
      double x,y,w,h;
      lerds(qry,&x,&y,&w,&h);
      p = getFirstElementTree(getQuadra(cid));
      removedh(cid,p,x,y,w,h,txt);

    }
    else if(strcmp(fig,"ds")==0){
      double x,y,w,h;
      lerds(qry,&x,&y,&w,&h);
      p = getFirstElementTree(getSemaforo(cid));
      removeds(cid,p,x,y,w,h,txt);
    }
    else if(strcmp(fig,"dt")==0){
      double x,y,w,h;
      lerds(qry,&x,&y,&w,&h);
      p = getFirstElementTree(getTorre(cid));
      removedt(cid,p,x,y,w,h,txt);
    }
    else if(strcmp(fig,"Dq")==0){
      double x,y,r;
      lerDs(qry,&x,&y,&r);
      p = getFirstElementTree(getQuadra(cid));
      removeDq(cid,p,x,y,r,txt,&del,&cpd);
    }
    else if(strcmp(fig,"Dh")==0){
      double x,y,r;
      lerDs(qry,&x,&y,&r);
      p = getFirstElementTree(getHidrante(cid));
      removeDh(cid,p,x,y,r,txt);
    }
    else if(strcmp(fig,"Ds")==0){
      double x,y,r;
      lerDs(qry,&x,&y,&r);
      p = getFirstElementTree(getSemaforo(cid));
      removeDs(cid,p,x,y,r,txt);
    }
    else if(strcmp(fig,"Dt")==0){
      char *ident;
      int j,tam;
      double x,y,r;
      lerDs(qry,&x,&y,&r);
      p = getFirstElementTree(getTorre(cid));
      removeDt(cid,p,x,y,r,txt);
    }
    else if(strcmp(fig,"crd?")==0){
      fscanf(*qry, "%s",cep);
      p = getFirstElementTree(getQuadra(cid));
      if(p != NULL)
        percorreCidQuadra(cid,txt,&cep,p);
      p = getFirstElementTree(getHidrante(cid));
      if(p != NULL)
        percorreCidHidrante(cid,txt,&cep,p);
      p = getFirstElementTree(getTorre(cid));
      if(p != NULL)
        percorreCidTorre(cid,txt,&cep,p);
      p = getFirstElementTree(getSemaforo(cid));
      if(p != NULL)
        percorreCidSemaforo(cid,txt,&cep,p);
    }
    else if(strcmp(fig,"con")==0){
      lerComandoCon(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"m?")==0){
      lerComandoM(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"dm?")==0){
      lerComandoDm(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"de?")==0){
      lerComandoDe(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"lk?")==0){
      lerComandoLk(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"rb?")==0){
      lerComandoRb(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"dc?")==0){
      lerComandoDc(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"ecq?")==0){
      lerComandoEcq(qry,dic,cid,txt);
    }
    else if(strcmp(fig,"@f?")==0){
      lerComandoQryF(qry,dic,cid,registradores);
    }
    else if(strcmp(fig,"@m?")==0){
      lerComandoQryM(qry,dic,cid,registradores);
    }
    else if(strcmp(fig,"@e?")==0){
      lerComandoQryE(qry,dic,cid,registradores);
    }
    else if(strcmp(fig,"@g?")==0){
      lerComandoQryG(qry,dic,cid,registradores);
    }
    else if(strcmp(fig,"@xy?")==0){
      lerComandoQryXY(qry,registradores);
    }
    else if(strcmp(fig,"@tp?")==0){
      lerComandoQryTp(qry,dic,cid,registradores);
    }
    else if(strcmp(fig,"p?")==0){
      char *name,*saida,*nameqry;
      name = (char *)malloc((strlen(*nome)+1)*sizeof(char));
      saida = (char *)malloc((strlen(*dir)+1)*sizeof(char));
      nameqry = (char *)malloc((strlen(*aux)+1)*sizeof(char));
      strcpy(name,*nome);
      strcpy(saida,*dir);
      strcpy(nameqry,*aux);
      lerComandoQryP(qry,saida,name,nameqry,grafo,cid,dic,registradores);
      /*
      free(name);
      free(saida);
      free(nameqry);
      */
    }
    else if(strcmp(fig,"ac?")==0){
      Lista l1,l2;
      Circulo cc;
      int pts=10,i=0;
      double area=0,x=0,y=0,l=0,a=0;
      Pilha f,r;
      Vetor v;
      PosicNo n;
      Posic p;
      if(!feof(*qry)){
        fscanf(*qry,"%c ",&caracter);
        lg = 1;
      }
      if(caracter == ' '){
        lerComandoAc(qry,&x,&y,&l,&a);
        n = getFirstElementTree(getTorre(cid));
        l1 = createList();
        l2 = createList();
        l1 = converterTreeToList(l1,getTorre(cid),n);
        l2 = buscarPontosPoligono(l1,l2,x,y,l,a);
        pts = length(l2)*pts;
        if(pts != 0){
          v = criaVetor(pts);
          p = getFirst(l2);

          for(i=0;i<length(l2);i++){
            calcularPontosCirculo(v,getTorreX(get(l2,p)),getTorreY(get(l2,p)),getTorreRaio(get(l2,p)),10);
            p = getNext(l2,p);
          }
        }
      }
      else{
        n = getFirstElementTree(getTorre(cid));
        l1 = createList();
        l1 = converterTreeToList(l1,getTorre(cid),n);
        pts = length(l1)*pts;
        if(pts != 0){
          v = criaVetor(pts);
          p = getFirst(l1);
          for(i=0;i<length(l1);i++){
            calcularPontosCirculo(v,getTorreX(get(l1,p)),getTorreY(get(l1,p)),getTorreRaio(get(l1,p)),10);
            p = getNext(l1,p);
          }
        }

      }
      if(pts != 0){
        v = PrimeiroPasso(v,comparaY,coordPolarCirculo,comparaAng);
        f = inicializacao();
        r = inicializacao();
        f = calculaEnvoltoria(v,orientacaoCirculo,f,r);
        v = converterPilhaParaVetor(f,getCirculoX,getCirculoY,pts);

        area = calculaAreaPoligno(v);
        fprintf(*txt, "Area ac?: %lf\n",area);
      }
      else{
        fprintf(*txt, "Região não contém nenhum equipamento\n");
      }


    }
    else if(strcmp(fig,"pc?")==0){
      int pts=10,i=0;
      double area=0,x=0,y=0,l=0,a=0;
      Lista l1,l2;
      Pilha f,r;
      Vetor v;
      PosicNo n;
      Posic p;
      FILE *svg;
      fscanf(*qry, "%s",cep);
      if(!feof(*qry)){
        fscanf(*qry,"%c ",&caracter);
        lg = 1;
      }
      if(caracter == ' '){
        lerComandoAc(qry,&x,&y,&l,&a);
        n = getFirstElementTree(getTorre(cid));
        l1 = createList();
        l2 = createList();
        l1 = converterTreeToList(l1,getTorre(cid),n);

        l2 = buscarPontosPoligono(l1,l2,x,y,l,a);
        pts = length(l2)*pts;
        if(pts != 0){
          v = criaVetor(pts);
          p = getFirst(l2);

          for(i=0;i<length(l2);i++){
            calcularPontosCirculo(v,getTorreX(get(l2,p)),getTorreY(get(l2,p)),getTorreRaio(get(l2,p)),10);
            p = getNext(l2,p);
          }
          v = PrimeiroPasso(v,comparaY,coordPolarCirculo,comparaAng);
          f = inicializacao();
          r = inicializacao();
          f = calculaEnvoltoria(v,orientacaoCirculo,f,r);
          v = converterPilhaParaVetor(f,getCirculoX,getCirculoY,pts);
          string = somenteNomeArq(*testes);
          *str = criaArqSvgComSulfixoPoligono(*dir,*nome,string,cep);
          svg = fopen(*str,"w");
          escrevePoligono(&svg,v,cid,l2);
          fclose(svg);
          free(*str);
        }
      }
      else{
        n = getFirstElementTree(getTorre(cid));
        l1 = createList();
        l1 = converterTreeToList(l1,getTorre(cid),n);
        pts = length(l1)*pts;
        if(pts != 0){
          v = criaVetor(pts);
          p = getFirst(l1);
          for(i=0;i<length(l1);i++){
            calcularPontosCirculo(v,getTorreX(get(l1,p)),getTorreY(get(l1,p)),getTorreRaio(get(l1,p)),10);
            p = getNext(l1,p);
          }
          v = PrimeiroPasso(v,comparaY,coordPolarCirculo,comparaAng);
          f = inicializacao();
          r = inicializacao();
          f = calculaEnvoltoria(v,orientacaoCirculo,f,r);
          v = converterPilhaParaVetor(f,getCirculoX,getCirculoY,pts);
          string = somenteNomeArq(*testes);
          *str = criaArqSvgComSulfixoPoligono(*dir,*nome,string,cep);
          svg = fopen(*str,"w");
          escrevePoligono(&svg,v,cid,l1);
          fclose(svg);
          free(*str);
        }
      }
    }
  }

  if(*k == 1){
    *str = criaResumo(*dir);

    *resum = fopen(*str,"w");
    free(*str);
    fprintf(*resum, "Nome\t\t #ins\t #cpi\t #del\t #cpd\n");
    fprintf(*resum, "%s.geo - %s.qry\t %d\t\t %d\t\t %d\t\t %d \n",*nome,*aux,ins,getComp(getQuadra(cid)),del,cpd);
  }
  else if(*k == 2){
    *str = criaResumo(*dir);

    *resum = fopen(*str,"a");
    free(*str);
    fprintf(*resum, "%s.geo - %s.qry\t %d\t\t %d\t\t %d\t\t %d\n",*nome,*aux,ins,getComp(getQuadra(cid)),del,cpd);
  }
  else if(k == 0){

  }
  free(fig);
  free(cep);
}

void lerds(FILE **qry,double *x,double *y,double *w,double *h){
  fscanf(*qry," %lf",x);
  fscanf(*qry," %lf",y);
  fscanf(*qry," %lf",w);
  fscanf(*qry," %lf",h);
}

void lerDs(FILE **qry,double *x,double *y,double *r){
  fscanf(*qry," %lf",x);
  fscanf(*qry," %lf",y);
  fscanf(*qry," %lf",r);
}

void lerComandoAc(FILE **arq,double *x,double *y,double *l,double *a){
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %lf",l);
  fscanf(*arq," %lf",a);
}

int removedq(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt,int *del,int *cpd){
  double x2,y2,x1,y1,xq,yq;
  int tam=0;
  char *ident;

  if(leafNe(getQuadra(cid),n) == 1)
    removedq(cid,getNe(getQuadra(cid),n),x,y,w,h,txt,del,cpd);

  if(leafNw(getQuadra(cid),n) == 1)
    removedq(cid,getNw(getQuadra(cid),n),x,y,w,h,txt,del,cpd);

  if(leafSe(getQuadra(cid),n) == 1)
    removedq(cid,getSe(getQuadra(cid),n),x,y,w,h,txt,del,cpd);

  if(leafSw(getQuadra(cid),n) == 1)
    removedq(cid,getSw(getQuadra(cid),n),x,y,w,h,txt,del,cpd);

  if(n != NULL){
    x2 = x+w;
    y2 = y+h;
    xq = getQuadraX(getElement(getQuadra(cid),n));
    yq = getQuadraY(getElement(getQuadra(cid),n));
    x1 = getQuadraX(getElement(getQuadra(cid),n))+getQuadraLarg(getElement(getQuadra(cid),n));
    y1 = getQuadraY(getElement(getQuadra(cid),n))+getQuadraAlt(getElement(getQuadra(cid),n));
    if(xq>x && x1<x2){
      if(yq>y && y1<y2){
        tam = strlen(getQuadraCep(getElement(getQuadra(cid),n)));
        ident = (char *)malloc((tam+1)*sizeof(char));
        strcpy(ident,getQuadraCep(getElement(getQuadra(cid),n)));
        fprintf(*txt, "Quadra Removida - id: %s\n",ident);
        free(ident);
        removeTree(getQuadra(cid),n);
        *del+=1;
      }
    }
    else
      *cpd+=1;
  }

  return 0;
}

int removedh(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt){
  char *ident;
  int tam=0;
  double x2,y2,x1,y1;

  if(leafNe(getHidrante(cid),n) == 1)
    removedh(cid,getNe(getHidrante(cid),n),x,y,w,h,txt);

  if(leafNw(getHidrante(cid),n) == 1)
    removedh(cid,getNw(getHidrante(cid),n),x,y,w,h,txt);

  if(leafSe(getHidrante(cid),n) == 1)
    removedh(cid,getSe(getHidrante(cid),n),x,y,w,h,txt);

  if(leafSw(getHidrante(cid),n) == 1)
    removedh(cid,getSw(getHidrante(cid),n),x,y,w,h,txt);

  if(n != NULL){
    x2 = x+w;
    y2 = y+h;
    x1 = getHidranteX(getElement(getHidrante(cid),n));
    y1 = getHidranteY(getElement(getHidrante(cid),n));
    if(x1>x && x1<x2){
      if(y1>y && y1<y2){
        tam = strlen(getHidranteId(getElement(getHidrante(cid),n)));
        ident = (char *)malloc((tam+1)*sizeof(char));
        strcpy(ident,getHidranteId(getElement(getHidrante(cid),n)));
        fprintf(*txt, "Hidrante Removido - id: %s\n",ident);
        free(ident);
        removeTree(getHidrante(cid),n);
      }
    }
  }

  return 0;
}

int removeds(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt){
  char *ident;
  int tam=0;
  double x2,y2,x1,y1;

  if(leafNe(getSemaforo(cid),n) == 1)
    removeds(cid,getNe(getSemaforo(cid),n),x,y,w,h,txt);

  if(leafNw(getSemaforo(cid),n) == 1)
    removeds(cid,getNw(getSemaforo(cid),n),x,y,w,h,txt);

  if(leafSe(getSemaforo(cid),n) == 1)
    removeds(cid,getSe(getSemaforo(cid),n),x,y,w,h,txt);

  if(leafSw(getSemaforo(cid),n) == 1)
    removeds(cid,getSw(getSemaforo(cid),n),x,y,w,h,txt);

  if(n != NULL){
    x2 = x+w;
    y2 = y+h;
    x1 = getSemaforoX(getElement(getSemaforo(cid),n));
    y1 = getSemaforoY(getElement(getSemaforo(cid),n));
    if(x1>x && x1<x2){
      if(y1>y && y1<y2){
        tam = strlen(getSemaforoId(getElement(getSemaforo(cid),n)));
        ident = (char *)malloc((tam+1)*sizeof(char));
        strcpy(ident,getSemaforoId(getElement(getSemaforo(cid),n)));
        fprintf(*txt, "Semaforo Removido - id: %s\n",ident);
        free(ident);
        removeTree(getSemaforo(cid),n);
      }
    }
  }

  return 0;
}

int removedt(Cidade *cid,PosicNo *n,double x,double y,double w,double h,FILE **txt){
  int tam=0;
  char *ident;
  double x2,y2,x1,y1;

  if(leafNe(getTorre(cid),n) == 1)
    removedt(cid,getNe(getTorre(cid),n),x,y,w,h,txt);

  if(leafNw(getTorre(cid),n) == 1)
    removedt(cid,getNw(getTorre(cid),n),x,y,w,h,txt);

  if(leafSe(getTorre(cid),n) == 1)
    removedt(cid,getSe(getTorre(cid),n),x,y,w,h,txt);

  if(leafSw(getTorre(cid),n) == 1)
    removedt(cid,getSw(getTorre(cid),n),x,y,w,h,txt);

  if(n!=NULL){
    x2 = x+w;
    y2 = y+h;
    x1 = getTorreX(getElement(getTorre(cid),n));
    y1 = getTorreY(getElement(getTorre(cid),n));
    if(x1>x && x1<x2){
      if(y1>y && y1<y2){
        tam = strlen(getTorreId(getElement(getTorre(cid),n)));
        ident = (char *)malloc((tam+1)*sizeof(char));
        strcpy(ident,getTorreId(getElement(getTorre(cid),n)));
        fprintf(*txt, "Torre Removida - id: %s\n",ident);
        free(ident);
        removeTree(getTorre(cid),n);
      }
    }
  }

  return 0;
}

int removeDq(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt,int *del,int *cpd){
  char *ident;
  int tam=0;
  double xx,xd,yy,ye,yb,result;

  if(leafNe(getQuadra(cid),n) == 1)
    removeDq(cid,getNe(getQuadra(cid),n),x,y,r,txt,del,cpd);

  if(leafNw(getQuadra(cid),n) == 1)
    removeDq(cid,getNw(getQuadra(cid),n),x,y,r,txt,del,cpd);

  if(leafSe(getQuadra(cid),n) == 1)
    removeDq(cid,getSe(getQuadra(cid),n),x,y,r,txt,del,cpd);

  if(leafSw(getQuadra(cid),n) == 1)
    removeDq(cid,getSw(getQuadra(cid),n),x,y,r,txt,del,cpd);

  if(n != NULL){
    xx = getQuadraX(getElement(getQuadra(cid),n));
    yy = getQuadraY(getElement(getQuadra(cid),n));
    result = ((x-xx)*(x-xx)) + ((y-yy)*(y-yy));
    /*Testa ancora*/
    if(result < (r*r)){
      xd = xx+getQuadraLarg(getElement(getQuadra(cid),n));
      result = ((x-xd)*(x-xd)) + ((y-yy)*(y-yy));
      /*Testa Ponto de cima a direita*/
      if(result < (r*r)){
        ye = yy+getQuadraAlt(getElement(getQuadra(cid),n));
        result = ((x-xx)*(x-xx)) + ((y-ye)*(y-ye));
        /*Testa Ponto de baixa a esquerda*/
        if(result < (r*r)){
          result = ((x-xd)*(x-xd)) + ((y-ye)*(y-ye));
          /*Testa Ponto de baixo a direita*/
          if(result < (r*r)){
            tam = strlen(getQuadraCep(getElement(getQuadra(cid),n)));
            ident = (char *)malloc((tam+1)*sizeof(char));
            strcpy(ident,getQuadraCep(getElement(getQuadra(cid),n)));
            fprintf(*txt, "Quadra Removida - cep: %s\n",ident);
            free(ident);
            removeTree(getQuadra(cid),n);
            *del++;
          }
        }
      }
      else
        *cpd++;
    }
  }


  return 0;
}

int removeDh(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt){
  char *ident;
  int tam=0;
  double px,py,result;

  if(leafNe(getHidrante(cid),n) == 1)
    removeDh(cid,getNe(getHidrante(cid),n),x,y,r,txt);

  if(leafNw(getHidrante(cid),n) == 1)
    removeDh(cid,getNw(getHidrante(cid),n),x,y,r,txt);

  if(leafSe(getHidrante(cid),n) == 1)
    removeDh(cid,getSe(getHidrante(cid),n),x,y,r,txt);

  if(leafSw(getHidrante(cid),n) == 1)
    removeDh(cid,getSw(getHidrante(cid),n),x,y,r,txt);

  if(n != NULL){
    px = getHidranteX(getElement(getHidrante(cid),n));
    py = getHidranteY(getElement(getHidrante(cid),n));

    result = ((x-px)*(x-px)) + ((y-py)*(y-py));
    if(result < (r*r)){
      tam = strlen(getHidranteId(getElement(getHidrante(cid),n)));
      ident = (char *)malloc((tam+1)*sizeof(char));
      strcpy(ident,getHidranteId(getElement(getHidrante(cid),n)));
      fprintf(*txt, "Hidrante Removido - id: %s\n",ident);
      free(ident);
      removeTree(getHidrante(cid),n);
    }
  }
  return 0;
}

int removeDs(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt){
  char *ident;
  int tam=0;
  double px,py,result;

  if(leafNe(getSemaforo(cid),n) == 1)
    removeDs(cid,getNe(getSemaforo(cid),n),x,y,r,txt);

  if(leafNw(getSemaforo(cid),n) == 1)
    removeDs(cid,getNw(getSemaforo(cid),n),x,y,r,txt);

  if(leafSe(getSemaforo(cid),n) == 1)
    removeDs(cid,getSe(getSemaforo(cid),n),x,y,r,txt);

  if(leafSw(getSemaforo(cid),n) == 1)
    removeDs(cid,getSw(getSemaforo(cid),n),x,y,r,txt);

  if(n != NULL){
    px = getSemaforoX(getElement(getSemaforo(cid),n));
    py = getSemaforoY(getElement(getSemaforo(cid),n));

    result = ((x-px)*(x-px)) + ((y-py)*(y-py));
    if(result < (r*r)){
      tam = strlen(getSemaforoId(getElement(getSemaforo(cid),n)));
      ident = (char *)malloc((tam+1)*sizeof(char));
      strcpy(ident,getSemaforoId(getElement(getSemaforo(cid),n)));
      fprintf(*txt, "Semaforo Removido - id: %s\n",ident);
      free(ident);
      removeTree(getSemaforo(cid),n);
    }
  }
  return 0;
}
int removeDt(Cidade *cid,PosicNo *n,double x,double y,double r,FILE **txt){
  char *ident;
  int tam=0;
  double px,py,result;

  if(leafNe(getTorre(cid),n) == 1)
    removeDt(cid,getNe(getTorre(cid),n),x,y,r,txt);

  if(leafNw(getTorre(cid),n) == 1)
    removeDt(cid,getNw(getTorre(cid),n),x,y,r,txt);

  if(leafSe(getTorre(cid),n) == 1)
    removeDt(cid,getSe(getTorre(cid),n),x,y,r,txt);

  if(leafSw(getTorre(cid),n) == 1)
    removeDt(cid,getSw(getTorre(cid),n),x,y,r,txt);

  if(n != NULL){
    px = getTorreX(getElement(getTorre(cid),n));
    py = getTorreY(getElement(getTorre(cid),n));

    result = ((x-px)*(x-px)) + ((y-py)*(y-py));
    if(result < (r*r)){
      tam = strlen(getTorreId(getElement(getTorre(cid),n)));
      ident = (char *)malloc((tam+1)*sizeof(char));
      strcpy(ident,getTorreId(getElement(getTorre(cid),n)));
      fprintf(*txt, "Torre Removida - id: %s\n",ident);
      free(ident);
      removeTree(getTorre(cid),n);
    }
  }
  return 0;
}

void percorreCidQuadra(Cidade *cid,FILE **txt,char **id,PosicNo *n){

  if(leafNe(getQuadra(cid),n) == 1)
    percorreCidQuadra(cid,txt,id,getNe(getQuadra(cid),n));

  if(leafNw(getQuadra(cid),n) == 1)
    percorreCidQuadra(cid,txt,id,getNw(getQuadra(cid),n));

  if(leafSe(getQuadra(cid),n) == 1)
    percorreCidQuadra(cid,txt,id,getSe(getQuadra(cid),n));

  if(leafSw(getQuadra(cid),n) == 1)
    percorreCidQuadra(cid,txt,id,getSw(getQuadra(cid),n));

    if(strcmp(*id,getQuadraCep(getElement(getQuadra(cid),n)))==0){
      fprintf(*txt, "CRD? = Equipamento: Quadra id: %s X: %lf Y: %lf Larg: %lf Alt: %lf\n",getQuadraCep(getElement(getQuadra(cid),n)),getQuadraX(getElement(getQuadra(cid),n)),getQuadraY(getElement(getQuadra(cid),n)),getQuadraLarg(getElement(getQuadra(cid),n)),getQuadraAlt(getElement(getQuadra(cid),n)));
    }
}

void percorreCidHidrante(Cidade *cid,FILE **txt,char **id,PosicNo *n){

  if(leafNe(getHidrante(cid),n) == 1)
    percorreCidHidrante(cid,txt,id,getNe(getHidrante(cid),n));

  if(leafNw(getHidrante(cid),n) == 1)
    percorreCidHidrante(cid,txt,id,getNw(getHidrante(cid),n));

  if(leafSe(getHidrante(cid),n) == 1)
    percorreCidHidrante(cid,txt,id,getSe(getHidrante(cid),n));

  if(leafSw(getHidrante(cid),n) == 1)
    percorreCidHidrante(cid,txt,id,getSw(getHidrante(cid),n));

    if(strcmp(*id,getHidranteId(getElement(getHidrante(cid),n)))==0){
      fprintf(*txt, "CRD? = Equipamento: Hidrante id:%s X: %lf Y: %lf\n",getHidranteId(getElement(getHidrante(cid),n)),getHidranteX(getElement(getHidrante(cid),n)),getHidranteY(getElement(getHidrante(cid),n)));
    }
}

void percorreCidSemaforo(Cidade *cid,FILE **txt,char **id,PosicNo *n){

  if(leafNe(getSemaforo(cid),n) == 1)
    percorreCidSemaforo(cid,txt,id,getNe(getSemaforo(cid),n));

  if(leafNw(getSemaforo(cid),n) == 1)
    percorreCidSemaforo(cid,txt,id,getNw(getSemaforo(cid),n));

  if(leafSe(getSemaforo(cid),n) == 1)
    percorreCidSemaforo(cid,txt,id,getSe(getSemaforo(cid),n));

  if(leafSw(getSemaforo(cid),n) == 1)
    percorreCidSemaforo(cid,txt,id,getSw(getSemaforo(cid),n));

  if(strcmp(*id,getSemaforoId(getElement(getSemaforo(cid),n)))==0){
    fprintf(*txt, "CRD? = Equipamento: Semáforo id: %s X: %lf Y: %lf\n",getSemaforoId(getElement(getSemaforo(cid),n)),getSemaforoX(getElement(getSemaforo(cid),n)),getSemaforoY(getElement(getSemaforo(cid),n)));
  }
}

void percorreCidTorre(Cidade *cid,FILE **txt,char **id,PosicNo *n){

  if(leafNe(getTorre(cid),n) == 1)
    percorreCidTorre(cid,txt,id,getNe(getTorre(cid),n));

  if(leafNw(getTorre(cid),n) == 1)
    percorreCidTorre(cid,txt,id,getNw(getTorre(cid),n));

  if(leafSe(getTorre(cid),n) == 1)
    percorreCidTorre(cid,txt,id,getSe(getTorre(cid),n));

  if(leafSw(getTorre(cid),n) == 1)
    percorreCidTorre(cid,txt,id,getSw(getTorre(cid),n));

    if(strcmp(*id,getTorreId(getElement(getTorre(cid),n)))==0){
      fprintf(*txt, "CRD? = Equipamento: Torre id: %s X: %lf Y: %lf\n",getTorreId(getElement(getTorre(cid),n)),getTorreX(getElement(getTorre(cid),n)),getTorreY(getElement(getTorre(cid),n)));
    }
}

/*
//////////////////////
        T5
//////////////////////
*/
void lerComandoCon(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *cep,*numcel,face;
  double d;
  int num;
  cep = (char *)malloc(300*sizeof(char));
  numcel = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",numcel);
  fscanf(*qry," %s",cep);
  fscanf(*qry," %c",&face);
  fscanf(*qry," %d",&num);
  d = processaCon(dic,&numcel,&cep,face,num,cid,txt);
  free(cep);
  free(numcel);
}

void lerComandoM(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *cep;
  cep = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",cep);
  processaComandoM(dic,&cep,cid,txt);
  free(cep);
}
void lerComandoDm(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *cpf;
  cpf = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",cpf);
  processaComandoDm(&cpf,dic,txt);
  free(cpf);
}

void lerComandoDe(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *cnpj;
  cnpj = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",cnpj);
  processaComandoDe(&cnpj,dic,txt);
  free(cnpj);
}

void lerComandoLk(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *id;
  id = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",id);
  processaComandoLk(&id,dic,cid,txt);
  free(id);
}

void lerComandoRb(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *numcel;
  numcel = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",numcel);
  processaComandoRb(&numcel,dic,txt);
  free(numcel);
}

void lerComandoEcq(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *cep;
  cep = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",cep);
  processaComandoEcq(&cep,dic,txt);
  free(cep);
}

void lerComandoDc(FILE **qry,Dicionario dic,Cidade cid,FILE **txt){
  char *numtel;
  numtel = (char *)malloc(300*sizeof(char));
  fscanf(*qry," %s",numtel);
  processaComandoDc(&numtel,dic,txt);
  free(numtel);
}





/*
///////////////////////
        T6
//////////////////////
*/
void lerComandoQryF(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores){
  Hash numcelXradio;
  Vertice vertice;
	Torre torre;
	char *pRegistrador, *pNumcel, *registrador, *numcel;
	double x, y;
	int i;

	pRegistrador = (char *) malloc(5*sizeof(char));
	pNumcel = (char *) malloc(1000*sizeof(char));

	fscanf(*qry, " %s %s ", pRegistrador, pNumcel);

	registrador = (char *) malloc((strlen(pRegistrador)+1)*sizeof(char));
	strcpy(registrador, pRegistrador);

	numcel = (char *) malloc((strlen(pNumcel)+1)*sizeof(char));
	strcpy(numcel, pNumcel);

  numcelXradio = getHashDicionario(dic,"numcelXradio");
  torre = getRegInfo(numcelXradio,numcel);
	if (torre != NULL) {
		x = getTorreX(torre);
		y = getTorreY(torre);

		if (x >= 0 && y >= 0) {
			vertice = criarVertice(registrador, x, y);

			i = calculaIndice(registrador);

			addElemento(registradores, i, vertice, x, y);
		}
	}

	free(pRegistrador);
	free(pNumcel);
	free(registrador);
	free(numcel);
}

void lerComandoQryM(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores){
  Hash pessoaCpf;
  Vertice vertice;
	Pessoa pessoa;
	char *pCpf, *cpf, *pRegistrador, *registrador;
	double x, y;
	int i;

	pCpf = (char *) malloc(1000*sizeof(char));
	pRegistrador = (char *) malloc(5*sizeof(char));

	fscanf(*qry, " %s %s ", pRegistrador, pCpf);

	cpf = (char *) malloc((strlen(pCpf)+1)*sizeof(char));
	strcpy(cpf, pCpf);

	registrador = (char *) malloc((strlen(pRegistrador)+1)*sizeof(char));
	strcpy(registrador, pRegistrador);

  pessoaCpf = getHashDicionario(dic,"pessoaCpf");
  pessoa = getRegInfo(pessoaCpf,cpf);
	if (pessoa != NULL) {
		x = getPessoaX(pessoa);
		y = getPessoaY(pessoa);

		if (x >= 0 && y >= 0) {
			vertice = criarVertice(registrador, x, y);

			i = calculaIndice(registrador);
			addElemento(registradores, i, vertice, x, y);
		}
	}

	free(pRegistrador);
	free(pCpf);
	free(registrador);
	free(cpf);
}

void lerComandoQryE(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores){
  Vertice vertice;
	Hash cepXquadra;
	Quadra quadra;
	char *pRegistrador, *pCep, *registrador, *cep, face;
	double x, y;
	int i, num;

	pRegistrador = (char *) malloc(5*sizeof(char));
	pCep = (char *) malloc(1000*sizeof(char));

	fscanf(*qry, " %s %s %c %d ", pRegistrador, pCep, &face, &num);

	registrador = (char *) malloc((strlen(pRegistrador)+1)*sizeof(char));
	strcpy(registrador, pRegistrador);

	cep = (char *) malloc((strlen(pCep)+1)*sizeof(char));
	strcpy(cep, pCep);

	cepXquadra = getHashDicionario(dic, "cepXquadra");
	quadra = getRegInfo(cepXquadra, cep);

	if (quadra != NULL) {
		x = getQuadraX(quadra);
		y = getQuadraY(quadra);

		calculaPontosXY(&x, &y, face, num);

		if (x >= 0 && y >= 0) {
			vertice = criarVertice(registrador, x, y);

			i = calculaIndice(registrador);

			addElemento(registradores, i, vertice, x, y);
		}
	}

	free(pRegistrador);
	free(pCep);
	free(registrador);
	free(cep);
}

void lerComandoQryG(FILE **qry,Dicionario dic,Cidade cid,Vetor registradores){
  Vertice vertice;
	Quadra quadra;
	Hidrante hidrante;
	Semaforo semaforo;
	Torre torre;
	char *pRegistrador, *pId, *registrador, *id;
	double x=-1, y=-1;
	int i;

	pRegistrador = (char *) malloc(5*sizeof(char));
	pId = (char *) malloc(1000*sizeof(char));

	fscanf(*qry, " %s %s ", pRegistrador, pId);

	registrador = (char *) malloc((strlen(pRegistrador)+1)*sizeof(char));
	strcpy(registrador, pRegistrador);

	id = (char *) malloc((strlen(pId)+1)*sizeof(char));
	strcpy(id, pId);

	quadra = retornaEquipQuadra(cid,id);
	hidrante = retornaEquipHidrante(cid,id);
	semaforo = retornaEquipSemaforo(cid,id);
	torre = retornaEquipTorre(cid,id);

	if (quadra != NULL) {
		x = getQuadraX(quadra);
		y = getQuadraY(quadra);
	}
	else if (hidrante != NULL) {
		x = getHidranteX(hidrante);
		y = getHidranteY(hidrante);
	}
	else if (semaforo != NULL) {
		x = getSemaforoX(semaforo);
		y = getSemaforoY(semaforo);
	}
	else if (torre != NULL) {
		x = getTorreX(torre);
		y = getTorreY(torre);
	}

	if (x >= 0 && y >= 0) {
		vertice = criarVertice(registrador, x, y);

		i = calculaIndice(registrador);

		addElemento(registradores, i, vertice, x, y);
	}

	free(pRegistrador);
	free(pId);
	free(registrador);
	free(id);
}

void lerComandoQryXY(FILE **qry,Vetor registradores){
  Vertice vertice;
  char *pRegistrador, *registrador;
  double x, y;
  int i;

  pRegistrador = (char *) malloc(5*sizeof(char));

  fscanf(*qry, " %s %lf %lf ", pRegistrador, &x, &y);

  registrador = (char *) malloc((strlen(pRegistrador)+1)*sizeof(char));
  strcpy(registrador, pRegistrador);

  if (x >= 0 && y >= 0) {
  vertice = criarVertice(registrador, x, y);

  i = calculaIndice(registrador);

  addElemento(registradores, i, vertice, x, y);
  }

  free(pRegistrador);
  free(registrador);
}

void lerComandoQryTp(FILE **qry,Cidade cid,Dicionario dic,Vetor registradores){
  Vertice vertice1, vertice2;
	Hash estCnpj;
	EstabelecimentoCom comercial;
	Lista estabelecimentos;
	char *pRegistrador1, *pRegistrador2, *pCodt, *registrador1, *registrador2, *codt;
	double x1, y1, x2, y2;
	int i;

	pRegistrador1 = (char *) malloc(5*sizeof(char));
	pRegistrador2 = (char *) malloc(5*sizeof(char));
	pCodt = (char *) malloc(1000*sizeof(char));

	fscanf(*qry, " %s %s %s ", pRegistrador1, pCodt, pRegistrador2);

	registrador1 = (char *) malloc((strlen(pRegistrador1)+1)*sizeof(char));
	strcpy(registrador1, pRegistrador1);

	registrador2 = (char *) malloc((strlen(pRegistrador2)+1)*sizeof(char));
	strcpy(registrador2, pRegistrador2);

	codt = (char *) malloc((strlen(pCodt)+1)*sizeof(char));
	strcpy(codt, pCodt);

	i = calculaIndice(registrador2);
	x2 = getVetorX(registradores, i);
	y2 = getVetorY(registradores, i);

	estCnpj = getHashDicionario(dic, "estCnpj");
	estabelecimentos = getAllRegInfo(estCnpj);
	comercial = encontraEstabelecimentoProx(estabelecimentos, x2, y2, codt);

	if (comercial != NULL) {
		x1 = getEstabelecimentoX(comercial);
		y1 = getEstabelecimentoY(comercial);

		vertice1 = criarVertice(registrador1, x1, y1);

		i = calculaIndice(registrador1);

		addElemento(registradores, i, vertice1, x1, y1);
	}

	/*clearLista(estabelecimentos);*/
	free(pRegistrador1);
	free(pRegistrador2);
	free(pCodt);
	free(registrador1);
	free(registrador2);
	free(codt);
}

void lerComandoQryP(FILE **qry,char *dir,char *nome,char *aux,Grafo grafo,Cidade cid,Dicionario dic,Vetor registradores){
  Vertice origem,destino,r1,r2;
  Lista list;
	char *path, *nomeSvg, *nomeTxt, *pSufixoSvg, *pRegistrador1, *pRegistrador2, *pCor, *sufixoSvg, *sufixoTxt, *registrador1, *registrador2, *cor, tipo, peso;
	double x, y;
	int i, cont;

	pRegistrador1 = (char *) malloc(5*sizeof(char));
	pRegistrador2 = (char *) malloc(5*sizeof(char));

	fscanf(*qry, " %c ", &tipo);

	/* Sufixo do SVG */
	if (tipo == 'p') {
		pSufixoSvg = (char *) malloc(1000*sizeof(char));

		fscanf(*qry, " %s ", pSufixoSvg);

		sufixoSvg = (char *) malloc((strlen(pSufixoSvg)+1)*sizeof(char));
		strcpy(sufixoSvg, pSufixoSvg);
	}

	fscanf(*qry, " %c %s %s ", &peso, pRegistrador1, pRegistrador2);

	registrador1 = (char *) malloc((strlen(pRegistrador1)+1)*sizeof(char));
	strcpy(registrador1, pRegistrador1);

	registrador2 = (char *) malloc((strlen(pRegistrador2)+1)*sizeof(char));
	strcpy(registrador2, pRegistrador2);

	i = calculaIndice(registrador1);
	x = getVetorX(registradores,i);
	y = getVetorY(registradores,i);
  list = getAllVertices(grafo);
	origem = encontraVerticeProx(list, x, y);

	i = calculaIndice(registrador2);
	x = getVetorX(registradores, i);
	y = getVetorY(registradores, i);
	destino = encontraVerticeProx(list, x, y);

	/* Cor do SVG */
	if (tipo == 'p') {
		pCor = (char *) malloc(100*sizeof(char));

		fscanf (*qry, " %s ", pCor);

		cor = (char *) malloc((strlen(pCor)+1)*sizeof(char));
		strcpy(cor, pCor);

    path = criaArqSvgComSulfixoPoligono(dir,nome,aux,sufixoSvg);
		representacaoPictorica(cid,dic,grafo,origem,destino,peso,path,cor);
  }
	else {
		cont = 2 + 1 + 1 + strlen(registrador1) + strlen(registrador2) + 4 + 1;
		sufixoTxt = (char *) malloc(cont*sizeof(char));
		sprintf(sufixoTxt, "%s_%c_%c_%s_%s", "p?", tipo, peso, registrador1, registrador2);

    path = criaArqTxtComSufixo(dir,nome,aux,sufixoTxt);
		describe(grafo,origem,destino,peso,path);
  }

	if (tipo == 'p') {
		free(pSufixoSvg);
		free(sufixoSvg);
		free(pCor);
		free(cor);
    /*
		free(nomeSvg);
    */
  }
	else {
		free(sufixoTxt);
    /*
		 free(nomeTxt);
     */
	 }

	free(path);
	free(pRegistrador1);
	free(pRegistrador2);
	free(registrador1);
	free(registrador2);
}

EstabelecimentoCom encontraEstabelecimentoProx(Lista estabelecimentos, double x, double y, char *codt) {
	Posic p;
	EstabelecimentoCom aux, estabelecimento=NULL;
	double xEstabelecimento, yEstabelecimento, menor, dist;
	char *tipo;

	p = getFirst(estabelecimentos);
	aux = get(estabelecimentos, p);

	xEstabelecimento = getEstabelecimentoX(aux);
	yEstabelecimento = getEstabelecimentoY(aux);

  dist = sqrt(pow((xEstabelecimento-x),2)+pow((yEstabelecimento-y),2));
	menor = dist;

	while (p != NULL) {
		aux = get(estabelecimentos, p);

		xEstabelecimento = getEstabelecimentoX(aux);
		yEstabelecimento = getEstabelecimentoY(aux);
		tipo = getEstabelecimentoCodt(aux);
    dist = sqrt(pow((xEstabelecimento-x),2)+pow((yEstabelecimento-y),2));

		if (dist < menor && strcmp(tipo, codt) == 0) {
			menor = dist;
			estabelecimento = aux;
		}

		p = getNext(estabelecimentos, p);
	}

	return estabelecimento;
}

Vertice encontraVerticeProx(Lista vertices, double x, double y){
  double verticeX,verticeY,dist,menor;
  Posic p;
  Vertice aux,v;
  p = getFirst(vertices);

  aux = get(vertices,p);
  verticeX = getVerticeX(aux);
  verticeY = getVerticeY(aux);

  dist = sqrt(pow((verticeX-x),2)+pow((verticeY-y),2));
	menor = dist;
  v = aux;
  p = getNext(vertices,p);
  while(p != NULL){
    aux = get(vertices,p);
    verticeX = getVerticeX(aux);
    verticeY = getVerticeY(aux);
    dist = sqrt(pow((verticeX-x),2)+pow((verticeY-y),2));
    if(dist < menor){
      menor = dist;
      v = aux;
    }
    p = getNext(vertices,p);
  }
  return v;
}
