#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "./executaveis/lerArquivos.h"
#include "./executaveis/matriz.h"

int menu(int opcao){
    printf("\n======= MENU =======");
    printf("\n0) Sair");
    printf("\n1) Ler Arquivo e montar a matriz");
    printf("\nEscolha: ");
    scanf("%d",&opcao);
    return opcao;
}

int main(int argc, char **argv){
    int **matriz;
    //int *linhas,*colunas;
    int opcao = -1;
    char **nomeArquivo;

    nomeArquivo = malloc(sizeof(char) * 30);
    *nomeArquivo = argv[1];
    
    while(opcao != 0){
        opcao = menu(opcao);
        switch (opcao)
        {
        case 0:
            break;
        case 1:
            if (*nomeArquivo == NULL)
            {
                char nomeArqv[30];
                printf("\nDigite o nome do arquivo .txt: ");            
                scanf("%s", nomeArqv);
                *nomeArquivo = nomeArqv;               
            }
            lerArquivoPrincipal(nomeArquivo, matriz);
            break;
        default:
            break;
        }
    }

    return 0;
}