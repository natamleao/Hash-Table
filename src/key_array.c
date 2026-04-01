#include "node.h"
#include <stdlib.h>

/******************************************************* PRIVATE INTERFACE *******************************************************/

void KeyArrayShuffle(int *keysArray, int n){
    for(int i = n - 1; i > 0; i--){
        int j = rand() % (i + 1);
        int temp = keysArray[i];
        keysArray[i] = keysArray[j];
        keysArray[j] = temp;
    }
}

/******************************************************* PUBLIC INTERFACE ********************************************************/

int* KeyArrayCreate(int keysNumber, int min, int max){
    int range = max - min + 1;
    if(keysNumber > range) return NULL;

    int *allValues = calloc(range, sizeof(int));
    if(!allValues) return NULL;

    for(int i = 0; i < range; i++)
        allValues[i] = min + i;

    KeyArrayShuffle(allValues, range);

    int *result = calloc(keysNumber, sizeof(int));
    if(!result){
        free(allValues);
        return NULL;
    }

    for(int i = 0; i < keysNumber; i++)
        result[i] = allValues[i];

    free(allValues);
    
    return result;
}

/*********************************************************************************************************************************/