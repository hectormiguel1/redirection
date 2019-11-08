#include <stdio.h>
#include <limits.h> //Used to establish int limit
#include <stdlib.h> //used for functions like atoi
#include <ctype.h> //Used for isdigit function
#include "errorPrinter.h" //used to have access to print to the stderr function

/**
 * CONSTANT:
 * MAX_YEAR : maximum allow number for the year.
 * MIN_YEAR: minimum allowed number for the year.
 */
const int MAX_YEAR = INT_MAX;
const int MIN_YEAR = INT_MIN;

typedef enum bool {
    false, true
}bool;

typedef enum MONTHS {

    JAN = 1, FEB, MAR, APR, MAY, JUN, JUL, AUG, SEP, OCT, NOV, DEC
}MONTHS;

typedef struct Date
{
    int month;
    int day;
    int year;
}Date;

/**
 * Constants Macros:
 * MIN_DAYS: Minimum number of days in a month (1).
 * DAYS_IN_LONG_MONTH: number of days in long months (months with 31 days)
 * DAYS_IN_MED_MONTH: number of days in medium months (months with 30 days)
 * DAYS_SHORT_FEB: number of days in FEB (non leap year)
 * DAYS_LONG_FEB: number of days in FEB (leap year)
 * ZERO_INITIALIZER: empty value initializer for new variables.
 * EXPECTED_ARGS: number of args expected to be passed to validationMain (2)
 * ALL_ENTRIES: magic argument to be passed to read from stdin till EOF is reached.
 * TERMINATION_SIGNAL: value printed when validationMain has finished (-1).
 * ERROR_EXIT: value to exit on main when the program encounters an error.
 * NO_ERROR_EXIT: value to return success when program ran correctly.
 * BUFFER_SIZE: size of the buffer used to store input from stdin for validation.
 * EXPECTED_SSCANF_MATCHES: number of expected matches made from sscanf when reading from buffer.
 * SENTINEL_VALUE: value used to indicate that an operation finished incorrectly, used for error reporting.
 * DESIRED_ENTRIES_INDEX: location in the args array where the desired values argument is stored.
 * SCANNER_FORMAT: format to be used when scanning the input buffer.
 * INVALID_ARGUMENT_ERROR: error string passed when there is an error processing the argument passed.
 * DESIRED_ENTRIES_ERROR: error string printed when the DESIRED_ENTRIES argument is not a valid value.
 * REACHED_END_OF_STREAM_ERROR: warning informing the user that the program reached the end of the stream but it did not
 *                              find the specified number of desired entries.
 */
#define MIN_DAYS 1
#define DAYS_IN_LONG_MONTH 31
#define DAYS_IN_MED_MONTH 30
#define DAYS_SHORT_FEB 28
#define DAYS_LONG_FEB 29
#define ZERO_INITIALIZER 0
#define EXPECTED_ARGS 2
#define ALL_ENTRIES 0
#define TERMINATION_SIGNAL "-1"
#define ERROR_EXIT 1
#define NO_ERROR_EXIT 0
#define BUFFER_SIZE 100
#define EXPECTED_SSCANF_MATCHES 3
#define SENTINEL_VALUE -1
#define DESIRED_ENTRIES_INDEX 1
#define SCANNER_FORMAT "%d/%d/%d"
#define INVALID_ARGUMENTS_ERROR "VALIDATION MAIN: ARGUMENTS PASSED ARE NOT VALID"
#define DESIRED_ENTRIES_ERROR "ARGUMENT VALID ENTRIES IS NOT VALID"
#define REACHED_END_OF_STREAM_ERROR "REACHED END OF INPUT STREAM, NUMBER OF PROCESSED ENTRIES LESS THAN DESIRED!"

/**
 * FUNCTION PROTOTYPES, SEE FUNCTION DECLARATION FOR FUNCTION HEADER
 */
bool validateBuffer(char *buffer, Date *);
bool validateYear(Date *pDate);
bool isLeapYear(int);
bool isShortMonth(int);
void printDate(Date *pDate);
int processArgs(char arg[]);
void readUntil(int);