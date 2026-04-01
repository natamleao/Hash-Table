#include "hash.h"
#include "key_array.h"
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

int main(){
    srand(time(NULL));

    int keysNumber = 50;             
    int min = 1000, max = 100000;
    int hashCapacity = 15;

    hashTable *hash = HashCreate(hashCapacity);

    int *keysArray = KeyArrayCreate(keysNumber, min, max);

    hash = HashCreate(hashCapacity);

    printf("Hase after Digit Analysis Method:\n");

    HashDigitAnalysisMethod(HashCountDigits, keysArray, keysNumber, hash);
    HashPrint(hash);

    HashDestroy(hash);

    return 0;
}