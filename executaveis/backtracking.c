#include "backtracking.h"

TipoPilha pilha;

/*
//bool solveMazeUtil(int maze[N][N], int x, int y,int sol[N][N]);

// A utility function to print solution matrix sol[N][N]
void printSolution(int sol[N][N])
{
	for (int i = 0; i < N; i++) {
		for (int j = 0; j < N; j++)
			printf(" %d ", sol[i][j]);
		printf("\n");
	}
}


// A utility function to check if x, y is valid index for
// N*N maze
*/

void achaCaminho(Celula **matriz, int numLinhas, int numColunas){

	TipoItem item;
    FPVazia(&pilha);

	int *caminho = malloc((numLinhas*numColunas)*sizeof(int));
	caminho = criaCaminho(numLinhas, numColunas);

	//printaCaminho(caminho, numLinhas, numColunas);
	
	int indiceCaminho = 0;
	
	if (confereCaminho(matriz, numLinhas, numColunas, 0, 0, &pilha, caminho, &indiceCaminho) == false) {
		printf("\n\nImpossivel!");
		return;
	}

	for(int i = 0; i < Tamanho(pilha); i++){ 
		Desempilha (&pilha, &item);
      	printf ("\n\nDesempilhou: %d \n", item.celulaMatriz.valor);
    }
    
	return;
}

bool verificaPosicao(Celula **matriz, int numLinhas, int numColunas, int x, int y, int *caminho, int indiceCaminho)
{
	printf("\n\nEntrou na verifica caminho: ");
	printf("\n\n Matriz[%d][%d]: %d", x,y,matriz[x][y].valor);
	printf("\n\n Caminho[*indiceCaminho]: %d", caminho[indiceCaminho]);
	

	// if (x, y outside maze) return false
	if (x >= 0 && x < numLinhas && y >= 0 && y < numColunas && matriz[x][y].valor == caminho[indiceCaminho]) //passar qual valor tem q comparar: contador
		return true;
	return false;
}

// A recursive utility function to solve Maze problem
bool confereCaminho(Celula **matriz, int numLinhas, int numColunas, int x, int y, TipoPilha* pilha, int *caminho, int *indiceCaminho)
{
	//printaCaminho(caminho, numLinhas, numColunas);
	
	TipoItem item;

	printf("\n\n indice %d", *indiceCaminho);
	printf("\n\n caminho[0]: %d", caminho[0]);
	printf("\n\n caminho[*indiceCaminho]: %d", caminho[*indiceCaminho]);
	printf("\n\n matriz[%d][%d]: %d", x,y,matriz[x][y].valor);

	if (x == numLinhas - 1 && matriz[x][y].valor == caminho[*indiceCaminho]) {
		printf("\n\n matriz[x][y]: %d", matriz[x][y].valor);
		item.celulaMatriz = matriz[x][y];
		Empilha(item , pilha);
		return true;
	}
	
	// Verifica se a posicao é valida
	if (verificaPosicao(matriz, numLinhas, numColunas, x, y, caminho, *indiceCaminho) == true) {
		// Check if the current block is already part of
		// solution path.
		if (matriz[x][y].visitado == true)
			return false;
		// mark x, y as part of solution path
		Empilha(item , pilha);
		indiceCaminho ++;
		//Primeira opção de caminho: 
		// Andar para baixo
		
		if (confereCaminho(matriz, numLinhas, numColunas, x+1, y, pilha, caminho, indiceCaminho) == true)
			printf("chamou pra baixo");
			return true;
		//Se para baixo não der solução:
		//Andar para direita
		
		if (confereCaminho(matriz, numLinhas, numColunas, x, y+1, pilha, caminho, indiceCaminho) == true)
			printf("chamou pra direita");
			return true;
		//Se para direita não der solução:
		//Andar para esquerda

		if (confereCaminho(matriz, numLinhas, numColunas, x, y-1, pilha, caminho, indiceCaminho) == true)
			printf("chamou pra esquerda");
			return true;
		//Se para esquerda não der solução:
		//Andar para cima
		if (confereCaminho(matriz, numLinhas, numColunas, x-1, y, pilha, caminho, indiceCaminho) == true)
			printf("chamou pra cima");
			return true;
		
		//se para cima não der solução => nao tem: desmarcar posição e voltar indiceCaminho
		Desempilha (pilha, &item);
		indiceCaminho --;
		return false;
	}
	return false;
}

int* criaCaminho(int N, int M){
	int *caminho = calloc((N*M),sizeof(int));
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
	int max = numLinha*numColuna;
	printf("\nCaminho = ");
    for (int i = 0; i < max; i++){
        printf("%d-", caminho[i]);
    }
}
