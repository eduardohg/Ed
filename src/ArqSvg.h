#ifndef ARQSVG_H
#define ARQSVG_H
#include "Lista.h"
#include "Cidade.h"

typedef void (* setEquipamento)(void*,double);

typedef void (* setOp)(void*,char*);

typedef char* (* getIDEquip)(void*);

/*
 -Menu de funções recebidas no arquivo.geo
 -cid:cidade genérica
 -circ:lista de circulos
 -retang:lista de retangulos
 -sobrepos:lista de sobreposições
 -arq:arquivo.geo
 -svg:arquivo.svg
 -txt:arquivo.txt
 -maxx:tamanho maximo do x no svg
 -maxy:tamanho maximo do y no svg
 -str:string auxiliar em procedimentos
 -nome:nome do arquivo.geo
 -dir:diretório de saida
 -cor:string
 -ins:variável que conta o numero de quadras inseridas
 -logic: variável que diz se houve ou não sobreposição
*/
void menu(Cidade *cid,Lista *circ,Lista *retang,Lista *sobrepos,FILE **arq,FILE **svg,FILE **txt,double *maxx,double *maxy,char **str,char **nome,char **dir,char **cor,int *ins,int *logic);

/*
  -Lê os atributos do Circulo
  -arq:Arquivo.geo
  -id:identificador do Circulo
  -r:raio do Circulo
  -x:ponto x do Circulo
  -y:ponto y do Circulo
  -cor:cor do Circulo
*/
void lerCirc(FILE **arq,int *id,double *r,double *x,double *y,char **cor);

/*
  -Lê os atributos do Retangulo
  -arq:Arquivo.geo
  -id:identificador do Retangulo
  -w:largura do Retangulo
  -h:altura do Retangulo
  -x:ponto x do Retangulo
  -y:ponto y do Retangulo
  -cor:cor do Retangulo
*/
void lerRet(FILE **arq,int *id,double *w,double *h,double *x,double *y,char **cor);

/*
  -Lê os atributos de uma Quadra
  -arq:Arquivo.geo
  -x:ponto x da Quadra
  -y:ponto y da Quadra
  -w:largura da Quadra
  -h:altura da Quadra
  -cep:Cep da Quadra
*/
void lerQuadra(FILE **arq,double *x,double *y,double *w,double *h,char **cep);

/*
  -Lê os atributos de um Hidrante
  -arq:Arquivo.geo
  -x:ponto x do Hidrante
  -y:ponto y do Hidrante
  -id:identificador do Hidrante
*/
void lerHidrante(FILE **arq,double *x,double *y,char **id);

/*
  -Lê os atributos do Semaforo
  -arq:Arquivo.geo
  -x:ponto x do Semaforo
  -y:ponto y do Semaforo
  -id:identificador do Semaforo
*/
void lerSemaforo(FILE **arq,double *x,double *y,char **id);

/*
  -Lê os atributos da Torre
  -arq:Arquivo.geo
  -x:ponto x da Torre
  -y:ponto y da Torre
  -id:identificador da Torre
*/
void lerTorre(FILE **arq,double *x,double *y,char **id);

/*
  -Lê os comandos para calcular a distancia
  -arq:Arquivo.geo
  -a:primeiro id
  -b:segundo id
*/
void lerDist(FILE **arq,int *a,int *b);

/*
  -Lê os comandos da função 'i'
  -arq:Arquivo.geo
  -id:identificador da figura
  -x:ponto x
  -y:ponto y
*/
void lerComandoI(FILE **arq,int *id,double *x,double *y);

/*
  -Lê os comandos da função 'o'
  -arq:Arquivo.geo
  -a:Primeiro id
  -b:Segundo id
*/
void lerComandoO(FILE **arq,int *a,int *b);

/*
  -Lê os comandos da função hI
  -arq:Arquivo.geo
  -id:Id do hidrante
  -vazão:Vazão do hidrante
*/
void lerComandoHI(FILE **arq,char **id,double *vazao);

/*
  -Lê os comandos da função tI
  -arq:Arquivo.geo
  -id:Id da Torre
  -raio:Raio de alcance da radio base
*/
void lerComandoTI(FILE **arq,char **id,double *raio);

/*
  -Lê os comandos da função sI
  -arq:Arquivo.geo
  -id:Id do semaforo
  -tempo:Tempo do ciclo do semaforo
*/
void lerComandoSI(FILE **arq,char **cep,double *tempo);

/*
  -Lê os comandos da função 'a'
  -arq:Arquivo.geo
  -sulfixo:sulfixo para a criação
  -cor:cor dos pontos no arquivo-sulfixo.svg
*/
void lerComandoA(FILE **arq,char **sulfixo,char **cor);

/*
  -Escreve Lista de circulos no arquivo.svg
  -svg:Arquivo.svg
  -list:Lista de circulos
*/
void escreveCirc(FILE **svg,Lista *list);

/*
  -Escreve Lista de retangulos no arquivo.svg
  -svg:Arquivo.svg
  -list:Lista de retangulos
*/
void escreveRet(FILE **svg,Lista *list);

/*
  -Escreve Lista de sobreposições no arquivo.svg
  -svg:Arquivo.svg
  -list:Lista de sobreposições
*/
void escreveSobrepos(FILE **svg,Lista *list);

/*
  -Escreve Lista de circulos no arquivo-sulfixo.svg
  -svg:Arquivo.svg
  -list:Lista de circulos
  -cor:cor recebida no comando 'a'
*/
void escreveCircComandoA(FILE **svg,Lista *list,char **cor);

/*
  -Escreve Lista de retangulos no arquivo-sulfixo.svg
  -svg:Arquivo.svg
  -list:Lista de retangulos
  -cor:cor recebida no comando 'a'
*/
void escreveRetComandoA(FILE **svg,Lista *list,char **cor);

int procuraEquipPorID(Tree arv,char *cep,double vazao,PosicNo nohArv,setEquipamento setEquip,getIDEquip getID,int a);


int adicionaOperadora(Tree arv,char *cep,char *op,PosicNo nohArv,setOp setEquip,getIDEquip getID,int a);

/*
  -Busca um determinado indice na lista de circulos e retangulos
  -circ:lista de circulos
  -retang:lista de retangulos
  -id:identificador que será buscado
*/
int buscaInd(Lista *circ,Lista *retang,int id);

/*
  -Busca na lista de circulos o id indicado
  -circ:lista de circulos
  -id:id desejado
*/
Posic buscaCirculo(Lista *circ,int id);

/*
  -Busca na lista de retangulos o id indicado
  -retang:lista de retangulos
  -id:id desejado
*/
Posic buscaRetangulo(Lista *retang,int id);

#endif
