#include "errorPrinter.h"

/**
 * FUNCTION NAME: printError
 * This function is in charge of printing errors to stderr
 * @param errMsg : message to be printed.
 */
void printError(char * errMsg)
{
    fprintf ( stderr, "%s\n", errMsg );
}