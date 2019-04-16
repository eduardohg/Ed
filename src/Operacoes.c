#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include <math.h>
#include "Circulo.h"
#include "Retangulo.h"
#include "Vetor.h"
#include "Operacoes.h"
#include "Lista.h"

int entrada(int argc,char **argv,char **caminho,char **dir,char **pasta,char **testes,char **ec,char **pm,char **tm,char **via,int *num,int *a,int *mat){
  int i,n1=0,n,n2,n3,logic=0;

  for(i=0;i<argc;i++){
    if(strcmp(argv[i],"-f")==0){
      n1 = strlen(argv[i+1]);
      *caminho = (char *)malloc((n1+1)*sizeof(char));
      strcpy(*caminho,argv[i+1]); /*Copia depois de -f para a string caminho*/
    }

    if(strcmp(argv[i],"-o")==0){
      n = strlen(argv[i+1]);
      *dir = (char *)malloc((n+2)*sizeof(char));
      strcpy(*dir,argv[i+1]);/*Copia depois de -o para a string dir*/
    }

    if(strcmp(argv[i],"-e")==0){
      n2 = strlen(argv[i+1]);
      *pasta = (char *)malloc((n2+2)*sizeof(char));
      strcpy(*pasta,argv[i+1]);
      logic = 1;
    }
    if(strcmp(argv[i],"-q")==0){
      n3 = strlen(argv[i+1]);
      *testes = (char *)malloc((n3+1)*sizeof(char));
      strcpy(*testes,argv[i+1]);
      *num = 1;
    }
    if(strcmp(argv[i],"-acc0")==0){
      *a = 1;
    }
    if(strcmp(argv[i],"-acc")==0){
      *a = 2;
    }
    if(strcmp(argv[i],"-id")==0){
      *mat = 1;
    }
    if(strcmp(argv[i],"-ec")==0){
      n = strlen(argv[i+1]);
      *ec = (char *)malloc((n+1)*sizeof(char));
      strcpy(*ec,argv[i+1]);
    }
    if(strcmp(argv[i],"-pm")==0){
      n = strlen(argv[i+1]);
      *pm = (char *)malloc((n+1)*sizeof(char));
      strcpy(*pm,argv[i+1]);
    }
    if(strcmp(argv[i],"-tm")==0){
      n = strlen(argv[i+1]);
      *tm = (char *)malloc((n+1)*sizeof(char));
      strcpy(*tm,argv[i+1]);
    }
    if(strcmp(argv[i],"-v")==0){
      n = strlen(argv[i+1]);
      *via = (char *)malloc((n+1)*sizeof(char));
      strcpy(*via,argv[i+1]);
    }
  }
  return logic;
}

