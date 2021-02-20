/** @file searchUnspecificString.c
 *  @brief Short, generic description about the function
 *
 *  @author Georg Pohl
 *
 *  @bug no known bugs
 * 
 *  Date of creation: 20-04-2020
 * 
 *  Version: 1.0
 * 
 *  Last change: 20-04-2020
 *
 *  -------------------------------------
 *  This search function takes a file stream as input. It reads
 *  line by line until it hits the pattern.
 *  This line is then tokenized and the tokens are counted until
 *  'cntr' is equal to 'offset'; which is the n-th word the user
 *  is looking for. You can provide upto three search strings
 *  (p1, p2, p3), where the last two are somewhat optional, but
 *  then must be provided as empty string ("").
 *  
 *
 *  Example: Search for of Copyright-year results in,
 *
 *  searchPattern("searchUnspecificString.C", 4, "Copyright", "", "")
 *
 *  which returns: 2020
 *  
 *  Because this function is called for several lookups
 *  in the same (one-time opened) file, the file
 *  read-pointer is rewinded before new lookups, so that
 *  the search can start from the beginning of the file. 
 *
 *  Copyright (C) Apr. 2020: Georg Pohl, 70174 Stuttgart
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>

/* CONSTANTS */

/* STRUCTS */

/* PROTOTYPES */

/* FUNCTIONS */

char *searchUnspecificString(char *fn, int offset, const char *p1, const char *p2, const char *p3) {
  FILE *fp;
  fp = fopen(fn, "r");
  if (NULL == fp) {
    printf("Fehler beim Oeffnen der Datei: %s\n", fn);
    exit(1);	
  }
  size_t len = 0;
  char *line = NULL;
  static char *token;
  int cntr = 0;
  while ((getline(&line, &len, fp)) != EOF) {
    if ( (strstr(line, p1))  && (strstr(line, p2)) && (strstr(line, p3)) ) {
      token = strtok(line, " ,\t");
      while (token != NULL) {
	cntr++;
	if (cntr == offset) {
	/* Delete newline character, if present */
	  size_t sz = strlen(token);
	  if (token[sz-1] == '\n') {
	    token[sz-1] = '\0';
	  }
	  if (token[sz-1] == '\x0d') {
            token[sz-1] = '\0';
          }
	  return token;
	} 
	token = strtok(NULL, " ,\t");
      }
    }
  }
  fclose(fp);
  return token;
} /* End of searchUnspecificString.c */

