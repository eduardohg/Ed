#ifndef HIDRANTE_H
#define HIDRANTE_H

/*
  Hidrante é um tipo que possibilita a criação e manipulação de hidrantes.
*/
typedef void* Hidrante;

/*
  -Cria um Hidrante
  -id = identificador
  -x,y:pontos do plano cartesiano, corp:cor do preenchimento do Hidrante, corb: cor da borda do Hidrante
*/
Hidrante criarHidrante(char* id,double x,double y,char* corp,char* corb);

void setVazaoHidrante(Hidrante h,double vazao);


/*
  -Retorna o id de um Hidrante
  -h: Hidrante genérico
*/
char* getHidranteId(Hidrante h);

/*
  -Retorna o ponto x de um Hidrante
  -h: Hidrante genérico
*/
double getHidranteX(Hidrante h);

/*
  -Retorna o ponto y de um Hidrante
  -h: Hidrante genérico
*/
double getHidranteY(Hidrante h);

/*
  -Retorna a cor de preenchimento de um Hidrante
  -h: Hidrante genérico
*/
char* getHidranteCorP(Hidrante h);

/*
  -Retorna a cor da borda de um Hidrante
  -h: Hidrante genérico
*/
char* getHidranteCorB(Hidrante h);

int comparaHidrante(Hidrante h1,Hidrante h2);

void escreveHidrante(FILE **arq,Hidrante h);

double coordPolarHidrante(Hidrante h1,Hidrante h2);

int orientacaoHidrante(Hidrante h1,Hidrante h2,Hidrante h3);

/*
  -Desaloca a memória utilizada por um Hidrante
  -h:hidrante genérico que será desalocado
*/
void liberaHidrante(Hidrante h);

#endif
