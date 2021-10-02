#include <stdio.h>
#include <stdlib.h>

#define true 1
#define false 0

typedef int bool;

typedef struct aux{
	int chave;
	struct aux *esq, *dir;
} No;

No *inicializa();
No *adiciona();
No *criaNovoNo();
No *mostraNo();
No *buscaNo(No *raiz, int valor, No **pai);
No *removeNo(No *raiz, int valor);
int quantidadeNos(No *raiz);
void mostraArvore(No *raiz);

int main(int argc, char const *argv[])
{
	No *raiz = inicializa();
	No *no = criaNovoNo(50);
	raiz = adiciona(raiz, no);
	no = criaNovoNo(25);
	raiz = adiciona(raiz, no);
	no = criaNovoNo(42);
	raiz = adiciona(raiz, no);
	no = criaNovoNo(60);
	raiz = adiciona(raiz, no);
	printf("%d -> O valor de uma chave especifica\n", mostraNo(50, raiz)->chave);
	printf("%d -> Quantidade de Nós\n", quantidadeNos(raiz));
	mostraArvore(raiz); printf("\n");
	removeNo(raiz, 42);
	mostraArvore(raiz); printf("\n");
	return 0;
}

No *removeNo(No *raiz, int valor){
	No *pai, *no, *p, *q;

	no = buscaNo(raiz, valor, &pai);

	if (no == NULL) return raiz;

	if(!no->esq || !no->dir)
		if (!no->esq) q = no->dir;
		else q = no->esq;
	else{
		p = no;
		q = no->esq;

		while(q->dir){
			p = q;
			q = q->dir;
		}

		if (p != no){
			p->dir = q->esq;
			q->esq = no->esq;
		}
		q->dir = no->dir;
	}
		if(!pai){
			return q;
		}

		if (valor < pai->chave) pai->esq = q;
		else pai->dir = q;
		return raiz;
}


No *buscaNo(No *raiz, int valor, No **pai){
	No *atual = raiz;
	*pai = NULL;

	while(atual){
		if (atual->chave == valor) return (atual);
		*pai = atual;
		if (valor < atual->chave) atual = atual->esq;
		else atual = atual->dir;
	}

	return NULL;
}

void mostraArvore(No *raiz){
	if (raiz != NULL)
	{
		printf("%d", raiz->chave);
		printf("(");
		mostraArvore(raiz->esq);
		mostraArvore(raiz->dir);
		printf(")");
	}
}
int quantidadeNos(No *raiz){
	if (!raiz) return 0;

	return(quantidadeNos(raiz->esq) + quantidadeNos(raiz->dir) + 1);
}

No *mostraNo(int valor, No *raiz){
	if (raiz == NULL) return NULL;

	if (raiz->chave == valor) return(raiz);
	if (raiz->chave > valor) return(mostraNo(valor, raiz->esq));
	return(mostraNo(valor, raiz->dir));
	
}

No *inicializa(){
	return(NULL);
}

No *adiciona(No *raiz, No *no){
	if (raiz == NULL) return(no);

	if (no->chave < raiz->chave)
		raiz->esq = adiciona(raiz->esq, no);
	else
		raiz->dir = adiciona(raiz->dir, no);
	return raiz;
}

No *criaNovoNo(int novaChave){
	No *novoNo = malloc(sizeof(No));
	novoNo->esq = NULL;
	novoNo->dir = NULL;
	novoNo->chave = novaChave;
	return(novoNo);
}