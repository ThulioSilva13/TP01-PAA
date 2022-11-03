#include "pilha.h"

void FPVazia(TipoPilha *Pilha){ 
  Pilha->Topo = (TipoApontadorPilha) malloc(sizeof(TipoCelula));
  Pilha->Fundo = Pilha->Topo;
  Pilha->Topo->Prox = NULL;
  Pilha->Tamanho = 0;
  Pilha->qntdRecursao = 0;
  Pilha->nivelRecursao = calloc(5,sizeof(int));
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
  //printf("\nEmpilhou: %d %d", x.celulaMatriz.posicaoLinha, x.celulaMatriz.posicaoColuna);
} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ 
  TipoApontadorPilha q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
  // printf ("\nDesempilhou: %d %d", Item->celulaMatriz.posicaoLinha, Item->celulaMatriz.posicaoColuna);
} 

int Tamanho(TipoPilha Pilha)
{ return (Pilha.Tamanho); } 

int QntdRecursao(TipoPilha Pilha){ return (Pilha.qntdRecursao); }

void Imprime_QuantidadeRecursaoDirecao(TipoPilha Pilha){
    printf("Baixo[%d] ",Pilha.nivelRecursao[0]);
    printf("Direita[%d] ",Pilha.nivelRecursao[1]);
    printf("Esquerda[%d] ",Pilha.nivelRecursao[2]);
    printf("Cima[%d] ",Pilha.nivelRecursao[3]);
    printf("Recursao fora do if[%d]",Pilha.nivelRecursao[4]-(Pilha.nivelRecursao[0]+Pilha.nivelRecursao[3]+Pilha.nivelRecursao[1]+Pilha.nivelRecursao[2]));
}

void imprimePilhaInvertida(TipoPilha *pilhaAuxiliar){
    TipoApontadorPilha apAuxiliar;
    apAuxiliar = (*pilhaAuxiliar).Topo->Prox;
    if(Vazia(*pilhaAuxiliar)){
        //printf("A pilha esta vazia!\n");
        return;
    }
    else{
        while( apAuxiliar !=NULL){
            // printf("%d %d => valor: %d => visitado: %d",apAuxiliar->Item.celulaMatriz.posicaoLinha+1, 
            // apAuxiliar->Item.celulaMatriz.posicaoColuna+1, apAuxiliar->Item.celulaMatriz.valor,apAuxiliar->Item.celulaMatriz.visitado);
            printf("%d %d",apAuxiliar->Item.celulaMatriz.posicaoLinha,  apAuxiliar->Item.celulaMatriz.posicaoColuna);
            printf("\n");
            apAuxiliar = apAuxiliar->Prox;
        }
        printf("\n");
    }
}

void invertePilha(TipoPilha *pilha){  
    TipoPilha pilhaAuxiliar;
    TipoItem itemPilhaAuxiliar;

    TipoApontadorPilha ap;
    ap = pilha->Topo->Prox;

    FPVazia(&pilhaAuxiliar);
    if(Vazia(*pilha)){
        //printf("A pilha esta vazia!\n");
        return;
    }
    else{
        while( ap !=NULL){
            itemPilhaAuxiliar.celulaMatriz.valor = ap->Item.celulaMatriz.valor;
            itemPilhaAuxiliar.celulaMatriz.posicaoLinha = ap->Item.celulaMatriz.posicaoLinha;
            itemPilhaAuxiliar.celulaMatriz.posicaoColuna = ap->Item.celulaMatriz.posicaoColuna;
            Empilha(itemPilhaAuxiliar, &pilhaAuxiliar);
            ap = ap->Prox;
        }
        printf("\n");
    }
    imprimePilhaInvertida(&pilhaAuxiliar);
}

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