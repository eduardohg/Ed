#ifndef OPERACOES_H
#define OPERACOES_H
#include "Lista.h"
#include "Vetor.h"
#include "QuadTree.h"
#include "Cidade.h"
#include "EnvoltorioConvexo.h"
#include "Quadra.h"
#include "Pilha.h"
#include "Torre.h"
#include "Hidrante.h"
#include "Semaforo.h"

typedef double (* getCoordenada)(void*);

/*
  -Trata os parâmetros de entrada na hora da execução do Programa
  -argc:quantidade de parâmetros recebidos
  -argv:Strings contendo os parâmetros recebidos
  -caminho:string que armazenará o path do arquivo de entrada
  -dir:string que armazenará o path dos arquivos de saida
  -num:numero que receberá a quantidade maxima de figuras(tamanho do vetor)
*/

int entrada(int argc,char **argv,char **caminho,char **dir,char **pasta,char **testes,char **ec,char **pm,char **tm,char **via,int *num,int *a,int *mat);

/*
  -Cria nome e extensão dos arquivos de saida resultantes do Programa
  -caminho:path do arquivo de entrada
  -dir:path dos arquivos de saida
  -y:variável para verificação se cria extensão txt,svg ou nome_arq-sulfixo.svg
  -sul:string do sulfixo do comando "a"
*/
char* criaExt(char *caminho,char *dir,int y,char *sul);

/*
  -Cria um arquivo txt com o nome do qry
  -dir: diretório de saida(-o)
  -nome: nome do arquivo geo
  -qry: nome do arquivo qry
*/
char *criaArqTxtComQuery(char *dir,char *nome,char *qry);

/*
  -Cria um arquivo txt sem o nome do qry
  -dir: Diretório de saida
  -nome: Nome do arquivo.getTorre
*/
char *criaArqTxtSemQuery(char *dir,char *nome);

/*
  -Cria um arquivo Svg com o sulfixo do poligono de cobertura
  -dir: Diretório de saida
  -geo: Nome do arquivo geo
  -qry: Nome do arquivo qry
  -sulfixo: nome do sulfixo inserido
*/
char *criaArqSvgComSulfixoPoligono(char *dir,char *geo,char *qry,char *sulfixo);

/*
  -Retorna o caminho do arquivo geo para a leitura
  -pasta: Diretório BED(-e)
  -nome: Nome arquivo geo(-f)
*/
char* retornaEntrada(char *pasta,char *nome);

/*
  -Cria um arquivo SVG sem qry
  -dir: Diretório de saida
  -nome: Nome do arquivo geo
*/
char *criaArqSvgSemQry(char *dir,char *nome);

/*
  -Cria arquivo svg com qry
  -dir: Diretório de saida
  -nome: Nome do arquivo geo
  -qry: Nome do arquivo qry
*/
char *criaArqSvgComQry(char *dir,char *nome,char *qry);

/*
  -Cria a string somente com o nome do arquivo, sem diretório
  -qry: String a ser formatada
*/
char *somenteNomeArq(char *qry);
/*
  -Cria o a string Resumo.txt
  -dir:Diretorio de saída
*/
char* criaResumo(char *dir);

/*
  -Calcula a distancia entre duas figuras e retorna o resultado
  -vet:vetor de figuras
  -a:identificador da primeira figura
  -b:identificador da segunda figura
*/

double calculaDistancia(Lista *circ,Lista *retang,int a,int b,int type1,int type2);

/*
  -Verifica se um ponto pertence a figura desejada e retorna o resultado(sim ou não)
  -circ:lista de circulos
  -retang:lista de retangulos
  -id:identificador da figura desejada
  -px:coordenada x que será verificada
  -py:coordenada y que será verificada
  -type:inteiro que diz se a figura é um circulo ou retangulo
*/
int verificaPonto(Lista *circ,Lista *retang,int id,int px,int py,int type);

