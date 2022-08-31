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
 * Function: make_string_lwrcase
 * Usage: make_string_lwrcase(str)
 * -----------------------------------------
 * @brief Converts string to lowercase
 * @param char *str
 * @return void
 *
 * A whole string (as opposed to 'tolower') is
 * converted to lowercase letters, inline.
 */

void make_string_lwrcase(char *str);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: make_string_uprcase
 * Usage: make_string_uprcase(str)
 * -----------------------------------------
 * @brief Converts string to uppercase
 * @param char *str
 * @return void
 *
 * A whole string (as opposed to 'toupper') is
 * converted to uppercase letters, inline.
 */

void make_string_uprcase(char *str);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: delete_entries_from_file
 * Usage: delete_entries_from_file(filename)
 * -----------------------------------------
 * @brief Deletes entries in a text file
 * @param char *fn
 * @return void
 *
 * The function can be used to delete random entries
 * from a given file, line by line. Therefore the
 * user has to enter the words/terms to be deleted.
 * Input is converted to uppercase.
 * Then the original file is read line by line and
 * every term that is  n o t  mentioned from the user
 * is written in a temporay file. At the end the
 * temp-file is renamed to the original filename,
 * which contains only the leftover entries.
 */

void delete_entries_from_file(char *fn);

/**
 * Copyright Eric S. Roberts
 *
 * Function:findInSortedArray
 * Usage: int index = findInSortedArray(key, arr, n);
 * --------------------------------------------------
 * @brief Wrapper function for binarysearch()
 * @param int key
 * @param int *arr
 * @param int n
 * @return int index
 *
 * Searches for the specified key in the array *arr,
 * which must be sorted in lexicographic (character code)
 * order. If the key is found, the function returns the
 * index in the vector at which that key appers. (If the
 * key appears more than once in the array, any of the
 * matching indices may be returned). If the key does not
 * exist in the array, the function returns -1. This
 * implementation is simply a wrapper function; all of
 * real work is done by the more general binary search
 * function.
 */

int findInSortedArray(int key, int *arr, int n);

/**
 * Function: binarysearch
 * Usage: int index = binarysearch(key, arr, p1, p2);
 * --------------------------------------------------
 * @brief 
 * Searches for the specific key in the arrar *arr,
 * looking only at indices between p1 and p2, inclusive.
 * The function returns the index of a matching element,
 * or -1 if no match is found.
 */

int binarysearch(int key, int *arr, int p1, int p2);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: shell_sort(int *arr)
 * Usage: shell_sort(arr[])
 * ----------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing
 * order by applying the shell-sort algorithm.
 * The function returns the no. of swaps needed
 * to sort the whole array.
 */

int shell_sort(int *array, int n);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: insertion_sort(int *arr)
 * Usage: insertion_sort(arr[])
 * ----------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing
 * order by applying the insertion-sort algorithm.
 * The function returns the no. of swaps needed
 * to sort the whole array.
 */

int insertion_sort(int *array, int n);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: bubble_sort(int *arr, int n)
 * Usage: bubble_sort(arr[], n)
 * --------------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing
 * order by applying the bubble-sort algorithm.
 * The function returns the no. of swaps needed
 * to sort the whole array.
 */

int bubble_sort(int *array, int n);

/**
 * Copyright May 2021: Georg Pohl, 70174 Stuttgart
 *
 * Function: selection_sort
 * Usage: int cycles = selection_sort(*arr, int n)
 * -----------------------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing
 * order by applying the selection-sort algorithm.
 * The function returns the no. of swaps needed
 * to sort the whole array.
 */

int selection_sort(int *array, int n);

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
 * Usage: printIntVector(int *vec, int n)
 * --------------------------------------
 * Prints values of an integral vector starting
 * form index 0 to the end.
 *
 */

void printIntVector(const int *vec, int n);

/**
 * Copyright August 2020: Georg Pohl, 70174 Stuttgart, Germany
 *
 * Function: printDoubleVector
 * Usage: printDoubleVector(int *vec, int n)
 * -----------------------------------------
 * Prints values of a double vector starting
 * form index 0 to the end.
 *
 */

void printDoubleVector(const double *vec, int n);

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
