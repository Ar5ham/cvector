/*
Copyright (c) 2016 shadownet

Abstract:
    Sample usage of cvector.

Author:

    Arsham

--*/ 

#include "precomp.h"

int __cdecl
wmain (
    _In_ LONG argc,
    _In_reads_(argc) PCWSTR* argv
    )
{
    UNREFERENCED_PARAMETER(argv); 
    UNREFERENCED_PARAMETER(argc);

    CVECTOR cvec;
    _init(&cvec);
    
    PWSTR elms[4] = {L"elm1", L"elm2", L"elm3", L"elm4"};

    // Just adding 4 elemets
    for(int i = 0; i < _countof(elms); i++)
    {
        _add(&cvec, elms[i]);
    }

    for (int j = 0; j < _size(&cvec); j++)
         wprintf(L"%ls ", (PCWSTR*) _get(&cvec, j));
    wprintf(L"\n");

    _free(&cvec);

    return 0;
}