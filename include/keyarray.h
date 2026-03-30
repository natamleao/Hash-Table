/******************************************************* PUBLIC INTERFACE ********************************************************/

#ifndef KEYARRAY_H
#define KEYARRAY_H

/**
 * @brief Cria um array de inteiros únicos dentro de um intervalo.
 *
 * Gera "keysNumber" valores distintos e aleatórios no intervalo [min, max].
 *
 * @param keysNumber Quantidade de valores únicos desejados.
 * @param min Valor mínimo (inclusivo) do intervalo.
 * @param max Valor máximo (inclusivo) do intervalo.
 * @return Ponteiro para o array alocado dinamicamente, ou NULL em caso de erro
 */
int *KeyArrayCreate(int keysNumber, int min, int max);

#endif

/*********************************************************************************************************************************/