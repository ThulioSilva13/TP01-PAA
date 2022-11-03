#include "backtracking.h"

void achaCaminho(Celula **matriz, int numLinhas, int numColunas, int modoAnalise){

	TipoPilha pilha;
    FPVazia(&pilha);

	int *caminho = malloc((numLinhas*numColunas)*sizeof(int));
	caminho = criaCaminho(numLinhas, numColunas);
	
	int indiceCaminho = 0;
	int countFalse = 0;

	for(int i=0; i<numColunas; i++){
		if (movimentar(matriz, numLinhas, numColunas, 0, i, &pilha, caminho, &indiceCaminho) == false) {
			countFalse++;
		}
		else{
			printf("\n\nEncontrou Caminho!");
			invertePilha(&pilha);
			printaMatriz(matriz, numLinhas, numColunas);
			break;
		}
	}

	if (countFalse == (numColunas)){
		printf("\n\nImpossivel!");
	}

	if (modoAnalise == 1){
		printf("\nQuantidade de chamadas recursivas: %d\n", QntdRecursao(pilha));
		Imprime_QuantidadeRecursaoDirecao(pilha);
	}

	return;
}

bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas, int x, int y, int *caminho, int indiceCaminho)
{
	// if (x, y outside maze) return false
	if ((x >= 0 && x < numLinhas) && (y >= 0 && y < numColunas) &&
	 (matriz[x][y].valor == caminho[indiceCaminho])){		
		return true;
	} //passar qual valor tem q comparar: contador
	
	return false;
}

// A recursive utility function to solve Maze problem
bool movimentar(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha, int *caminho, int *indiceCaminho)
{
	TipoItem item;
	pilha->nivelRecursao[4]++;
	pilha->qntdRecursao++;

	int novoIndice = *indiceCaminho;

	// Verifica se a posicao é valida
	if (verificaPosicao(matriz, numLinhas, numColunas, x, y, caminho, novoIndice) == true) {
		
		if ((x == numLinhas - 1) && (matriz[x][y].valor == caminho[novoIndice])) {
			item.celulaMatriz = matriz[x][y];		

			//item.celulaMatriz.visitado = true;
			strcpy(matriz[x][y].cor, ANSI_COLOR_GREEN);
			Empilha(item , pilha);
			return true;
		}
		
		// Check if the current block is already part of solution path.
		// if (matriz[x][y].visitado != true){
		// 	item.celulaMatriz = matriz[x][y];
		// 	Empilha(item , pilha);
		// }

		if (matriz[x][y].visitado == true){
			return false;
		}

		// mark x, y as part of solution path
		matriz[x][y].visitado = true;
		strcpy(matriz[x][y].cor, ANSI_COLOR_GREEN);
		
		item.celulaMatriz = matriz[x][y];
		Empilha(item,pilha);
		novoIndice ++;
		
		//Primeira opção de caminho: 
		// Andar para baixo
		// printf("tenta pra baixo");
		
		pilha->nivelRecursao[0] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x+1, y, pilha, caminho, &novoIndice) == true){
			// printf("chamou pra baixo");
			return true;
		}
			
		//Se para baixo não der solução:
		//Andar para direita
		// printf("\ntenta pra direita");

		pilha->nivelRecursao[1] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x, y+1, pilha, caminho, &novoIndice) == true){
			return true;
		}
			
		//Se para direita não der solução:
		//Andar para esquerda

		// printf("\ntenta pra esquerda");
		pilha->nivelRecursao[2] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x, y-1, pilha, caminho, &novoIndice) == true){
			return true;
		}
		//Se para esquerda não der solução:
		//Andar para cima
		
		pilha->nivelRecursao[3] += 1;
		if (movimentar(matriz, numLinhas, numColunas, x-1, y, pilha, caminho, &novoIndice) == true){
			return true;
		}
		
		//se para cima não der solução => nao tem: desmarcar posição e voltar indiceCaminho
		
		Desempilha (pilha, &item);
		matriz[x][y].visitado = false;
		strcpy(matriz[x][y].cor, ANSI_COLOR_DEFAULT);
		indiceCaminho--;
		return false;
	}
	return false;
}

int* criaCaminho(int N, int M){
	int *caminho = malloc((N*M)*sizeof(int));
    int max = N*M;
    int indice = 0;
    int qtd = 1;
    while (indice < max) {
        for (int i = 1; i < qtd; i++){
			if (indice == max){
				return caminho;
			}
            caminho[indice] = fibonacci(i);
            indice ++;
        }
        qtd++;
    }

	return caminho;
}

int fibonacci(int n)
{ 
    int i = 1, k, F = 0;
    for (k = 1; k <= n; k++)
    { 
        F += i;  i = F - i;
    }
    return F;
}

void printaCaminho(int *caminho, int numLinha, int numColuna){
	int max = numLinha * numColuna;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++){
        printf("%d-", caminho[i]);
    }
}
