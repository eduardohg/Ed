#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "Procedimentos.h"

Dicionario generateDictionary(){
	Dicionario dictionary;
	Hash cpfXcep, SUnumcelXpessoa, UMnumcelXpessoa, numcelXradio, comercialXdescricao, pessoaCpf, cepXquadra, estCnpj;
	int n=26;

	dictionary = createDicionario();

	cpfXcep = createHash(n);
	SUnumcelXpessoa = createHash(n);
	UMnumcelXpessoa = createHash(n);
	numcelXradio = createHash(n);
	comercialXdescricao = createHash(n);
	pessoaCpf = createHash(n);
	cepXquadra = createHash(n);
	estCnpj = createHash(n);

	insertDicionario(dictionary, cpfXcep, "cpfXcep");
	insertDicionario(dictionary, SUnumcelXpessoa, "SUnumcelXpessoa");
	insertDicionario(dictionary, UMnumcelXpessoa, "UMnumcelXpessoa");
	insertDicionario(dictionary, numcelXradio, "numcelXradio");
	insertDicionario(dictionary, comercialXdescricao, "comercialXdescricao");
	insertDicionario(dictionary, pessoaCpf, "pessoaCpf");
	insertDicionario(dictionary, cepXquadra, "cepXquadra");
	insertDicionario(dictionary, estCnpj, "estCnpj");

	return dictionary;
}

void insereQuadrasHash(Dicionario dic,Cidade cid){
  PosicNo n;

  n = getFirstElementTree(getQuadra(cid));
  dic = QuadrasParaHash(getQuadra(cid),n,dic);

}

Dicionario QuadrasParaHash(Tree arv,PosicNo nohArv,Dicionario dic){
  Hash cepXquadra;

  if(leafNe(arv,nohArv) == 1){
    dic = QuadrasParaHash(arv,getNe(arv,nohArv),dic);
  }

  if(leafNw(arv,nohArv) == 1){
    dic = QuadrasParaHash(arv,getNw(arv,nohArv),dic);
  }

  if(leafSe(arv,nohArv) == 1){
    dic = QuadrasParaHash(arv,getSe(arv,nohArv),dic);
  }

  if(leafSw(arv,nohArv) == 1){
    dic = QuadrasParaHash(arv,getSw(arv,nohArv),dic);
  }
  cepXquadra = getHashDicionario(dic, "cepXquadra");
  insertRegInfo(cepXquadra,getElement(arv,nohArv),getQuadraCep(getElement(arv,nohArv)));
  return dic;

}

double processaCon(Dicionario dic,char **numcel,char **cep,char face,int num,Cidade cid,FILE **txt){
	double x,y,d=0;
	Hash SUnumcelXpessoa,UMnumcelXpessoa,cepXquadra;
	Pessoa pessoa;
	Quadra quadra;
	UMnumcelXpessoa = getHashDicionario(dic, "UMnumcelXpessoa");
	pessoa = getRegInfo(UMnumcelXpessoa,*numcel);
	if(pessoa != NULL){
		cepXquadra = getHashDicionario(dic,"cepXquadra");
		quadra = getRegInfo(cepXquadra,*cep);
		if(quadra != NULL){
			x = getQuadraX(quadra);
			y = getQuadraY(quadra);
			calculaPontosXY(&x,&y,face,num);

			d = retornaDist(dic,x,y,cid,"UELMobile",numcel);
			fprintf(*txt, "con - (%s,%s)-UELMobile - distancia: %lf\n",getPessoaCpf(pessoa),getPessoaNomeCompleto(pessoa),d);
		}
		else
			fprintf(*txt, "con - A quadra de cep %s não existe\n",*cep);
	}
	else{
		SUnumcelXpessoa = getHashDicionario(dic,"SUnumcelXpessoa");
		pessoa = getRegInfo(SUnumcelXpessoa,*numcel);
		if(pessoa != NULL){
			cepXquadra = getHashDicionario(dic,"cepXquadra");
			quadra = getRegInfo(cepXquadra,*cep);
			if(quadra != NULL){
				x = getQuadraX(quadra);
				y = getQuadraY(quadra);

				calculaPontosXY(&x,&y,face,num);

				d = retornaDist(dic,x,y,cid,"SercomtUEL",numcel);
				fprintf(*txt, "Con: (%s,%s)-SercomtUEL - distancia: %lf\n",getPessoaCpf(pessoa),getPessoaNomeCompleto(pessoa),d);
			}
			else
				fprintf(*txt, "con - A quadra de cep %s não existe\n",*cep);
		}
		else
			fprintf(*txt, "con - Não existe pessoa com o número %s\n",*numcel);
	}
	return d;
}

