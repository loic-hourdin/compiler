
#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "lib.h"

struct symtable * symtable_new()
{
    struct symtable * t = malloc(sizeof(struct symtable));
    t->capacity = 1024;
    t->symbols = malloc(t->capacity*sizeof(struct symbol));
    t->temporary = 0;
    t->size = 0;
    return t;
}

static void symtable_grow(struct symtable * t) 
{
    t->capacity += 1024;
    t->symbols = realloc(t->symbols,t->capacity*sizeof(struct symbol));
    if(t->symbols == NULL) 
    {
      fprintf(stderr,"Error attempting to grow symbol table (actual size is %d)\n",t->size);
        exit(4);
    }
}

struct symbol * symtable_const(struct symtable * t, int v) 
{
    unsigned int i;
    for ( i=0 ; i<t->size && t->symbols[i].u.value != v; i++ );
    if(i==t->size)
    {
        if(t->size==t->capacity)
          symtable_grow(t);
        struct symbol *s = &(t->symbols[t->size]);
        s->kind = CONSTANT;
        s->u.value = v;
        ++ (t->size);
        return s;
    }
    else 
    {
        return &(t->symbols[i]);
    }
}

struct symbol * symtable_get(struct symtable * t, const char * id) 
{
    unsigned int i;
    for ( i=0 ; i<t->size && strcmp(t->symbols[i].u.name,id) != 0; i++ );
    if(i<t->size)
      return &(t->symbols[i]);
    return NULL;
}

struct symbol * symtable_put(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = NAME;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}

struct symbol * symtable_put_list_dim(struct symtable * t, const char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = DIM;
    strcpy(s->u.name,id);
    ++ (t->size);
    return s;
}

struct symbol * symbol_new_label( char * id) 
{
    
    struct symbol *s = malloc (sizeof(struct symbol));
    s->kind = LABEL;
    strcpy(s->u.label,id);
    //s->u.label=id;
    //printf("%s\n",id);
    return s;
}

struct symbol * symtable_put_string(struct symtable * t,char * id) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = TEXT;
    //strcpy(s->u.text.str,id);
    s->u.text.str=strdup(id);
    s->u.text.nbr=t->temporary_string;
    ++ (t->temporary_string);
    ++ (t->size);
    return s;
}

struct symbol * symtable_put_list(struct symtable * t, const char * list, int dim, char *type) 
{
    if(t->size==t->capacity)
      symtable_grow(t);
    struct symbol *s = &(t->symbols[t->size]);
    s->kind = LIST;
    strcpy(s->u.list.name,list);
    if(strcmp(type, "INT") == 0) {
        s->u.list.dim = dim*sizeof(int);
        s->u.list.type = LIST_INT;
    }
    else if(strcmp(type, "CHAR") == 0) {
        s->u.list.dim = dim*sizeof(char);
        s->u.list.type = LIST_CHAR;
    }
    else {
        fprintf(stderr, "Erreur : type non pris en charge dans les listes\n");
        exit(4);
    }
    ++ (t->size);
    return s;
}

void symtable_dump(struct symtable * t)
{
    unsigned int i;
    for ( i=0 ; i<t->size; i++ )
    {
      if(t->symbols[i].kind==CONSTANT)
        printf("       %p = %d\n",&(t->symbols[i]),t->symbols[i].u.value);
      else if(t->symbols[i].kind==NAME)
        printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
      else if(t->symbols[i].kind==DIM)
        printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
      else if(t->symbols[i].kind==LIST)
        printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.list.name);
    }
    printf("       --------\n");
}

void symtable_free(struct symtable * t)
{
    free(t->symbols);
    free(t);
}

struct code * code_new()
{
    struct code * r = malloc(sizeof(struct code));
    r->capacity = 1;
    r->quads = malloc(r->capacity*sizeof(struct quad));
    r->nextquad = 0;
    return r;
}

static void code_grow(struct code * c)
{
    c->capacity += 1024;
    c->quads = realloc(c->quads,c->capacity*sizeof(struct quad));
    if(c->quads == NULL) 
    {
      fprintf(stderr,"Error attempting to grow quad list (actual size is %d)\n",c->nextquad);
        exit(4);
    }
}

struct code * concat_code(struct code * c1,struct code * c2)
{   unsigned int i;
    struct code * c=code_new();
    for ( i=0 ; i<c1->nextquad ; i++ )
    {
        if ( c->nextquad == c->capacity )
            code_grow(c);
        c->quads[c->nextquad]=c1->quads[i];
        ++ (c->nextquad);
    }

    for ( i=0 ; i<c2->nextquad ; i++ )
    {
        if ( c->nextquad == c->capacity )
            code_grow(c);
        c->quads[c->nextquad]=c2->quads[i];
        ++ (c->nextquad);
    }
    return (c);
}

