
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

// For periodToMinute()
#define MINUTE  1
#define HOUR    (MINUTE * 60)
#define DAY     (HOUR * 24)
#define WEEK    (DAY * 7)
#define YEAR    (WEEK * 52)

/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: searchUnspecificString()
 * Usage: char *ptr = searchUnspecificString(char *, int, char *, char *, char *);
 * -------------------------------------------------------------------------------
 * This function opens a filestream from a given filename 'fn', reads
 * it  line by line until it reaches the search pattern(s). From this
 * line the term found at position 'offset' is returned; where offset 1
 * finds the first word, etc.
 */

char *searchUnspecificString(char *fn, int offset, const char *p1, const char *p2, const char *p3);


/**
 * Copyright April 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: periodToMinute()
 * Usage: int minutes = periodToMinute(const char *periodUnit);
 * ------------------------------------------------------------
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
 * Copyright February 2021: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: dump_buffer()
 * Usage: dump_buffer(stdin);
 * ----------------------------------------------------------------------
 * If you want to empty an input buffer after reading input via 'scanf',
 * use this function.
 */

void dump_buffer(FILE *fp);

/**
 * Copyright February 2021: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: killNL()
 * Usage: killNL();
 * ----------------------------------------------------------------------
 * Deletes unwanted newline character ('\n') from a string.
 */

void killNL(char *str);


#endif /* GANYLIB_H_ */
