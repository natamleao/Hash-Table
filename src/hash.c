#include "hash.h"
#include "keyarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include <string.h>

/******************************************************* PRIVATE INTERFACE *******************************************************/

struct _hashTable{
    Node **buckets;
    int size;
    int capacity;
};

int* HashSplitDigits(void (*function)(int number, int *size), int number, int *size){
    int temp = abs(number);

    function(number, size);   

    int *digits = calloc(*size, sizeof(int));
    if(!digits) return NULL;

    for(int i = (*size) - 1; i >= 0; i--){
        digits[i] = temp % 10;
        temp /= 10;
    }

    return digits;
}

float* HashCalculateDeviations(int **distributionMatrix, int digitsCount, int indexsNumber){
    float *deviationArray = calloc(digitsCount, sizeof(float));
    if(!deviationArray) return NULL;

    float idealFreq = (float)indexsNumber / 10.0f;

    for(int col = 0; col < digitsCount; col++){
        float deviation = 0.0f;
        for(int digit = 0; digit < 10; digit++)
            deviation += distributionMatrix[col][digit] * fabsf((float)digit - idealFreq);

        deviationArray[col] = deviation;
    }

    return deviationArray;
}

int HashFindMinDeviationIndex(float *array, int size){
    if(!array || size <= 0) return -1;

    int minIndex = 0;
    float minValue = array[0];

    for(int i = 1; i < size; i++){
        if(array[i] < minValue){
            minValue = array[i];
            minIndex = i;
        }
    }
    return minIndex;
}

int **HashAllocateMemoryArray(int columns, int rows){
    int **matrix = calloc(rows, sizeof(int*));
    if(!matrix) return NULL;

    for(int i = 0; i < rows; i++)
        matrix[i] = calloc(columns, sizeof(int));

    return matrix;
}

void HashInsert(hashTable *hash, int index, int value){
    Node *newNode = NodeCreate(index, value);
    if(!newNode) return;

    NodeSetNextNode(newNode, HashGetBuckets(hash)[index]);
    HashSetBuckets(hash, index, newNode);
}

int HashComputeIndexFromDigit(int *digits, int bestDigit, int capacity){
    int d = digits[bestDigit];  
    return d % capacity;       
}

/******************************************************* PUBLIC INTERFACE ********************************************************/

hashTable* HashCreateHashTable(int capacity){
    if(capacity <= 0){
        printf("Erro: capacidade inválida!\n");
        return NULL;
    }

    hashTable *hash = (hashTable*)malloc(sizeof(hashTable));
    if(!hash) return NULL;

    hash->buckets = calloc(capacity, sizeof(Node*));
    if(!hash->buckets){
        free(hash);
        return NULL;
    }

    hash->size = 0;           
    hash->capacity = capacity;

    return hash;
}

Node** HashGetBuckets(hashTable *hash){return hash->buckets;}
int HashGetCapacity(hashTable *hash){return hash->capacity;}
int HashGetSize(hashTable *hash){return hash->size;}

void HashSetBuckets(hashTable *hash, int index, Node *node){hash->buckets[index] = node;}
void HashSetCapacity(hashTable *hash, int value){hash->capacity = value;}
void HashSetSize(hashTable *hash, int value){hash->size = value;}

void HashChangeCapacity(hashTable *hash, int delta){HashSetCapacity(hash, HashGetCapacity(hash) + delta);}
void HashChangeSize(hashTable *hash, int delta){HashSetSize(hash, HashGetSize(hash) + delta);}

void HashCountDigits(int number, int *size){
    int temp = abs(number);
    *size = 0;

    if(temp == 0){
        *size = 1;
        return;
    }

    while(temp > 0){
        temp /= 10;
        (*size)++;
    }
}

void HashDigitAnalysisMethod(void (*function)(int number, int *size), int *indexsArray, int indexsNumber, hashTable *hash){
    int digitsCount = 0;
    HashCountDigits(indexsArray[0], &digitsCount);

    int **matrixDigits = calloc(indexsNumber, sizeof(int*));
    if(!matrixDigits) return;

    for(int i = 0; i < indexsNumber; i++)
        matrixDigits[i] = HashSplitDigits(function, indexsArray[i], &digitsCount);

    int **distributionMatrix = HashAllocateMemoryArray(10, digitsCount);

    for(int i = 0; i < indexsNumber; i++){
        for(int j = 0; j < digitsCount; j++){
            int digit = matrixDigits[i][j];
            distributionMatrix[j][digit]++;
        }
    }

    float *deviations = HashCalculateDeviations(distributionMatrix, digitsCount, indexsNumber);

    int bestDigit = HashFindMinDeviationIndex(deviations, digitsCount);

    for(int i = 0; i < indexsNumber; i++){
        int *digits = matrixDigits[i];

        int index = HashComputeIndexFromDigit(digits, bestDigit, HashGetCapacity(hash));

        HashInsert(hash, index, indexsArray[i]);
    }
}

void HashPrint(hashTable *hash) {
    for(int i = 0; i < HashGetCapacity(hash); i++){
        printf("Bucket %d: ", i);
        Node *curr = HashGetBuckets(hash)[i];
        if(!curr){
            printf("vazio\n");
            continue;
        }

        while(curr){
            printf("(Chave: %d, Valor: %d)", NodeGetIndex(curr), NodeGetValue(curr));
            curr = NodeGetNextNode(curr);
            if(curr) printf(" -> "); 
        }
        printf("\n");
    }
}

void HashDestroy(hashTable *hash){
    if(hash){
        for(int i = 0; i < HashGetCapacity(hash); i++){
            Node *actualNode = HashGetBuckets(hash)[i];
            while(actualNode){
                Node *deleteNode = actualNode;
                actualNode = NodeGetNextNode(actualNode);  
                NodeDestroy(deleteNode);        
            }
        }
        free(hash->buckets);
        free(hash);
    }
}

/*********************************************************************************************************************************/