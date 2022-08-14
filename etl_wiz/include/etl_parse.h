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
