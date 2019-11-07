#include <stdio.h>
#include <limits.h>
#include <string.h>
#include <stdlib.h>
#include <ctype.h>


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


/**
 * The rules for leap years state that a leap year must meet the fallowing criteria:
 * it must be divisible by 4,
 * it can not be divisible by 100,
 * it must be divisible by 400.
 * There for it is a constant definition that a leap year is one which is
 * mod 4 equals 0, mod 400 equals zero but mod 100 does not equal 0.
 */
#define isLeapYear(Year) ((Year % 4) == 0 && (Year % 100) != 0 && (Year % 400) == 0) ? true : false
/**
 * Check if the months passed is on the months with medium length (30) days.
 */
#define isMediumMonth(Month) (Month == APR || Month == JUN || Month == SEP || Month == NOV ) ? true : false