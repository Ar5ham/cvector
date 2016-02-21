/*++

Copyright (c) 2016 shadownet

Module Name:

    cvector.h

Abstract:

    cvector header file.

Author:

    Arsham

--*/ 


#ifndef CVECTOR_H
#define CVECTOR_H

#define VECTOR_INIT_CAPACITY 100

#if ! defined _countof
    #define _countof(x) (sizeof(x)/sizeof(x[0]))
#endif

typedef struct _C_VECTOR
{
    void** elm;         // Array of elements
    uint32 capacity;    // total available slots
    uint32 size;        // slots used so far.
} CVECTOR, *PCVECTOR;


void _init(_In_ PCVECTOR vec);
void _free(PCVECTOR vec); 
int _size(_In_ PCVECTOR vec);

void _add(PCVECTOR vec, void* item);
void _set(PCVECTOR vec, void* id, uint32 index);

void* _get(PCVECTOR vec, uint32 index);


#endif