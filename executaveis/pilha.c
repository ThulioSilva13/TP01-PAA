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
} 

void Desempilha(TipoPilha *Pilha, TipoItem *Item)
{ 
  TipoApontadorPilha q;
  if (Vazia(*Pilha)) { printf("Erro: lista vazia\n"); return; }
  q = Pilha->Topo;
  Pilha->Topo = q->Prox;
  *Item = q->Prox->Item;
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
    int maior = Pilha.nivelRecursao[0];
    for (int i = 0; i < 4; i++) 
    {
       if (Pilha.nivelRecursao[i] > maior)
           maior = Pilha.nivelRecursao[i];
    }
    printf("\nNivel maximo de recursao: %d", maior);
}

void imprimePilhaInvertida(TipoPilha *pilhaAuxiliar){
    TipoApontadorPilha apAuxiliar;
    apAuxiliar = (*pilhaAuxiliar).Topo->Prox;
    if(Vazia(*pilhaAuxiliar)){
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