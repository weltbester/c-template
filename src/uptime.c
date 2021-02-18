/* 
 * Copyright 2020: Georg Pohl, 70174 Stuttgart
 * File: uptime.c
 * --------------
 * This file implements the interface 'uptime' from
 * the 'ganylib.h' library.
 */

#include <stdio.h>
#include <string.h>
#include <stdlib.h>
#include "../eigeneVorlagen/ganylib.h"
/* {} [] | \ */					\

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
