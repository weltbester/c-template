/**
 * File: ganylib.h
 * ---------------
 * This file defines functions needed for everyday networking use.
 * 
 * Here, general information about the usage is provided. If you're a
 * programmer, have a look at the relevant implementation file for
 * more details.
 */

#ifndef GANYLIB_H_
#define GANYLIB_H_

#include <stdio.h>
#include <string.h>
#include <stdio.h>
#include <stdbool.h>

/**
 * Copyright: November 2024, Georg Pohl, 70174 Stuttgart
 *
 * @brief Sorts an array of integers using the counting sort algorithm.
 *
 * This function sorts an array of integers in non-decreasing order using
 * the counting sort algorithm. It first finds the maximum value in the array
 * to determine the range of the counts array. It then counts the occurrences
 * of each integer in the input array and uses these counts to determine the
 * starting indices of each integer in the sorted array. Finally, it constructs
 * the sorted array and copies it back to the input array.
 *
 * @param array Pointer to the array of integers to be sorted.
 * @param size The number of elements in the array.
 */
void counting_sort(int *array, int size);

/**
 * Copyright: Februar 2024, Georg Pohl, 70174 Stuttgart
 *
 * Function: device_is_reachable
 * Usage: device_is_reachable(hostname)
 * ------------------------------------
 * @brief Checks if a device is reachable
 * @param char *hostname
 * @return bool
 * @details This function checks if a device is reachable by pinging
 * it once. It returns true if the device is reachable, otherwise
 * false.
 */
bool device_is_reachable(char *hostname);

/**
  * Copyright: Februar 2024, Georg Pohl, 70174 Stuttgart
  *
  * Function: extract_router_uptime
  * Usage: extract_router_uptime("line");
  * -----------------------------------------
  * @brief Extracts the uptime of a router
  * @param line of 'show version' output
  * @return int of the uptime in days
  * @details This function extracts the uptime of a router from the
  * output of 'show version' and returns it in days.
  */

int extract_router_uptime(char* line);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: search_pattern_in_string
 * Usage: search_pattern_in_string(char *a, char *b)
 * -------------------------------------------------
 * @brief Searches a substring in a string
 * @param char *a String to search in
 * @param char *b Search string
 * @return int index Position where string is found in 'a'
 * @exception Exceptions
 * 	      
 * The funktion returns the index where the pattern is found in the
 * original string 'a', otherwise if not found it returns -1.
 *
 */
int search_pattern_in_string(char *a, char *b);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: replace_from_length
 * Usage: replace_from_length(char *a, char *b, int from, int len)
 * ---------------------------------------------------------------
 * @brief Replaces part of 'a' with 'b'
 * @param char *a Replacement takes place here
 * @param char *b String to be inserted
 * @param int from Start index
 * @param int len Length of string 'b'
 * @return void
 * @exception Exceptions
 * 	      
 * This function replaces a substring 'b' in the original string
 * 'a'. It uses the already defined functions 'erase_from_length' and
 * 'insert_at_position'.
 *
 */
void replace_from_length(char *a, char *b, int from, int len);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: replace_from_to
 * Usage: replace_from_to(char *a, char *b, int from, int to)
 * ----------------------------------------------------------
 * @brief Replaces part of 'a' with 'b'
 * @param char *a Replacement takes place here
 * @param char *b String to be inserted
 * @param int from Start index
 * @param int to End index
 * @return void
 * @exception Exceptions
 * 	      
 * This function replaces a substring 'b' in the original string
 * 'a'. It uses the already defined functions 'erase_from_to' and
 * 'insert_at_position'.
 *
 */
void replace_from_to(char *a, char *b, int from, int to);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: insert_at_position
 * Usage: insert_at_position(char *a, char *b, int position)
 * ---------------------------------------------------------
 * @brief Inserts a string into another string at a certain position
 * @param char *a String to be inserted into
 * @param char *b String to be inserted
 * @param int position Index to insert in string 'a'
 * @return void
 * @exception Exceptions
 * 	      
 * String 'b' will be inserted in string 'a' at the index 'position of
 * 'a'.
 *
 */
void insert_at_position(char *a, char *b, int position);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: erase_from_length
 * Usage: erase_from_length(char *a, int from, int len)
 * ----------------------------------------------------
 * @brief char *a
 * @param char *a Original string
 * @param int from Start index
 * @param int len Length of part to erase
 * @return void
 * @exception Exceptions
 * 	      
 * Erases a part of the original string, limited by the index and the
 * length of the part to be erased.
 *
 */
