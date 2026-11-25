#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*
 * IMPLEMENTAÇÃO DO ALUNO
 *
 * Resolva uma questão por vez. Não apague os contratos do arquivo listas.h.
 * Antes de implementar, desenhe os ponteiros em papel para os casos:
 *   - lista vazia;
 *   - lista com um único nó;
 *   - operação no primeiro nó;
 *   - operação no último nó.
 *
 * Os retornos abaixo são apenas stubs para permitir compilar o projeto.
 * Substitua cada TODO pela sua implementação.
 */

/* A. Simples sem cabeçote */

No *criarListaSimples(void)
{
    No *listaSimples = NULL;

    return listaSimples;
}

int inserirInicioSimples(No **lista, int valor)
{
    No *novo = (No *) malloc(sizeof(No));


    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;
    novo->prox = *lista;

    *lista = novo;

    return SUCESSO;
}

int inserirFinalSimples(No **lista, int valor)
{
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return FALHA;
    }

    No *atual = *lista;

    if(atual == NULL){
        novo->valor = valor;
        novo->prox = *lista;

        *lista = novo;

        return SUCESSO;
    }

    novo->valor = valor;
    novo->prox =  NULL;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;

    return SUCESSO;
}

int contarSimples(No *lista)
{
    int cont = 0;

    No *atual = lista;

    while(atual != NULL){
        atual = atual->prox;
        cont++;
    }

    return cont;
}

No *buscarSimples(No *lista, int valor)
{
    
    No *atual = lista;

    if(atual == NULL){
        return NULL;
    }

    while(atual != NULL){
        if(atual->valor == valor){
            return atual;
        }
        atual = atual->prox;
    }

    return NULL
}

/* B. Simples com cabeçote */

No *criarListaComCabecote(void)
{
    No *listaCabecote = (No *) malloc(sizeof(No));

    listaCabecote->prox = NULL;

    if(listaCabecote == NULL){
        return NULL;
    }

    return listaCabecote;
}

int inserirInicioComCabecote(No *cabecote, int valor)
{
    No *novo = (No *) malloc(sizeof(No));

    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;
    novo->prox = cabecote->prox;

    cabecote->prox = novo;

    return SUCESSO;
}
 
int inserirFinalComCabecote(No *cabecote, int valor)
{   
    No *novo = (No*) malloc(sizeof(No));

    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;

    No *atual = cabecote->prox;

    if(atual == NULL){
        novo->prox = cabecote->prox;

        cabecote->prox = novo;

        return SUCESSO;
    }

    novo->prox = NULL;

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;

    return SUCESSO;
}

int contarComCabecote(No *cabecote)
{
    int cont = 0;

    No *atual = cabecote->prox;

    while(atual != NULL){
        cont++;
        atual = atual->prox;
    }

    return cont;
}

/* C. Dupla sem cabeçote */

int inserirInicioDupla(NoDuplo **lista, int valor)
{
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;
    novo->prox = *lista;
    novo->ant = NULL;

    if(*lista != NULL){
        (*lista)->ant = novo;
    }

    *lista = novo;

    return SUCESSO;
}

int inserirFinalDupla(NoDuplo **lista, int valor)
{
    NoDuplo *novo = (NoDuplo*) malloc(sizeof(NoDuplo));

    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;
    novo->prox = NULL;
    novo->ant = NULL;

    NoDuplo *atual = *lista;

    if(*lista == NULL){
        *lista = novo;

        return SUCESSO;
    }

    while(atual->prox != NULL){
        atual = atual->prox;
    }

    atual->prox = novo;
    novo->ant = atual;

    return SUCESSO;
}

NoDuplo *buscarDupla(NoDuplo *lista, int valor)
{
    NoDuplo *atual = lista;

    while(atual != NULL){
        if(atual->valor == valor){
            return atual;
        }

        atual = atual->prox;
    }

    return NULL;
}