void processaComandoM(Dicionario dic,char **cep,Cidade cid,FILE **txt){
	Lista moradores;
	Posic p;
	Hash cepXquadra;
	Quadra q;
	cepXquadra = getHashDicionario(dic,"cepXquadra");
	q = getRegInfo(cepXquadra,*cep);
	if(q != NULL){
		moradores = getListaMoradoresQuadra(q);
		if(length(moradores)>0){
			p = getFirst(moradores);
			while(p != NULL){
				fprintf(*txt, "m? - Nome:%s End:(%s,%c,%d,%s) Cel:%s Operadora:%s\n",getPessoaNome(get(moradores,p)),*cep,getMoradorNum(get(moradores,p)),getMoradorCompl(get(moradores,p)),getPessoaNumTel(get(moradores,p)),getPessoaOp(get(moradores,p)));
				p = getNext(moradores,p);
			}
		}
		else
			fprintf(*txt, "m? Não existe nenhum morador no cep %s\n",*cep);
	}
	else{
		fprintf(*txt, "Não existe a quadra de cep %s\n",*cep);
	}

}

void processaComandoDm(char **cpf,Dicionario dic,FILE **txt){
	Hash pessoaCpf;
	Pessoa p;
	pessoaCpf = getHashDicionario(dic,"pessoaCpf");
	p = getRegInfo(pessoaCpf,*cpf);
	if(p != NULL){
		if(getPessoaNumTel(p) != NULL)
			fprintf(*txt, "dm? - Nome: %s Sexo: %c Nasc: %s Cel: %s Operadora:%s Coord:(%lf,%lf)\n",getPessoaNome(p),getPessoaSexo(p),getPessoaNasc(p),getPessoaNumTel(p),getPessoaOp(p),getPessoaX(p),getPessoaY(p));
		else
		fprintf(*txt, "dm? - Nome: %s Sexo: %c Nasc: %s Coord:(%lf,%lf)\n",getPessoaNome(p),getPessoaSexo(p),getPessoaNasc(p),getPessoaNumTel(p),getPessoaOp(p),getPessoaX(p),getPessoaY(p));
	}
	else
		fprintf(*txt, "Não existe morador com o cpf %s\n",*cpf);
}

void processaComandoDe(char **cnpj,Dicionario dic,FILE **txt){
	Hash estCnpj,comercialXdescricao;
	EstabelecimentoCom est;

	estCnpj = getHashDicionario(dic,"estCnpj");
	est = getRegInfo(estCnpj,*cnpj);
	if(est != NULL)
		fprintf(*txt, "de? - Nome: %s Cnpj: %s Cep: %s Face: %c Num: %d Coord:(%lf,%lf)\n",getEstabelecimentoNome(est),*cnpj,getEstabelecimentoCep(est),getEstabelecimentoFace(est),getEstabelecimentoNum(est),getEstabelecimentoX(est),getEstabelecimentoY(est));
	else
		fprintf(*txt, "de? - Não foi encontrado nenhum estabelecimento com o cnpj %s\n",*cnpj);
}

void processaComandoLk(char **id,Dicionario dic,Cidade cid,FILE **txt){
	Lista celulares;
	Posic p;
	Torre torre;
	torre = retornaEquipTorre(cid,*id);
	if(torre != NULL){
		celulares = getListaCelTorre(torre);
		if(length(celulares)>0){
			p = getFirst(celulares);
			while(p != NULL){
				fprintf(*txt, "lk? - Número: %s\n",(char *)get(celulares,p));
				p = getNext(celulares,p);
			}
		}
		else{
			fprintf(*txt, "A torre de id %s não possui nenhum número conectado \n",*id);
		}
	}
	else
		fprintf(*txt, "lk? - Torre de id %s não existe\n",*id);
}

void processaComandoRb(char **numcel,Dicionario dic,FILE **txt){
	Torre torre;
	Hash numcelXradio;
	numcelXradio = getHashDicionario(dic,"numcelXradio");
	torre = getRegInfo(numcelXradio,*numcel);
	if(torre != NULL){
		if(getTorreOp(torre) != NULL)
			fprintf(*txt, "rb? - Torre id: %s Operadora: %s\n",getTorreId(torre),getTorreOp(torre));
		else
			fprintf(*txt, "rb? - Torre id: %s \n",getTorreId(torre));
	}
	else
		fprintf(*txt, "O celular de número %s não está conectado a nenhuma Rádio-base\n",*numcel);
}

void processaComandoEcq(char **cep,Dicionario dic,FILE **txt){
	Lista estab;
	Posic p;
	Quadra q;
	EstabelecimentoCom e;
	Hash cepXquadra;
	cepXquadra = getHashDicionario(dic,"cepXquadra");
	q = getRegInfo(cepXquadra,*cep);
	if(q != NULL){
		estab = getListaEstabQuadra(q);
		if(length(estab)>0){
			p = getFirst(estab);
			while(p != NULL){
				fprintf(*txt, "ecq? - CNPJ:%s Nome:%s Tipo:%s Face:%c Num:%d\n",getEstabelecimentoCnpj(get(estab,p)),getEstabelecimentoNome(get(estab,p)),getEstabelecimentoCodt(get(estab,p)),getEstabelecimentoFace(get(estab,p)),getEstabelecimentoNum(get(estab,p)));
				p = getNext(estab,p);
			}
		}
		else
			fprintf(*txt, "O cep %s n possui estabelecimentos comerciais\n",*cep);
	}
	else
		fprintf(*txt, "Não existe quadra com o cep %s\n",*cep);
}

