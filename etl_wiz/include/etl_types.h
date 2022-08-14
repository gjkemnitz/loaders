#ifndef ETL_STRING_H_INCL
#define ETL_STRING_H_INCL

/* string type */

typedef enum ETL_Charset {
  ETL_ASCII,
  ETL_UTF8,
  ETL_UTF16,
  ETL_BINARY
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

/* other types */

typedef enum ETL_Datatype {
  ETL_INT,
  ETL_FLOAT,
  ETL_STRING,
  ETL_BOOL,
  ETL_DATETIME,
  ETL_TIMESTAMP
} ETL_Datatype;

typedef enum ETL_OpType {
  ETL_ADD,
  ETL_SUBTRACT,
  ETL_MULTIPLY,
  ETL_DIVIDE,
  ETL_MODULUS,
  ETL_UNEG, /* -<exp> */
  ETL_AND,
  ETL_OR,
  ETL_NOT
} ETL_OpType;

typedef enum ETL_SpecialValue {
  ETL_NULL,
  ETL_DEFAULT
} ETL_SpecialValue;

#endif /* ETL_STRING_H_INCL */
