/**
 * File: ganylib.h
 * ---------------
 * This file defines functions needed for the Ganymed Inventory System.
 * There's a seperate library file for the search patterns which are
 * defined as constants in the 'pattern' file.
 * 
 * Here, general information about the usage is provided. If you're
 * a programmer, have a look at the relevant implementation file for
 * more details.
 */

#ifndef GANYLIB_H_
#define GANYLIB_H_

/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: searchPattern()
 * Usage: char *ptr = searchPattern(char *, char *, int);
 * ----------------------------------------------------------------------
 * This function opens a filestream from a given filename 'fn', reads
 * it  line by line until it reaches the search pattern(s). From this
 * line the term found at position 'offset'
 * is returned; where offset 1 finds the first word, etc.
 */

char * searchPattern(char *fn, const char *p1, int offset);


/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: periodToMinute()
 * Usage: int minutes = periodToMinute(const char *periodUnit);
 * -------------------------------------------
 * 'periodToMinute' takes time periods, like 'year(s)', 'week(s) etc. as
 * a string, reverse calculates it to the smallest unit and returns
 * 'minutes' as an integer. 
 */

int periodToMinute(char *periodUnit);

/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: uptime()
 * Usage: int days = uptime(const char *line);
 * -------------------------------------------
 * 'uptime' takes a string, extracts relevant information about
 * the years, weeks, days etc. a router is running and finally
 * calculates and returns the summa summarum in days for the relevant
 * router.
 */

int uptime(const char *line);

/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: searchUnspecificWordInString()
 * Usage: char *ptr = searchUnspecificWordInString(char *, int, char *, char *, char *);
 * ----------------------------------------------------------------------
 * This function opens a filestream from a given filename 'fn', reads
 * it  line by line until it reaches the search pattern(s). From this
 * line the term found at position 'offset'
 * is returned; where offset 1 finds the first word, etc.
 */

char * searchUnspecificString(char *fn, const char *pattern, int offset);

/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: readDataFromTerminal()
 * Usage: char *ptr = readDataFromTerminal(char *, char *);
 * ------------------------------------------------------
 * This function prints a prompt message to the terminal, reads the
 * user input and returns a string.
 */

char * readFromPrompt(char prompt);

/**
 * Copyright October 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: unspecifiedSearch()
 * Usage: char *result = unspecifiedSearch(char *fn, char *p1, char *p2, int ofs);
 * ----------------------------------------------------------------------
 * This function is useful when the search pattern cannot not exactly be specified,
 * because it's available more than one. So the function opens a given file and
 * makes a lookup for the first patteren 'p1'. In the following paragraph it searches
 * for the second pattern 'p2'. Here the offset parameter ('ofs') identifies the
 * needed information, which is returned to the caller.
 */

char * unspecifiedSearch(char *fn, const char *p1, const char *p2, int ofs);

/**
 * Copyright February 2021: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: dump_file()
 * Usage: dump_file(stdin);
 * ----------------------------------------------------------------------
 * If you want to empty an input buffer after reading input from a
 * filestream via 'scanf', use this function.
 */

void dump_file(FILE *fp);

#endif /* GANYLIB_H_ */
