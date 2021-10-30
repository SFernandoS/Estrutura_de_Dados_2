#include <stdio.h>
#include <stdlib.h>

#define hash(v, M) (v % M)
#define hashTwo(v, M) (v % 97 + 1) // saltos esquisitos hihi
#define Key(x) (x.chave)
#define less(a,b) (Key(a) < Key(b))
#define eq(a,b) (a == b)
#define null(A) (Key(ht[A]) == Key(NULLItem))

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item; Item NULLItem = {0, 0, 0, 0};

static int N, M = 100;
static Item *ht;

void HTinsert(Item item);
void expand();
Item HTsearch (int v);

int main(int argc, char const *argv[])
{	

	Item um;
	Item dois;
	Item tres;

	um.chave = 1;
	um.e1 = 1;
	um.elemento = 1;
	um.e2 = 1;

	dois.chave = 1;
	dois.e1 = 1;
	dois.elemento = 1;
	dois.e2 = 1;

	tres.chave = 1;
	tres.e1 = 1;
	tres.elemento = 1;
	tres.e2 = 1;

	HTinsert(um);
	return 0;
}

void expand(){

	int i;
	Item *t = ht;

	ht = malloc(sizeof(Item) * M * 2);
	M = M * 2;

	for (i = 0; i < M/2; i++)
		if (Key(t[i]) != Key(NULLItem)) // t = ht antiga
			HTinsert(t[i]);

	free(t);
}

void HTinsert(Item item){
	
	int v = Key(item);
	int i = hash(v, M);
	int k = hashTwo(v, M);
	
	while(!null(i)) i = (i + k) % M;
	printf("------------------------------->debug<---------------------------------------\n");
	ht[i] = item;
	N++;

	if (N > M/2) //Já tenho a metade dos elementos do tamanho da minha tabela. Vamos expandir
		expand();
}

Item HTsearch (int v){
	int i = hash(v, M);
	int k = hashTwo(v, M);

	while(!null(i))
		if(eq(v, Key(ht[i])))
			return ht[i];
		else
			i = (i + k) % M;
		return NULLItem;
}
