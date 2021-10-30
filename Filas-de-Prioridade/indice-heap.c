#include <stdio.h>
#include <stdlib.h>

#define less(a,b) (a < b)
#define exch(a,b) (a = a + b, b = a - b, a = a - b)

typedef struct pqIst
{
	int *pq;
	int N;
}pqIst;

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item; Item NULLItem = {0, 0, 0, 0};

Item *data;

// Fila de prioridade baseada em índice!
/*
Item *data; <- gerado fora da fila de prioridade e possui os elementos que etão sendo manipulados pelo programa
possui definição das funções "less" que sabem comparar os elementos tipo Item
No lado da fila de prioridade, temos: 
*/
Struct pq-ist{
	int N;
	int *pq; //Fila de prioridades que armazena os índices de um conjunto de Item
	int *qp; // Mantém a posição da HEAP para o elemento de índice K do cojunto de Itens (funciona como uma Hash)
}


int main(int argc, char const *argv[])
{
	int a = 5, b = 7;

	printf("%d %d\n", a, b);

	exch(a,b);
	printf("%d %d\n", a, b);
	return 0;
}

void fixUp(int *v, int k){
	while(k > 1 && less(v[k/2], v[k])){
		exch(v[k], v[k/2]);
		k = k/2;
	}
}

void fixDown(int *v, int k, int N ){ //  N = tamanho da Heap
	int j;

	while(2/k <= N){
		j = 2*k;

		if (j < N && less(v[j], v[j+1])) j++;
		if(!less(v[k],v[j])) break;

		exch(v[k], v[j]);
		k = j;
	}
}

void PQinit(pqIst *PQ, int max){
	PQ->N = 0; 
	PQ->pq = malloc(sizeof(int)*(max+1));
	PQ->qp = malloc(sizeof(int)*(max+1));
}

int PQempty(pqIst *PQ){
	return !PQ->N;
}

void PQinsert(pqIst *PQ, int k){
	PQ->qp[k] = ++PQ->N;
	PQ->pq[PQ->N] = k;
	fixUp(PQ->pq, PQ->N);
}

void exchPQ(int i, int j){ // Deve ser modificado
	int t;
	t = qp[i]; qp[i] qp[k]; qp[j] = t;
	pq[qp[i]] = i; pq[qp[j]] = j;
}

int *PQdelMax(pqIst *PQ){
	exch(PQ->pq[1], PQ->pq[PQ->N]);
	fixDown(PQ->pq, 1,--PQ->N);
	return PQ->pq[PQ->N+1];
}


void PQchange(pqIst *PQ, int k){

}





