char* criaExt(char *caminho,char *dir,int y,char *sul){
  int i=0,n,j=0,tam,tam2,tam3;
	char *result,*x;

  n = strlen(caminho);
	tam = strlen(dir);
  /*Se o path de saida não tem barra no final, coloca*/
  if(dir[tam-1]!='/'){
    dir[tam] = '/';
    dir[tam+1] = '\0';
  }
  /*Laço até encontrar a ultima barra no path do arquivo de entrada*/
	for(i=n;i>=0;i--){
    if(caminho[i]=='/'){
			j = i+1;
			break;
		}
	}
  /*Strig para armazenar somente o nome do arquivo*/
  result = (char *)malloc((n-i-4)*sizeof(char));

	i=0;
	for(j;j<n;j++){
    if(caminho[j]=='.'){
			result[i]='\0';
			i++;
			break;
		}
		result[i]=caminho[j];
		i++;
	}
  tam2 = strlen(result);
  tam = strlen(dir);
  /*Se o parametro recebido for y=1 cria string com final .svg se y=2 cria .txt */
  if(y==1 || y == 2){
	  x = (char *)malloc((tam2+tam+5)*sizeof(char));
    if(y==1){
      sprintf(x, "%s%s.svg",dir,result);
    }
    else{
      sprintf(x, "%s%s.txt",dir,result);
    }
  }
  /*Se não cria nome_arq-sulfixo.svg */
  else{
    tam3 = strlen(sul);
    x = (char *)malloc((tam+tam2+tam3+6)*sizeof(char));
    sprintf(x, "%s%s-%s.svg",dir,result,sul);
  }
  free(result);
	return x; /*retorna a string formatada */
}
char *criaArqTxtComQuery(char *dir,char *nome,char *qry){
  char *x;
  int tam1,tam2,tam3;
  tam1 = strlen(dir);
  tam2 = strlen(nome);
  tam3 = strlen(qry);
  if(dir[tam1-1]!='/'){
    dir[tam1] = '/';
    dir[tam1+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+tam3+6)*sizeof(char));
  sprintf(x, "%s%s-%s.txt",dir,nome,qry);

  return x;
}
char *criaArqTxtSemQuery(char *dir,char *nome){
  char *x;
  int tam1,tam2;
  tam1 = strlen(dir);
  tam2 = strlen(nome);
  if(dir[tam1-1]!='/'){
    dir[tam1] = '/';
    dir[tam1+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+5)*sizeof(char));
  sprintf(x, "%s%s.txt",dir,nome);

  return x;
}
char *criaArqSvgComQry(char *dir,char *nome,char *qry){
  char *x,*result;
  int tam1,tam2,tam3;
  tam1 = strlen(dir);
  tam2 = strlen(nome);
  tam3 = strlen(qry);
  /*Se o path de saida não tem barra no final, coloca*/
  if(dir[tam1-1]!='/'){
    dir[tam1] = '/';
    dir[tam1+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+tam3+7)*sizeof(char));
  sprintf(x, "%s%s-%s.svg",dir,nome,qry);

  return x;
}

char *criaArqSvgSemQry(char *dir,char *nome){
  char *x;
  int tam1,tam2;
  tam1 = strlen(dir);
  tam2 = strlen(nome);

  /*Se o path de saida não tem barra no final, coloca*/
  if(dir[tam1-1]!='/'){
    dir[tam1] = '/';
    dir[tam1+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+6)*sizeof(char));
  sprintf(x, "%s%s.svg",dir,nome);

  return x;
}

char *criaArqSvgComSulfixoPoligono(char *dir,char *geo,char *qry,char *sulfixo){
  char *x;
  int tam1=0,tam2=0,tam3=0,tam4=0;
  tam4 = strlen(dir);
  tam1 = strlen(geo);
  tam2 = strlen(qry);
  tam3 = strlen(sulfixo);

  if(dir[tam4-1]!='/'){
    dir[tam4] = '/';
    dir[tam4+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+tam3+tam4+8)*sizeof(char));
  sprintf(x,"%s%s-%s-%s.svg",dir,geo,qry,sulfixo);

  return x;
}

char *criaArqTxtComSufixo(char *dir,char *geo,char *qry,char *sufixo){
  char *x;
  int tam1=0,tam2=0,tam3=0,tam4=0;
  tam4 = strlen(dir);
  tam1 = strlen(geo);
  tam2 = strlen(qry);
  tam3 = strlen(sufixo);

  if(dir[tam4-1]!='/'){
    dir[tam4] = '/';
    dir[tam4+1] = '\0';
  }
  x = (char *)malloc((tam1+tam2+tam3+tam4+8)*sizeof(char));
  sprintf(x,"%s%s-%s-%s.txt",dir,geo,qry,sufixo);

  return x;
}

char* retornaEntrada(char *pasta,char *nome){
  int tam,tam2;
  char *result;


  tam = strlen(pasta);
  tam2 = strlen(nome);
  if(pasta[tam-1]!='/'){
    pasta[tam] = '/';
    pasta[tam+1] = '\0';
  }
  result = (char *)malloc((tam+tam2+2)*sizeof(char));
  sprintf(result, "%s%s",pasta,nome);
  return result;
}

