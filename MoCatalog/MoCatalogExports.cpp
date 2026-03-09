/**
 * @file MoCatalogExports.cpp
 * @brief gettext-style MO catalog wrapper exports for Boost.Locale
 *
 * GitHub: https://github.com/SevenKeyboard/mo-catalog
 * Author: SevenKeyboard Ltd. (2026)
 * License: MIT License
 */
#include "pch.h"
#include "MoCatalogExports.h"
#include <string>
#include <locale>
#include <cstring>
#include <memory>
#include <boost/locale.hpp>

struct CatalogHandle
{
    std::string localeDir;
    std::string localeName;
    std::string domain;
    std::locale loc;
};

static size_t copyTranslatedString(
    const std::string& translated,
    char* outBuf,
    size_t outBufSize
);

static size_t failOutputBuffer(
    char* outBuf,
    size_t outBufSize
);

MOCATALOG_API void* MOCATALOG_CALL MoCatalogCreate(
    const char* localeDir,
    const char* localeName,
    const char* domain
)
{
    if (!localeDir || !localeName || !domain)
        return nullptr;
    try
    {
        auto handle = std::make_unique<CatalogHandle>();
        handle->localeDir = localeDir;
        handle->localeName = localeName;
        handle->domain = domain;

        boost::locale::generator gen;
        gen.add_messages_path(handle->localeDir);
        gen.add_messages_domain(handle->domain);
        handle->loc = gen(handle->localeName);

        return handle.release();
    }
    catch (...)
    {
        return nullptr;
    }
}

MOCATALOG_API void MOCATALOG_CALL MoCatalogDestroy(
    void* handle
)
{
    delete static_cast<CatalogHandle*>(handle);
}

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogGetText(
    void* handle,
    const char* msgid,
    char* outBuf,
    size_t outBufSize
)
{
    if (!handle || !msgid) return 0;
    auto* catalog = static_cast<CatalogHandle*>(handle);
    try
    {
        const std::string translated = boost::locale::gettext(msgid, catalog->loc);
        return copyTranslatedString(translated, outBuf, outBufSize);
    }
    catch (...)
    {
        return failOutputBuffer(outBuf, outBufSize);
    }
}

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogNGetText(
    void* handle,
    const char* singular,
    const char* plural,
    int n,
    char* outBuf,
    size_t outBufSize
)
{
    if (!handle || !singular || !plural) return 0;
    auto* catalog = static_cast<CatalogHandle*>(handle);
    try
    {
        const std::string translated = boost::locale::ngettext(singular, plural, n, catalog->loc);
        return copyTranslatedString(translated, outBuf, outBufSize);
    }
    catch (...)
    {
        return failOutputBuffer(outBuf, outBufSize);
    }
}

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogPGetText(
    void* handle,
    const char* context,
    const char* msgid,
    char* outBuf,
    size_t outBufSize
)
{
    if (!handle || !context || !msgid) return 0;
    auto* catalog = static_cast<CatalogHandle*>(handle);
    try
    {
        const std::string translated = boost::locale::pgettext(context, msgid, catalog->loc);
        return copyTranslatedString(translated, outBuf, outBufSize);
    }
    catch (...)
    {
        return failOutputBuffer(outBuf, outBufSize);
    }
}

MOCATALOG_API size_t MOCATALOG_CALL MoCatalogNPGetText(
    void* handle,
    const char* context,
    const char* singular,
    const char* plural,
    int n,
    char* outBuf,
    size_t outBufSize
)
{
    if (!handle || !context || !singular || !plural) return 0;
    auto* catalog = static_cast<CatalogHandle*>(handle);
    try
    {
        const std::string translated = boost::locale::npgettext(context, singular, plural, n, catalog->loc);
        return copyTranslatedString(translated, outBuf, outBufSize);
    }
    catch (...)
    {
        return failOutputBuffer(outBuf, outBufSize);
    }
}

static size_t copyTranslatedString(
    const std::string& translated,
    char* outBuf,
    size_t outBufSize
)
{
    const size_t requiredSize = translated.size() + 1;
    if (outBuf && outBufSize >= requiredSize)
        memcpy(outBuf, translated.c_str(), requiredSize);
    return requiredSize;
}

static size_t failOutputBuffer(
    char* outBuf,
    size_t outBufSize
)
{
    if (outBuf && outBufSize)
        outBuf[0] = '\0';
    return 0;
}