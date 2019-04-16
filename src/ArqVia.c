#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ArqVia.h"

int menuVia(FILE **via, Grafo grafo, char boolean) {
  char comando;
  int cont=0;

  while (!feof(*via)) {
    fscanf(*via, "%c", &comando);
    if(feof(*via)){
      break;
    }
    if(comando == 'v'){
      comandoV(via,grafo,boolean);
      cont++;
    }
    else if(comando == 'e'){
      comandoE(via,grafo,boolean);
    }
  }

  return cont;
}

void comandoV(FILE **via, Grafo grafo, char boolean) {
  Vertice vertice;
  char *pId, *id;
  double x, y;

  pId = (char *) malloc(1000*sizeof(char));

  fscanf(*via, " %s %lf %lf ", pId, &x, &y);

  if (boolean == 't') {
    id = (char *) malloc((strlen(pId)+1)*sizeof(char));
    strcpy(id, pId);

    vertice = criarVertice(id, x, y);
    insereVertice(grafo, vertice);

    free(id);
  }

  free(pId);
}

void comandoE(FILE **via, Grafo grafo, char boolean) {
  Vertice vertice1, vertice2;
  Aresta aresta;
  char *pV1, *pV2, *pLdir, *pLesq, *pNome, *v1, *v2, *ldir, *lesq, *nome;
  double cmp, vm;

  pV1 = (char *) malloc(1000*sizeof(char));
  pV2 = (char *) malloc(1000*sizeof(char));
  pLdir = (char *) malloc(1000*sizeof(char));
  pLesq = (char *) malloc(1000*sizeof(char));
  pNome = (char *) malloc(1000*sizeof(char));

  fscanf(*via, " %s %s %s %s %lf %lf %s", pV1, pV2, pLdir, pLesq, &cmp, &vm, pNome);

  if (boolean == 't'){

    v1 = (char *) malloc((strlen(pV1)+1)*sizeof(char));
    strcpy(v1, pV1);

    v2 = (char *) malloc((strlen(pV2)+1)*sizeof(char));
    strcpy(v2, pV2);

    ldir = (char *) malloc((strlen(pLdir)+1)*sizeof(char));
    strcpy(ldir, pLdir);

    lesq = (char *) malloc((strlen(pLesq)+1)*sizeof(char));
    strcpy(lesq, pLesq);

    nome = (char *) malloc((strlen(pNome)+1)*sizeof(char));
    strcpy(nome, pNome);

    aresta = criarAresta(nome, ldir, lesq, cmp, vm);
    vertice1 = getVertice(grafo, v1);
    vertice2 = getVertice(grafo, v2);
    insereAresta(grafo, aresta, vertice1, vertice2);

    free(v1);
    free(v2);
    free(ldir);
    free(lesq);
    free(nome);
  }

  free(pV1);
  free(pV2);
  free(pLdir);
  free(pLesq);
  free(pNome);
}