int removerValorDupla(NoDuplo **lista, int valor)
{
    NoDuplo *atual = *lista;

    if(*lista == NULL){
        return FALHA;
    }

    if(atual->prox == NULL && atual->valor == valor){
        *lista = NULL;
        free(atual);
        return SUCESSO;
    }

    while(atual != NULL && atual->valor != valor){
        atual = atual->prox;
    }

    if (atual == NULL) {
        return FALHA;
    }

    if(atual->ant == NULL){
        atual->prox->ant = NULL;
        *lista = atual->prox;
        free(atual);
        return SUCESSO;
    }

    if(atual->prox == NULL){
        atual->ant->prox = NULL;
        free(atual);
        return SUCESSO;
    }


    atual->ant->prox = atual->prox;
    atual->prox->ant = atual->ant;

    free(atual);

    return SUCESSO;

}

void imprimirInversaDupla(NoDuplo *lista)
{

    if(lista == NULL){
        printf("Lista Vazia");

        return;
    }
    NoDuplo *atual = lista;

    NoDuplo *ultimo = lista;

    while(atual->prox != NULL){
        atual = atual->prox;
        ultimo = atual;
    }

    while(ultimo != NULL){
        printf("Endereço no: %p\n", ultimo);
        printf("Endereço apontado por proximo deste no: %p\n", ultimo->prox);
        printf("Endereço apontado por anterior deste no: %p\n", ultimo->ant);
        printf("Valor do No %p: %d\n", ultimo, ultimo->valor);
        ultimo = ultimo->ant;
    }
}

/* D. Dupla com cabeçote */

NoDuplo *criarListaDuplaComCabecote(void)
{
    NoDuplo *listaCabeca = (NoDuplo *) malloc(sizeof(NoDuplo));

    listaCabeca->prox = NULL;

    if(listaCabeca == NULL){
        return NULL;
    }

    return listaCabeca;


}

int inserirInicioDuplaComCabecote(NoDuplo *cabecote, int valor)
{
    NoDuplo *novo = (NoDuplo *) malloc(sizeof(NoDuplo));

    if(novo == NULL){
        return FALHA;
    }

    novo->valor = valor;
    novo->ant = cabecote;
    novo->prox = cabecote->prox;

    if (cabecote->prox != NULL) {
        cabecote->prox->ant = novo;
    }

    cabecote->prox = novo;
    return SUCESSO;
}

int removerDuplaComCabecote(NoDuplo *cabecote, int valor)
{
    NoDuplo *atual = cabecote->prox;

    if(cabecote->prox == NULL){
        return FALHA;
    }

    while(atual != NULL && atual->valor != valor){
        atual = atual->prox;
    }

    if(atual != NULL){
        if(atual->ant == cabecote){
            cabecote->prox = atual->prox;

            if(atual->prox != NULL){
                atual->prox->ant = cabecote;
            }

            free(atual);
    
            return SUCESSO;
        }

        if(atual->prox == NULL){
            atual->ant->prox = NULL;
            free(atual);
            return SUCESSO;
        }

        atual->ant->prox = atual->prox;
        atual->prox->ant = atual->ant;

        free(atual);

        return SUCESSO;
    }

    return FALHA;
}

/* E. Circulares */

int inserirFinalCircular(No **lista, int valor)
{
    (void)lista; (void)valor;
    return FALHA; /* TODO 18 */
}

int contarCircular(No *lista)
{
    (void)lista;
    return 0; /* TODO 19 */
}

No *criarCircularComCabecote(void)
{
    return NULL; /* TODO 20 */
}

int inserirFinalCircularComCabecote(No *cabecote, int valor)
{
    (void)cabecote; (void)valor;
    return FALHA; /* TODO 21 */
}

NoDuplo *criarCircularDuplaComCabecote(void)
{
    return NULL; /* TODO 22 */
}

/* F. Consolidação */

int concatenarSimples(No **listaA, No **listaB)
{
    (void)listaA; (void)listaB;
    return FALHA; /* TODO 23 */
}

void inverterSimples(No **lista)
{
    (void)lista; /* TODO 24 */
}

void liberarSimples(No **lista)
{
    (void)lista; /* TODO 25 */
}
