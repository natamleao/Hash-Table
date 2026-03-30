# Hash Table com Análise de Dígitos em C

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-hash_table-yellow)
![Collision](https://img.shields.io/badge/collision-chaining-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Sobre o projeto

> [!NOTE]
> Este projeto implementa uma **tabela hash em C** utilizando **encadeamento (chaining)** para tratamento de colisões.

O diferencial aqui não é só “jogar número no bucket” — o projeto usa um **método de análise de dígitos** para tentar melhorar a distribuição das chaves.

A ideia é simples:

* quebrar os números em dígitos
* analisar a distribuição
* escolher o dígito “mais estável”
* usar esse dígito como base para o índice na hash

Ou seja: **uma tentativa de reduzir colisões com heurística**, não só força bruta.

---

> [!IMPORTANT]
> ## Tecnologias utilizadas
> 
> * **C (C11)**
> * **GNU Make**
> * Estruturas:
> 
>   * **Tabela hash**
>   * **Lista encadeada (para colisões)**

---

## Conceitos aplicados

Esse projeto bate forte em fundamentos importantes:

* Alocação dinâmica (`malloc`, `calloc`, `free`)
* Manipulação de ponteiros
* Estruturas encadeadas
* Modularização (`.h` e `.c`)
* Separação de responsabilidades
* Análise de distribuição de dados
* Uso de funções como ponteiros (callback)
* Algoritmos de embaralhamento (shuffle)

---

## Estrutura da Hash Table

Cada bucket da tabela aponta para uma lista encadeada:

```
Hash Table (buckets)

[0] → (k,v) → (k,v)
[1] → vazio
[2] → (k,v)
[3] → (k,v) → (k,v) → (k,v)
...
```

---

## Estrutura do nó

```c
struct _node{
    int _index;
    int _value;
    struct _node *_next;
};
```

---

## Estrutura da tabela hash

```c
struct _hashTable{
    Node **buckets;
    int size;
    int capacity;
};
```

---

## Funcionamento do método de hashing

### 1. Quebra em dígitos

Cada número é decomposto:

```
123 → [1, 2, 3]
```

---

### 2. Matriz de distribuição

O sistema conta a frequência de cada dígito (0–9) em cada posição.

---

### 3. Cálculo de desvio

É calculado o quanto cada posição de dígito “se afasta” de uma distribuição ideal.

---

### 4. Escolha do melhor dígito

Seleciona o dígito com **menor desvio** → mais equilibrado.

---

### 5. Cálculo do índice

```c
index = digit % capacity;
```

Simples, mas agora usando o **melhor dígito possível**.

---

## Funcionalidades

### Criar tabela hash

```c
HashCreateHashTable(capacity);
```

---

### Inserção

Inserção indireta via:

```c
HashDigitAnalysisMethod(...)
```

Que:

* analisa os dados
* decide como distribuir
* insere automaticamente

---

### Impressão

```c
HashPrint(hash);
```

Saída exemplo:

```
Bucket 0: (Chave: 3, Valor: 123)
Bucket 1: vazio
Bucket 2: (Chave: 2, Valor: 456) -> (Chave: 2, Valor: 789)
```

---

### Destruição

```c
HashDestroy(hash);
```

Libera toda a memória corretamente (incluindo listas).

---

## Geração de chaves

O módulo `keyarray` permite gerar números únicos aleatórios:

```c
KeyArrayCreate(qtd, min, max);
```

### Características:

* Sem repetição
* Distribuição aleatória (shuffle)
* Base para testes da hash

---

## Estrutura do projeto

```
Hash-Table/
│
├── app/             # Arquivo principal da aplicação (main)
├── bin/             # Executáveis gerados
├── include/         # Arquivos de cabeçalho (.h)
├── build/           # Arquivos objeto (.o)
├── src/             # Código-fonte da aplicação (.c)
├── lib/             # Biblioteca estática
│
├── Makefile         # Regras de compilação
├── README.md        # Documentação do projeto
└── LICENSE          # Licença do projeto
```

> [!IMPORTANT]
> ## Requisitos
>
> Para compilar e executar o projeto é necessário:
>
> * **GCC ou Clang**
> * **GNU Make**
> * Sistema **Linux ou macOS**

---

## Instalação

Clone o repositório:

```bash
git clone git@github.com:natamleao/Hash-Table.git
cd Hash-Table
```

---

## Compilação

Compile o projeto com:

```bash
make
```

---

## Execução

Execute o programa com:

```bash
make run
```

---

## Limpeza do projeto

Remover arquivos compilados:

```bash
make clean
make cleanapp
```

---

> [!WARNING]
> ## Licença
>
> Este projeto está licenciado sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---
