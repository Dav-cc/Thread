#include "memory.h"
#include "chunk.h"
#include <stdint.h>
#include <stdlib.h>

void initChunk(Chunk* chunk){
    chunk->code = NULL;
    chunk->capacity = 0;
    chunk->count = 0;
}


void writeChunk(Chunk* chunk, uint8_t byte){
    if(chunk->count >= chunk->capacity){
        int oldcap = chunk->capacity;
        chunk->capacity = GROW_CAPACITY(oldcap);
        chunk->code = GROW_ARRAY(uint8_t, chunk->code, oldcap, chunk->capacity);
    }
    chunk->code[chunk->count] = byte;
    chunk->count++;
}

void freeChunk(Chunk* chunk){
    FREE_ARRAY(uint8_t, chunk->code, chunk->capacity);
    initChunk(chunk);
}
