#include <stdio.h>
#include <stdlib.h>
#include <ctype.h>

typedef struct Cidade
{
    char nome[28];
    char ultimaLetra;

}Cidade;

int main(int argc, char const *argv[])
{
    int contador = 0;
    int tamanho = 0;
    Cidade *cidade = malloc(sizeof(Cidade)*(1000000));

    while(scanf(" %s", cidade[contador].nome) != EOF){
        while(cidade[contador].nome[tamanho] != '\0')
            tamanho++;
        cidade[contador].ultimaLetra = toupper(cidade[contador].nome[tamanho-1]);
        contador++;
        tamanho = 0;
    }

    printf("%s\n",cidade[0].nome);
    for (int i = 1; i < contador; i++)
    {
        if(cidade[i - 1].ultimaLetra == cidade[i].nome[0]){
            Cidade aux = cidade[i];
            for (int j = i; j < contador; j++)
                cidade[j] = cidade[j + 1];

            cidade[contador - 1] = aux;
            i--;
        }else
            printf("%s\n", cidade[i].nome);
    }
    return 0;
}

