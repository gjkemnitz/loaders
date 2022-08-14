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
#define ETL_EXP_SPEC_VALUE  14

typedef struct ETL_IfExp {
  struct ETL_Exp *test_exp;
  struct ETL_Exp *true_exp;
  struct ETL_Exp *false_exp;
} ETL_IfExp;

typedef struct ETL_IfNullExp {
  struct ETL_Exp *test_exp;
  struct ETL_Exp *ifnull_exp;
  bool if_empty; /* IFEMPTY() is logically identical to IFNULL() */
} ETL_IfNullExp;

typedef struct ETL_ConcatExp {
  struct ETL_Exp **c_exps;
  int n_args;
} ETL_ConcatExp;

/* may add int, float, etc later */

typedef struct ETL_LiteralExp {
  ETL_String *str; 
} ETL_LiteralExp;

/* may come up with something different later */

typedef struct ETL_TgtrefExp {
  ETL_String *tabname;
  ETL_String *colname;
} ETL_TgtrefExp;

typedef struct ETL_InExp {
  struct ETL_Exp *test_exp;
  struct ETL_Exp **in_vals;
  int n_in_vals;
} ETL_InExp;

/* we'll see if AND and OR need to be done like this */

/* Also, may need a more sophisticated treatment at some point */

typedef struct ETL_OpExp {
  struct ETL_Exp *lhs; /* lhs can be NULL for unary ops */
  struct ETL_Exp *rhs; 
  ETL_OpType op_type; /* +, -, AND, etc */
} ETL_OpExp;

typedef struct ETL_SrcRefExp {
  ETL_String *refname;
} ETL_SrcrefExp;

typedef struct ETL_VariableExp {
  ETL_String *var_name;
  ETL_String *var_value;
} ETL_VariableExp;

/* case(1,0,2,1,3,4) is 3 */

typedef struct ETL_CaseExp {
  struct ETL_Exp *test_exp;
  struct ETL_Exp **equal_tests;
  struct ETL_Exp **equal_values;
  struct ETL_Exp *fallthrough_value;
  int n_equal_vals;
} ETL_CaseExp;

/* NULL or DEFAULT */

typedef struct ETL_SpecialValueExp {
  ETL_SpecialValue value;
} ETL_SpecialValueExp; 

/* this is the unifying exp struct */

typedef struct ETL_Exp {
  ETL_Datatype exp_datatype;
  int exp_type; /* one of ETL_EXP_IF, etc */
  union {
    ETL_IfExp             ie;
    ETL_IfNullExp         ne;
    ETL_ConcatExp         ce;
    ETL_LiteralExp        le;
    ETL_TgtrefExp         te;
    ETL_InExp             ine;
    ETL_OpExp             oe;
    ETL_SrcrefExp         se;
    ETL_VariableExp       ve;
    ETL_CaseExp           cse;
    ETL_SpecialValueExp   sve;
  } e;
} ETL_Exp;

#endif /* ETL_EXP_H_INCL */
