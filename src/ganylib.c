/**
 * File: ganylib.h
 * ---------------
 * This file defines functions needed for everyday networking use.
 * 
 * Here, general information about the usage is provided. If you're
 * a programmer, have a look at the relevant implementation file for
 * more details.
 */

#define _GNU_SOURCE	/* for getline(), Non-ANSI */

#ifndef GANYLIB_H_
#define GANYLIB_H_

// For periodToMinute()
#define MINUTE  1
#define HOUR    (MINUTE * 60)
#define DAY     (HOUR * 24)
#define WEEK    (DAY * 7)
#define YEAR    (WEEK * 52)

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
 * This function implements the interface to
 * deleteNetMask.
 * 
 */
string deleteNetMask(const string ipAddr) {
  std::string woMask;
  std::size_t found = ipAddr.rfind("/");
  if (found != std::string::npos) {
    // Cut off netmask ...
    woMask = ipAddr.substr(0, found);
    return woMask;
  } else {
    return ipAddr + " Pruefen!";
  }
}

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
string incrLastOctett(const string ipAddr) {
  std::string incrIPAddr;
  std::size_t found = ipAddr.rfind(".");
  if (found != std::string::npos) {
    // Make last octet an Integer ...
    string lastOctett = ipAddr.substr(found + 1);
    std::size_t sz;
    int OctettAsInt = std::stoi(lastOctett, &sz);	// Default base: 10, not needed as last argument here
    // ... increment last by 1
    OctettAsInt++;
    // Transform into string again ...
    incrIPAddr = ipAddr.substr(0, found + 1);
    incrIPAddr += to_string(OctettAsInt);
    return incrIPAddr;
    // ... and put it alltogether
  } else {
    return incrIPAddr + " Check address!";
  }
}

#endif /* GANYLIB_H_ */
