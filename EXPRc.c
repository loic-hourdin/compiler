
#include "EXPRc.h"

int main(int argc, char* argv[])
{
	if (argc == 2) {
		if ((yyin = fopen(argv[1], "r")) == NULL) {
			fprintf(stderr, "[texcc] error: unable to open file %s\n", argv[1]);
			exit(0);
		}
	}
	else {
		fprintf(stderr, "[texcc] usage: %s input_file\n", argv[0]);
		exit(0);
	}
	if ((mips_out = fopen("output.s", "w")) == NULL) {
		fprintf(stderr, "[texcc] error: unable to open file output.s\n");
		exit(0);
	}

	SYMTAB = symtable_new();
	CODE = code_new();
	int r = yyparse();
	symtable_dump(SYMTAB);
	code_dump(CODE);
	mips_data(SYMTAB);
	mips_code(CODE);
	symtable_free(SYMTAB);
	code_free(CODE);
	fclose(yyin);
	fclose(mips_out);
	return r;
}
