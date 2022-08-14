#ifndef ETL_EXP_H_INCL
#define ETL_EXP_H_INCL

#define ETL_EXP_IF           0
#define ETL_EXP_IFNULL       1
#define ETL_EXP_CONCAT       2
#define ETL_EXP_LITERAL      3
#define ETL_EXP_TGTREF       4 /* tab.col - refers to already computed tgt */
#define ETL_EXP_IN           5
#define ETL_EXP_AND          6
#define ETL_EXP_OR           7
#define ETL_EXP_NOT          8
#define ETL_EXP_SRCREF       9 /* $1, $2, etc - referring to inbound source */
#define ETL_EXP_VARIABLE    10 /* @uservar */
#define ETL_EXP_IFEMPTY     11 /* like IFNULL, but an empty-string test */
#define ETL_EXP_BETWEEN     12
#define ETL_EXP_CASE        13

#endif /* ETL_EXP_H_INCL */
