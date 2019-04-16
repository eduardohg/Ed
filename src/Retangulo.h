#ifndef RETANGULO_H
#define RETANGULO_H

/*
  Retangulo é um tipo que possibilita a criação e manipulação de retangulos.
*/
typedef void* Retangulo;

/*
  -Cria um Retangulo
  -id = identificador
  -w:largura, h:altura, x,y:pontos do plano cartesiano, cor:cor do Retangulo
*/
Retangulo criarRetangulo(int id,double w,double h,double x,double y,char *cor);

/*
  -Retorna o id de um retangulo
  -ret: retangulo genérico
*/
int getRetanguloId(Retangulo ret);

/*
  -Retorna a largura de um retangulo
  -ret:retangulo genérico
*/
double getRetanguloW(Retangulo ret);

/*
  -Retorna a altura de um retangulo
  -ret:retangulo genérico
*/
double getRetanguloH(Retangulo ret);

/*
  -Retorna o ponto x de um retangulo
  -ret:retangulo genérico
*/
double getRetanguloX(Retangulo ret);

/*
  -Retorna o ponto y de um retangulo
  -ret:retangulo genérico
*/
double getRetanguloY(Retangulo ret);

/*
  -Retorna a cor de um retangulo
  -ret:retangulo genérico
*/
char* getRetanguloCor(Retangulo ret);

/*
  -Desaloca a memória utilizada por um retangulo
  -ret:retangulo genérico que será desalocado
*/
void liberaRetangulo(Retangulo ret);

#endif
