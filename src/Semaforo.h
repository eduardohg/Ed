#ifndef SEMAFORO_H
#define SEMAFORO_H

/*
  Semaforo é um tipo que possibilita a criação e manipulação de semáforos.
*/
typedef void* Semaforo;

/*
  -Cria um Semaforo
  -id = identificador
  -x,y:pontos do plano cartesiano, corp:cor do preenchimento do Semaforo, corb: cor da borda do Semaforo
*/
Semaforo criarSemaforo(char* id,double x,double y,char* corp,char* corb);

void setSemaforoTempo(Semaforo s,double tempo);

/*
  -Retorna o id de um Semáforo
  -s: Semáforo genérico
*/
char* getSemaforoId(Semaforo s);

/*
  -Retorna o ponto x de um semáforo
  -s:semáforo genérico
*/
double getSemaforoX(Semaforo s);

/*
  -Retorna o ponto y de um semáforo
  -s:semáforo genérico
*/
double getSemaforoY(Semaforo s);

/*
  -Retorna a cor de preenchimento de um semáforo
  -s:semáforo genérico
*/
char* getSemaforoCorP(Semaforo s);

/*
  -Retorna a cor da borda de um semáforo
  -s:semáforo genérico
*/
char* getSemaforoCorB(Semaforo s);

/*
  -Compara o ponto y de dois semaforos
*/
int comparaSemaforo(Semaforo s1,Semaforo s2);

void escreveSemaforo(FILE **arq,Semaforo s);

double coordPolarSemaforo(Semaforo s1,Semaforo s2);

int orientacaoSemaforo(Semaforo s1,Semaforo s2,Semaforo s3);

/*
  -Desaloca a memória utilizada por um semaforo
  -s:semaforo genérico que será desalocado
*/
void liberaSemaforo(Semaforo s);

#endif
