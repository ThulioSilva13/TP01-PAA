#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./executaveis/lerArquivo.h"
#include "./executaveis/matriz.h"
#include "./executaveis/backtracking.h"

int menu(int opcao){
    printf("\n\n======= MENU =======");
    printf("\n0) Sair");
    printf("\n1) Ler arquivo e montar a matriz");
    printf("\nEscolha: ");
    scanf("%d",&opcao);
    return opcao;
}

int menuAnalise(int modoAnalise){
    printf("\nAtivar modo analise?: ");
    printf("\n0) Nao");
    printf("\n1) Sim");
    printf("\nEscolha: ");
    scanf("%d", &modoAnalise);
    return modoAnalise;
}
int main(int argc, char **argv){
    Celula **matriz;
    int opcao = -1;
    char **nomeArquivo;
    int numLinhas, numColunas;

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
            if (lerArquivoPrincipal(nomeArquivo, &numLinhas,&numColunas, &matriz) == 1)
            {
                if (numLinhas > 100 || numColunas > 100)
                {
                    printf("\nNúmero de linhas ou colunas maiores que 100.");
                    break;
                }
                
                int modoAnalise  = menuAnalise(modoAnalise);
                achaCaminho(matriz, numLinhas, numColunas, modoAnalise);
                liberaMatriz(matriz, numLinhas);
            }                 
            break;
        default:
            break;
        }
    }
    return 0;
}