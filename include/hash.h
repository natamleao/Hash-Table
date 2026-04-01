/******************************************************* PUBLIC INTERFACE ********************************************************/
#ifndef HASH_H
#define HASH_H

#include "node.h"

// Estrutura de Hash
typedef struct _hashTable hashTable;

/**
 * @brief Cria a estrutura de um Hash a partir de um array qualquer.
 *
 * Copia os elementos do array passado para o array da estrutura,
 * mas sem transformá-la em um Hash, ajusta size, vituralSize e capacidade.
 *
 * @param capacity Capacidade máxima que o Hash deve ter (>= array_size).
 * @return Ponteiro para o Hash alocado, ou NULL se falhar.
 */
hashTable* HashCreate(int capacity);

/**
 * @brief Retorna o vetor interno de dados do Hash.
 *
 * Permite acesso direto ao array que armazena os elementos do Hash.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @return Ponteiro para o vetor de floats que representa os dados.
 */
Node** HashGetBuckets(hashTable *hash);

/**
 * @brief Retorna a capacidade máxima do Hash.
 *
 * Informa quantos elementos o Hash pode armazenar antes de ocorrer overflow.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @return Capacidade máxima do Hash.
 */
int HashGetCapacity(hashTable *hash);

/**
 * @brief Retorna o tamanho atual do Hash.
 *
 * Indica quantos elementos válidos estão armazenados no Hash no momento.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @return Número de elementos atualmente no Hash.
 */
int HashGetSize(hashTable *hash);

/**
 * @brief Define o valor de um elemento no Hash.
 *
 * Altera diretamente o valor armazenado no índice especificado.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @param index Índice do elemento a ser alterado (0 a size-1).
 * @param value Novo valor a ser colocado nessa posição.
 */
void HashSet(hashTable *hash, int index, Node *node);

/**
 * @brief Ajusta a capacidade do Hash.
 *
 * Altera a capacidade máxima em relação ao valor atual.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @param value Valor a ser adicionado à capacidade.
 */
void HashSetCapacity(hashTable *hash, int value);

/**
 * @brief Ajusta o tamanho atual do Hash.
 *
 * Altera o campo `size` em relação ao valor atual.
 *
 * @param hash Ponteiro para a estrutura do Hash.
 * @param value Valor a ser adicionado ao tamanho.
 */
void HashSetSize(hashTable *hash, int value);

/**
 * @brief Imprime todos os elementos do Hash no console.
 *
 * A função percorre o vetor interno do Hash do índice 0 até Hash->size - 1
 * e imprime os valores. 
 *
 * @param hash Ponteiro para o Hash a ser impresso.
 *
 * @note Os elementos são impressos na ordem interna do vetor, não necessariamente
 *       em ordem decrescente de valor.
 */
void HashPrint(hashTable *hash);

/**
 * @brief Conta o número de dígitos em um número inteiro.
 *
 * Calcula quantos dígitos compõem o valor absoluto do número
 * fornecido e armazena o resultado no ponteiro `size`.
 *
 * @param number Número inteiro a ser analisado.
 * @param size Ponteiro para armazenar o número de dígitos encontrados.
 */
void HashCountDigits(int number, int *size);

/**
 * @brief Insere múltiplos valores no Hash usando o método de Análise de Dígitos.
 *
 * Analisa os dígitos dos números fornecidos para determinar o melhor dígito
 * a ser usado como chave de hash, e insere os valores no Hash de acordo.
 *
 * @param function Ponteiro para a função que conta os dígitos de um número.
 * @param keysArray Array de inteiros contendo os valores a serem inseridos.
 * @param keysNumber Número de elementos no array `keysArray`.
 * @param hash Ponteiro para a estrutura do Hash onde os valores serão inseridos.
 */
void HashDigitAnalysisMethod(void (*function)(int number, int *size), int *keysArray, int keysNumber, hashTable *hash);

/**
 * @brief Libera toda a memória usada pelo Hash.
 *
 * Desaloca o vetor interno de dados (`data`) e a própria estrutura
 * do Hash. 
 *
 * @param hash Ponteiro para a estrutura do Hash a ser destruída.
 */
void HashDestroy(hashTable *hash);

#endif

/*********************************************************************************************************************************/