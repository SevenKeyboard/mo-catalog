/**
 * @file MoCatalogExports.h
 * @brief Public DLL exports for MoCatalog
 *
 * GitHub: https://github.com/SevenKeyboard/mo-catalog
 * Author: SevenKeyboard Ltd. (2026)
 * License: MIT License
 */
#pragma once

#include <cstddef>

#ifdef MOCATALOG_EXPORTS
#   define MOCATALOG_API extern "C" __declspec(dllexport)
#else
#   define MOCATALOG_API extern "C" __declspec(dllimport)
#endif

#define MOCATALOG_CALL __stdcall

MOCATALOG_API void* MOCATALOG_CALL MoCatalogCreate(
    const char* localeDir,
    const char* localeName,
    const char* domain
);

MOCATALOG_API void MOCATALOG_CALL MoCatalogDestroy(
    void* handle
);

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogGetText(
    void* handle,
    const char* msgid,
    char* outBuf,
    size_t outBufSize
);

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogNGetText(
    void* handle,
    const char* singular,
    const char* plural,
    int n,
    char* outBuf,
    size_t outBufSize
);

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogPGetText(
    void* handle,
    const char* context,
    const char* msgid,
    char* outBuf,
    size_t outBufSize
);

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogNPGetText(
    void* handle,
    const char* context,
    const char* singular,
    const char* plural,
    int n,
    char* outBuf,
    size_t outBufSize
);