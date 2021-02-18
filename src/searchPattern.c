#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ganylib.h"

/* CONSTANTS */

/* STRUCTS */

/* PROTOTYPES */

/* FUNCTIONS */

/*
 * Implementation notes: searchPattern
 * -----------------------------------
 * This search function takes a file stream as input.
 * It reads line by line until it hits the pattern.
 * This line is then tokenized and the tokens are
 * counted until 'cntr' is equal to 'offset'; which
 * is the n-th word the user is looking for.
 * 
 * Because this function is called for several lookups
 * in the same (one-time opened) file, the file
 * read-pointer is rewinded before new lookup, so that
 * the search can start from the beginning of the file. 
 */

char * searchPattern(char *fn, const char *pattern, int offset) {
  FILE *fp;
  fp = fopen(fn, "r");
  if (NULL == fp) {
    printf("Fehler beim Oeffnen der Datei: %s\n", fn);
    exit(1);	
  }
  size_t len = 0;
  char *line = NULL;
  static char *token = NULL;
  int cntr = 0;
  while ((getline(&line, &len, fp)) != EOF) {
    if (strstr(line, pattern)) {
      token = strtok(line, " ,\t");
      while (token != NULL) {
        cntr++;
        if (cntr == offset) {
          /* Delete new-line character, if present */
	  size_t sz = strlen(token);
	  if (token[sz-1] == '\n') {
	    token[sz-1] = '\0';
	    }
	  return token;
        } 
        token = strtok(NULL, " ");
      }
    }
  }
  fclose(fp);
  return token;
}
