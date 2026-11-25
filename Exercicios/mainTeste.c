#include <stdio.h>
#include <stdlib.h>
#include "listas.h"

/*
 * TESTES AUTOMATICOS
 *
 * Compile:
 * gcc -Wall -Wextra -Wpedantic listas.c mainTeste.c -o testes
 *
 * Execute:
 * ./testes
 *
 * Cada teste verifica uma funcao. Enquanto a funcao estiver como TODO em
 * listas.c, o teste correspondente provavelmente falhara.
 */

static int totalTestes = 0;
static int aprovados = 0;
static int reprovados = 0;

#define VERIFICAR(condicao, descricao) do { \
    totalTestes++; \
    if (condicao) { \
        aprovados++; \
        printf("[OK]   %s\n", descricao); \
    } else { \
        reprovados++; \
        printf("[ERRO] %s\n", descricao); \
    } \
} while (0)

static int valoresIguais(No *lista, const int esperados[], int quantidade)
{
    int i = 0;

    while (lista != NULL && i < quantidade) {
        if (lista->valor != esperados[i]) {
            return 0;
        }
        lista = lista->prox;
        i++;
    }

    return lista == NULL && i == quantidade;
}

static int valoresIguaisCabecote(No *cabecote, const int esperados[], int quantidade)
{
    if (cabecote == NULL) {
        return 0;
    }

    return valoresIguais(cabecote->prox, esperados, quantidade);
}

static int valoresIguaisDupla(NoDuplo *lista, const int esperados[], int quantidade)
{
    int i = 0;
    NoDuplo *anterior = NULL;

    while (lista != NULL && i < quantidade) {
        if (lista->valor != esperados[i] || lista->ant != anterior) {
            return 0;
        }

        anterior = lista;
        lista = lista->prox;
        i++;
    }

    return lista == NULL && i == quantidade;
}

static void liberarDuplaTeste(NoDuplo **lista)
{
    NoDuplo *atual = *lista;

    while (atual != NULL) {
        NoDuplo *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    *lista = NULL;
}

static void liberarCircularTeste(No **lista)
{
    if (*lista == NULL) {
        return;
    }

    No *inicio = *lista;
    No *atual = inicio->prox;

    while (atual != inicio) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(inicio);
    *lista = NULL;
}

static void liberarCircularCabecoteTeste(No *cabecote)
{
    if (cabecote == NULL) {
        return;
    }

    No *atual = cabecote->prox;

    while (atual != cabecote) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }

    free(cabecote);
}

static void testarListaSimplesSemCabecote(void)
{
    printf("\n=== A. SIMPLES SEM CABECOTE ===\n");

    No *lista = criarListaSimples();
    VERIFICAR(lista == NULL, "01 - criar lista vazia");

    int r1 = inserirInicioSimples(&lista, 20);
    int r2 = inserirInicioSimples(&lista, 10);
    int r3 = inserirFinalSimples(&lista, 30);
    int esperado[] = {10, 20, 30};

    VERIFICAR(r1 == SUCESSO && r2 == SUCESSO && r3 == SUCESSO &&
              valoresIguais(lista, esperado, 3),
              "02/03 - inserir no inicio e no final");

    VERIFICAR(contarSimples(lista) == 3, "04 - contar nos");

    No *encontrado = buscarSimples(lista, 20);
    No *ausente = buscarSimples(lista, 99);

    VERIFICAR(encontrado != NULL && encontrado->valor == 20 && ausente == NULL,
              "05 - buscar valor existente e inexistente");

    liberarSimples(&lista);
}