void processaComandoDc(char **numtel,Dicionario dic,FILE **txt){
	Hash SUnumcelXpessoa,UMnumcelXpessoa;
	Pessoa p;

	SUnumcelXpessoa = getHashDicionario(dic,"SUnumcelXpessoa");
	UMnumcelXpessoa = getHashDicionario(dic,"UMnumcelXpessoa");
	p = getRegInfo(SUnumcelXpessoa,*numtel);
	if(p != NULL){
		fprintf(*txt, "dc? - Pessoa Nome: %s Cpf: %s Sexo: %c Nasc: %s Operadora: SercomtUEL\n",getPessoaNome(p),getPessoaCpf(p),getPessoaSexo(p),getPessoaNasc(p));
	}
	else{
		p = getRegInfo(UMnumcelXpessoa,*numtel);
		if(p != NULL){
			fprintf(*txt, "dc? - Pessoa Nome: %s Cpf: %s Sexo: %c Nasc: %s Operadora: UELMobile\n",getPessoaNome(p),getPessoaCpf(p),getPessoaSexo(p),getPessoaNasc(p));
		}
		else
			fprintf(*txt, "dc? - Não existe pessoa com o número %s\n",*numtel);
	}
}







void calculaPontosXY(double *x,double *y,char face,int num){

	if (face == 'N')
		*y += num;
	else if (face == 'S')
		*y -= num;
	else if (face == 'L')
		*x -= num;
	else if (face == 'O')
		*x += num;
}

double retornaDist(Dicionario dic,double x,double y,Cidade cid,char *op,char **numcel){
	Hash numcelXradio;
	Torre t;
	Lista l;
	PosicNo n;
	double menor = 9999999999;
	l = createList();
  n = getFirstElementTree(getTorre(cid));
	l = converterTreeToList(l,getTorre(cid),n);

	t = menorDistTorre(l,x,y,&menor,op);
	numcelXradio = getHashDicionario(dic,"numcelXradio");
	removeRegInfo(numcelXradio,*numcel);
	insertRegInfo(numcelXradio,t,*numcel);
	insertCelTorre(t,*numcel);
	return menor;

}

Torre menorDistTorre(Lista list,double x,double y,double *menor,char *op){
	double x2,y2,dist=0;
	Posic p;
	Torre aux,t;
	p = getFirst(list);

	while (p != NULL) {
		if(strcmp(getTorreOp(get(list,p)),op)==0){
			x2 = getTorreX(get(list,p));
	  	y2 = getTorreY(get(list,p));
			aux = get(list,p);
	  	dist = sqrt(pow((x-x2),2)+pow((y-y2),2));
			if(dist < *menor){
				*menor = dist;
				t = aux;
			}
		}
  	p = getNext(list,p);
	}
  return t;
}

Quadra retornaEquipQuadra(Cidade cid,char *id){
	Lista list;
	PosicNo n;
	Posic p;
	Quadra info;
	list = createList();
	n = getFirstElementTree(getQuadra(cid));
	list = converterTreeToList(list,getQuadra(cid),n);
	p = getFirst(list);
	while (p != NULL) {
		if(strcmp(getQuadraCep(get(list,p)),id)==0){
			info = get(list,p);
			return info;
		}
		p = getNext(list,p);
	}
	return NULL;
}

Hidrante retornaEquipHidrante(Cidade cid,char *id){
	Lista list;
	PosicNo n;
	Posic p;
	Hidrante info;
	list = createList();
	n = getFirstElementTree(getHidrante(cid));
	list = converterTreeToList(list,getHidrante(cid),n);
	p = getFirst(list);
	while (p != NULL) {
		if(strcmp(getHidranteId(get(list,p)),id)==0){
			info = get(list,p);
			return info;
		}
		p = getNext(list,p);
	}
	return NULL;
}

Semaforo retornaEquipSemaforo(Cidade cid,char *id){
	Lista list;
	PosicNo n;
	Posic p;
	Semaforo info;
	list = createList();
	n = getFirstElementTree(getSemaforo(cid));
	list = converterTreeToList(list,getSemaforo(cid),n);
	p = getFirst(list);
	while (p != NULL) {
		if(strcmp(getSemaforoId(get(list,p)),id)==0){
			info = get(list,p);
			return info;
		}
		p = getNext(list,p);
	}
	return NULL;
}

Torre retornaEquipTorre(Cidade cid,char *id){
	Lista list;
	PosicNo n;
	Posic p;
	Torre info;
	list = createList();
	n = getFirstElementTree(getTorre(cid));
	list = converterTreeToList(list,getTorre(cid),n);
	p = getFirst(list);
	while (p != NULL) {
		if(strcmp(getTorreId(get(list,p)),id)==0){
			info = get(list,p);
			return info;
		}
		p = getNext(list,p);
	}
	return NULL;
}
