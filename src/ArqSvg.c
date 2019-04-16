#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Operacoes.h"
#include "Cidade.h"
#include "ArqSvg.h"
#include "Circulo.h"
#include "Hidrante.h"
#include "Semaforo.h"
#include "Torre.h"
#include "Retangulo.h"

void menu(Cidade *cid,Lista *circ,Lista *retang,Lista *sobrepos,FILE **arq,FILE **svg,FILE **txt,double *maxx,double *maxy,char **str,char **nome,char **dir,char **cor,int *ins,int *logic){
  Posic p;
  PosicNo n;
  int ids=0;
  char *fig,*operadora,*corpQ,*corbQ,*corpH,*corbH,*corpT,*corbT,*corpS,*corbS,*sulfixo,*cep;

  cep = (char *)malloc(100*sizeof(char));
  sulfixo = (char *)malloc(500*sizeof(char));
  corpQ = (char *)malloc(50*sizeof(char));
  corbQ = (char *)malloc(50*sizeof(char));
  corpT = (char *)malloc(50*sizeof(char));
  corbT = (char *)malloc(50*sizeof(char));
  corpH = (char *)malloc(50*sizeof(char));
  corbH = (char *)malloc(50*sizeof(char));
  corpS = (char *)malloc(50*sizeof(char));
  corbS = (char *)malloc(50*sizeof(char));
  operadora = (char *)malloc(100*sizeof(char));
  fig = (char *)malloc(5*sizeof(char));
  while(!feof(*arq)){

    fscanf(*arq," %s", fig);
    if(feof(*arq)){
      break;
    }
    /*Se for o final do arquivo define o tamanho do svg*/
    if(strcmp(fig,"#")==0){
      fclose(*arq);
      break;
    }

    /*Se comando for 'c' de circulo*/
    if(strcmp(fig,"c")==0){
      Circulo *c;
      int id;
      double r,x,y;
      lerCirc(arq,&id,&r,&x,&y,cor);
      c = criarCirculo(id,r,x,y,*cor);
      p = insert(circ,c);
      if(x+r > *maxx){
        *maxx = x+r;
      }
      if(y+r > *maxy){
        *maxy = y+r;
      }

    }
    /*Se comando for 'r' de retangulo*/
    else if(strcmp(fig,"r")==0){
      Retangulo *ret;
      int id;
      double x,y,w,h;
      lerRet(arq,&id,&w,&h,&x,&y,cor);
      ret = criarRetangulo(id,w,h,x,y,*cor);
      p = insert(retang,ret);
      if(x+w > *maxx){
        *maxx = x+w;
      }
      if(y+h > *maxy){
        *maxy = y+h;
      }
    }
    /*Se comando for 'q' de quadra*/
    else if(strcmp(fig,"q")==0){
      Quadra q;
      int id;
      double x,y,w,h;
      lerQuadra(arq,&x,&y,&w,&h,&cep);
      q = criarQuadra(x,y,w,h,cep,corpQ,corbQ);
      id = insereQuadra(cid,q,x,y);
      *ins+=1;
      if(x+w > *maxx){
        *maxx = x+w;
      }
      if(y+h > *maxy){
        *maxy = y+h;
      }
    }
    /*Se comando for 'h' de hidrante*/
    else if(strcmp(fig,"h")==0){
      Hidrante h;
      int id;
      double x,y;
      lerHidrante(arq,&x,&y,&cep);
      h = criarHidrante(cep,x,y,corpH,corbH);
      id = insereHidrante(cid,h,x,y);
      if(x+5.0 > *maxx){
        *maxx = x+5.0;
      }
      if(y+5.0 > *maxy){
        *maxy = y+5.0;
      }
    }
    /*Se comando for 's' de semaforo*/
    else if(strcmp(fig,"s")==0){
      Semaforo s;
      int id;
      double x,y;
      lerSemaforo(arq,&x,&y,&cep);
      s = criarSemaforo(cep,x,y,corpS,corbS);
      id = insereSemaforo(cid,s,x,y);
      if(x+5.0 > *maxx){
        *maxx = x+5.0;
      }
      if(y+5.0 > *maxy){
        *maxy = y+5.0;
      }
    }
    /*Se comando for 't' de torre*/
    else if(strcmp(fig,"t")==0){
      Torre t;
      int id;
      double x,y;
      lerTorre(arq,&x,&y,&cep);
      t = criarTorre(cep,x,y,corpT,corbT);
      id = insereTorre(cid,t,x,y);
      if(x+5.0 > *maxx){
        *maxx = x+5.0;
      }
      if(y+5.0 > *maxy){
        *maxy = y+5.0;
      }
    }
    else if(strcmp(fig,"cq")==0){
      fscanf(*arq," %s",corpQ);
      fscanf(*arq," %s",corbQ);
    }
    else if(strcmp(fig,"ch")==0){
      fscanf(*arq," %s",corpH);
      fscanf(*arq," %s",corbH);
    }
    else if(strcmp(fig,"ct")==0){
      fscanf(*arq," %s",corpT);
      fscanf(*arq," %s",corbT);
    }
    else if(strcmp(fig,"cs")==0){
      fscanf(*arq," %s",corpS);
      fscanf(*arq," %s",corbS);
    }
    else if(strcmp(fig,"hI")==0){
      double vazao=0;
      int a;
      lerComandoHI(arq,&cep,&vazao);
      n = getFirstElementTree(getHidrante(cid));
      a = procuraEquipPorID(getHidrante(cid),cep,vazao,n,setVazaoHidrante,getHidranteId,0);

    }
    else if(strcmp(fig,"tI")==0){
      int a;
      double vazao=0;
      lerComandoTI(arq,&cep,&vazao);
      n = getFirstElementTree(getTorre(cid));
      a = procuraEquipPorID(getTorre(cid),cep,vazao,n,setRaioTorre,getTorreId,0);

    }
    else if(strcmp(fig,"sI")==0){
      int a;
      double tempo=0;
      lerComandoSI(arq,&cep,&tempo);
      n = getFirstElementTree(getSemaforo(cid));
      a = procuraEquipPorID(getSemaforo(cid),cep,tempo,n,setSemaforoTempo,getSemaforoId,0);
    
    }
    /*Se comando for 'i' para verificar ponto*/
    else if(strcmp(fig,"i")==0){
      int id,type,i;
      double x,y;
      lerComandoI(arq,&id,&x,&y);
      i = buscaInd(circ,retang,id);
      i = verificaPonto(circ,retang,id,x,y,i);
      if(i!=1){
        fprintf(*txt, "%s ponto (%lf,%lf) Não é interno a *figura %d\n",fig,x,y,id);
      }
      else{
        fprintf(*txt, "%s ponto(%lf,%lf) É interno a *figura %d\n",fig,x,y,id);
      }
    }
    /*Se comando for igual a 'd' para verificar distancia */
    else if(strcmp(fig,"d")==0){
      int i,type1=0,type2=0,a,b;
      double result;
      lerDist(arq,&a,&b);
      i = buscaInd(circ,retang,a);
      while(1){
        if(i == 1){
          type1 = 1;
        }
        else if(i == 2){
          type1 = 2;
        }
        else if(i==0){
          fprintf(*txt, "Indice não existe\n");
          break;
        }
        i = buscaInd(circ,retang,b);
        if(i == 1){
          type2 = 1;
        }
        else if(i == 2){
          type2 = 2;
        }
        else if(i == 0){
          fprintf(*txt, "Indice não existe\n");
          break;
        }
        result = calculaDistancia(circ,retang,a,b,type1,type2);
        fprintf(*txt, "%s A distancia entre as *figuras %d e %d é de %f\n",fig,a,b,result);
        break;
      }
    }

    /*Se comando for 'a' para criar svg com sulfixo*/
    else if(strcmp(fig,"a")==0){
      FILE *sul;
      lerComandoA(arq,&sulfixo,cor);
      free(*str);
      *str = criaExt(*nome,*dir,3,sulfixo);
      sul = fopen(*str,"w");
      free(*str);
      fprintf(sul, "<svg viewBox=\"0 0 %f %f\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n",*maxx+100,*maxy+100);
      escreveCircComandoA(&sul,circ,cor);
      escreveRetComandoA(&sul,retang,cor);
      fprintf(sul, "</svg>\n");
      fclose(sul);
    }
    /*Se comando for 'o' para verificar sobreposição*/
    else if(strcmp(fig,"o")==0){
      int i,a,b,type1,type2;
      lerComandoO(arq,&a,&b);
      i = buscaInd(circ,retang,a);
      if(i == 1){
        type1 = 1;
      }
      else if(i == 2){
        type1 = 2;
      }
      i = buscaInd(circ,retang,b);
      if(i == 1){
        type2 = 1;
      }
      else if(i == 2){
        type2 = 2;
      }
      i = calculaSobreposicao(circ,retang,sobrepos,a,b,type1,type2,ids);/*Calcula,escreve e retorna inteiro*/

      if(i == 1){
        fprintf(*txt, "%s As formas %d e %d estão sobrepostas.\n",fig,a,b);
        *logic = 1;
      }
      else
        fprintf(*txt, "%s As formas %d e %d não estão sobrepostas\n",fig,a,b);
    }
    else if(strcmp(fig,"su")==0){
      int a;
      fscanf(*arq," %s",operadora);
      n = getFirstElementTree(getTorre(cid));
      a = adicionaOperadora(getTorre(cid),operadora,"SercomtUEL",n,setOperadoraTorre,getTorreId,0);

    }
    else if(strcmp(fig,"um")==0){
      int a;
      fscanf(*arq," %s",operadora);
      n = getFirstElementTree(getTorre(cid));
      a = adicionaOperadora(getTorre(cid),operadora,"UELMobile",n,setOperadoraTorre,getTorreId,0);
    }

  }
  free(fig);
  free(cep);
  free(corpQ);
  free(corbQ);
  free(corpT);
  free(corbT);
  free(corpH);
  free(corbH);
  free(corpS);
  free(corbS);
  free(sulfixo);
}

