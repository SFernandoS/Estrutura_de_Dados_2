#include <stdio.h>
#include <stdlib.h>

//#define hash(v, M) (v % M) // Ok, para n primos
#define hash(chave, tamanhoHash) ((618033 * (unsigned) chave) % tamanhoHash)
#define Key(x) (x.chave)
#define less(a,b) (Key(a) < Key(b))
#define eq(a,b) (a == b)
#define null(A) (Key(hashTable[A]) == Key(NULLItem))

typedef struct Item{
    int chave;
    long e1, e2;
    long elemento;
} Item; Item NULLItem = {0, 0, 0, 0};


static int numElementos, tamanhoHash;
static Item *hashTable;

void HTInit(int max){
    int aux;
    numElementos = 0;
    tamanhoHash = 2 * max;
    hashTable = malloc(sizeof(Item)*tamanhoHash);

    for (aux = 0; aux < tamanhoHash; aux++)
    {
        hashTable[aux] = NULLItem;
    }
}

int HTCount() { return numElementos;}

void HTInsert(Item item){
    int chave = Key(item);
    int aux = hash(chave, tamanhoHash);

    while(!null(aux)) aux = (aux + 1) % tamanhoHash;

        hashTable[aux] = item;
        numElementos++; //quantidade de elementos
}

Item HTSearch(int chave){
    int aux = hash(chave, tamanhoHash);

    while(!null(aux)){
        if(eq(chave, Key(hashTable[aux])))
            return hashTable[aux];
        else
            aux = (aux + 1) % tamanhoHash;
    }
    return NULLItem;
}


int main(int argc, char const *argv[])
{
    Item first = {1, 2, 3, 4};
    HTInit(50);
    HTInsert(first);
    printf("%ld\n", HTSearch(1).elemento);
    return 0;
}

// O custo do calculo dessa Hash começa a ficar caro, pois percorre toda a v
/*int hashU(char *v, int M){
    int valorHash, a = 31415, b = 27183;

    for (h = 0; *v != 0; v++)
    {
        a = a * b % (M - 1);
        valorHash = (a * h + *v) % M;

    }
    return valorHash;
}*/