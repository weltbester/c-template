/** @file ganylib.c
 *  @brief Library with useful functions
 *
 *  @author Georg Pohl
 *
 *  @bug no known bugs
 * 
 *  Date of creation: 18-02-2021
 * 
 *  Version: 1.0
 * 
 *  Last change: 18-02-2021
 *
 *  -------------------------------------
 *  Here is the implementation of ganylib.h
 *  with several useful generic functions. 
 *
 *  Copyright (C) Apr. 2020: Georg Pohl, 70174 Stuttgart
 */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ganylib.h"

/* CONSTANTS */

/* STRUCTS */

/* PROTOTYPES */


/* FUNCTIONS */

/**
 *  Implementation notes: printIntVector
 *  ------------------------------------
 *  Nothing to declare.
 */

void printIntVector(const int  *vec, int n) {
  printf("[ ");
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      printf("%d", vec[i]);
    } else {
      printf(", %d", vec[i]);
    }
  }
  printf(" ]\n");
}

/**
 *  Implementation notes: printDoubleVector
 *  ---------------------------------------
 *  Nothing to declare.
 */
void printDoubleVector(const double  *vec, int n) {
  printf("[ ");
  for (int i = 0; i < n; ++i) {
    if (i == 0) {
      printf("%g", vec[i]);
    } else {
      printf(", %g", vec[i]);
    }
  }
  printf(" ]\n");
}

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

/* Deletes newline char ('\n'), if there */
void killNL(char *str) {
  size_t p = strlen(str);
  if ( str[p-1] == '\n') {
    str[p-1] = '\0';
  }
}

/*
 * Implementation notes: periodToMinute
 * ------------------------------------
 * The function takes a string with a term like "year(s)", "week(s)" etc.
 * and returns the amount in minutes, for later calculation.
 */

int periodToMinute(char *periodUnit) {
  if (strstr(periodUnit, "year") != NULL) {
    return YEAR;
  }
  if (strstr(periodUnit, "week") != NULL) {
    return WEEK;
  }
  if (strstr(periodUnit, "day") != NULL) {
    return DAY;
  }
  if (strstr(periodUnit, "hour") != NULL) {
    return HOUR;
  }
  return 1;
}

/*
 * Implementation notes: uptime
 * ----------------------------
 * The function copies 'line' in a new working string (lineCopy) for
 * edititng. This string is edited, until only the relevant data is leftover.
 * 
 * 1. Before edititing: "System uptime is, 1 years 51 weeks 6 days 23 hours 59 minutes"
 * 2. After editing: "1 years 51 weeks 6 days 23 hours 59 minutes"
 *
 * This part is then tokenized and every time the loop is passed, one integer and the
 * correspondint time period is extracted. With the 'periodToMinute' function the duration
 * in minutes is calculated and added to 'totalMinutes'. This is done for all tuples in
 * the string.
 * The function is also working if there are tuples missing, like in:
 *
 * "System uptime is,  3 days 8 hours 2 minutes"
 */

int uptime(const char *line) {
  int days = 0;
  int totalMinutes = 0;
  int timePeriod;
  char *lineCopy = malloc(strlen(line));
  memcpy(lineCopy, line, strlen(line));
  lineCopy = strchr(lineCopy, ',') + 2;
  char *ndx = strtok(lineCopy, " ");
  while (ndx) {
    timePeriod = atoi(ndx);
    totalMinutes += timePeriod * periodToMinute(strtok(NULL, " "));
    ndx = strtok(NULL, " ");
  }
  days =  totalMinutes / 60 / 24;
  return days;
}

/**
 *  Implementation notes: unspecificSearch
 *  --------------------------------------
 *  This search function takes a file stream as input. It reads
 *  line by line until it hits the pattern(s).
 *  This line is then tokenized and the tokens are counted until
 *  'cntr' is equal to 'offset'; which is the n-th word the user
 *  is looking for. You can provide upto three search strings
 *  (p1, p2, p3), where the last two are somewhat optional, but
 *  then an empty string ("") has to be provided.
 *  
 *  Example: Search for of Copyright-year in this paragraph would
 *  result in:
 *
 *  unspecificSearch("ganylib.c", 4, "Copyright", "", "")
 *
 *  which returns: 2020:
 *  
 *  Because this function is called for several lookups
 *  in the same (one-time opened) file, the file
 *  read-pointer is rewinded before new lookups, so that
 *  the search can start from the beginning of the file. 
 *
 *  Copyright (C) Apr. 2020: Georg Pohl, 70174 Stuttgart
 */

char *unspecificSearch(char *fn, int offset, const char *p1, const char *p2, const char *p3) {
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
}

/* End of ganylib.c */
