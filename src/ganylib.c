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
#include <ctype.h>
#include "ganylib.h"

/**
 * Implementation notes: make_string_lwrcase
 * -----------------------------------------
 * This function implements the binary make_string_lwrcase
 * function.
 */

void make_string_lwrcase(char *str) {
  while (*str) {
    *str = tolower((unsigned int) *str);
    str++;
  }
}

/**
 * Implementation notes: make_string_uprcase
 * -----------------------------------------
 * This function implements the binary make_string_uprcase
 * function.
 */

void make_string_uprcase(char *str) {
  while (*str) {
    *str = toupper((unsigned int) *str);
    str++;
  }
}

/**
 * Implementation notes: delete_entries_from_file
 * ----------------------------------------------
 * This function implements the binary delete_entries_from_file
 * function.
 */

void delete_entries_from_file(char *fn) {
  const int MAX = 65;
  FILE *read, *write;
  char entry[MAX];
  char **entries_to_erase = NULL;
  int i, n;
  
  // Set entries counter to zero and take input from user
  n = 0;
  printf("Entries to delete? Input 'q' ENTER when finished" 
	"\nEnter captial letters line by line:\n");

  printf("-> ");
  scanf("%s", entry);
  while (strcmp(entry, "q") != 0) {
    if (entries_to_erase == NULL) {
      entries_to_erase = malloc(sizeof(char *));
      if (entries_to_erase == NULL) {
	fprintf(stderr, "malloc: not enough memory for 'entries_to_erase'");
	exit(EXIT_FAILURE);
      }
    } else {
      entries_to_erase = realloc(entries_to_erase, (n + 1) * sizeof(char *));
      if (entries_to_erase == NULL) {
	fprintf(stderr, "realloc: not enough new memory for 'entries_to_erase'");
	exit(EXIT_FAILURE);
      }
    }
    int len = strlen(entry);
    entries_to_erase[n] = malloc((len + 1) * sizeof(char));
    if (entries_to_erase[n] == NULL) {
      fprintf(stderr, "realloc: not enough new memory for 'entries_to_erase'");
      exit(EXIT_FAILURE);
    }
    make_string_uprcase(entry);
    strncpy(entries_to_erase[n], entry, len);
    n++;
    printf("-> ");
    scanf("%s", entry);
  }
  
  // Read original file and write to be deleted entries to temporary file
  read = fopen(fn, "r");
  write = fopen("tmp_file.txt", "w");
  if (read == NULL || write == NULL) {
    fprintf(stderr, "fopen: can't open file\n");
    exit(EXIT_FAILURE);
  }
  // Compare entries from file with entries to delete
  while ((fgets(entry, MAX, read)) != NULL) {
    int found = 0;
    killNL(entry);
    for (i = 0; i < n; ++i) {
      if ((strcmp(entry, entries_to_erase[i]) == 0)) {
  	found = 1;
  	break;
      }
    }
    if (found == 1) {
      printf("Deleted %s\n", entries_to_erase[i]);
      continue;
    }
    fprintf(write, "%s\n", entry);
  }

  for (int j = 0; j < n; ++j) {
    free(entries_to_erase[j]);
  }
  free(entries_to_erase);
  
  fclose(read);
  fclose(write);

  rename("tmp_file.txt", fn);
  return;
}

/**
 * Implementation notes: findInSortedArray
 * ---------------------------------------
 * This function is a wrapper function for the
 * binary search function.
 *
 * The Big-O of this binary search is log N. 
 */
int findInSortedArray(int key, int *arr, int n) {
  return binarysearch(key, arr, 0, n-1);
}

/**
 * Implementation notes: binarysearch
 * ----------------------------------
 * This function implements the binary search algrithm.
 *
 * The Big-O of this binary search is log N. 
 */

int binarysearch(int key, int *arr, int p1, int p2) {
  if (p1 > p2) {
    return -1;
  }
  int mid = (p1 + p2) / 2;
  if (key == arr[mid]) {
    return mid;
  }
  if (key < arr[mid]) {
    return binarysearch(key, arr, p1, mid - 1);
  } else {
    return binarysearch(key, arr, mid + 1, p2);
  }
}

/**
 * Implementation notes: shell_sort
 * --------------------------------
 * This function implements the Shell Sort algrithm.
 *
 * The Big-O of this Shell Sort is N^2. 
 */

int shell_sort (int *array, int n) {
  int i, j, temp, m, swaps = 0;
  /* Anfangswert für die Distanz errechnen */
  for ( m = 1; m <= n/9; m = 3*m+1) {
    ;
  }
  for (; m > 0; m /= 3) {
    for (i = m; i <= n; i++) {
      temp = array[i];
      /* Größer als temp und nicht n
       * sowie >= und nicht > */
       for(j = i; j >= m && array[j-m] > temp; j -= m) {
           array[j] = array[j-m];
        }
        array[j] = temp;
	swaps++;
     }
  }
  return swaps;
}

/**
 * Implementation notes: insertion_sort
 * ------------------------------------
 * This function implements the Insertion Sort algrithm.
 *
 * The Big-O of this Insertion Sort is N^2. 
 */

int insertion_sort(int *array, int n) {
  int i, ndx_min, val_min, swaps = 0;

  for (i = 1; i < n; ++i) {
    
    val_min = array[i];
    for (ndx_min = i; array[ndx_min - 1] > val_min && ndx_min > 0; --ndx_min) {
      array[ndx_min] = array[ndx_min - 1];
    }
    array[ndx_min] = val_min;
    swaps++;
  }
  return swaps;
}

/**
 * Implementation notes: bubble_sort
 * ------------------------------------
 * This function implements the Bubble Sort algrithm.
 *
 * The Big-O of this Bubble Sort is N^2. 
 */

int bubble_sort(int *array, int n) {
  int swapped, tmp = 0, swaps = 0;
  
  do {
    swapped = 0;
    for (int i = 0; i < n - 1; ++i) {
      if (array[i+1] < array[i]) {
	tmp = array[i];
	array[i] = array[i+1];
	array[i+1] = tmp;
	swapped = 1;
	swaps++;
      }
    }
  } while (swapped);
  return swaps;
}

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

int selection_sort(int *array, int n) {
  int swaps = 0;

  for (int lh = 0; lh < n; ++lh) {
    int rh = lh;
    for (int i = lh + 1; i < n; ++i) {
      if (array[i] < array[rh]) {
	rh = i;
      }
    }
    int tmp = array[lh];
    array[lh] = array[rh];
    array[rh] = tmp;
    swaps++;
  }
  return swaps;
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
  snprintf(deleteBackupFiles, MAX-1, "find %s -maxdepth 1 -type f -mtime -%d -delete", folder, period);

  // Cleanup old backups from black- and whitelist
  system(deleteBackupFiles);
  return;
} /* End deleteFilesByAge.c */


/**
 *  Implementation notes: printIntVector
 *  ------------------------------------
 *  Nothing to declare.
 */

void printIntVector(const int *vec, int n) {
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
void printDoubleVector(const double *vec, int n) {
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
  int p = strlen(str);
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
/*     int OctettAsInt = std::stoi(lastOctett, &sz); // ... increment last by 1 */
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