void lerCirc(FILE **arq,int *id,double *r,double *x,double *y,char **cor){

  fscanf(*arq," %d",id);
  fscanf(*arq," %lf",r);
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %s",*cor);

}

void lerRet(FILE **arq,int *id,double *w,double *h,double *x,double *y,char **cor){

  fscanf(*arq," %d",id);
  fscanf(*arq," %lf",w);
  fscanf(*arq," %lf",h);
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %s",*cor);
}

void lerQuadra(FILE **arq,double *x,double *y,double *w,double *h,char **cep){
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %lf",w);
  fscanf(*arq," %lf",h);
  fscanf(*arq," %s",*cep);
}

void lerHidrante(FILE **arq,double *x,double *y,char **id){
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %s",*id);
}

void lerSemaforo(FILE **arq,double *x,double *y,char **id){
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %s",*id);
}

void lerTorre(FILE **arq,double *x,double *y,char **id){
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
  fscanf(*arq," %s",*id);
}

void lerDist(FILE **arq,int *a,int *b){
  fscanf(*arq," %d",a);
  fscanf(*arq," %d",b);
}

void lerComandoI(FILE **arq,int *id,double *x,double *y){
  fscanf(*arq," %d",id);
  fscanf(*arq," %lf",x);
  fscanf(*arq," %lf",y);
}