void gencode(struct code * c,
              enum quad_kind k,
              struct symbol * s1,
              struct symbol * s2,
              struct symbol * s3)
{
    if ( c->nextquad == c->capacity )
        code_grow(c);
    struct quad * q = &(c->quads[c->nextquad]);
    q->kind = k;
    q->sym1 = s1;
    q->sym2 = s2;
    q->sym3 = s3;
    ++ (c->nextquad);
}

void code_replace_unknow_label(struct code * c,struct symbol * s){
    unsigned int i;
    struct quad * q;
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        q = &(c->quads[i]);
        if(q->sym1!=NULL)
            if(q->sym1->kind==LABEL)
                if(strcmp(q->sym1->u.label,"unknown")==0)
                    q->sym1=s;
        if(q->sym2!=NULL)
            if(q->sym2->kind==LABEL)
                if(strcmp(q->sym1->u.label,"unknown")==0)
                    q->sym2=s;
        if(q->sym2!=NULL)
            if(q->sym2->kind==LABEL)
                if(strcmp(q->sym1->u.label,"unknown")==0)
                    q->sym2=s;
    }
}


struct symbol *newtemp(struct symtable * t)
{
  struct symbol * s;
  name_t name;
  sprintf(name,"t%d",t->temporary);
  s = symtable_put(t,name);
  ++ (t->temporary);
  return s;
}
struct symbol *newlabel(struct symtable * t)
{
  struct symbol * s;
  name_t label;
  sprintf(label,"l%d",t->temporary_label);
  s = symbol_new_label(label);
  ++ (t->temporary_label);
  return s;
}
struct symbol *label_unknown()
{
  struct symbol * s;
  char label[10];
  sprintf(label,"unknown");
  s = symbol_new_label(label);
  return s;
}

static void symbol_dump(struct symbol * s)
{
    switch ( s->kind )
    {
        case NAME:
            printf("%s",s->u.name);
            break;
        case DIM:
            printf("%s",s->u.name);
            break;
        case LABEL:
            printf("%s",s->u.label);
            break;
        case CONSTANT:
            printf("%d",s->u.value);
            break;
        case TEXT:
            printf("%s",s->u.text.str);
            break;
        case LIST:
            printf("%s",s->u.list.name);
            break;
        default:
            break;
    }
}

static char* symbol_d(struct symbol * s)
{   
    char *f=malloc(20*sizeof(char));
    switch ( s->kind )
    {   
        case NAME:
            sprintf(f,"val_%s",s->u.name);
            break;
        case DIM:
            sprintf(f,"dim_%s",s->u.name);
            break;
        case LABEL:
            sprintf(f,"lab_%s",s->u.label);
            break;
        case CONSTANT:
            sprintf(f,"%d",s->u.value);
            break;
        case TEXT:
            sprintf(f,"text%i",s->u.text.nbr);
            break; 
        case LIST:
            sprintf(f,"list_%s",s->u.list.name);
            break;
        default:
            printf("::error:: bad type of symbol\n");
            break;
    }
    return(f);
}

static void quad_dump(struct quad * q)
{
    switch ( q->kind )
    {
        case BOP_PLUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" + ");
            symbol_dump(q->sym3);
            break;
        case BOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" - ");
            symbol_dump(q->sym3);
            break;
        case BOP_MULT:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf(" * ");
            symbol_dump(q->sym3);
            break;
        case UOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            printf("- ");
            symbol_dump(q->sym2);
            break;
        case CALL_PRINT:
            printf("print ");
            symbol_dump(q->sym1);
            break;
        case CALL_PRINT_STRING:
            printf("printtexte ");
            symbol_dump(q->sym1);
            break;
        case CALL_PRINT_LN:
            printf("println");
            break;
        case COPY:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            break;
        case SET_LABEL:
            symbol_dump(q->sym1);
            printf(" : ");
            break;
        case GOTO:
            printf("GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_VAR:
            printf("if ");
            symbol_dump(q->sym2);
            printf(" GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_EGALITE:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" = ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_NON_VAR:
            printf("if not ");
            symbol_dump(q->sym2);
            printf(" GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_NON_EGALITE:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" != ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_GREATER_OR_EQ:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" >= ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_GREATER:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" > ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_LESS_OR_EQ:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" <= ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case TEST_LESS:
            printf("if ( ");
            symbol_dump(q->sym2);
            printf(" < ");
            symbol_dump(q->sym3);
            printf(" ) GOTO ");
            symbol_dump(q->sym1);
            break;
        case LIST_SET:
            symbol_dump(q->sym1);
            printf("[");
            symbol_dump(q->sym2);
            printf("] := ");
            symbol_dump(q->sym3);
            break;
        case LIST_GET:
            symbol_dump(q->sym1);
            printf(" := ");
            symbol_dump(q->sym2);
            printf("[");
            symbol_dump(q->sym3);
            printf("] ");
            break;
        default:
            printf("BUG %i\n",q->kind);
            break;
    }
}

void code_dump(struct code * c)
{
    unsigned int i;
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        printf("%4u | ",i);
        quad_dump(&(c->quads[i]));
        printf("\n");
    }
}

