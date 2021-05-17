/**
 * File: ganylib.h
 * ---------------
 * This file defines functions needed for everyday networking use.
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
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: selection_sort(int *arr)
 * Usage: selection_sort(arr[])
 * ----------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return void
 *
 * This function sorts an integer array in increasing
 * order by applying the selection-sort Algorithm.
 */

void selection_sort(int *array);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: deleteFilesByAge(char *folder, int period)
 * Usage: deleteFilesByAge("folder/to/check/", 30)
 * ----------------------------------------------------
 * @brief Deletes files by a given age
 * @param char *folder
 * @param int period
 * @return void
 *
 * This is a function to free folders from old and
 * unneeded files. Therefore it checks all files in
 * a given folder.
 * If a file is  o l d e r  than the given period, these file are going
 * to be deleted.
 * 
 * This function does not work on Windows Systems. 
 */

void deleteFilesByAge(const char folder[], int period);

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: printIntVector
 * Usage: printIntVector(int *vec)
 * -------------------------------
 * Prints values of an integral vector starting
 * form index 0 to the end.
 *
 */

void printIntVector(const int  *vec, int n);

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: printDoubleVector
 * Usage: printDoubleVector(int *vec)
 * ----------------------------------
 * Prints values of a double vector starting
 * form index 0 to the end.
 *
 */

void printDoubleVector(const double  *vec, int n);

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
 * Function: unspecificSearch()
 * Usage: char *ptr = unspecificSearch(char *, int, const char *, const char *, const char *)
 * ------------------------------------------------------------------------------------------
 * This function opens a filestream from a given filename 'fn', reads it  line by line until
 * it reaches the search pattern(s). From this line the term found at position 'offset' is
 * returned; where offset 1 finds the first word, etc.
 */

char *unspecificSearch(char *fn, int offset, const char *p1, const char *p2, const char *p3);

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * C++ Function: deleteNetMask
 * Usage: string netAddr = deleteNetMask(const string)
 * --------------------_------------------------------
 * Deletes the Postfix of the Netmaks from a given IPv4
 * Address and returns the pure Network Address to the
 * caller. For example:
 *
 * deleteNetMask("192.168.1.0/24") returns "192.168.1.0"
 * 
 */
// std::string deleteNetMask(const std::string ipAddr);

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * C++ Function: incrLastOctett
 * Usage: string nextAddr = incrLastOctett(const string)
 * -----------------------------------------------------
 * Increases a given IPv4 Network Adress' (without netmask)
 * Hostpart by 1, to get a pingeable network address. For
 * example:
 *
 * incrLastOctett("192.168.1.19") returns "192.168.1.20"
 *
 */
// std::string incrLastOctett(const std::string ipAddr);

#endif /* GANYLIB_H_ */
