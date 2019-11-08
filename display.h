
#include "validation.h"
#include "errorPrinter.h"

/**
 * CONSTANTS (MACROS)
 * DATES_PATH: path (file name) of the Dates.dat file
 * MODE: mode used when opening the file (read only)
 * DAY_CELL_SIZE: padding used when printing day
 * YEAR_CELL_SIZE: padding used when printing year
 * SENTINEL_VALUE_INDEX: location in the internal buffer where the TERMINATION_SIGNAL will be stored if sent.
 * NEW_LINE: new line char '\n'
 * PRINT_FORMAT: format string used when printing the dates in the specified format (see project specs)
 * OPEN_DATES_ERROR: error string to be printed if the Dates.dat could not be opened for reading.
 */
#define DATES_PATH "Dates.dat"
#define MODE "r"
#define DAY_CELL_SIZE 2
#define YEAR_CELL_SIZE 20
#define SENTINEL_VALUE_INDEX 0
#define NEW_LINE "\n"
#define PRINT_FORMAT "%*d %s %-*d\n"
#define OPEN_DATES_ERROR "UNABLE TO OPEN Dates.dat. FOR READING!"

/**
 * const char pointer to char array containing the 3 letter month SYMBOL.
 */
const char * MONTH_STRING[] =
        {
        "", "JAN", "FEB", "MAR", "APR","MAY","JUN","JUL","AUG", "SEP", "OCT", "NOV", "DEC"
        };

/**
 * FUNCTION PROTOTYPE: SEE FUNCTION DEFINITION FOR FUNCTION HEADER.
 */
void handleInput();
void printFile(FILE *datesPtr);
