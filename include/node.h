/******************************************************* PUBLIC INTERFACE ********************************************************/

#ifndef NODE_H
#define NODE_H

typedef struct _node Node;

/**
 * @brief Cria um novo nó com uma chave e um valor.
 * 
 * @param index   Chave do nó.
 * @param value Valor associado à chave.
 * @return Node* Ponteiro para o nó criado, ou NULL se falha na alocação.
 */
Node* NodeCreate(int index, int value);

/**
 * @brief Retorna a chave do nó.
 * 
 * @param node_ Ponteiro para o nó.
 * @return int A chave armazenada no nó.
 */
int NodeGetIndex(Node *node_);

/**
 * @brief Retorna o valor do nó.
 * 
 * @param node_ Ponteiro para o nó.
 * @return int O valor armazenado no nó.
 */
int NodeGetValue(Node *node_);

/**
 * @brief Retorna o próximo nó da lista encadeada.
 * 
 * @param node_ Ponteiro para o nó atual.
 * @return node* Ponteiro para o próximo nó.
 */
Node* NodeGetNextNode(Node *node_);

/**
 * @brief Define/atualiza a chave do nó.
 * 
 * @param node_ Ponteiro para o nó.
 * @param index   Nova chave a ser atribuída.
 */
void NodeSetIndex(Node *node_, int index);

/**
 * @brief Define/atualiza o valor do nó.
 * 
 * @param node_ Ponteiro para o nó.
 * @param value Novo valor a ser atribuído.
 */
void NodeSetValue(Node *node_, int value);

/**
 * @brief Define o próximo nó da lista encadeada.
 * 
 * @param node_ Ponteiro para o nó atual.
 * @param next  Ponteiro para o nó que será o próximo.
 */
void NodeSetNextNode(Node *node_, Node *next);

/**
 * @brief Libera a memória de um nó e de toda a lista encadeada a partir dele.
 * 
 * @param node_ Ponteiro para o nó inicial da lista.
 */
void NodeDestroy(Node *node_);

#endif

/*********************************************************************************************************************************/