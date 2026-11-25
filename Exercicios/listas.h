#ifndef LISTAS_H
#define LISTAS_H

/*
 * Laboratorio de Listas Encadeadas - INF029 / Linguagem C
 *
 * Convenções:
 * - Lista simplesmente encadeada: cada nó aponta para o próximo.
 * - Lista duplamente encadeada: cada nó aponta para o anterior e o próximo.
 * - Com cabeçote: o ponteiro da lista aponta para um nó sentinela.
 *   O cabeçote não armazena um valor da lista; o primeiro elemento está em cabecote->prox.
 * - Sem cabeçote: o ponteiro da lista aponta diretamente para o primeiro elemento.
 * - Circular: o último nó aponta novamente para o primeiro (ou para o cabeçote,
 *   quando a lista circular utiliza cabeçote).
 *
 * Regra geral para este laboratório:
 * - Funções que alteram o início de uma lista recebem ponteiro para ponteiro.
 * - Retornos de status: 1 = sucesso; 0 = falha/condição não atendida,
 *   salvo quando o comentário de uma questão especificar outra coisa.
 */

#define SUCESSO 1
#define FALHA 0

typedef struct no {
    int valor;
    struct no *prox;
} No;

typedef struct noDuplo {
    int valor;
    struct noDuplo *ant;
    struct noDuplo *prox;
} NoDuplo;

/* ============================================================
 * A. LISTA SIMPLESMENTE ENCADEADA SEM CABEÇOTE (01 a 05)
 * ============================================================ */

/* 01. Criar uma lista vazia. Retorna NULL. */
No *criarListaSimples(void);

/* 02. Inserir um valor no início. Retorna SUCESSO ou FALHA. */
int inserirInicioSimples(No **lista, int valor);

/* 03. Inserir um valor no final. Retorna SUCESSO ou FALHA. */
int inserirFinalSimples(No **lista, int valor);

/* 04. Contar quantos nós existem na lista. */
int contarSimples(No *lista);

/* 05. Buscar um valor. Retorna o endereço do nó ou NULL. */
No *buscarSimples(No *lista, int valor);

/* ============================================================
 * B. LISTA SIMPLESMENTE ENCADEADA COM CABEÇOTE (06 a 09)
 * ============================================================ */

/* 06. Criar uma lista com cabeçote vazio. Retorna NULL se malloc falhar. */
No *criarListaComCabecote(void);

/* 07. Inserir um valor no início lógico (logo após o cabeçote). */
int inserirInicioComCabecote(No *cabecote, int valor);

/* 08. Inserir um valor no final lógico (antes de NULL). */
int inserirFinalComCabecote(No *cabecote, int valor);

/* 09. Contar os elementos, sem contar o cabeçote. */
int contarComCabecote(No *cabecote);

/* ============================================================
 * C. LISTA DUPLAMENTE ENCADEADA SEM CABEÇOTE (10 a 14)
 * ============================================================ */

/* 10. Inserir um valor no início. Atualiza o início da lista. */
int inserirInicioDupla(NoDuplo **lista, int valor);

/* 11. Inserir um valor no final. */
int inserirFinalDupla(NoDuplo **lista, int valor);

/* 12. Buscar um valor. Retorna o nó encontrado ou NULL. */
NoDuplo *buscarDupla(NoDuplo *lista, int valor);

/* 13. Remover a primeira ocorrência de um valor. */
int removerValorDupla(NoDuplo **lista, int valor);

/* 14. Percorrer e imprimir do último nó até o primeiro. */
void imprimirInversaDupla(NoDuplo *lista);

/* ============================================================
 * D. LISTA DUPLAMENTE ENCADEADA COM CABEÇOTE (15 a 17)
 * ============================================================ */

/* 15. Criar cabeçote vazio. O cabeçote não contém elemento válido. */
NoDuplo *criarListaDuplaComCabecote(void);

/* 16. Inserir no início lógico (após o cabeçote). */
int inserirInicioDuplaComCabecote(NoDuplo *cabecote, int valor);

/* 17. Remover a primeira ocorrência. Não remover o cabeçote. */
int removerDuplaComCabecote(NoDuplo *cabecote, int valor);

/* ============================================================
 * E. LISTAS CIRCULARES (18 a 22)
 * ============================================================ */

/*
 * 18. Lista simplesmente encadeada circular SEM cabeçote:
 * inserir no final. Em lista não vazia, o último->prox aponta para o início.
 */
int inserirFinalCircular(No **lista, int valor);

/* 19. Lista simplesmente encadeada circular SEM cabeçote:
 * contar os nós sem entrar em loop infinito.
 */
int contarCircular(No *lista);

/*
 * 20. Lista simplesmente encadeada circular COM cabeçote:
 * criar o cabeçote. Lista vazia: cabecote->prox aponta para o próprio cabeçote.
 */
No *criarCircularComCabecote(void);

/* 21. Inserir no final da lista circular com cabeçote. */
int inserirFinalCircularComCabecote(No *cabecote, int valor);

/*
 * 22. Lista duplamente encadeada circular COM cabeçote:
 * criar cabeçote. Lista vazia: ant e prox apontam para o próprio cabeçote.
 */
NoDuplo *criarCircularDuplaComCabecote(void);

/* ============================================================
 * F. EXERCÍCIOS DE CONSOLIDAÇÃO (23 a 25)
 * ============================================================ */

/* 23. Concatenar lista B ao final de A (simples, sem cabeçote).
 * A lista B deve ser incorporada; não crie cópias dos nós.
 */
int concatenarSimples(No **listaA, No **listaB);

/* 24. Inverter uma lista simplesmente encadeada sem criar novos nós. */
void inverterSimples(No **lista);

/* 25. Liberar todos os nós de uma lista simples sem cabeçote.
 * Ao final, o ponteiro da lista deve ser NULL.
 */
void liberarSimples(No **lista);

#endif
