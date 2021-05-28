/** @file main.c
 *  @brief brief Short, generic description about the function
 *
 *  @author Georg Pohl
 *
 *  @bug no known bugs
 * 
 *  Date of creation: 29-01-2021
 * 
 *  Version: 1.0
 * 
 *  Last change: 29-01-2021
 *
 *  -------------------------------------
 *
 *  Here you can describe in detail how
 *  the implementation is done, what are
 *  the corner cases and what problems
 *  can arise due to wrong usage.
 *
 *  Copyright (C) Jan. 2021: Georg Pohl, 70174 Stuttgart
 */


#include <stdio.h>
#include <stdlib.h>
#include "ganylib.h"

/* DEFINES(CONSTANT MACROS, FUNCTION MACROS) */

/* TYPEDEFS, ENUMS, STRUCTS */

/* GLOBAL / EXTERNAL VARIABLES */
extern int something[11];	/* Size must be declared, except you have a
				   null-terminated character array */ 

non-static something_else;

static another_something;
	
/* CONSTANTS */
const double PI = 3.1415926;
 
/* PROTOTYPES / FUNCTIONS */
void my_function(void);

/* Always use Prototypes and the 'void' keyword */
/* Put like functions together or apply alphabetical order */


int main(void) {
  int *ptr, *filename;
  int start = 1;		// Initialize all vars with non-standard values 
  int i;			// No need for initialization
  int number_of_transactions;

  char *s;			// Ditto
  char first_name[32], last_name[32];
  
  return EXIT_SUCCESS;
}
/* FUNCTIONS */
/*
/* End of main.c */

/* Naming conventions */

  /* !TODO: gpohl 2021-01-01
  Put code in here... 
  Comments (address one of the two questions):
  	1. What does this block do?

	2. Why did I implement this block in this way?

  Comments in functions
  	1. Write comment above the lines, not behind and above a paragraph
  	2. Use "// " (empty space) for a single line, else /* Comment */
  	3. Start with capital letter, if possible
	4. Declare what you do, more than how you do something 

   Don't declare pointer- and non-pointer variable in the same line	
  
   Only use 8-Bit ASCII codex and avoid ASCII-Codes > 127, no 'ö' etc.
   or 'ß' etc.
  
   Divide logical block with newline, no alignment wiht the equal signed
   for example
  
   Only one statement per line; comment each variable
  
   Use always curly braces, even when there's only one statement
 
   Curly Braces in Kernighan & Ritchie-Style
  
   Spaces between operators ...


- Conditions

 if (x > 0) {
    printf("x is positive\n");
}
else if (x < 0) {
    printf("x is negative\n");
} // For comments
else {
    printf("x is zero\n");
}

- Loops

for (int i = 0; i < LIMIT; i++) {
    for (int j = 0; j < LIMIT; j++)
    {
        for (int k = 0; k < LIMIT; k++)
        {
            // Do something
        }
    }
}

while (condition) {
  ; /* VOID */
}

do {
    // Do something
}
while (condition);


- Switch Statements

switch (n) {
    case -1:
        printf("n is -1\n");
        break;

    case 1:
        printf("n is 1\n");
        break;

    default:
        printf("n is neither -1 nor 1\n");
        break;
}

- Structures

typedef struct student {
    string name;
    string dorm;
} student_t;
*/
