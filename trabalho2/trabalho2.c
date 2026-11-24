#include <stdio.h>
#include <stdlib.h>
#define TAM 10

#include "trabalho2.h"

EstruturaAuxiliar auxiliares[TAM];


int ehPosicaoValida(int posicao);

int criarEstruturaAuxiliar(int posicao, int tamanho)
{

    if (ehPosicaoValida(posicao) == POSICAO_INVALIDA) {
        return POSICAO_INVALIDA;
    }

  
    int i = posicao - 1;

    if (auxiliares[i].nums != NULL) {
        return JA_TEM_ESTRUTURA_AUXILIAR;
    }

    if (tamanho < 1) {
        return TAMANHO_INVALIDO;
    }

    auxiliares[i].nums = (int *) malloc(sizeof(int) * tamanho);
    if (auxiliares[i].nums == NULL) {
        return SEM_ESPACO_DE_MEMORIA;
    }

    
    auxiliares[i].max_tam = tamanho;
    auxiliares[i].qtd = 0;

    return SUCESSO;
}

/*
Objetivo: inserir número 'valor' em estrutura auxiliar da posição 'posicao'
Rertono (int)
    SUCESSO - inserido com sucesso
    SEM_ESPACO - não tem espaço
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
CONSTANTES
*/
int inserirNumeroEmEstrutura(int posicao, int valor)
{
    int retorno = 0;
    int posicao_invalida = 0;

    posicao_invalida = ehPosicaoValida(posicao);

    if (posicao_invalida == POSICAO_INVALIDA){
        return POSICAO_INVALIDA;
    }else
    {

        // testar se existe a estrutura auxiliar
        if (auxiliares[posicao - 1].nums != NULL)
        {
            if (auxiliares[posicao - 1].qtd < auxiliares[posicao - 1].max_tam)
            {
                auxiliares[posicao - 1].nums[auxiliares[posicao-1].qtd] = valor;
                auxiliares[posicao - 1].qtd++;
                return SUCESSO;
            }
            else
            {
                return SEM_ESPACO;
            }
        }
        else
        {
            return SEM_ESTRUTURA_AUXILIAR;
        }
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar no final da estrutura.
ex: suponha os valores [3, 8, 7, 9,  ,  ]. Após excluir, a estrutura deve ficar da seguinte forma [3, 8, 7,  ,  ,  ].
Obs. Esta é uma exclusão lógica

Rertono (int)
    SUCESSO - excluido com sucesso
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int excluirNumeroDoFinaldaEstrutura(int posicao)
{

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (auxiliares[posicao - 1].nums == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }


    if(auxiliares[posicao - 1].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }else{
        auxiliares[posicao - 1].qtd--;
        return SUCESSO;
    }
}

/*
Objetivo: excluir o numero 'valor' da estrutura auxiliar da posição 'posicao'.
Caso seja excluido, os números posteriores devem ser movidos para as posições anteriores
ex: suponha os valores [3, 8, 7, 9,  ,  ] onde deve ser excluido o valor 8. A estrutura deve ficar da seguinte forma [3, 7, 9,  ,  ,  ]
Obs. Esta é uma exclusão lógica
Rertono (int)
    SUCESSO - excluido com sucesso 'valor' da estrutura na posição 'posicao'
    ESTRUTURA_AUXILIAR_VAZIA - estrutura vazia
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    NUMERO_INEXISTENTE - Número não existe
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar

*/
int excluirNumeroEspecificoDeEstrutura(int posicao, int valor)
{
    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (auxiliares[posicao - 1].nums == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }


    if(auxiliares[posicao - 1].qtd == 0){
        return ESTRUTURA_AUXILIAR_VAZIA;
    }

    for(int i = 0; i < auxiliares[posicao - 1].qtd; i++){

        if(valor == auxiliares[posicao - 1].nums[i]){

            for(int j = i; j < auxiliares[posicao - 1].qtd - 1; j++){
                auxiliares[posicao - 1].nums[j] = auxiliares[posicao - 1].nums[j + 1];
            }
            auxiliares[posicao - 1].qtd--;
            return SUCESSO;
        }
    }

    return NUMERO_INEXISTENTE;

    
}

// se posição é um valor válido {entre 1 e 10}
int ehPosicaoValida(int posicao)
{
    int retorno = 0;
    if (posicao < 1 || posicao > 10)
    {
        retorno = POSICAO_INVALIDA;
    }
    else
        retorno = SUCESSO;

    return retorno;
}
/*
Objetivo: retorna os números da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Retorno (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (auxiliares[posicao - 1].nums == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }

    for(int i = 0; i < auxiliares[posicao - 1].qtd; i++){
        vetorAux[i] = auxiliares[posicao - 1].nums[i];
    }

    return SUCESSO;
}

/*
Objetivo: retorna os números ordenados da estrutura auxiliar da posição 'posicao (1..10)'.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao (1..10)'
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
*/
int getDadosOrdenadosEstruturaAuxiliar(int posicao, int vetorAux[])
{

    if(posicao < 1 || posicao > 10){
        return POSICAO_INVALIDA;
    }

    if (auxiliares[posicao - 1].nums == NULL) {
        return SEM_ESTRUTURA_AUXILIAR;
    }


    for(int i = 0; i < auxiliares[posicao - 1].qtd; i++){
        vetorAux[i] = auxiliares[posicao - 1].nums[i];
    }
    
    for(int i = 1; i < auxiliares[posicao - 1].qtd; i++){
        int chave = vetorAux[i];
        int j = i - 1;

        while(j >= 0 && vetorAux[j] > chave){
            vetorAux[j + 1] = vetorAux[j];
            j--;
        }

        vetorAux[j + 1] = chave;
    }

    return SUCESSO;

}

/*
Objetivo: retorna os números de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna os números ordenados de todas as estruturas auxiliares.
os números devem ser armazenados em vetorAux

Rertono (int)
    SUCESSO - recuperado com sucesso os valores da estrutura na posição 'posicao'
    TODAS_ESTRUTURAS_AUXILIARES_VAZIAS - todas as estruturas auxiliares estão vazias
*/
int getDadosOrdenadosDeTodasEstruturasAuxiliares(int vetorAux[])
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: modificar o tamanho da estrutura auxiliar da posição 'posicao' para o novo tamanho 'novoTamanho' + tamanho atual
Suponha o tamanho inicial = x, e novo tamanho = n. O tamanho resultante deve ser x + n. Sendo que x + n deve ser sempre >= 1

Rertono (int)
    SUCESSO - foi modificado corretamente o tamanho da estrutura auxiliar
    SEM_ESTRUTURA_AUXILIAR - Não tem estrutura auxiliar
    POSICAO_INVALIDA - Posição inválida para estrutura auxiliar
    NOVO_TAMANHO_INVALIDO - novo tamanho não pode ser negativo
    SEM_ESPACO_DE_MEMORIA - erro na alocação do novo valor
*/
int modificarTamanhoEstruturaAuxiliar(int posicao, int novoTamanho)
{

    int retorno = 0;
    return retorno;
}

/*
Objetivo: retorna a quantidade de elementos preenchidos da estrutura auxiliar da posição 'posicao'.

Retorno (int)
    POSICAO_INVALIDA - posição inválida
    SEM_ESTRUTURA_AUXILIAR - sem estrutura auxiliar
    ESTRUTURA_AUXILIAR_VAZIA - estrutura auxiliar vazia
    Um número int > 0 correpondente a quantidade de elementos preenchidos da estrutura
*/
int getQuantidadeElementosEstruturaAuxiliar(int posicao)
{

    int retorno = 0;

    return retorno;
}

/*
Objetivo: montar a lista encadeada com cabeçote com todos os números presentes em todas as estruturas.

Retorno (No*)
    NULL, caso não tenha nenhum número nas listas
    No*, ponteiro para o início da lista com cabeçote
*/
No *montarListaEncadeadaComCabecote()
{

    return NULL;
}

/*
Objetivo: retorna os números da lista enceada com cabeçote armazenando em vetorAux.
Retorno void
*/
void getDadosListaEncadeadaComCabecote(No *inicio, int vetorAux[])
{
}

/*
Objetivo: Destruir a lista encadeada com cabeçote a partir de início.
O ponteiro inicio deve ficar com NULL.

Retorno 
    void.
*/
void destruirListaEncadeadaComCabecote(No **inicio)
{
}

/*
Objetivo: inicializa o programa. deve ser chamado ao inicio do programa 

*/

void inicializar()
{
}

/*
Objetivo: finaliza o programa. deve ser chamado ao final do programa 
para poder liberar todos os espaços de memória das estruturas auxiliares.

*/

void finalizar()
{
    for (int i = 0; i < TAM; i++)
        {
            if (auxiliares[i].nums != NULL)
            {
                free(auxiliares[i].nums);
                auxiliares[i].nums = NULL;
                auxiliares[i].qtd = 0;
                auxiliares[i].max_tam = 0;
            }
        }
}