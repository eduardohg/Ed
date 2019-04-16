#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "Rota.h"

void representacaoPictorica(Cidade cid,Dicionario dic,Grafo grafo,Vertice origem,Vertice destino,char peso,char *nomeSvg,char *cor){
	FILE *arq;
	Pilha p;

	arq = fopen(nomeSvg,"w");
	if (arq != NULL) {
		p = menorCaminho(grafo,origem,destino,peso);
		fazerRota(&arq,cid,grafo,dic,p,cor);
	}

	fclose(arq);
}

void fazerRota(FILE **arq,Cidade cid,Grafo grafo,Dicionario dic,Pilha pilha,char *cor) {
	Cidade miniCity;
	Vertice v;
	Aresta a;
	Lista arestas,list;
	Posic p, pEdge;
	Hash cepXquadra;
	Quadra q;
	int i, cont;
	double x, y, maiorX, menorX, maiorY, menorY;
	char direction;

	cepXquadra = getHashDicionario(dic, "cepXquadra");

	fprintf(*arq, "<svg height=\"%%\" width=\"auto\">\n");
	fprintf(*arq, "\t<polyline points=\" ");

	list = converterPilhaParaLista(pilha);
	free(pilha);

	p = getFirst(list);
	while (p != NULL) {
		v = get(list, p);

		x = getVerticeX(v);
		y = getVerticeY(v);

		fprintf(*arq, "%lf,%lf ", x, y);

		p = getNext(list, p);
	}

	fprintf(*arq, "%lf,%lf ", x, y);
	fprintf(*arq, "\" style=\"fill:white; stroke:%s; stroke-width:4\"/>\n", cor);

	/*
	*/
	p = getFirst(list);
	while (p != NULL) {
		v = get(list, p);

		arestas = getAllVerticesArestas(grafo,v);

		pEdge = getFirst(arestas);
		while (pEdge != NULL) {
			a = get(arestas, pEdge);

			q = getRegInfo(cepXquadra, getArestaLdir(a));
			if (q != NULL) {
				escreveQuadra(arq,q);
			}

			q = getRegInfo(cepXquadra, getArestaLesq(a));
			if (q != NULL) {
				escreveQuadra(arq,q);
			}

			pEdge = getNext(arestas, pEdge);
		}

		p = getNext(list, p);
	}

	/*escreverCidade(arq, city);*/

	fprintf(*arq, "</svg>\n");

	/*clearLista(routeList);*/
}

void describe(Grafo grafo,Vertice origem,Vertice destino,char peso,char *nomeTxt){
	FILE *arq;
	Pilha pilha;

  arq = fopen(nomeTxt,"w");
	if (arq != NULL) {
		pilha = menorCaminho(grafo,origem,destino,peso);
		writeRoute(&arq,grafo,pilha);
	}

	fclose(arq);
}

void writeRoute(FILE **arq,Grafo grafo,Pilha pilha) {
	Vertice v1,v2;
	Aresta aresta;
	int i, cont;
	char direction;

	cont = tamanhoPilha(pilha);
	v1 = pop(pilha);
	for (i=1; i<cont; i++) {
		v2 = pop(pilha);

		aresta = getAresta(grafo, v1, v2);

		direction = getDirection(v1, v2);

		fprintf(*arq, "Siga na direção ");

		if (direction == 'N') {
			fprintf(*arq, "Norte ");
		}
		else if (direction == 'S') {
			fprintf(*arq, "Sul ");
		}
		else if (direction == 'L') {
			fprintf(*arq, "Leste ");
		}
		else if (direction == 'O') {
			fprintf(*arq, "Oeste ");
		}

		fprintf(*arq, "na rua %s.\n",getArestaNome(aresta));

		v1 = v2;
	}

	fprintf(*arq, "Você chegou ao seu destino!\n");

	free(pilha);
}