char *somenteNomeArq(char *qry){
  int j,i,n,tam,tam2,tam3;
  char *result;
  n = strlen(qry);
  j=0;
  for(i=n;i>=0;i--){
    if(qry[i]=='/'){
      j = i+1;
      break;
    }
  }

  /*Strig para armazenar somente o nome do arquivo*/
  result = (char *)malloc((n-i-4)*sizeof(char));

  i=0;
  for(j;j<n;j++){
    if(qry[j]=='.'){
      result[i]='\0';
      i++;
      break;
    }
    result[i]=qry[j];
    i++;
  }

  return result;
}

char* criaResumo(char *dir){
  int tam;
  char *result;
  tam = strlen(dir);
  result = (char *)malloc((tam+11)*sizeof(char));
  sprintf(result, "%sresumo.txt",dir);
  return result;


}

double calculaDistancia(Lista *circ,Lista *retang,int a,int b,int type1,int type2){
  Posic p;
  double x1,y1,x2,y2,d;

  /*Se id 'a' for um circulo*/
  if(type1 == 1){
    p = retornaIdCirc(circ,p,a);
    x1 = getCirculoX(get(circ,p));
    y1 = getCirculoY(get(circ,p));
  }
  /*Se id 'a' for um retangulo*/
  else{
    p = retornaIdRet(retang,p,a);
    x1 = getRetanguloX(get(retang,p));
    y1 = getRetanguloY(get(retang,p));
    x1 = x1+(getRetanguloW(get(retang,p))/2);
    y1 = y1+(getRetanguloH(get(retang,p))/2);
  }
  /*Se id 'b' for um circulo*/
  if(type2 == 1){
    p = retornaIdCirc(circ,p,b);
    x2 = getCirculoX(get(circ,p));
    y2 = getCirculoY(get(circ,p));
  }
  /*Se id 'b' for um retangulo*/
  else{
    p = retornaIdRet(retang,p,b);
    x2 = getRetanguloX(get(retang,p));
    y2 = getRetanguloY(get(retang,p));
    x2 = x2+(getRetanguloW(get(retang,p))/2);
    y2 = y2+(getRetanguloH(get(retang,p))/2);
  }
  d = sqrt(pow((x1-x2),2)+pow((y1-y2),2));/*Calcula a distancia entre as figuras*/
  return d;
}

int verificaPonto(Lista *circ,Lista *retang,int id,int px,int py,int type){
  Posic p;
  double x,y,r,result,tx,ty,h,w;

  /*Se figura for um circulo*/
  if(type == 1){
    p = retornaIdCirc(circ,p,id);
    r = getCirculoR(get(circ,p));
    x = getCirculoX(get(circ,p));
    y = getCirculoY(get(circ,p));
    result = ((x-px)*(x-px)) + ((y-py)*(y-py));
    if(result>(r*r)){
      return 0;/*Ponto é externo a figura*/
    }
    else if(result==(r*r)){
      return 2;/*Ponto está na borda(externo)*/
    }
    else{
      return 1;/*Ponto é interno a figura*/
    }
  }
  /*Se figura for um retangulo*/
  else if(type == 2){
    p = retornaIdRet(retang,p,id);
    x = getRetanguloX(get(retang,p));
    y = getRetanguloY(get(retang,p));
    h = getRetanguloH(get(retang,p));
    w = getRetanguloW(get(retang,p));
    tx = x+w;
    ty = y+h;
    if(px>x && px<tx && py>y && py<ty){
      return 1;/*Ponto é interno a figura*/
    }
    else if(px>=x && px<=tx && py>=y && py<=ty){
        return 2;/*Ponto na borda*/
    }
    else{
      return 0;/*Ponto é externo a figura*/
    }
  }
}

