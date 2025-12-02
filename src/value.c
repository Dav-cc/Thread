#include <stdio.h>

#include "memory.h"
#include "value.h"


void initValueArray(ValueArray* array){
    array->values = NULL;
    array->count = 0;
    array->capacity = 0;
}

void writeValueArray(ValueArray* array, Value *value){
    if(array->count < array->capacity){
        int oldcap = array->capacity;
        array->capacity = GROW_CAPACITY(oldcap);
        array->values = GROW_ARRAY(uint8_t, array->values, oldcap, array->capacity);
    }
}
