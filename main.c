#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include "./executaveis/lerArquivo.h"
#include "./executaveis/matriz.h"
#include "./executaveis/backtracking.h"

int menu(int opcao){
    printf("\n======= MENU =======");
    printf("\n0) Sair");
    printf("\n1) Ler arquivo e montar a matriz");
    printf("\nEscolha: ");
    scanf("%d",&opcao);
    return opcao;
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
                printaMatriz(matriz,numLinhas,numColunas);
                //LiberaMatriz(matriz, l);  
            }
            
            
            
            //criaCaminho(numLinhas, numColunas);
            //printaCaminho(caminho);  
            
            achaCaminho(matriz, numLinhas, numColunas);     
   
            break;
        default:
            break;
        }
    }
    return 0;
}