/*
  -Calcula a sobreposição de duas figuras e retorna o resultado(sim ou não)
  -circ:lista de circulos
  -retang:lista de retangulos
  -sobrepos:lista de sobreposições
  -a:primeira figura
  -b:segunda figura
  -type1:inteiro que diz se a primeira figura(a) é um circulo ou retangulo
  -type2:inteiro que diz se a segunda figura(b) é um circulo ou retangulo
  -id:id da forma da sobreposição para inclusão na lista
*/
int calculaSobreposicao(Lista *circ,Lista *retang,Lista *sobrepos,int a,int b,int type1,int type2,int id);

/*
  -Retorna o identificador do Posic p na lista de circulos(se houver)
  -circ: lista de circulos
  -p:Posic
  -id:identificador que será procurado na lista de circulos
*/
Posic retornaIdCirc(Lista *circ,Posic p,int id);

/*
  -Retorna o identificador do Posic p na lista de retangulos(se houver)
  -retang: lista de retangulos
  -p:Posic
  -id:identificador que será procurado na lista de retangulos
*/
Posic retornaIdRet(Lista *retang,Posic p,int id);

/*
  -Função que começa o processo de converter a cidade de QuadTree p/ uma QuadTree balanceada passando pelo convexHull
  -c: Cidade
*/
Cidade converterTrees(Cidade c);

/*
  -Converte as Quadras, passando pelo convexHull e inserindo na nova cidade, 'city'
  -c: Cidade antiga
  -city: Nova cidade
*/
void converteQuadra(Cidade c,Cidade city);

/*
  -Converte as Torres, passando pelo convexHull e inserindo na nova cidade 'city'
  -c: Cidade antiga
  -city: Nova cidade
*/
void converteTorre(Cidade c,Cidade city);

/*
  -Converte os Hidrantes, passando pelo convexHull e inserindo na nova cidade, 'city'
  -c: Cidade antiga
  -city: Nova cidade
*/
void converteHidrante(Cidade c,Cidade city);

/*
  -Converte os Semaforos, passando pelo convexHull e inserindo na nova cidade, 'city'
  -c: Cidade antiga
  -city: Nova cidade
*/
void converteSemaforo(Cidade c,Cidade city);

/*
  Função que converte uma Tree para um Vetor
  -v: Vetor
  -arv: Tree a ser convertida
  -nohArv: Nó da arvore
  -getCoordX: Função que pega a coordenada x de um equipamento urbano
  -getCoordY: Função que pega a coordenada y de um equipamento urbano
  -i: indice do vetor
*/
int convertTreeToVector(Vetor v,Tree arv,PosicNo nohArv,getCoordenada getCoordX,getCoordenada getCoordY,int i);

/*
  -Função que converte uma lista para um Vetor
  -list: lista a ser convertida
  -v: Vetor
*/
Vetor convertListToVector(Lista *list,Vetor v);

/*
  -Função que converte uma Tree para lista
  -l:Lista que será retornada
  -arv:Tree que será convertida
  -nohArv: Nó da arvore
*/
Lista converterTreeToList(Lista l,Tree arv,PosicNo nohArv);

/*
  -Função que converte uma Pilha para um Vetor
  -monte: Pilha que será convertida
  -getCoordX: Função que pega a coordenada x de um equipamento urbano
  -getCoordY: Função que pega a coordenada y de um equipamento urbano
*/
Vetor converterPilhaParaVetor(Pilha monte,getCoordenada getCoordX,getCoordenada getCoordY,int pts);

Lista converterPilhaParaLista(Pilha monte);
/*
  -Função que busca os pontos que estão no poligono de cobertura
  -l: lista que contém todos os pontos
  -l2: lista que irá conter os pontos dentro da região
  -x: ponto x da região
  -y: ponto y da região
  -larg: largura da região
  -alt: altura da região
*/
Lista buscarPontosPoligono(Lista l,Lista l2,double x,double y,double larg,double alt);

char *criaArqTxtComSufixo(char *dir,char *geo,char *qry,char *sufixo);


#endif
