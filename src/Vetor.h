#ifndef VETOR_H
#define VETOR_H

/*
  Vetor é um tipo que possibilita a criação e manipulação de um vetor de figuras(circulos e retangulos)
*/
typedef void* Vetor;

/*
  -Cria um vetor de figuras geométricas(circulos e retangulos) e retorna um ponteiro para o Vetor
  -qtd: Quantidade de figuras máximas(tamanho do vetor)
*/
Vetor criaVetor(int qtd);

/*
  -Adiciona uma figura ao vetor(circulo ou retangulo)
  -vet:vetor genérico
  -i:Indice do vetor em que a figura será adicionada
  -forma:Ponteiro de alguma figura a ser adicionada no vetor(circulo ou retangulo)
  -tipo:char para identificar se o indice do vetor corresponde a um circulo ou retangulo
*/
void addElemento(Vetor vet,int i,void *forma,double x,double y);

/*
  -Retorna a figura presente no indice mandado como parâmetro
  -vet:vetor genérico
  -i:indice do vetor desejado
*/
Vetor *getElemento(Vetor vet,int i);

/*
  -Retorna o angulo de um elemento
  -vet: vetor genérico
  -i: indice do vetor desejado
*/
double getAng(Vetor vet,int i);

/*
  -Retorna o ponto X de um elemento
  -vet: vetor genérico
  -i: indice do vetor
*/
double getVetorX(Vetor vet,int i);

/*
  Retorna o ponto y de um elemento
  -vet: vetor genérico
  -i: indice do vetor
*/
double getVetorY(Vetor vet,int i);

/*
  -Adiciona um angulo a determinado elemento
  -vet: vetor genérico
  -i: indice do Vetor
  -angulo: angulo que será adicionado
*/
void addAng(Vetor vet,int i,double angulo);

/*
  -Compara a coordenada Y de dois elementos e retorna a maior/menor
  -vet: vetor genérico
  -i: indice do primeiro elemento
  -j: indice do segundo elemento
*/
int comparaY(Vetor vet,int i, int j);

/*
  -Compara a coordenada X de dois elementos e retorna o maior/menor
  -vet: vetor genérico
  -i: indice do primeiro elemento
  -j: indice do segundo elemento
*/
int comparaX(Vetor vet,int i,int j);

/*
  -Compara o angulo de dois elementos e retorna o maior/menor
  -vet: vetor genérico
  -i: indice do primeiro elemento
  -j: indice do segundo elemento
*/
int comparaAng(Vetor vet,int i,int j);

/*
  -Troca dois elementos de posição
  -vet:vetor genérico
  -i:indice do primeiro elemento
  -j:indice do segundo elemento
*/
void troca(Vetor vet,int i,int j);

int calculaIndice(char *ind);

/*
  -Desaloca a memória utilizada por um vetor de figuras, percorrendo cada indice e desalocando a figura presente
  -vet:vetor genérico que será desalocado
  -i:tamanho do vetor

void liberaVetor(Vetor vet,int i);
*/
int getTamanhoVetor(Vetor vet);

#endif
