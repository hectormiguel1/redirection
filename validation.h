#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>
#include "errorPrinter.h"

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
#define BUFFER_SIZE 20
#define EXPECTED_SSCANF_MATCHES 3
#define SENTINEL_VALUE -1
#define DESIRED_ENTRIES_INDEX 1
#define SCANNER_FORMAT "%d/%d/%d"
#define INVALID_ARGUMENTS_ERROR "VALIDATION MAIN: ARGUMENTS PASSED ARE NOT VALID"
#define DESIRED_ENTRIES_ERROR "ARGUMENT VALID ENTRIES IS NOT VALID"
#define REACHED_END_OF_STREAM_ERROR "REACHED END OF INPUT STREAM, NUMBER OF PROCESSED ENTRIES LESS THAN DESIRED!"

bool validateBuffer(char *buffer, Date *);
bool validateYear(Date *pDate);
bool isLeapYear(int);
bool isShortMonth(int);
void printDate(Date *pDate);
int processArgs(char arg[]);
void readUntil(int);