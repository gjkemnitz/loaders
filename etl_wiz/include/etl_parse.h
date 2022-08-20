#ifndef ETL_PARSE_H_INCL
#define ETL_PARSE_H_INCL

/*
 * These are parse utilities used to parse etl_script processing
 * language.
 */

#define ETL_TOK_INT              1
#define ETL_TOK_FLOAT            2
#define ETL_TOK_STRING           3

#define ETL_TOK_COLREF           4 /* foo.bar */
#define ETL_TOK_LEFTPAREN        5
#define ETL_TOK_RIGHTPAREN       6
#define ETL_TOK_COMMA            7
#define ETL_TOK_NAME             8 /* An alphanumeric name */
#define ETL_TOK_SYMBOL           9 /* A string of symbols, ie +, <=, etc */
#define ETL_TOK_PARAM            10 /* $<INTEGER>$, used for parameter funcs */

#define ETL_TOK_NULL             11
#define ETL_TOK_ERROR            12
#define ETL_TOK_DONE             13
#define ETL_TOK_IDENTIFIER       14

#define ETL_TOK_NOT              15
#define ETL_TOK_AND              16
#define ETL_TOK_CASE             17
#define ETL_TOK_CONCAT           18
#define ETL_TOK_OR               19
#define ETL_TOK_CLENGTH          20
#define ETL_TOK_DEFAULT          21
#define ETL_TOK_IF               22
#define ETL_TOK_IFNULL           23
#define ETL_TOK_IFEMPTY          24
#define ETL_TOK_IN               25
#define ETL_TOK_INSTR            26
#define ETL_TOK_ISNOTEMPTY       27
#define ETL_TOK_ISEMPTY          28
#define ETL_TOK_ISNOTNULL        29
#define ETL_TOK_ISNULL           30
#define ETL_TOK_LENGTH           31
#define ETL_TOK_LIKE             32
#define ETL_TOK_LOWER            33
#define ETL_TOK_SUBSTR           34
#define ETL_TOK_UPPER            35

/*
 * We try hard to keep ETL_LexInfo an integral value
 */

#define ETL_MAXNAME              54

typedef struct ETL_LexInfo {
    void *lexstr; /* points at "given" string data! */
    int32_t position;
    int32_t nchars;
    uint32_t param_pos;
    char buf[ETL_MAXNAME];
    ETL_String *str;
    bool all_ascii;
} ETL_LexInfo;

ETL_LexInfo *
ETL_LexInit(ETL_String *lexstr);

void
ETL_LexInfoDestroy(ETL_LexInfo *linfo);

int
ETL_Lexer(ETL_LexInfo *l);

#endif /* ETL_PARSE_H_INCL */
