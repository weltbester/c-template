/* 
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart
 * File: readDataFromTerminal.c
 * ----------------------------
 * This function implements the interface of 'ganylib.h'.
 */

#include <stdio.h>
#include <stdlib.h>
#include "eigeneVorlagen/ganylib.h"

/* CONSTANTS */

/* STRUCTS */

/* PROTOTYPES */


/* FUNCTIONS */
/* {} [] \ */

/*
 * Implementation notes: dump_buffer()
 * --------------------------------------------
 * Takes a filestream and runs through it until it
 * reaches EOF or '\n'. After that the stream is
 * empty for further use.
 */

void dump_buffer(FILE *fp) {
  int ch;
  while ( (ch = fgetc(fp)) != EOF && ch != '\n' ) {
    /* keine Anweisung nötig */ ;
  }
}


