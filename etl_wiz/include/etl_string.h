#ifndef ETL_STRING_H_INCL
#define ETL_STRING_H_INCL

typedef enum ETL_Charset {
  ASCII,
  UTF8,
  UTF16,
  BINARY
} ETL_Charset;

/* a bit more "wasteful" than other strings I've done
 * because these strings are transient and we never have more
 * than a few dozen in RAM at any given time - and we don't
 * store them.  But these string types need to handle
 * embedded NULs and such, particularly for UTF16 and BINARY
 */

typedef struct ETL_String {
  uint32_t nbytes;
  uint32_t nchars;
  ETL_Charset charset;
  uint8_t bytes[1]; /* Variable length array of nbytes */
} ETL_String;

#endif /* ETL_STRING_H_INCL */
