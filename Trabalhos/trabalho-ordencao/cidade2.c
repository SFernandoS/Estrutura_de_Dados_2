#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Cidade
{
    char nome[28];
    char ultimaLetra;

}Cidade;

Cidade *calcula(Cidade *cidade, int *contador);

int main(int argc, char const *argv[])
{
    int contador = 0;
    int tamanho = 0;
    int sentinela = 1;
    Cidade *cidade = calloc(29, sizeof(Cidade)*(1000000));

    while(scanf(" %s", cidade[contador].nome) != EOF){
        while(cidade[contador].nome[tamanho] != '\0')
            tamanho++;
        cidade[contador].ultimaLetra = toupper(cidade[contador].nome[tamanho-1]);
        contador++;
        tamanho = 0;
    }

    while(cidade[0].ultimaLetra != 0)
    {
        cidade = calcula(cidade, &contador);
    }

    return 0;
}

Cidade *calcula(Cidade *cidade, int *contador){
    Cidade *aux = calloc(29, sizeof(Cidade)*(1000000));
    int auxContador = 0;
    int sentinela = 1;

    printf("%s\n",cidade[0].nome);
    for (int i = 1; i < *contador; i++)
    {
        if(cidade[i - 1].ultimaLetra == cidade[i].nome[0] && sentinela){
            aux[auxContador] = cidade[i];
            auxContador++;
            sentinela = 0;    
        }else{
            sentinela = 1;
            printf("%s\n", cidade[i].nome);
        }
    }
    free(cidade);
    *contador = auxContador;
    return aux;
}

