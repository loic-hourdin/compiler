#include <string.h>
/* TABLE DES SYMBOLES */

typedef char name_t[8];
typedef struct{
  char* str;
  unsigned int nbr;
}str;
typedef struct{
  name_t name;
  int dim;
  enum { LIST_INT, LIST_CHAR } type;
}struct_list;

struct symbol {
  enum { NAME, CONSTANT, TEXT, LABEL, LIST, DIM } kind;
    union {
        name_t name;
        int value;
        str text;
        name_t label;
        struct_list list;
    } u;
};

struct symtable {
    unsigned int capacity;
    unsigned int temporary;
    unsigned int temporary_string;
    unsigned int temporary_label;
    unsigned int size;
    struct symbol * symbols;
};

struct symtable * symtable_new();

struct symbol * symtable_const(struct symtable * t, int v);

struct symbol * symtable_get(struct symtable * t, const char * s);

struct symbol * symtable_put(struct symtable * t, const char * s);
struct symbol * symtable_put_string(struct symtable * t, char * s);
struct symbol * symtable_put_list(struct symtable * t, const char * list, int dim, char *type);
struct symbol * symtable_put_list_dim(struct symtable * t, const char * s);

void symtable_dump(struct symtable * t);

void symtable_free(struct symtable * t);


/* QUADRUPLETS ET CODE */

struct quad {
  enum quad_kind { BOP_PLUS, BOP_MINUS, BOP_MULT, UOP_MINUS, COPY, CALL_PRINT, CALL_PRINT_STRING, CALL_PRINT_LN, SET_LABEL, GOTO, TEST_VAR,TEST_NON_VAR, TEST_EGALITE, TEST_NON_EGALITE, TEST_GREATER_OR_EQ, TEST_GREATER, TEST_LESS_OR_EQ, TEST_LESS, LIST_SET, LIST_GET } kind;
  struct symbol * sym1;
  struct symbol * sym2;
  struct symbol * sym3;
};

struct code {
    unsigned int capacity;
    unsigned int nextquad;
    struct quad * quads;
};

struct code * code_new();
struct code * concat_code(struct code * c1,struct code * c2);
void code_replace_unknow_label(struct code * c,struct symbol * s);


void gencode(struct code * c,
              enum quad_kind k,
              struct symbol * s1,
              struct symbol * s2,
              struct symbol * s3);

struct symbol *newtemp(struct symtable * t);
struct symbol * symbol_new_label( char * id) ;
struct symbol *newlabel(struct symtable * t);
struct symbol *label_unknown();

void code_dump(struct code * c);
;
void code_free(struct code * c);

/*MIPS*/

FILE * mips_out;

void mips_lecture_symbole(struct symbol * s,char* c);

void mips_data(struct symtable *t );
void mips_list_get_set_value(struct symbol *list, char* list_tmp, char* index_tmp);
void mips_list_get_value(struct symbol *list, char* list_tmp, char* index_tmp, char *result_tmp);
void mips_list_set_value(struct symbol *list, char* list_tmp, char* index_tmp, char *new_value);
void mips_code(struct code *c );
void mips_print_ascii(FILE *mips_out, char c);
