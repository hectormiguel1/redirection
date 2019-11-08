/*=============================================================================
|   Source code:  [printError.c]
|   Author:  [Hector M. Ramirez ]
|   Student ID:  [5708475]
|   Assignment:  Program #[5] [Redirection and Pipes]
|
|   Course:  [COP4338 (Programing III)]
|   Section:  [U04]
|   Instructor:  William Feild
|   Due Date:  [November 12, 2019], at the beginning of class
|
|I hereby certify that this collective work is my own
|and none of it is the work of any other person or entity.
|______________________________________ [Signature]|
|        Language:  [C]
|  Compile/Run:  [This program contains to file with main, is just a function to be included with other executables]
|  +-----------------------------------------------------------------------------
|
|  Description:  [Prints error messages to stderr]
|
|        Input: [the only input is the parameter passed to printError which is a string message. ]
|       Output: [prints passed argument to stderr ]
|      Process: [prints argument to stderr]
|
|   Required Features Not Included:[All features are working as expected.]
|
|   Known Bugs:  [No known bugs]
|  *===========================================================================*/
#include "errorPrinter.h" //used to make the function portable and independent.

/**
 * FUNCTION NAME: printError
 * This function is in charge of printing errors to stderr
 * @param errMsg : message to be printed.
 */
void printError(char * errMsg)
{
    fprintf ( stderr, "%s\n", errMsg );
}