void code_free(struct code * c)
{
    free(c->quads);
    free(c);
}


/*MIPS*/

void mips_lecture_symbole(struct symbol * s,char* c){
    //printf("atest\n");
    switch ( s->kind )
        {   
            case NAME:
                fprintf(mips_out,"lw %s, val_%s\n",c,s->u.name);
                break;
            case DIM:
                fprintf(mips_out,"lw %s, dim_%s\n",c,s->u.name);
                break;
            case CONSTANT:
                fprintf(mips_out,"li %s, %d\n",c,s->u.value);
                break;
            case LIST:
                fprintf(mips_out,"la %s, list_%s\n",c,s->u.list.name);
                break;
            default:
                printf("::error::(mips_code) bad type of symbol\n");
                break;
        }
}

void mips_list_get_set_value(struct symbol *list, char* list_tmp, char* index_tmp) {
    switch(list->u.list.type) {
        case LIST_INT:
            //Index = 4*index + index_list
            fprintf(mips_out, "add %s, %s, %s\n", index_tmp, index_tmp, index_tmp);
            fprintf(mips_out, "add %s, %s, %s\n", index_tmp, index_tmp, index_tmp);
            fprintf(mips_out, "add %s, %s, %s\n", index_tmp, index_tmp, list_tmp);
            break;
        case LIST_CHAR:
            //Index = index + index_list
            fprintf(mips_out, "add %s, %s, %s\n", index_tmp, index_tmp, list_tmp);
            break;
        default:
            printf("::error::(mips_code) bad type of list\n");
            break;
    }
}

void mips_list_get_value(struct symbol *list, char *result_tmp, char* list_tmp, char* index_tmp) {
    mips_list_get_set_value(list, list_tmp, index_tmp);
    fprintf(mips_out,"lw %s, 0(%s)\n", result_tmp, index_tmp);
}

void mips_list_set_value(struct symbol *list, char* list_tmp, char* index_tmp, char *new_value) {
    mips_list_get_set_value(list, list_tmp, index_tmp);
    fprintf(mips_out,"sw %s, 0(%s)\n", new_value, index_tmp);
}

void mips_data(struct symtable *t){
    unsigned int i;
    fprintf(mips_out,"\t\t.data\n");
    for ( i=0 ; i<t->size; i++ )
    {
      if(t->symbols[i].kind==NAME)
       fprintf(mips_out,"val_%s:\t.word\t0\n",t->symbols[i].u.name);
       // printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
      else if(t->symbols[i].kind==DIM)
       fprintf(mips_out,"dim_%s:\t.word\t0\n",t->symbols[i].u.name);
       // printf("       %p = %s\n",&(t->symbols[i]),t->symbols[i].u.name);
      else if(t->symbols[i].kind==TEXT)
       fprintf(mips_out,"text%i:\t.asciiz\t%s\n",t->symbols[i].u.text.nbr,t->symbols[i].u.text.str);
      else if(t->symbols[i].kind==LIST) {
            fprintf(mips_out,"list_%s:\t.space\t%d\n",t->symbols[i].u.list.name, t->symbols[i].u.list.dim);
        }
    }
    //printf("       --------\n");
}

void mips_print_ascii(FILE *mips_out, char c) {
    fprintf(mips_out, "li $a0, %d\n", c);
    fprintf(mips_out, "li $v0, 11\n");
    fprintf(mips_out, "syscall\n");
}

