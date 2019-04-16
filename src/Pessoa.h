#ifndef PESSOA_H
#define PESSOA_H

typedef void* Pessoa;

/*
  -Cria uma Pessoa
  -cpf: Cpf da pessoa que será criada
  -nome: Nome da Pessoa
  -sobrenome: Sobrenome da Pessoa
  -sexo: Sexo da Pessoa
  -nasc: Data de nascimento da Pessoa
*/
Pessoa criarPessoa(char *cpf, char *nome, char *sobrenome, char sexo, char *nasc);

/*
  -Retorna o cpf de uma Pessoa
  -p: Pessoa genérica
*/
char* getPessoaCpf(Pessoa p);

/*
  -Retorna o nome de uma Pessoa
  -p: Pessoa genérica
*/
char* getPessoaNome(Pessoa p);

/*
  -Retorna o sobrenome de uma Pessoa
  -p: Pessoa genérica
*/
char* getPessoaSobrenome(Pessoa p);

/*
  -Retorna o nome completo de uma Pessoa
  -p: Pessoa genérica
*/
char* getPessoaNomeCompleto(Pessoa p);

/*
  -Retorna o sexo de uma Pessoa
  -p: Pessoa genérica
*/
char getPessoaSexo(Pessoa p);

/*
  -Retorna a data de nascimento de uma Pessoa
  -p: Pessoa genérica
*/
char* getPessoaNasc(Pessoa p);

/*
  Retorna a coordenada x de uma pessoa
  -p: Pessoa genérica
*/
double getPessoaX(Pessoa p);

/*
  Retorna a coordenada y de uma pessoa
  -p: Pessoa genérica
*/
double getPessoaY(Pessoa p);

/*
  -Seta atributos de morador a uma pessoa
  -p: Pessoa genérica
  -cep: cep da quadra do morador
  -face: Face da quadra do morador
  -compl: Complemento do morador
*/
void setMorador(Pessoa p,char *cep,char face,char *comp,int num);

/*
  -Seta o número de telefone de uma pessoa
  -p: Pessoa genérica
  -tel: Número que será inserido
*/
void setPessoaNumTel(Pessoa p,char *tel);

/*
  Seta a operadora de telefone de uma pessoa
  -p: Pessoa genérica
  -op: Operadora
*/
void setPessoaOp(Pessoa p,char *op);

/*
  Retorna a operadora de telefone de uma pessoa
  -p: Pessoa genérica
*/
char* getPessoaOp(Pessoa p);

/*
  Retorna o número de telefone de uma pessoa
  -p: Pessoa genérica
*/
char* getPessoaNumTel(Pessoa p);

/*
  -Retorna o cep da quadra que um morador
  -p: Pessoa genérica
*/
char* getMoradorCep(Pessoa p);

/*
  -Retorna a face da quadra de um morador
  -p: Pessoa genérica
*/
char getMoradorFace(Pessoa p);

/*
  -Retorna o complemento de um morador
  -p: Pessoa genérica
*/
char* getMoradorCompl(Pessoa p);

/*
  -Retorna o número do morador
  -p: Pessoa genérica
*/
int getMoradorNum(Pessoa p);


#endif
