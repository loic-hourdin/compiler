
#include <stdio.h>
#include <stdlib.h>
#include "lib.h"

struct symtable * SYMTAB;
struct code * CODE;
extern FILE* yyin;
extern int yyparse();
