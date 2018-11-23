#include<stdio.h>
#include<stdlib.h>
#include<string.h>

struct lista{
    int peso;
    struct cidade *cidade;
    struct lista *prox; 

};

struct  cidade{
    char nome[15];
    struct lista *caminhos; 
};

typedef struct cidade Cidade;
typedef struct lista Lista;

void cadastraCaminho(Cidade *cidade){
    int novoPeso=100;
    Lista *novoCaminho, *p;
    novoCaminho=(Lista) malloc(sizeof(Lista));
    if(cidade->caminhos!=NULL){
        for(p=cidade->caminhos; p->prox != NULL || p->prox->peso < novoPeso; p=p->prox);        
        if(p->prox==NULL)novoCaminho->prox=NULL;
        else novoCaminho->prox=p->prox;
        p->prox=novoCaminho;
        novoCaminho->peso=novoPeso;
    }
    
    
   // novoCaminho->peso=123;




}
Cidade *cadastra(Cidade *novaCidade);

int main(){
    
    Cidade *cidadeOrigem=NULL;
    cidadeOrigem=cadastra(cidadeOrigem);
    puts(cidadeOrigem->nome);
}



Cidade *cadastra(Cidade *cidadeOrigem){
    if(cidadeOrigem==NULL){
        Cidade *novaCidade=NULL;
        novaCidade=(Cidade*) malloc(sizeof(Cidade));
        strcpy(novaCidade->nome, "Santa maria");
        cidadeOrigem=novaCidade;
        novaCidade->caminhos=NULL;
    }else{
        Cidade *novaCidade=NULL;
        novaCidade=(Cidade*) malloc(sizeof(Cidade));
        strcpy(novaCidade->nome, "Santa maria");
        cadastraCaminho(novaCidade);

    }
    return cidadeOrigem;
    



}