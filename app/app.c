#include "hash.h"
#include "keyarray.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int keysNumber = 50;             
    int min = 1000, max = 100000;
    int hashCapacity = 15;

    hashTable *hash = HashCreateHashTable(hashCapacity);

    int *keysArray = KeyArrayCreate(keysNumber, min, max);

    hash = HashCreateHashTable(hashCapacity);

    printf("Hase after Digit Analysis Method:\n");

    HashDigitAnalysisMethod(HashCountDigits, keysArray, keysNumber, hash);
    HashPrint(hash);

    HashDestroy(hash);

    return 0;
}