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

/* CONSTANTS */
 
/* STRUCTS */

/* PROTOTYPES */
// Always use Prototypes and the 'void' keyword
void my_function(void);

/* GLOBAL VARIABLES */

int main(void) {

  
  return EXIT_SUCCESS;
}
/* FUNCTIONS */
/*	                                                       					   | linelength: 80,  | 100 characters */
/* End of main.c */

/* Naming conventions */

  /* !TODO: gpohl 2021-01-01
  Put code in here... 
  Comments (address one of the two questions):
  	1. What does this block do?

	2. Why did I implement this block in this way?

  Comments in functions
  	1. Write comment above the lines, not behing
  	2. Use "// " (empty space)
  	3. Start with capital letter, if possible

   Don't declare pointer- and non-pointer variable in the same line	
  
   Only use 8-Bit ASCII codex and avoid ASCII-Codes > 127, no 'ö' etc. or 'ß' etc.
  
   Divide logical block with newline, no alignment of e.g. equal sign
  
   Only one statement per line; comment each variable
  
   Use always curly braces, even when there's only one statement
 
   Curly Braces in Kernighan & Ritchie-Style
  
   Spaces between operators ...


- Conditions

 if (x > 0)
{
    printf("x is positive\n");
}
else if (x < 0)
{
    printf("x is negative\n");
}
else
{
    printf("x is zero\n");
}

- Loops

for (int i = 0; i < LIMIT; i++)
{
    for (int j = 0; j < LIMIT; j++)
    {
        for (int k = 0; k < LIMIT; k++)
        {
            // Do something
        }
    }
}

while (condition)
{
    // Do something
}

do
{
    // Do something
}
while (condition);


- Switch Statements

switch (n)
{
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

typedef struct
{
    string name;
    string dorm;
}
student;



*/
