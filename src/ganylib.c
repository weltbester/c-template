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
 *  Last change: 13-04-2021
 *
 *  -------------------------------------
 *  Here is the implementation of ganylib.h
 *  with several useful generic functions. 
 *
 *  Copyright (C) Apr. 2020: Georg Pohl, 70174 Stuttgart
 */

#define _GNU_SOURCE	/* for getline(), Non-ANSI */

#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "ganylib.h"

/**
 * Implementation notes: selection_sort
 * ------------------------------------
 * This implementation uses an algorithm called selection sort, which can be
 * described as follows. With your left hand (lh), point at each element in
 * the vector in turn, starting at index 0. At each step in the cycle:
 *
 * 1. Find the smalles element in the range between your left hand and the
 * end of the vector, and point at that element with your right hand (rh).
 *
 * 2. Move that element into its correct positioning by exchanging the
 * elements indicated by your left and right hands. (This explanation
 * is lend from Eric S. Roberts 'Programming Abstractions in C++'.)
 *
 * The Big-O of this sorting Algorithm is N^2. 
 */

void selection_sort(int *array) {
  int n = sizeof(array) / sizeof(int);

  for (int lh = 0; lh < n; ++lh) {
    int rh = lh;
    for (i = lh + 1; i < n; ++i) {
      if (array[i] < array[rh]) {
	rh = i;
      }
    }
    int tmp = array[lh];
    array[lh] = array[rh];
    array[rh] = tmp;
  }
}

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 * File: deleteFilesByAge.c
 * Implementation notes: deleteFilesByAge()
 * ----------------------------------------
 * This function makes use of the 'system' command,
 * because the goal is achieved much easier than
 * with the Non-ANSI-C 'mtime' attribute of the
 */

void deleteFilesByAge(const char folder[], int period) {
  const unsigned int MAX = 255;
  char deleteBackupFiles[MAX];

  // Create string for system command depending on function parameters
  snprintf(deleteBackupFiles, MAX-1, "find %s -maxdepth 1 -type f -mtime -%d 
		-delete", folder, period);

  // Cleanup old backups from black- and whitelist
  system(deleteBackupFiles);
  return;
} /* End deleteFilesByAge.c */


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
 * 1. Before edititing: "System uptime is, 1 years 51 weeks 6 days 23 hours 
 * 59 minutes"
 * 2. After editing: "1 years 51 weeks 6 days 23 hours 59 minutes"
 *
 * This part is then tokenized and every time the loop is passed, one integer 
 * and the correspondint time period is extracted. With the 'periodToMinute'
 * function the duration in minutes is calculated and added to 'totalMinutes'.
 * This is done for all tuples in the string.
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

char *unspecificSearch(char *fn, int offset, const char *p1,
		       const char *p2, const char *p3) {
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

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * C++ Function: deleteNetMask
 * Usage: string netAddr = deleteNetMask(const string)
 * --------------------_------------------------------
 * This function implements the interface to
 * deleteNetMask.
 * 
 */

/* string deleteNetMask(const string ipAddr) { */
/*   std::string woMask; */
/*   std::size_t found = ipAddr.rfind("/"); */
/*   if (found != std::string::npos) { */
/*     // Cut off netmask ... */
/*     woMask = ipAddr.substr(0, found); */
/*     return woMask; */
/*   } else { */
/*     return ipAddr + " Pruefen!"; */
/*   } */
/* } */

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * C++ Function: incrLastOctett
 * Usage: string nextAddr = incrLastOctett(const string)
 * -----------------------------------------------------
 * To make a just somewhat reliable function, in the
 * input IPv4 Address the last octett (searching for the
 * last '.') is being isolated and translated from a
 * string to an integer; which can be corrctly
 * incremented. Then everything is re-translated into a
 * string and concatenated to the original string at the
 * right place.
 * If there's no dot ('.'), the function returns the
 * original IP-Address and the Postfix " Check address!".
 */

/* string incrLastOctett(const string ipAddr) { */
/*   std::string incrIPAddr; */
/*   std::size_t found = ipAddr.rfind("."); */
/*   if (found != std::string::npos) { */
/*     // Make last octet an Integer ... */
/*     string lastOctett = ipAddr.substr(found + 1); */
/*     std::size_t sz; */
/*     int OctettAsInt = std::stoi(lastOctett, &sz);
/*     // ... increment last by 1 */
/*     OctettAsInt++; */
/*     // Transform into string again ... */
/*     incrIPAddr = ipAddr.substr(0, found + 1); */
/*     incrIPAddr += to_string(OctettAsInt); */
/*     return incrIPAddr; */
/*     // ... and put it alltogether */
/*   } else { */
/*     return incrIPAddr + " Check address!"; */
/*   } */
/* } */

/* End of ganylib.c */

