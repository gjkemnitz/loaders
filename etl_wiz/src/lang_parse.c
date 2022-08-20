#include <stddef.h>
#include <stdbool.h>
#include <stdint.h>

#include "etl_types.h"

#include "etl_parse.h"

typedef struct kw {
  int n_keywords;
  struct {
    char *keyword;
    int kw_id;
  } x[10];
} ETL_KeywordStruct;

static
int
ETL_GetKeyWord(char *keyword)

{
  /* The idea below is to use the first letter in the keyword to hash into
   * the keyword lookup array, with position 0 in the 'A' position, etc.
   *
   * The keyword is assumed to be all UPPER_CASE here.
   * This minimizes search time, particularly for
   * non-keyword identifiers, because we don't have an enormous number of
   * "if" statements to wade through.
   */

  static ETL_KeywordStruct
  kw_list[26]={{1, {{"AND", ETL_TOK_AND}}},
               {0, {{NULL}}},
               {2, {{"CASE", ETL_TOK_CASE}, {"CLENGTH", ETL_TOK_CLENGTH},
                    {"CONCAT", ETL_TOK_CONCAT}}},
               {1, {{"DEFAULT", ETL_TOK_DEFAULT}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {9, {{"IF", ETL_TOK_IF},
                    {"IFEMPTY", ETL_TOK_IFEMPTY},
                    {"IFNULL", ETL_TOK_IFNULL},
                    {"IN", ETL_TOK_IN}, 
                    {"INSTR", ETL_TOK_INSTR}, 
                    {"ISEMPTY", ETL_TOK_ISEMPTY},
                    {"ISNOTEMPTY", ETL_TOK_ISNOTEMPTY},
                    {"ISNOTNULL", ETL_TOK_ISNOTNULL},
                    {"ISNULL", ETL_TOK_ISNULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {3, {{"LENGTH", ETL_TOK_LENGTH}, {"LIKE", ETL_TOK_LIKE},
                    {"LOWER", ETL_TOK_LOWER}}},
               {0, {{NULL}}},
               {2, {{"NOT", ETL_TOK_NOT}, {"NULL", ETL_TOK_NULL}}},
               {1, {{"OR", ETL_TOK_OR}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {1, {{"SUBSTR", ETL_TOK_SUBSTR}}},
               {0, {{NULL}}},
               {1, {{"UPPER", ETL_TOK_UPPER}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
               {0, {{NULL}}},
              };
  int i, n, off;
  char *p;
  char *q;

  /* No SQL keywords shorter than 2 characters */

  if (keyword[1] == 0) return ETL_TOK_IDENTIFIER;

  off = keyword[0] - 'A';

  /* Check for Unicode non-ascii keywords */

  if (off < 0 || off > 25) return ETL_TOK_IDENTIFIER;

  n = kw_list[off].n_keywords;

  for (i = 0; i < n; i++) {
    p = &(kw_list[off].x[i].keyword[1]);
    q = &keyword[1];

    while (*p == *q && *p != 0) {
      p++; q++;
    }
    if (*p == 0 && *q == 0) {
      return kw_list[off].x[i].kw_id;
    }
  }

  return ETL_TOK_IDENTIFIER;
}

/* #define TEST_LEX_STANDALONE */
#ifdef TEST_LEX_STANDALONE

#include <stdio.h>
#include <string.h>

int
main(void)

{
  int x;
  bool done = false;

  while (!done) {
    char buf[128];
    printf("--> ");

    if (fgets(buf, 128, stdin) == NULL) {
      done = true;
      continue;
    }

    buf[strlen(buf)-1] = '\0';

    x = ETL_GetKeyWord(buf);
    printf("keyword is %d\n", x);
  }
 
  return 0;
}

#endif /* TEST_LEX_STANDALONE */