void lerComandoO(FILE **arq,int *a,int *b){
  fscanf(*arq," %d",a);
  fscanf(*arq," %d",b);
}

void lerComandoHI(FILE **arq,char **id,double *vazao){
  fscanf(*arq," %s",*id);
  fscanf(*arq," %lf",vazao);
}

void lerComandoTI(FILE **arq,char **cep,double *raio){
  fscanf(*arq," %s",*cep);
  fscanf(*arq," %lf",raio);
}

void lerComandoSI(FILE **arq,char **cep,double *tempo){
  fscanf(*arq," %s",*cep);
  fscanf(*arq," %lf",tempo);
}

void lerComandoA(FILE **arq,char **sulfixo,char **cor){
  fscanf(*arq," %s",*sulfixo);
  fscanf(*arq," %s",*cor);
}

void escreveCirc(FILE **svg,Lista *list){
  Posic p;
  p = getFirst(list);

  while(p!=NULL){
    fprintf(*svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"%lf\" fill=\"%s\" />\n",getCirculoX(get(list,p)),getCirculoY(get(list,p)),getCirculoR(get(list,p)),getCirculoCor(get(list,p)));
    p = getNext(list,p);
  }
}

void escreveRet(FILE **svg,Lista *list){
  Posic p;
  p = getFirst(list);

  while (p!=NULL) {
    fprintf(*svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"%s\" />\n",getRetanguloX(get(list,p)),getRetanguloY(get(list,p)),getRetanguloW(get(list,p)),getRetanguloH(get(list,p)),getRetanguloCor(get(list,p)));
    p = getNext(list,p);
  }
}

void escreveSobrepos(FILE **svg,Lista *list){
  Posic p;
  p = getFirst(list);

  while (p != NULL) {
    fprintf(*svg, "<rect x=\"%lf\" y=\"%lf\" width=\"%lf\" height=\"%lf\" fill=\"none\" stroke-width=\"3.0\" stroke=\"black\" stroke-dasharray=\"7,5\"/>\n",getRetanguloX(get(list,p)),getRetanguloY(get(list,p)),getRetanguloW(get(list,p)),getRetanguloH(get(list,p)));
    fprintf(*svg, "<text x=\"%lf\" y=\"%lf\" fill=\"red\"> sobrepoe</text>\n",getRetanguloX(get(list,p)),getRetanguloY(get(list,p))+9.5);
    p = getNext(list,p);
  }
}

