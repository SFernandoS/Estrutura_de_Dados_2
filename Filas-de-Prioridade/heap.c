#include <stdio.h>
#include <stdlib.h>

#define less(a,b) (a < b)
#define exch(a, b) { Item t; t = a; a = b; b = t; }

typedef long long int lli;

typedef struct item{
	lli pontuacao, x, y;
} Item;

typedef struct pqSt
{
	Item *pq;
	int N;
}pqSt;

// Fila de prioridade baseada em índice!
/*
Item *data; <- gerado fora da fila de prioridade e possui os elementos que etão sendo manipulados pelo programa
possui definição das funções "less" que sabem comparar os elementos tipo Item
No lado da fila de prioridade, temos: 
Struct pq-ist{
	int N;
	int *pq:
	int *qp;
}
*/


void fixUp(Item *v, int k){
	while(k > 1 && less(v[k/2].pontuacao, v[k].pontuacao)){
		exch(v[k], v[k/2]);
		k = k/2;
	}
}

void fixDown(Item *v, int k, int N ){ //  N = tamanho da Heap
	int j;

	while(2/k <= N){
		j = 2*k;

		if (j < N && less(v[j].pontuacao, v[j+1].pontuacao)) j++;
		if(!less(v[k].pontuacao,v[j].pontuacao)) break;

		exch(v[k], v[j]);
		k = j;
	}
}

void PQinit(int maxN, pqSt *PQ){
	PQ->pq = malloc(sizeof(Item)*(maxN+1));
	PQ->N = 0;
}

int PQempty(pqSt *PQ){
	return PQ->N == 0;
}

void PQinsert(pqSt *PQ, Item novo){
	PQ->pq[++PQ->N] = novo;
	fixUp(PQ->pq, PQ->N);
}

Item PQdelMax(pqSt *PQ){
	exch(PQ->pq[1], PQ->pq[PQ->N]);
	fixDown(PQ->pq, 1,--PQ->N);
	return PQ->pq[PQ->N+1];
}

int main(int argc, char const *argv[])
{
	pqSt *PQ;
	Item um;
	Item dois;
	Item tres;

	um.pontuacao = 5;
	um.x = 5;
	um.y = 5;

	dois.pontuacao = 6;
	dois.x = 6;
	dois.y = 6;

	tres.pontuacao = 7;
	tres.x = 7;
	tres.y = 7;

	PQ = malloc(sizeof(pqSt));

	PQinit(5,PQ);
	PQinsert(PQ, um);
	PQinsert(PQ, dois);
	PQinsert(PQ, tres);

	printf("%lld %lld %lld\n", PQ->pq[1].pontuacao, PQ->pq[2].pontuacao, PQ->pq[3].pontuacao);
	printf("%lld %lld %lld\n", PQ->pq[1].x, PQ->pq[2].x, PQ->pq[3].x);

	return 0;
}


















