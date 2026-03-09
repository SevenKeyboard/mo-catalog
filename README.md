# MoCatalog
A small runtime library for loading GNU gettext MO catalogs and retrieving localized strings.

- Provides a small DLL wrapper around [Boost.Locale](https://www.boost.org/libs/locale/) for loading GNU gettext MO catalogs and retrieving translated strings.
- Uses UTF-8 for input strings and output strings.
- Exposes a small C-style DLL interface for external consumers.
- Third-party libraries and their licenses can be found in the `third_party` folder.

## API

- `MoCatalogCreate(localeDir, localeName, domain)`  
  Creates a catalog handle for the specified locale directory, locale name, and domain.

- `MoCatalogDestroy(handle)`  
  Destroys a catalog handle created by `MoCatalogCreate`.

- `MoCatalogGetText(handle, msgid, outBuf, outBufSize)`  
  Retrieves the translated string for `msgid`.

- `MoCatalogNGetText(handle, singular, plural, n, outBuf, outBufSize)`  
  Retrieves the plural-aware translated string for the given count `n`.

- `MoCatalogPGetText(handle, context, msgid, outBuf, outBufSize)`  
  Retrieves the translated string for `msgid` within the specified context.

- `MoCatalogNPGetText(handle, context, singular, plural, n, outBuf, outBufSize)`  
  Retrieves the context-aware plural translation for the given count `n`.

## Notes

- All input strings and output strings use UTF-8.
- String-returning functions return the required buffer size including the null terminator.
- On failure, string-returning functions return `0`.