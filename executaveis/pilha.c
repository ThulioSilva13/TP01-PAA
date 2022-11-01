#include "pilha.h"

void FPVazia(TipoPilha *Pilha){ 
  Pilha->Topo = (TipoApontadorPilha) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
} 

int Vazia(TipoPilha Pilha)
{ return (Pilha.Topo == Pilha.Fundo); } 

void Empilha(TipoItem x, TipoPilha *Pilha){
  TipoApontadorPilha Aux;
  Aux = (TipoApontadorPilha) malloc(sizeof(TipoCelula));
  Pilha->Topo->Item = x;
  Aux->Prox = Pilha->Topo;
  Pilha->Topo = Aux;
  Pilha->Tamanho++;
  printf("\nEmpilhou: %d %d", x.celulaMatriz.posicaoLinha, x.celulaMatriz.posicaoColuna);
} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ 
  TipoApontadorPilha q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  printf ("\nDesempilhou: %d %d", Item->celulaMatriz.posicaoLinha, Item->celulaMatriz.posicaoColuna);
  //free(q);  
  //Pilha->Tamanho--;
} 

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); } 
/*
void printaPilha(TipoPilha *pilha){
  if (pilha->elementos==0) // pilha vazia  
 {
  printf("Nao ha elementos na pilha.\n"); // pilha zerada, mensagem de erro
  return;         // retorna a main
 }

for (int i=0;i<mystack->elementos;i++)  // Estrutura de repetição, corre os elementos do vetor

 printf( "%d ", mystack->elemento1[i]); // imprime o numero, e segue um espaço " ".

   printf("\n");        // enter no final
}
*/
/*
int main(int argc, char *argv[])
{ struct timeval t;
  TipoPilha pilha;
  TipoItem item;
  int vetor[MAX];
  int i, j, k, n;
 
  gettimeofday(&t,NULL);
  srand((unsigned int)t.tv_usec);
 
  FPVazia(&pilha);
  
  //Gera uma permutacao aleatoria de chaves entre 1 e MAX
  for(i = 0; i < MAX; i++) vetor[i] = i + 1;
  for(i = 0; i < MAX; i++)
    { k =  (int) (10.0*rand()/(RAND_MAX + 1.0));

      j =  (int) (10.0*rand()/(RAND_MAX + 1.0));
      n = vetor[k];
      vetor[k] = vetor[j];
      vetor[j] = n;
    }
  //Empilha cada chave 
  for (i = 0; i < MAX; i++)
    { item.Chave = vetor[i];
      Empilha(item, &pilha);
      printf("Empilhou: %d \n", item.Chave);
    }
  printf("Tamanho da pilha: %d \n", Tamanho(pilha));
  

  //Desempilha cada chave 
  for(i = 0; i < MAX; i++)
    { Desempilha (&pilha,&item);
      printf ("Desempilhou: %d \n", item.Chave);
    }
  printf("Tamanho da pilha: %d\n", Tamanho(pilha));
  return(0);
}
*/