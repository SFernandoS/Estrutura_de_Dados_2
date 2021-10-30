#include <stdio.h>
#include <stdlib.h>
#include <stdbool.h>
#include <math.h>

#define less(A, B) ((A) < (B))
#define exch(A, B) { Item t; t = A; A = B; B = t; }
#define primo 104729

typedef long long int llint;

typedef struct noLista{
    llint x;
    llint y;
    struct noLista* next;
}noLista;

typedef struct lista{
    noLista* head;
    llint tam;
}Lista;

typedef struct item{
    llint x;
    llint y;
    llint pontuacao;
}Item;

Lista* sondados[104730];
Lista* edazinhos;

static Item* pq;
static llint N;
static llint max = 9223372036854775807;

//------------------------------------------- Lista

Lista* initLista(){
    Lista* novaLista = (Lista*)malloc(sizeof(Lista));
    novaLista->head = NULL;
    novaLista->tam = 0;
    return novaLista;
}

void listaPush(Lista* list, llint x, llint y){
    noLista* nova = (noLista*)malloc(sizeof(noLista)); 
    nova->x = x;
    nova->y = y;
    if(list->head == NULL){
        nova->next = list->head;
        list->head = nova;
    }

    else{
        noLista* aux = list->head;

        while(aux->next != NULL){
            aux = aux->next;
        }
        nova->next = aux->next;
        aux->next = nova;
    }
    list->tam++;
}

void listaPop(Lista* list){
    if(list->head != NULL){
        noLista* aux = list->head;
        list->head = aux->next;
        free(aux);
    }
    list->tam--;
}

void printaLista(Lista* list){
    if(list->head != NULL){
        noLista* aux = list->head;
        while(aux != NULL){
            printf("x:%lld y:%lld\n", aux->x, aux->y);
            aux = aux->next;
        }
    }
    else{
        printf("LISTA VAZIA\n");
    }
}

//------------------------------------------- Fila de prioridade

void PQinit (llint maxN){
    pq = (Item*)malloc(sizeof(Item)*(maxN+1));
    N = 0;
}

bool PQempty(){
    return (N == 0);
}

void fixUp(llint k){
    if(k>1 && less(pq[k-1].pontuacao, pq[k].pontuacao)){
        exch(pq[k],pq[k-1]);
        k--;
        fixUp(k);
    }
}

void fixDown(llint k, llint N){
    llint j;
    while(2*k <= N){
        j = 2*k;
        
        if(j < N && less(pq[j].pontuacao, pq[j+1].pontuacao)){
            j++;
        }

        if(!less(pq[k].pontuacao, pq[j].pontuacao)){
            break;
        }

        exch(pq[k],pq[j]);
        k = j;
    }
}

void PQinsert(Item novo){
    pq[++N] = novo;
    fixUp(N);
}

Item PQdelMax(){
    exch(pq[1], pq[N]);
    fixDown(1,--N);
    return pq[N+1];
}

void puxaFila(llint x, llint y, llint pontuacao){
    Item novo;
    novo.x = x;
    novo.y = y;
    novo.pontuacao = pontuacao;
    PQinsert(novo);
}

llint cHash(llint x){
    return (abs(x)%primo);
}

bool naLista(Lista* list, llint x, llint y){
    bool encontrado = false;
    if(list->head != NULL){
        noLista* aux = list->head;
        while(aux != NULL){
            if(aux->x == x && aux->y == y){
                encontrado = true;
            }
            aux = aux->next;
        }
    }
    return encontrado;
}

bool addEdazinho(){
    bool adicionado = false;
    if(!PQempty()){
        char comando[15];
        llint pontos;
        printf("dominar %lld %lld\n",pq[1].x,pq[1].y);
        fflush(stdout);
        scanf(" %s", comando);
        scanf(" %lld", &pontos);
        listaPush(edazinhos,pq[1].x,pq[1].y);
        PQdelMax();
        adicionado = true;
    }
    return adicionado;
}