void erase_from_length(char *a, int from, int len);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: text_part_from_length
 * Usage: text_part_from_length(char *a, char *b, int from, int len)
 * -----------------------------------------------------------------
 * @brief Saves a substring of a string
 * @param char *a
 * @param char *b
 * @param int from
 * @parma int len
 * @return void
 * @exception Exceptions
 * 	      
 * Saves a part of string 'a', limited by an index and the length of
 * the substring into string 'b'.
 *
 */
void text_part_from_length(char *a, char *b, int from, int len);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: erase_from_to
 * Usage: erase_from_to(char *a, int from, int to)
 * -----------------------------------------
 * @brief Erases a substring in a string
 * @param char *a
 * @param int from
 * @param int to
 * @return void
 * @exception Exceptions
 * 	      
 * Erases a substring, limited by indices 'from' and 'to' in the original string.
 *
 */
void erase_from_to(char *a, int from, int to);

/**
 * Copyright: November 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: text_part_from_to
 * Usage: text_part_from_to(char *a, char *b, int from, int to)
 * ------------------------------------------------------------
 * @brief Saves a substring of a string
 * @param char *a
 * @param char *b
 * @param int from
 * @param int to
 * @return void
 *
 * Saves the part of a string, limited by indices 'from' and 'to' to
 * another string 'b'.
 */
void text_part_from_to(char *a, char *b, int from, int to);

/**
 * Copyright: October 2023, Georg Pohl, 70174 Stuttgart
 *
 * Function: unspecific_search
 * Usage: unspecific_search(line, pattern, position)
 * -------------------------------------------------
 * @brief Returns an unspecified search term 
 * @param char *str
 * @param char *str
 * @param int
 * @return char *str
 *
 * Examines a line for a pattern and then returns the term at the
 * given position.
 */
char* unspecific_search(const char* line, const char* pattern, int position);

/**
 * Copyright: May 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: make_string_lwrcase
 * Usage: make_string_lwrcase(str)
 * -----------------------------------------
 * @brief Converts string to lowercase
 * @param char *str
 * @return void
 *
 * A whole string (as opposed to 'tolower') is converted to lowercase
 * letters, inline.
 */
void make_string_lwrcase(char *str);

/**
 * Copyright: May 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: make_string_uprcase
 * Usage: make_string_uprcase(str)
 * -----------------------------------------
 * @brief Converts string to uppercase
 * @param char *str
 * @return void
 *
 * A whole string (as opposed to 'toupper') is converted to uppercase
 * letters, inline.
 */
void make_string_uprcase(char *str);

/**
 * Copyright: May 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: delete_entries_from_file
 * Usage: delete_entries_from_file(filename)
 * -----------------------------------------
 * @brief Deletes entries in a text file
 * @param char *fn
 * @return void
 *
 * The function can be used to delete random entries from a given
 * file, line by line. Therefore the user has to enter the words/terms
 * to be deleted.  Input is converted to uppercase.  Then the original
 * file is read line by line and every term that is n o t mentioned
 * from the user is written in a temporay file. At the end the
 * temp-file is renamed to the original filename, which contains only
 * the leftover entries.
 */
void delete_entries_from_file(char *fn);

/**
 * Copyright: Eric S. Roberts
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
 * Searches for the specified key in the array *arr, which must be
 * sorted in lexicographic (character code) order. If the key is
 * found, the function returns the index in the vector at which that
 * key appers. (If the key appears more than once in the array, any of
 * the matching indices may be returned). If the key does not exist in
 * the array, the function returns -1. This implementation is simply a
 * wrapper function; all of real work is done by the more general
 * binary search function.
 */
int findInSortedArray(int key, int *arr, int n);

/**
 * Copyright: Eric S. Roberts
 *
 * Function: binarysearch
 * Usage: int index = binarysearch(key, arr, p1, p2);
 * --------------------------------------------------
 * @brief Searches for the specific key in the arrar *arr, looking only
 * at indices between p1 and p2, inclusive.  The function returns the
 * index of a matching element, or -1 if no match is found.
 */
int binarysearch(int key, int *arr, int p1, int p2);

/**
 * Copyright: Eric S. Roberts
 *
 * Function: shell_sort(int *arr)
 * Usage: shell_sort(arr[])
 * ----------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing order by
 * applying the shell-sort algorithm.  The function returns the no. of
 * swaps needed to sort the whole array.
 */
