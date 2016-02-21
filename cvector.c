/*++

Copyright (c) 2016 shadownet

Module Name:

    cvector.c

Abstract:

    C implementation of Vector.

Author:

    Arsham

--*/ 

#include "precomp.h"

void _init(
    _In_ PCVECTOR vec)
{
    vec->capacity = VECTOR_INIT_CAPACITY;
    vec->size = 0;
    vec->elm = (void**) malloc(sizeof(void *) * vec->capacity);
}


static void _resize(PCVECTOR vec, int capacity)
{

    printf("_resize: %d to %d\n", vec->capacity, capacity);

    void **elm = (void **)realloc(vec->elm, sizeof(void *) * capacity);
    if (elm) {
        vec->elm = elm;
        vec->capacity = capacity;
    }
}

void _add(
    PCVECTOR vec, 
    void* id)
{
    if(vec->size == vec->capacity)
    {
        _resize(vec, vec->capacity * 2);
    }
    
    vec->elm[vec->size++] = id;
}

void _set(
    PCVECTOR vec, 
    void* id, uint32 index)
{
    if (index >= 0 && index < vec->size)
        vec->elm[index] = id;
}

void _delete(
    PCVECTOR vec, 
    uint32 index)
{
    if (index < 0 || index >= vec->size)
        return;

    vec->elm[index] = NULL;

    for (uint32 i = 0; i < vec->size - 1; i++) {
        vec->elm[i] =  vec->elm[i + 1];
        vec->elm[i + 1] = NULL;
    }

    vec->size--;

    if (vec->size > 0 && vec->size == vec->capacity / 4)
        _resize(vec, vec->capacity / 2);
}

void _free(PCVECTOR vec)
{
    free(vec->elm);
}

int _size(_In_ PCVECTOR vec)
{
    return vec->size;
}

void* _get(
    PCVECTOR vec, 
    uint32 index)
{
    if (index >= 0 && index < vec->size)
        return vec->elm[index];
    return NULL;
}