void dispSondar(){
    noLista* head = edazinhos->head;
    
    
    llint hcodemenor = cHash(head->x-1);
    llint hcode = cHash(head->x);
    llint hcodemaior = cHash(head->x+1);
    char comando[15];
    llint posX,posY, pontos;
    
    //para x-1
    if(head->x >= -9223372036854775807 && head->y >= -9223372036854775807 && !naLista(sondados[hcodemenor], head->x-1, head->y-1)){
        printf("sondar %lld %lld\n", head->x-1, head->y-1);
        fflush(stdout);
        listaPush(sondados[hcodemenor], head->x-1, head->y-1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else if(head->x >= -9223372036854775807 && !naLista(sondados[hcodemenor], head->x-1, head->y)){
        printf("sondar %lld %lld\n", head->x-1, head->y);
        fflush(stdout);
        listaPush(sondados[hcodemenor], head->x-1, head->y);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else if(head->x >= -9223372036854775807 && head->y < max && !naLista(sondados[hcodemenor], head->x-1, head->y+1)){
        printf("sondar %lld %lld\n", head->x-1, head->y+1);
        fflush(stdout);
        listaPush(sondados[hcodemenor], head->x-1, head->y+1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    //para x
    else if(head->y >= -9223372036854775807 && !naLista(sondados[hcode],head->x,head->y-1)){
        printf("sondar %lld %lld\n", head->x, head->y-1);
        fflush(stdout);
        listaPush(sondados[hcode], head->x, head->y-1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else if(head->y < max && !naLista(sondados[hcode], head->x,head->y+1)){
        printf("sondar %lld %lld\n", head->x, head->y+1);
        fflush(stdout);
        listaPush(sondados[hcode], head->x, head->y+1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }
    
    
    //para x+1
    else if(head->x < max && head->y >= -9223372036854775807 && !naLista(sondados[hcodemaior], head->x+1, head->y-1)){
        printf("sondar %lld %lld\n", head->x+1, head->y-1);
        fflush(stdout);
        listaPush(sondados[hcodemaior], head->x+1, head->y-1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else if(head->x < max && !naLista(sondados[hcodemaior],head->x+1,head->y)){
        printf("sondar %lld %lld\n", head->x+1, head->y);
        fflush(stdout);
        listaPush(sondados[hcodemaior],head->x+1,head->y);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else if(head->x < max && head->y < max && !naLista(sondados[hcodemaior],head->x+1,head->y+1)){
        printf("sondar %lld %lld\n", head->x+1, head->y+1);
        fflush(stdout);
        listaPush(sondados[hcodemaior],head->x+1,head->y+1);
        scanf(" %s", comando);
        scanf(" %lld %lld %lld", &posX, &posY, &pontos);
        puxaFila(posX,posY,pontos);
    }

    else{
        edazinhos->head = head->next;
        edazinhos->tam--;
        free(head);
        dispSondar();
    }
}

void sondagem(llint total){
    for(llint i=0;i<total;i++){
        dispSondar();
    }
}


int main(){
    bool game = true, dominou;
    llint xInicial, yInicial, pontoInicial, turnos;
    llint hcode;
    llint nSondagens=1;

    PQinit(100000);
    for(int i=0;i<primo+1;i++){
        sondados[i] = initLista();
    }
    edazinhos = initLista();

    scanf("%lld %lld %lld %lld", &xInicial, &yInicial, &pontoInicial, &turnos);

    listaPush(edazinhos, xInicial,yInicial);
    hcode = cHash(xInicial);
    listaPush(sondados[hcode],xInicial,yInicial);

    //printaLista(edazinhos);

    llint i = 0;
    while(game){
        dominou = false;
        if(i == turnos-1){
            game = false;
        }
        
        dominou = addEdazinho();
        sondagem(nSondagens);
        printf("fimturno\n");
        fflush(stdout);
        if(dominou){
            nSondagens++;
        }
        i++;
    }
    return 0;
}