int shell_sort(int *array, int n);

/**
 * Copyright: Eric S. Roberts
 *
 * Function: insertion_sort(int *arr)
 * Usage: insertion_sort(arr[])
 * ----------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing order by
 * applying the insertion-sort algorithm.  The function returns the
 * no. of swaps needed to sort the whole array.
 */
int insertion_sort(int *array, int n);

/**
 * Copyright: Eric S. Roberts
 *
 * Function: bubble_sort(int *arr, int n)
 * Usage: bubble_sort(arr[], n)
 * --------------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing order by
 * applying the bubble-sort algorithm.  The function returns the
 * no. of swaps needed to sort the whole array.
 */
int bubble_sort(int *array, int n);

/**
 * Copyright: Eric S. Roberts
 *
 * Function: selection_sort
 * Usage: int cycles = selection_sort(*arr, int n)
 * -----------------------------------------------
 * @brief Sorts an integer array
 * @param int *arr
 * @param int n
 * @return int swaps Number of swaps needed 
 *
 * This function sorts an integer array in increasing order by
 * applying the selection-sort algorithm.  The function returns the
 * no. of swaps needed to sort the whole array.
 */
int selection_sort(int *array, int n);

/**
 * Copyright: May 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: deleteFilesByAge(char *folder, int period)
 * Usage: deleteFilesByAge("folder/to/check/", 30)
 * ----------------------------------------------------
 * @brief Deletes files by a given age
 * @param char *folder
 * @param int period
 * @return void
 *
 * This is a function to free folders from old and unneeded
 * files. Therefore it checks all files in a given folder.  If a file
 * is o l d e r than the given period, these file are going to be
 * deleted.
 * 
 * This function does not work on Windows Systems. 
 */
void deleteFilesByAge(const char folder[], int period);

/**
 * Copyright: August 2020, Georg Pohl, 70174 Stuttgart
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
 * Copyright: August 2020, Georg Pohl, 70174 Stuttgart
 *
 * Function: printDoubleVector Usage: printDoubleVector(int *vec, int
 * n) ----------------------------------------- Prints values of a
 * double vector starting form index 0 to the end.
 *
 */
void printDoubleVector(const double *vec, int n);

/**
 * Copyright: February 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: dump_buffer()
 * Usage: dump_buffer(stdin);
 * ----------------------------------------------------------------------
 * If you want to empty an input buffer after reading input via
 * 'scanf', use this function.
 */
void dump_buffer(FILE *fp);

/**
 * Copyright: February 2021, Georg Pohl, 70174 Stuttgart
 *
 * Function: killNL()
 * Usage: killNL();
 * ----------------------------------------------------------------------
 * Deletes unwanted newline character ('\n') from a string.
 */
void killNL(char *str);

/**
 * Copyright: April 2020, Georg Pohl, 70174 Stuttgart
 *
 * Function: unspecificSearch()
 * Usage: char *ptr = unspecificSearch(char *, int, const char *, const char *, const char *)
 * ------------------------------------------------------------------------------------------
 * This function opens a filestream from a given filename 'fn', reads
 * it line by line until it reaches the search pattern(s). From this
 * line the term found at position 'offset' is returned; where offset
 * 1 finds the first word, etc.
 */
char *unspecificSearch(char *fn, int offset, const char *p1, const char *p2, const char *p3);

/**
 * Copyright: August 2020, Georg Pohl, 70174 Stuttgart,
 *
 * C++ Function: deleteNetMask
 * Usage: string netAddr = deleteNetMask(const string)
 * --------------------_------------------------------
 * Deletes the Postfix of the Netmaks from a given IPv4 Address and
 * returns the pure Network Address to the caller. For example:
 *
 * deleteNetMask("192.168.1.0/24") returns "192.168.1.0"
 * 
 */
// std::string deleteNetMask(const std::string ipAddr);

/**
 * Copyright: August 2020, Georg Pohl, 70174 Stuttgart
 *
 * C++ Function: incrLastOctett
 * Usage: string nextAddr = incrLastOctett(const string)
 * -----------------------------------------------------
 * Increases a given IPv4 Network Adress' (without netmask) Hostpart
 * by 1, to get a pingeable network address. For example:
 *
 * incrLastOctett("192.168.1.19") returns "192.168.1.20"
 *
 */
// std::string incrLastOctett(const std::string ipAddr);

#endif /* GANYLIB_H_ */