int calculaSobreposicao(Lista *circ,Lista *retang,Lista *sobrepos,int a,int b,int type1,int type2,int id){
  Posic p,pos;
  double x1=0,y1=0,x2=0,y2=0,h1=0,h2=0,w1=0,w2=0,d=0,r=0,r2=0,r1=0,xa=0,ya=0,ht=0;
  Retangulo *pontilhado;


  /*Se as duas figuras forem circulos*/
  if(type1 == 1 && type2 == 1){
    d = calculaDistancia(circ,retang,a,b,type1,type2);
    p = retornaIdCirc(circ,p,a);/*Pega nó de indice a*/
    r = getCirculoR(get(circ,p));
    pos = retornaIdCirc(circ,pos,b);/*Pega nó de indice b*/
    r = r+getCirculoR(get(circ,pos));
    if(d<r){

      r1 = getCirculoR(get(circ,p));
      r2 = getCirculoR(get(circ,pos));
      x1 = getCirculoX(get(circ,p));
      x2 = getCirculoX(get(circ,pos));
      y1 = getCirculoY(get(circ,p));
      y2 = getCirculoY(get(circ,pos));

      xa = (x2-r2<=x1-r1)?(x2-r2):(x1-r1);
      ya = (y1-r1<=y2-r2)?(y1-r1):(y2-r2);
      w1 = (x1+r1>=x2+r2)?(x1+r1):(x2+r2);
      w2 = w1-xa;
      h1 = (y1+r1>=y2+r2)?(y1+r1):(y2+r2);
      h2 = h1-ya;

      id++;
      pontilhado = criarRetangulo(id,w2,h2,xa,ya,"black");
      p = insert(sobrepos,pontilhado);

      return 1;/*As formas estão sobrepostas*/
    }
    else
      return 0;/*Não estão sobrepostas*/
  }
  /*Se as duas figuras forem retangulos*/
  else if(type1 == 2 && type2 == 2){
    printf("Sobreposição\n");
    p = retornaIdRet(retang,p,a);
    pos = retornaIdRet(retang,pos,b);
    x1 = getRetanguloX(get(retang,p));
    y1 = getRetanguloY(get(retang,p));
    h1 = getRetanguloH(get(retang,p));
    w1 = getRetanguloW(get(retang,p));
    x2 = getRetanguloX(get(retang,pos));
    y2 = getRetanguloY(get(retang,pos));
    h2 = getRetanguloH(get(retang,pos));
    w2 = getRetanguloW(get(retang,pos));

    if(x1+w1>=x2 && x2+w2>=x1 && y1+h1>=y2 && y2+h2>=y1){


      xa = (x1<x2)?(x1):(x2);
      ya = (y1<y2)?(y1):(y2);
      w2 = (x1+w1>x2+w2)?(x1+w1):(x2+w2);
      w2 = w2-xa;
      h2 = (y1+h1>y2+h2)?(y1+h1):(y2+h2);
      h2 = h2-ya;

      id++;
      pontilhado = criarRetangulo(id,w2,h2,xa,ya,"black");
      p = insert(sobrepos,pontilhado);
      return 1;/*retorna verdadeiro*/
    }
    else
      return 0;/*retorna falso*/
  }
  else{
    /*Se a o id 'a' for um circulo*/
    if(type1 == 1){
      p = retornaIdCirc(circ,p,a);
      pos = retornaIdRet(retang,pos,b);
      x1 = getCirculoX(get(circ,p));
      y1 = getCirculoY(get(circ,p));
      r = getCirculoR(get(circ,p));
      x2 = getRetanguloX(get(retang,pos));
      y2 = getRetanguloY(get(retang,pos));
      h2 = getRetanguloH(get(retang,pos));
      w2 = getRetanguloW(get(retang,pos));

      /*Calculos para escrever posteriormente o retangulo pontilhado da sobreposição*/
      xa = (x1-r<x2)?(x1-r):(x2);
      ya = (y1-r<y2)?(y1-r):(y2);
      w1 = (x1+r>x2+w2)?(x1+r):(x2+w2);
      w1 = w1-xa;
      ht = (y1+r>y2+h2)?(y1+r):(y2+h2);
      ht -= ya;

      /*Verifica se o centro de massa do circulo está dentro do retangulo*/
      if(verificaPonto(circ,retang,b,x1,y1,type2) != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      /*Se circulo estiver em cima e no meio do retangulo*/
      if(x2<x1 && x1<(x2+w2)){
        if(y1<y2){
          h1 = y1+r;
          if(verificaPonto(circ,retang,b,x1,h1,type2) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver em baixo e no meio do retangulo*/
      if(x2<x1 && x1<(x2+w2)){
        if(y1>(y2+h2)){
          h1 = y1-r;
          if(verificaPonto(circ,retang,b,x1,h1,type2) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver do lado esquerdo do retangulo e entrando no mesmo*/
      if(x1<x2){
        if(y2<y1 && y1<y2+h2){
          h1 = x1+r;
          if(verificaPonto(circ,retang,b,h1,y1,type2) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver do lado direito do retangulo e com um pedaço dentro do mesmo*/
      if(x1>(x2+w2)){
        if(y2<y1 && y1<y2+h2){
          h1 = x1-r;
          if(verificaPonto(circ,retang,b,h1,y1,type2) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver tocando algum dos quatro vértices do retangulo*/
      h1 = verificaPonto(circ,retang,a,x2,y2,type1);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,a,x2,(y2+h2),type1);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,a,(x2+w2),y2,type1);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,a,(x2+w2),(y2+h2),type1);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
    }
    else{
      /*Se o id 'a' for um retangulo */
      p = retornaIdRet(retang,p,a);
      pos = retornaIdCirc(circ,pos,b);
      x1 = getCirculoX(get(circ,pos));
      y1 = getCirculoY(get(circ,pos));
      r = getCirculoR(get(circ,pos));
      x2 = getRetanguloX(get(retang,p));
      y2 = getRetanguloY(get(retang,p));
      h2 = getRetanguloH(get(retang,p));
      w2 = getRetanguloW(get(retang,p));

      /*Calculos para escrever posteriormente o retangulo pontilhado da sobreposição*/
      xa = (x1-r<x2)?(x1-r):(x2);
      ya = (y1-r<y2)?(y1-r):(y2);
      w1 = (x1+r>x2+w2)?(x1+r):(x2+w2);
      w1 = w1-xa;
      ht = (y1+r>y2+h2)?(y1+r):(y2+h2);
      ht -= ya;

      /*Verifica se o centro de massa do circulo está dentro do retangulo*/
      if(verificaPonto(circ,retang,a,x1,y1,type1) != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }

      /*Se circulo estiver em cima do retangulo e no meio do mesmo*/
      if(x2<x1 && x1<(x2+w2)){
        if(y1<y2){
          h1 = y1+r;
          if(verificaPonto(circ,retang,a,x1,h1,type1) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver em baixo do retangulo e no meio do mesmo*/
      if(x2<x1 && x1<(x2+w2)){
        if(y1>(y2+h2)){
          h1 = y1-r;
          if(verificaPonto(circ,retang,a,x1,h1,type1) != 0){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver do lado esquerdo do retangulo e uma parte tocar o mesmo*/
      if(x1<x2){
        if(y2<y1 && y1<(y2+h2)){
          h1 = x1+r;
          if(verificaPonto(circ,retang,a,h1,y1,type1) != 1){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Se circulo estiver do lado direito do retangulo e uma parte tocar o mesmo*/
      if(x1>(x2+w2)){
        if(y2<y1 && y1<y2+h2){
          h1 = x1-r;
          if(verificaPonto(circ,retang,a,h1,y1,type1) != 1){
            id++;
            pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
            p = insert(sobrepos,pontilhado);
            return 1;
          }
        }
      }
      /*Verifica se o circulo está tocando algum dos quatro vértices do retangulo*/
      h1 = verificaPonto(circ,retang,b,x2,y2,type2);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,b,x2,(y2+h2),type2);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,b,(x2+w2),y2,type2);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
      h1 = verificaPonto(circ,retang,b,(x2+w2),(y2+h2),type2);
      if(h1 != 0){
        id++;
        pontilhado = criarRetangulo(id,w1,ht,xa,ya,"black");
        p = insert(sobrepos,pontilhado);
        return 1;
      }
    }
  }
}

Posic retornaIdCirc(Lista *circ,Posic p,int id){
  p = getFirst(circ);
  while(p != NULL){
    if(getCirculoId(get(circ,p))==id){
      return p;
    }
    p = getNext(circ,p);
  }
}

Posic retornaIdRet(Lista *retang,Posic p,int id){
  p = getFirst(retang);
  while(p != NULL){
    if(getRetanguloId(get(retang,p))==id){
      return p;
      break;
    }
    p = getNext(retang,p);
  }
}

Cidade converterTrees(Cidade c){
  Cidade city;

  city = criaCidade();

  converteQuadra(c,city);

  converteTorre(c,city);

  converteHidrante(c,city);

  converteSemaforo(c,city);

  return city;
}

void converteQuadra(Cidade c,Cidade city){
  Pilha heap,resto;
  PosicNo n;
  PosicPilha p;
  Vetor q;
  ItemPilha info;
  int tam=0,i;
  /*Pegando primeira quadra da treeQuadra*/
  n = getFirstElementTree(getQuadra(c));
  if(n != NULL){
    /*Primeira envoltoria sendo calculada*/
    q = criaVetor(sizeTree(getQuadra(c)));
    /*Converte Tree p/ vetor para calcular envoltoria*/
    convertTreeToVector(q,getQuadra(c),n,getQuadraX,getQuadraY,0);
    /*Inicio dos calculos*/
    q = PrimeiroPasso(q,comparaY,coordPolarQuadra,comparaAng);
    heap = inicializacao();
    resto = inicializacao();
    heap = calculaEnvoltoria(q,orientacaoQuadra,heap,resto);

    /*Enquanto pilha de resto for maior que 3 continua empilhando na pilha final*/
    while(tamanhoPilha(resto)>=3){
      q = converterPilhaParaVetor(resto,getQuadraX,getQuadraY,1);
      q = PrimeiroPasso(q,comparaY,coordPolarQuadra,comparaAng);
      resto = inicializacao();
      heap = calculaEnvoltoria(q,orientacaoQuadra,heap,resto);
    }
    /*Se a pilha de resto n estiver vazia*/
    tam = tamanhoPilha(resto);
    for(i=0;i<tam;i++){
      info = pop(resto);
      empilhar(heap,info);
    }

    /*Inserindo na Arvore novamente*/
    p = getTopoPilha(heap);
    for(i=0;i<tamanhoPilha(heap);i++){
      insereQuadra(city,getElementPilha(heap,p),getQuadraX(getElementPilha(heap,p)),getQuadraY(getElementPilha(heap,p)));
      p = getAnterior(heap,p);
    }
    tam = tamanhoPilha(heap);
    for(i=0;i<tam;i++){
      info = pop(heap);
    }
  }
  free(resto);
}

void converteTorre(Cidade c,Cidade city){
  int i,tam=0;
  Pilha heap,resto;
  PosicNo n;
  PosicPilha p;
  Vetor t;
  ItemPilha info;

  n = getFirstElementTree(getTorre(c));
  if(n != NULL){
    t = criaVetor(sizeTree(getTorre(c)));
    convertTreeToVector(t,getTorre(c),n,getTorreX,getTorreY,0);
    t = PrimeiroPasso(t,comparaY,coordPolarTorre,comparaAng);
    heap = inicializacao();
    resto = inicializacao();
    heap = calculaEnvoltoria(t,orientacaoTorre,heap,resto);
    while(tamanhoPilha(resto)>=3){
      t = converterPilhaParaVetor(resto,getTorreX,getTorreY,1);
      t = PrimeiroPasso(t,comparaY,coordPolarTorre,comparaAng);
      resto = inicializacao();
      heap = calculaEnvoltoria(t,orientacaoTorre,heap,resto);
    }
    /*Se a pilha de resto n estiver vazia*/
    tam = tamanhoPilha(resto);
    for(i=0;i<tam;i++){
      info = pop(resto);
      empilhar(heap,info);
    }

    p = getTopoPilha(heap);
    for(i=0;i<tamanhoPilha(heap);i++){
      insereTorre(city,getElementPilha(heap,p),getTorreX(getElementPilha(heap,p)),getTorreY(getElementPilha(heap,p)));
      p = getAnterior(heap,p);
    }
    tam = tamanhoPilha(heap);
    for(i=0;i<tam;i++){
      info = pop(heap);
    }
  }
  free(resto);
}

void converteHidrante(Cidade c,Cidade city){
  int i,tam=0;
  Pilha heap,resto;
  PosicNo n;
  PosicPilha p;
  Vetor h;
  ItemPilha info;

  n = getFirstElementTree(getHidrante(c));
  if(n != NULL){
    h = criaVetor(sizeTree(getHidrante(c)));
    convertTreeToVector(h,getHidrante(c),n,getHidranteX,getHidranteY,0);
    h = PrimeiroPasso(h,comparaY,coordPolarHidrante,comparaAng);
    heap = inicializacao();
    resto = inicializacao();
    heap = calculaEnvoltoria(h,orientacaoHidrante,heap,resto);
    while(tamanhoPilha(resto)>=3){
      h = converterPilhaParaVetor(resto,getHidranteX,getHidranteY,1);
      h = PrimeiroPasso(h,comparaY,coordPolarHidrante,comparaAng);
      resto = inicializacao();
      heap = calculaEnvoltoria(h,orientacaoHidrante,heap,resto);
    }
    /*Se a pilha de resto n estiver vazia*/
    tam = tamanhoPilha(resto);
    for(i=0;i<tam;i++){
      info = pop(resto);
      empilhar(heap,info);
    }

    p = getTopoPilha(heap);
    for(i=0;i<tamanhoPilha(heap);i++){
      insereHidrante(city,getElementPilha(heap,p),getHidranteX(getElementPilha(heap,p)),getHidranteY(getElementPilha(heap,p)));
      p = getAnterior(heap,p);
    }
    tam = tamanhoPilha(heap);
    for(i=0;i<tam;i++){
      info = pop(heap);
    }
  }
  free(resto);
}

void converteSemaforo(Cidade c,Cidade city){
  int i,tam=0;
  Pilha heap,resto;
  PosicNo n;
  PosicPilha p;
  Vetor s;
  ItemPilha info;

  n = getFirstElementTree(getSemaforo(c));
  if(n != NULL){
    s = criaVetor(sizeTree(getSemaforo(c)));
    convertTreeToVector(s,getSemaforo(c),n,getSemaforoX,getSemaforoY,0);
    s = PrimeiroPasso(s,comparaY,coordPolarSemaforo,comparaAng);
    heap = inicializacao();
    resto = inicializacao();
    heap = calculaEnvoltoria(s,orientacaoSemaforo,heap,resto);
    while(tamanhoPilha(resto)>=3){
      s = converterPilhaParaVetor(resto,getSemaforoX,getSemaforoY,1);
      s = PrimeiroPasso(s,comparaY,coordPolarSemaforo,comparaAng);
      resto = inicializacao();
      heap = calculaEnvoltoria(s,orientacaoSemaforo,heap,resto);
    }
    /*Se a pilha de resto n estiver vazia*/
    tam = tamanhoPilha(resto);
    for(i=0;i<tam;i++){
      info = pop(resto);
      empilhar(heap,info);
    }

    p = getTopoPilha(heap);
    for(i=0;i<tamanhoPilha(heap);i++){
      insereSemaforo(city,getElementPilha(heap,p),getSemaforoX(getElementPilha(heap,p)),getSemaforoY(getElementPilha(heap,p)));
      p = getAnterior(heap,p);
    }
    tam = tamanhoPilha(heap);
    for(i=0;i<tam;i++){
      info = pop(heap);
    }
  }
  free(resto);
}

int convertTreeToVector(Vetor v,Tree arv,PosicNo nohArv,getCoordenada getCoordX,getCoordenada getCoordY,int i){

  if(leafNe(arv,nohArv) == 1){
    i = convertTreeToVector(v,arv,getNe(arv,nohArv),getCoordX,getCoordY,i);
  }

  if(leafNw(arv,nohArv) == 1){
    i = convertTreeToVector(v,arv,getNw(arv,nohArv),getCoordX,getCoordY,i);
  }

  if(leafSe(arv,nohArv) == 1){
    i = convertTreeToVector(v,arv,getSe(arv,nohArv),getCoordX,getCoordY,i);
  }

  if(leafSw(arv,nohArv) == 1){
    i = convertTreeToVector(v,arv,getSw(arv,nohArv),getCoordX,getCoordY,i);
  }

  addElemento(v,i,getElement(arv,nohArv),getCoordX(getElement(arv,nohArv)),getCoordY(getElement(arv,nohArv)));
  i++;

  return i;
}

Lista buscarPontosPoligono(Lista l,Lista l2,double x,double y,double larg,double alt){
  Posic p;
  int i;
  double xx=0,yy=0,xl=0,ya=0;
  p = getFirst(l);
  xl = x+larg;
  ya = y+alt;

  for(i=0;i<length(l);i++){
    xx = getTorreX(get(l,p));
    yy = getTorreY(get(l,p));
    if(yy >= y && yy <= ya){
      if(xx >= x && xx <= xl){
        insert(l2,get(l,p));
      }
    }
    p = getNext(l,p);
  }
  return l2;
}

Vetor convertListToVector(Lista *list,Vetor v){
  int i,size;
  Posic p;

  size = length(list);
  p = getFirst(list);
  for(i=0;i<size;i++){
    addElemento(v,i,get(list,p),getTorreX(get(list,p)),getTorreY(get(list,p)));
    p = getNext(list,p);
  }
  return v;
}

Lista converterTreeToList(Lista l,Tree arv,PosicNo nohArv){

  if(leafNe(arv,nohArv) == 1){
    l = converterTreeToList(l,arv,getNe(arv,nohArv));
  }

  if(leafNw(arv,nohArv) == 1){
    l = converterTreeToList(l,arv,getNw(arv,nohArv));
  }

  if(leafSe(arv,nohArv) == 1){
    l = converterTreeToList(l,arv,getSe(arv,nohArv));
  }

  if(leafSw(arv,nohArv) == 1){
    l = converterTreeToList(l,arv,getSw(arv,nohArv));
  }

  insert(l,getElement(arv,nohArv));
  return l;
}

Vetor converterPilhaParaVetor(Pilha monte,getCoordenada getCoordX,getCoordenada getCoordY,int pts){
  Vetor vet;
  PosicPilha *p;
  int tamanhoP,i;

  p = getTopoPilha(monte);
  tamanhoP = tamanhoPilha(monte);
  vet = criaVetor(tamanhoP*pts);

  for(i=0;i<tamanhoP;i++){
    addElemento(vet,i,getElementPilha(monte,p),getCoordX(getElementPilha(monte,p)),getCoordY(getElementPilha(monte,p)));
    p = getAnterior(monte,p);
  }
  return vet;
}

Lista converterPilhaParaLista(Pilha monte){
  Lista list;
  PosicPilha *p;
  int tamanhoP,i;
  list = createList();
  p = getTopoPilha(monte);
  tamanhoP = tamanhoPilha(monte);
  for(i=0;i<tamanhoP;i++){
    insert(list,getElementPilha(monte,p));
    p = getAnterior(monte,p);
  }
  return list;
}