void escreveCircComandoA(FILE **svg,Lista *list,char **cor){
  Posic p;
  p = getFirst(list);

  while (p != NULL) {
    fprintf(*svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" />\n",getCirculoX(get(list,p)),getCirculoY(get(list,p)),*cor);
    p = getNext(list,p);
  }
}

void escreveRetComandoA(FILE **svg,Lista *list,char **cor){
  double w,h,x,y,xx,yy;
  Posic p;
  p = getFirst(list);


  while(p != NULL ){
    w = getRetanguloW(get(list,p));
    h = getRetanguloH(get(list,p));
    x = getRetanguloX(get(list,p));
    y = getRetanguloY(get(list,p));
    xx = x+w;
    yy = y+h;
    fprintf(*svg, "<circle cx=\"%lf\" cy =\"%lf\" r=\"5.0\" fill=\"%s\" />\n",x,y,*cor);
    fprintf(*svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" />\n",xx,y,*cor);
    fprintf(*svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" />\n",x,yy,*cor);
    fprintf(*svg, "<circle cx=\"%lf\" cy=\"%lf\" r=\"5.0\" fill=\"%s\" />\n",xx,yy,*cor);
    p = getNext(list,p);
  }
}

int procuraEquipPorID(Tree arv,char *cep,double vazao,PosicNo nohArv,setEquipamento setEquip,getIDEquip getID,int a){

  if(a == 1)
    return 1;

  if(leafNe(arv,nohArv) == 1){
    a = procuraEquipPorID(arv,cep,vazao,getNe(arv,nohArv),setEquip,getID,a);
  }

  if(leafNw(arv,nohArv) == 1){
    a = procuraEquipPorID(arv,cep,vazao,getNw(arv,nohArv),setEquip,getID,a);
  }

  if(leafSe(arv,nohArv) == 1){
    a = procuraEquipPorID(arv,cep,vazao,getSe(arv,nohArv),setEquip,getID,a);
  }

  if(leafSw(arv,nohArv) == 1){
    a = procuraEquipPorID(arv,cep,vazao,getSw(arv,nohArv),setEquip,getID,a);
  }
  if(strcmp(getID(getElement(arv,nohArv)),cep)==0){
    setEquip(getElement(arv,nohArv),vazao);
    a =  1;
  }
  return 0;
}

int adicionaOperadora(Tree arv,char *cep,char *op,PosicNo nohArv,setOp setEquip,getIDEquip getID,int a){
  if(a == 1)
    return 1;

  if(leafNe(arv,nohArv) == 1){
    a = adicionaOperadora(arv,cep,op,getNe(arv,nohArv),setEquip,getID,a);
  }

  if(leafNw(arv,nohArv) == 1){
    a = adicionaOperadora(arv,cep,op,getNw(arv,nohArv),setEquip,getID,a);
  }

  if(leafSe(arv,nohArv) == 1){
    a = adicionaOperadora(arv,cep,op,getSe(arv,nohArv),setEquip,getID,a);
  }

  if(leafSw(arv,nohArv) == 1){
    a = adicionaOperadora(arv,cep,op,getSw(arv,nohArv),setEquip,getID,a);
  }
  if(strcmp(getID(getElement(arv,nohArv)),cep)==0){
    setEquip(getElement(arv,nohArv),op);
    a =  1;
  }
  return 0;
}

int buscaInd(Lista *circ,Lista *retang,int id){
  Posic p;
  p = buscaCirculo(circ,id);
  if(p != NULL){
    return 1;
  }

  p = buscaRetangulo(retang,id);
  if(p!=NULL){
    return 2;
  }
  return 0;
}

Posic buscaCirculo(Lista *circ,int id){
  Posic p;
  p = getFirst(circ);

  while (p!=NULL) {
    if(getCirculoId(get(circ,p))== id){
      return p;
    }
    p = getNext(circ,p);
  }
  return p;
}

Posic buscaRetangulo(Lista *retang,int id){
  Posic p;
  p = getFirst(retang);

  while (p!=NULL) {
    if(getRetanguloId(get(retang,p))==id){
      return p;
    }
    p = getNext(retang,p);
  }
  return p;
}
