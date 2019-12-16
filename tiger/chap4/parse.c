/*
 * parse.c - Parse source file.
 */

#include "parse.h"
#include "absyn.h"
#include "errormsg.h"
#include "symbol.h"
#include "util.h"
#include <stdio.h>

extern int yyparse(void);
extern A_exp absyn_root;

/* parse source file fname;
y  return abstract syntax data structure */
A_exp parse(string fname) {
  EM_reset(fname);
  if (yyparse() == 0) /* parsing worked */
    return absyn_root;
  else
    return NULL;
}
