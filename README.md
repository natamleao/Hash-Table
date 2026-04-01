# *Hash Table* com Análise de Dígitos em C

![Language](https://img.shields.io/badge/language-C-blue)
![Standard](https://img.shields.io/badge/standard-C11-orange)
![Build](https://img.shields.io/badge/build-Makefile-green)
![Data Structure](https://img.shields.io/badge/data_structure-hash_table-yellow)
![Collision](https://img.shields.io/badge/collision-chaining-lightgrey)
![License](https://img.shields.io/badge/license-MIT-lightgrey)

---

## Sobre o projeto

Este projeto implementa uma *tabela hash* em C utilizando *encadeamento* (*chaining*) para resolução de colisões.

O diferencial está no método de *hashing*: ao invés de usar diretamente o valor da chave, o sistema realiza uma **análise estatística dos dígitos** das chaves antes de definir o índice.

A ideia central é:

* decompor os números em dígitos  
* analisar a distribuição desses dígitos por posição  
* calcular um “desvio” para cada posição  
* escolher a posição mais estável  
* usar esse dígito para gerar o índice da *hash*  

Ou seja: uma **heurística baseada em distribuição**, não uma função de *hash* fixa.

---

## Como o *hashing* funciona (na prática)

### 1. Quebra em dígitos

Cada número é dividido:

```

1234 → [1, 2, 3, 4]

```

---

### 2. Construção da matriz

É criada uma matriz:

```

(posição do dígito) × (0–9)

````

Onde cada célula conta quantas vezes um dígito aparece naquela posição.

---

### 3. Cálculo de desvio

Para cada posição, é calculado:

* frequência ideal: `N / 10`  
* desvio baseado na distância dos dígitos  

Isso gera um vetor de desvios.

---

### 4. Escolha do melhor dígito

O índice da posição com **menor desvio** é escolhido:

```c
int bestDigit = HashFindMinDeviationIndex(deviations, digitsCount);
````

---

### 5. Cálculo do índice final

```c
index = digit % capacity;
```

Simples — mas agora usando o dígito mais “equilibrado”.

---

## Estrutura da *Hash Table*

```
[0] → (k,v) → (k,v)
[1] → vazio
[2] → (k,v)
[3] → (k,v) → (k,v)
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

* `_index`: posição na tabela
* `_value`: valor original inserido
* `_next`: próximo nó (*lista encadeada*)

---

## Estrutura da tabela *hash*

```c
struct _hashTable{
    Node **buckets;
    int size;
    int capacity;
};
```

---

## Funcionalidades

### Criar tabela

```c
hashTable* HashCreateHashTable(int capacity);
```

---

### Inserção (via análise de dígitos)

```c
HashDigitAnalysisMethod(HashCountDigits, keysArray, keysNumber, hash);
```

Esse método:

* analisa todas as chaves
* define o melhor dígito
* insere automaticamente na tabela

---

### Impressão

```c
HashPrint(hash);
```

Saída:

```
Bucket 0: (Chave: 0, Valor: 1234)
Bucket 1: vazio
Bucket 2: (Chave: 2, Valor: 5678) -> (Chave: 2, Valor: 91011)
```

---

### Liberação de memória

```c
HashDestroy(hash);
```

Libera:

* todos os nós
* *buckets*
* estrutura da *hash*

---

## Geração de chaves (*KeyArray*)

```c
int* KeyArrayCreate(int keysNumber, int min, int max);
```

Características:

* valores únicos
* distribuição aleatória (*Fisher-Yates shuffle*)
* ideal para testes

---

## Exemplo de uso

```c
int main(){
    srand(time(NULL));

    int keysNumber = 50;
    int min = 1000, max = 100000;
    int hashCapacity = 15;

    hashTable *hash = HashCreateHashTable(hashCapacity);

    int *keysArray = KeyArrayCreate(keysNumber, min, max);

    HashDigitAnalysisMethod(HashCountDigits, keysArray, keysNumber, hash);

    HashPrint(hash);

    HashDestroy(hash);
    return 0;
}
```

---

## Conceitos aplicados

Esse projeto trabalha forte:

* ponteiros e memória dinâmica
* listas encadeadas
* análise de dados (distribuição)
* modularização em C
* heurísticas para *hashing*
* manipulação de *arrays* multidimensionais
* algoritmo de embaralhamento (*shuffle*)

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
├── README.md        # Documentação
└── LICENSE          # Licença
```

---

> [!IMPORTANT]
>
> ## Requisitos
>
> Para compilar e executar o projeto é necessário:
>
> * **GCC ou Clang**
> * **GNU Make**
> * Sistema **Linux ou macOS**

---

## Instalação

```bash
git clone git@github.com:natamleao/Hash-Table.git
cd Hash-Table
```

---

## Compilação

```bash
make
```

---

## Execução

```bash
make run
```

---

## Limpeza do projeto

```bash
make clean
make cleanapp
```

---

> [!WARNING]
>
> ## Licença
>
> Este projeto está licenciado sob a **Licença MIT**.

---

## Autor

**Natam Leão Ferreira**

Conclusão: **2026**

---