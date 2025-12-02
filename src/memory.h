#ifndef MEMORY_H
#define MEMORY_H
#include "common.h"

#define GROW_CAPACITY(capacity) \
    (capacity < 8 ? 8: (capacity)*2)



#define GROW_ARRAY(type, pointer, oldcap, newcap) \
    (type*)reallocate(pointer, sizeof(type) * (oldcap), \
        sizeof(type) * (newcap))


#define FREE_ARRAY(type, pointer, oldcap)\
    (type*)reallocate(pointer, sizeof(type) * (oldcap), 0)



void* reallocate(void* pointer, size_t oldsize, size_t newsize);
#endif