void mips_code(struct code *c ){
    unsigned int i;
    struct quad * q;
    fprintf(mips_out,"\t\t.text\nmain:\n");
    for ( i=0 ; i<c->nextquad ; i++ )
    {
        //printf("%4u | ",i);
        q = &(c->quads[i]);
        switch ( q->kind )
        {
        case BOP_PLUS:
            mips_lecture_symbole(q->sym2,"$t0");
            //fprintf(mips_out,"lw $t0, %s\n",symbol_d(q->sym2));
            mips_lecture_symbole(q->sym3,"$t1");
            //fprintf(mips_out,"lw $t1, %s\n",symbol_d(q->sym3));
            /*switch ( q->sym3->kind )
            {
                case NAME:
                    fprintf(mips_out,"lw $t1, %s\n",symbol_d(q->sym3));
                    break;
                case CONSTANT:
                    fprintf(mips_out,"li $t1, %s\n",symbol_d(q->sym3));
                    break;
                default:
                    printf("::error::(mips_code) bad type of symbol\n");
                    break;
            }*/
            fprintf(mips_out,"add $t2, $t0, $t1\n");
            fprintf(mips_out,"sw $t2, %s\n",symbol_d(q->sym1));
            break;
        case BOP_MINUS:
            mips_lecture_symbole(q->sym2,"$t0");
            //fprintf(mips_out,"lw $t0, %s\n",symbol_d(q->sym2));
            mips_lecture_symbole(q->sym3,"$t1");
            //fprintf(mips_out,"lw $t1, %s\n",symbol_d(q->sym3));
            fprintf(mips_out,"sub $t2, $t0, $t1\n");
            fprintf(mips_out,"sw $t2, %s\n",symbol_d(q->sym1));
            break;
        case BOP_MULT:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"mult $t0, $t1\n");
            fprintf(mips_out,"mflo $t2\n");
            fprintf(mips_out,"sw $t2, %s\n",symbol_d(q->sym1));
            break;
        case COPY:
            mips_lecture_symbole(q->sym2,"$t0");
            /*switch ( q->sym2->kind )
            {
                case NAME:
                    fprintf(mips_out,"lw $t0, %s\n",symbol_d(q->sym2));
                    break;
                case CONSTANT:
                    fprintf(mips_out,"li $t0, %s\n",symbol_d(q->sym2));
                    break;
                default:
                    printf("::error::(mips_code) bad type of symbol\n");
                    break;
            }*/
            fprintf(mips_out,"sw $t0, %s\n",symbol_d(q->sym1));
            break;
        case CALL_PRINT:
            fprintf(mips_out,"li $v0, 1\n");
            fprintf(mips_out,"lw $a0, %s\n",symbol_d(q->sym1));
            fprintf(mips_out,"syscall\n");
            mips_print_ascii(mips_out, ' ');
            break;
        case CALL_PRINT_STRING:
            fprintf(mips_out,"li $v0, 4\n");
            fprintf(mips_out,"la $a0, %s\n",symbol_d(q->sym1));
            fprintf(mips_out,"syscall\n");
            mips_print_ascii(mips_out, ' ');
            break;
        case CALL_PRINT_LN:
            mips_print_ascii(mips_out, '\n');
            break;
        case SET_LABEL:
            fprintf(mips_out,"%s:\n",symbol_d(q->sym1));
            break;
        case GOTO:
            fprintf(mips_out,"j %s\n",symbol_d(q->sym1));
            break;
        case TEST_NON_VAR:
            mips_lecture_symbole(q->sym2,"$t0");
            fprintf(mips_out,"bne $t0, 1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_NON_EGALITE:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"bne $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_VAR:
            mips_lecture_symbole(q->sym2,"$t0");
            fprintf(mips_out,"beq $t0, 1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_EGALITE:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"beq $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_GREATER_OR_EQ:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"bge $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_GREATER:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"bgt $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_LESS_OR_EQ:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"ble $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case TEST_LESS:
            mips_lecture_symbole(q->sym2,"$t0");
            mips_lecture_symbole(q->sym3,"$t1");
            fprintf(mips_out,"blt $t0, $t1, %s \n",symbol_d(q->sym1));
            break;
        case LIST_SET:
            mips_lecture_symbole(q->sym3,"$t0"); //new_value
            mips_lecture_symbole(q->sym2,"$t1"); //index
            mips_lecture_symbole(q->sym1,"$t2"); //list
            mips_list_set_value(q->sym1, "$t2", "$t1", "$t0");
            break;
        case LIST_GET:
            mips_lecture_symbole(q->sym3,"$t2"); //index
            mips_lecture_symbole(q->sym2,"$t1"); //list
            mips_list_get_value(q->sym2, "$t0", "$t1", "$t2");
            fprintf(mips_out,"sw $t0, %s\n",symbol_d(q->sym1));
            break;
        /*case BOP_MULT:
            printf("lw $t0, %s\n",symbol_d(q->sym2));
            printf("lw $t1, %s\n",symbol_d(q->sym3));
            printf("mul $t2, $t0, $t1\n");
            printf("sw $t2, %s\n",symbol_d(q->sym1));
            break;
        case UOP_MINUS:
            symbol_dump(q->sym1);
            printf(" := ");
            printf("- ");
            symbol_dump(q->sym2);
            break;
        
        */
        default:
            printf("BUG écriture en mips %i\n",q->kind);
            break;
        }
        
        //printf("\n");
    }
mips_print_ascii(mips_out, '\n');
fprintf(mips_out,"li $v0, 10\n");
fprintf(mips_out,"syscall\n");
}