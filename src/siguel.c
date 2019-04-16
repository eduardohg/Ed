#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "Cidade.h"
#include "Lista.h"
#include "Torre.h"
#include "Quadra.h"
#include "Hidrante.h"
#include "Semaforo.h"
#include "Retangulo.h"
#include "Circulo.h"
#include "ArqSvg.h"
#include "ArqQry.h"
#include "Operacoes.h"
#include "Pilha.h"
#include "EnvoltorioConvexo.h"
#include "ArqTm.h"
#include "ArqPm.h"
#include "ArqEc.h"
#include "ArqVia.h"
#include "Procedimentos.h"

int main(int argc,char *argv[]){
  /*Cidades*/
  Cidade cid,cid2;
  /*Lista para circulos*/
  Lista circ;
  /*Lista para retangulos*/
  Lista retang;
  /*Lista para as sobreposições*/
  Lista sobrepos;
  /*Posic*/
  Posic p,pr,ps;
  Vetor v;
  Dicionario dic;
  Grafo grafo;

  char *nome,*dir,*str,*pasta,*testes,*cor,*aux,*aux1,*ec = NULL,*pm = NULL,*tm = NULL,*via = NULL;
  double maxx=0,maxy=0;
  int n=0,num,tam,var,logic=0,ids=0,k=0,ins=0,del=0,mat=0;
  FILE *arq,*svg,*txt;
  /*Alocando String cor*/
  cor = (char *)malloc(50*sizeof(char));
  dic = generateDictionary();
  /*Recebe os parâmetros de entrada na hora da execução*/
  var = entrada(argc,argv,&nome,&dir,&pasta,&testes,&ec,&pm,&tm,&via,&n,&k,&mat);


  /*Se voltar 1 quer dizer que encontrou comando -e */
  if(var == 1){
    str = retornaEntrada(pasta,nome);
  }
  else{
    /*Senão str recebe o próprio nome do arquivo*/
    tam = strlen(nome);
    str = (char *)malloc((tam+1)*sizeof(char));
    strcpy(str,nome);
  }

  /*Abre o arquivo de entrada*/
  arq = fopen(str,"rt");
  free(str);
  if(arq == NULL){
    printf("Problemas para abrir o arquivo\n");
    return 0;
  }
  /*Abrindo arquivo.svg*/
  nome = somenteNomeArq(nome);

  /*Se tiver parâmetro -q */
  if(n == 1){
    aux = (char *)malloc(100*sizeof(char));
    aux = somenteNomeArq(testes);
    str = criaArqSvgComQry(dir,nome,aux);
  }
  /*Senão*/
  else{
    str = criaArqSvgSemQry(dir,nome);
  }
  /*Abre Arquivo Svg*/
  svg = fopen(str,"w");
  free(str);
  if(svg == NULL){
    printf("Problemas para criar o arquivo SVG!\n");
  }

  /*Abrindo arquivo.txt*/
  if(n == 1){
    str = criaArqTxtComQuery(dir,nome,aux);
  }
  else{
    str = criaArqTxtSemQuery(dir,nome);
  }

  txt = fopen(str,"w");

  /*Criando cidade*/
  cid = criaCidade();

  /*Criando listas de circulos,retangulos e sobreposições*/
  circ = createList();
  retang = createList();
  sobrepos = createList();
  free(str);

  /*Vai para o menu do arquivo.geo (função em ArqSvg.h)*/
  /*A inserção dos equipamentos urbanos é inserida na cidade em quadtree, porém não passa pelo convexHull ainda*/
  menu(cid,circ,retang,sobrepos,&arq,&svg,&txt,&maxx,&maxy,&str,&nome,&dir,&cor,&ins,&logic);

  /*A cidade 'cid' vai ser passada pelo convexHull e volta a ser inserida na cidade 'cid2'*/
  cid2 = converterTrees(cid);
  insereQuadrasHash(dic,cid2);

  if(pm != NULL){
    FILE *ArqPm;
    if(var == 1){
      str = retornaEntrada(pasta,pm);
    }
    else{
      str = (char *)malloc(300*sizeof(char));
      strcpy(str,pm);
    }
    ArqPm = fopen(str,"rt");
    free(str);
    menuPm(&ArqPm,dic);
  }
  if(ec != NULL){
    FILE *ArqEc;
    if(var == 1)
      str = retornaEntrada(pasta,ec);
    else{
      str = (char *)malloc(300*sizeof(char));
      strcpy(str,ec);
    }
    ArqEc = fopen(str,"rt");
    free(str);
    menuEc(&ArqEc,dic);
  }

  if(tm != NULL){
    FILE *ArqTm;
    if(var == 1)
      str = retornaEntrada(pasta,tm);
    else{
      str = (char *)malloc(300*sizeof(char));
      strcpy(str,tm);
    }
    ArqTm = fopen(str,"rt");
    free(str);
    menuTm(&ArqTm,dic);

  }
  if(via != NULL){
    FILE *ArqVia;
    int contador;
    if(var == 1)
      str = retornaEntrada(pasta,via);
    else{
      str = (char *)malloc(300*sizeof(char));
      strcpy(str,via);
    }
    ArqVia = fopen(str,"rt");
    contador = menuVia(&ArqVia,grafo,'n');
    fclose(ArqVia);
    grafo = criarGrafo(contador);
    ArqVia = fopen(str,"rt");
    menuVia(&ArqVia,grafo,'t');
    fclose(ArqVia);
  }

  /*Se tiver Arquivo qry*/
  if(n == 1){
    FILE *qry,*resum;

    /*Se existir comando -e*/
    if(var == 1){
      str = retornaEntrada(pasta,testes);
    }
    else{
      str = (char *)malloc(300*sizeof(char));
      strcpy(str,testes);
    }
    /*Abre o arquivo.qry*/
    qry = fopen(str,"rt");
    free(str);
    if(qry == NULL){
      printf("Problemas para abrir o arquivo\n");
    }

    /*Vai para o menu do arquivo.qry (função em ArqQry.h)*/
    menuQry(cid2,dic,circ,retang,sobrepos,&arq,&txt,&qry,&resum,&str,&testes,&aux,&pasta,&dir,&nome,&cor,&k,&var,ins,grafo);
    fclose(qry);
    free(aux);
    fclose(resum);

  }

  /*Printa todas as listas no arquivo.svg*/
  fprintf(svg, "<svg viewBox=\"0 0 %f %f\" version=\"1.1\" xmlns=\"http://www.w3.org/2000/svg\">\n",maxx+100,maxy+100);

  escreveCirc(&svg,circ);
  escreveRet(&svg,retang);
  /*Escreve no Arquivo de saida svg os equipamentos urbanos*/
  processarTree(cid2,getQuadra(cid2),getFirstElementTree(getQuadra(cid2)),escreveQuadra,&svg);
  processarTree(cid2,getHidrante(cid2),getFirstElementTree(getHidrante(cid2)),escreveHidrante,&svg);
  processarTree(cid2,getTorre(cid2),getFirstElementTree(getTorre(cid2)),escreveTorre,&svg);
  processarTree(cid2,getSemaforo(cid2),getFirstElementTree(getSemaforo(cid2)),escreveSemaforo,&svg);
  if(logic == 1){
    escreveSobrepos(&svg,sobrepos);

  }
  fprintf(svg, "</svg>\n");

  /*Desalocando variiáveis*/
  free(nome);
  free(cor);
  free(dir);
  if(var == 1){
    free(pasta);
  }
  fclose(svg);
  fclose(txt);
  /*
  fclose(ArqTm);
  fclose(ArqEc);
  fclose(ArqPm);
*/




  /*Desalocando listas - Sobreposição*/
  ps = getFirst(sobrepos);

  while(ps != NULL) {
    liberaRetangulo(get(sobrepos,ps));
    p = getNext(sobrepos,ps);
    remover(sobrepos,ps);

    ps = p;
  }

  /*Desalocando listas - Circulo*/
  p = getFirst(circ);

	while(p != NULL) {
		liberaCirculo(get(circ,p));
		pr = getNext(circ,p);
		remover(circ,p);

		p = pr;
	}

  /*Desalocando listas - Retangulo*/
	pr = getFirst(retang);

	/* ARRUMAR */
 	while(pr != NULL) {
		liberaRetangulo(get(retang,pr));
		p = getNext(retang,pr);
		remover(retang,pr);

		pr = p;
	}
  /*Desalocando...*/
  free(circ);
  free(retang);
  free(sobrepos);

  /*Se o parâmetro -id foi encontrado*/
  if(mat == 1){
    printf("Eduardo Henrique Giroto - 201600560035\n");
  }
  printf("Programa executado com Sucesso!\n");

	return 0;
}
