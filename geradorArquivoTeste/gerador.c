#include "fazenda.h"

void menu(){
    printf("\n---------------------------------------------------------------------");
    printf("\nMENU");
    printf("\n---------------------------------------------------------------------");
    printf("\n[ 1 ] | Arquivo sem Solucao");
    printf("\n[ 2 ] | Arquivo com Soulucao");
    printf("\n[ 3 ] | Encerrar");
    printf("\nEscolha: ");
}

int main(){

    int opcao, linhas, colunas;
    
    while(1){ //enquanto verdaade

        menu();
        scanf("%d",&opcao);

        if( opcao == 3){
            printf("\n---------------------------------------------------------------------");
            printf("\nPROGAMA ENCERRADO");
            printf("\n---------------------------------------------------------------------\n");
            break;
        }

        if((opcao!=1) && (opcao!=2)){
            printf("\nErro: OPCAO INVALIDA!");  
        }

        else{
            printf("\nEntre com as dimensões da fazenda: \n- N = ");
            scanf("%d",&linhas);
            printf("- M = ");
            scanf("%d",&colunas);

            if (linhas>100) linhas = 100;
            if (colunas>100) colunas= 100;
            

            Elemento **matriz;

            matriz = (Elemento**) malloc(linhas*sizeof(Elemento*));
            for(int i=0; i<linhas; i++)
                matriz [i] = (Elemento*)calloc(colunas,sizeof(Elemento)); //alocar e já inicializar com 0

            if (opcao == 1){
                printf("\n---------------------------------------------------------------------");
                printf("\nMATRIZ SEM SOLUÇÃO");
                printf("\n---------------------------------------------------------------------\n");
                preenche_aleatoriamente(matriz, linhas, colunas);
            }
            else{ //opcao == 2
                printf("\n---------------------------------------------------------------------");
                printf("\nMATRIZ COM SOLUÇÃO");
                printf("\n---------------------------------------------------------------------\n");
                preenche_caminho(matriz, linhas, colunas);
                preenche_aleatoriamente(matriz, linhas, colunas); //preencher posições que nao fazem parte do caminho
            }
            printa_matriz(matriz, linhas, colunas);
            printa_arquivo(matriz, linhas, colunas);
        }
    }
    return 0;
}