static void testarListaSimplesComCabecote(void)
{
    printf("\n=== B. SIMPLES COM CABECOTE ===\n");

    No *cabecote = criarListaComCabecote();

    VERIFICAR(cabecote != NULL && cabecote->prox == NULL,
              "06 - criar cabecote vazio");

    if (cabecote == NULL) {
        return;
    }

    int r1 = inserirInicioComCabecote(cabecote, 20);
    int r2 = inserirInicioComCabecote(cabecote, 10);
    int r3 = inserirFinalComCabecote(cabecote, 30);
    int esperado[] = {10, 20, 30};

    VERIFICAR(r1 == SUCESSO && r2 == SUCESSO && r3 == SUCESSO &&
              valoresIguaisCabecote(cabecote, esperado, 3),
              "07/08 - inserir no inicio e no final");

    VERIFICAR(contarComCabecote(cabecote) == 3,
              "09 - contar elementos sem contar cabecote");

    No *atual = cabecote->prox;
    while (atual != NULL) {
        No *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(cabecote);
}

static void testarListaDuplaSemCabecote(void)
{
    printf("\n=== C. DUPLA SEM CABECOTE ===\n");

    NoDuplo *lista = NULL;

    int r1 = inserirInicioDupla(&lista, 20);
    int r2 = inserirInicioDupla(&lista, 10);
    int r3 = inserirFinalDupla(&lista, 30);
    int esperado[] = {10, 20, 30};

    VERIFICAR(r1 == SUCESSO && r2 == SUCESSO && r3 == SUCESSO &&
              valoresIguaisDupla(lista, esperado, 3),
              "10/11 - inserir no inicio e no final, mantendo ant/prox");

    NoDuplo *encontrado = buscarDupla(lista, 20);
    NoDuplo *ausente = buscarDupla(lista, 99);

    VERIFICAR(encontrado != NULL && encontrado->valor == 20 && ausente == NULL,
              "12 - buscar valor existente e inexistente");

    int removido = removerValorDupla(&lista, 20);
    int depoisRemocao[] = {10, 30};

    VERIFICAR(removido == SUCESSO &&
              valoresIguaisDupla(lista, depoisRemocao, 2),
              "13 - remover valor do meio");

    printf("14 - imprimir inversa: ");
    imprimirInversaDupla(lista);
    printf("     (confira visualmente a ordem: 30 10)\n");

    liberarDuplaTeste(&lista);
}

static void testarListaDuplaComCabecote(void)
{
    printf("\n=== D. DUPLA COM CABECOTE ===\n");

    NoDuplo *cabecote = criarListaDuplaComCabecote();

    VERIFICAR(cabecote != NULL &&
              cabecote->prox == NULL && cabecote->ant == NULL,
              "15 - criar cabecote duplo vazio");

    if (cabecote == NULL) {
        return;
    }

    int r1 = inserirInicioDuplaComCabecote(cabecote, 20);
    int r2 = inserirInicioDuplaComCabecote(cabecote, 10);

    VERIFICAR(r1 == SUCESSO && r2 == SUCESSO &&
              cabecote->prox != NULL &&
              cabecote->prox->valor == 10 &&
              cabecote->prox->prox != NULL &&
              cabecote->prox->prox->valor == 20 &&
              cabecote->prox->ant == cabecote,
              "16 - inserir no inicio logico e ligar ant/prox");

    int removido = removerDuplaComCabecote(cabecote, 10);

    VERIFICAR(removido == SUCESSO &&
              cabecote->prox != NULL &&
              cabecote->prox->valor == 20 &&
              cabecote->prox->ant == cabecote,
              "17 - remover primeiro elemento sem remover cabecote");

    NoDuplo *atual = cabecote->prox;
    while (atual != NULL) {
        NoDuplo *proximo = atual->prox;
        free(atual);
        atual = proximo;
    }
    free(cabecote);
}

static void testarListasCirculares(void)
{
    printf("\n=== E. LISTAS CIRCULARES ===\n");

    No *lista = NULL;

    int r1 = inserirFinalCircular(&lista, 10);
    int r2 = inserirFinalCircular(&lista, 20);
    int r3 = inserirFinalCircular(&lista, 30);

    VERIFICAR(r1 == SUCESSO && r2 == SUCESSO && r3 == SUCESSO &&
              lista != NULL && lista->valor == 10 &&
              lista->prox != NULL && lista->prox->prox != NULL &&
              lista->prox->prox->prox == lista,
              "18 - inserir no final da circular simples");

    VERIFICAR(contarCircular(lista) == 3,
              "19 - contar nos da circular sem loop infinito");

    liberarCircularTeste(&lista);

    No *cabecote = criarCircularComCabecote();

    VERIFICAR(cabecote != NULL && cabecote->prox == cabecote,
              "20 - criar circular simples com cabecote");

    if (cabecote != NULL) {
        int c1 = inserirFinalCircularComCabecote(cabecote, 10);
        int c2 = inserirFinalCircularComCabecote(cabecote, 20);

        VERIFICAR(c1 == SUCESSO && c2 == SUCESSO &&
                  cabecote->prox != cabecote &&
                  cabecote->prox->valor == 10 &&
                  cabecote->prox->prox->valor == 20 &&
                  cabecote->prox->prox->prox == cabecote,
                  "21 - inserir no final da circular com cabecote");

        liberarCircularCabecoteTeste(cabecote);
    } else {
        VERIFICAR(0, "21 - inserir no final da circular com cabecote");
    }

    NoDuplo *duplaCircular = criarCircularDuplaComCabecote();

    VERIFICAR(duplaCircular != NULL &&
              duplaCircular->prox == duplaCircular &&
              duplaCircular->ant == duplaCircular,
              "22 - criar circular dupla com cabecote");

    if (duplaCircular != NULL) {
        free(duplaCircular);
    }
}

static void testarConsolidacao(void)
{
    printf("\n=== F. CONSOLIDACAO ===\n");

    No *a = NULL;
    No *b = NULL;

    inserirFinalSimples(&a, 1);
    inserirFinalSimples(&a, 2);
    inserirFinalSimples(&b, 3);
    inserirFinalSimples(&b, 4);

    int concatenou = concatenarSimples(&a, &b);
    int esperadoConcatenacao[] = {1, 2, 3, 4};

    VERIFICAR(concatenou == SUCESSO &&
              valoresIguais(a, esperadoConcatenacao, 4) &&
              b == NULL,
              "23 - concatenar listas sem copiar os nos");

    inverterSimples(&a);
    int esperadoInversao[] = {4, 3, 2, 1};

    VERIFICAR(valoresIguais(a, esperadoInversao, 4),
              "24 - inverter lista sem criar novos nos");

    liberarSimples(&a);

    VERIFICAR(a == NULL, "25 - liberar todos os nos e zerar ponteiro");
}

int main(void)
{
    printf("INICIANDO TESTES AUTOMATICOS DAS LISTAS\n");

    testarListaSimplesSemCabecote();
    testarListaSimplesComCabecote();
    testarListaDuplaSemCabecote();
    testarListaDuplaComCabecote();
    testarListasCirculares();
    testarConsolidacao();

    printf("\n============================================\n");
    printf("RESULTADO: %d testes | %d aprovados | %d reprovados\n",
           totalTestes, aprovados, reprovados);
    printf("============================================\n");

    return reprovados == 0 ? 0 : 1;
}

