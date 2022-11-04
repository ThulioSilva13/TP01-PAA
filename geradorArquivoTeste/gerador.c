#include "fazenda.h"

void menu(){

    printf("\n\n=========== MENU ===========");
    printf("\n1) Arquivo sem Solucao");
    printf("\n2) Arquivo com Solucao");
    printf("\n3) Encerrar");
    printf("\nEscolha: ");
}

int main(){

    int opcao, linhas, colunas;
    
    while(1){ //enquanto verdaade

        menu();
        scanf("%d",&opcao);

        if( opcao == 3){
            printf("\n==== PROGRAMA ENCERRADO ====\n");
            break;
        }

        if((opcao!=1) && (opcao!=2)){
            printf("\nErro: OPCAO INVALIDA!");  
        }

        else{
            printf("\nEntre com as dimensoes da fazenda: \n- comprimento = ");
            scanf("%d",&linhas);
            printf("- largura = ");
            scanf("%d",&colunas);

            if (linhas>100) linhas = 100;
            if (colunas>100) colunas= 100;

            Elemento **matriz;

            matriz = (Elemento**) malloc(linhas*sizeof(Elemento*));
            for(int i=0; i<linhas; i++)
                matriz [i] = (Elemento*)calloc(colunas,sizeof(Elemento)); //alocar e já inicializar com 0

            if (opcao == 1){
                printf("\n==== SEM CAMINHO OTIM0 =====\n");

                
                preenche_aleatoriamente(matriz, linhas, colunas);
            }
            else{ //opcao == 2
                printf("\n==== COM CAMINHO OTIM0 =====\n");
                preenche_caminho(matriz, linhas, colunas);
                preenche_aleatoriamente(matriz, linhas, colunas); //preencher posições que nao fazem parte do caminho
            }
            printa_matriz(matriz, linhas, colunas);
            printa_arquivo(matriz, linhas, colunas);
        }
    }
    return 0;
}