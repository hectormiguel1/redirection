/*=============================================================================
|   Source code:  [validation.c]
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
|  Compile/Run:  [Two options are provided to compile to program, make and gcc. printError.h validation.h display.h must be in directory!!!! ]
|       [MAKE]:  Inside the directory validation.c printError.c printError.h validation.h display.c display.h
|               $make
|        [GCC]:  Inside the directory containing validation.c printError.c printError.h validation.h
|               $gcc -std=c99 validation.c printError.c –o validationMain
|        [RUN (STAND-ALONE]: validation can be used standalone (stand alone it will read from stdin and print to stdout
|                               dates that were found to be valid until either end of stream  (EOF) or  number of valid
|                               dates found equals the numbers desired (passed as an argument).
|                               DESIRED NUMBER OF VALID ENTRIES must be a positive integer (0 to INT_MAX).
|                               0 for all entries till EOF
|               $ ./validation [DESIRED NUMBER OF VALID ENTRIES]
|       [RUN COMBINED] : combined with display, this program will process the input from stdin and send it to main
|                           to be displayed in the specified format as per the specifications.
|               $ ./validationMain [DESIRED NUMBER OF VALID ENTRIES] | ./displayMain
|  +-----------------------------------------------------------------------------
|
|  Description:  [This program will read dates from stdin and validate that it is a valid date. A valid date is a date
|                   who's month is between JAN (1) and DEC (12) and the days is between 1 and total days in that month.
|                   A year is considered to be valid so long as it is in the range of INT_MIN to INT_MAX. ]
|
|        Input: [Input will be read from stdin (what ever that might be) and attempted to construct into a date.
|                 if successful, the date will be validated to make sure that it conforms to what a valid date is as
|                 explained the section above.]
|       Output: [If the date constructed from the input is considered to be valid, it will be printed to stdout (what ever
|                   that might be). Several messages will be printed to stderr if any errors or warnings occur during the
|                    execution. ]
|      Process: [ We start by storing the input coming from stdin into a buffer and then using sscanf we attempt to
|                   convert the input into a date, if it fails to read the input, the input is discarded, if successful
|                   a date is constructed and passed along for validation. if validated it will be printed to stdout.]
|
|   Required Features Not Included:[All features are working as expected.]
|
|   Known Bugs:  [No known bugs]
|  *===========================================================================*/
#include "validation.h" //Used for shared constants and imports.

int main(int argc, char * args[])
{
    if ( argc != EXPECTED_ARGS )
    {
        printError ( INVALID_ARGUMENTS_ERROR );
        printf ( TERMINATION_SIGNAL );
        return ERROR_EXIT;
    } else
    {
        int desiredEntries = processArgs ( args[ DESIRED_ENTRIES_INDEX ] );
        if ( desiredEntries == SENTINEL_VALUE )
        {
            printError ( DESIRED_ENTRIES_ERROR );
            return ERROR_EXIT;
        } else
        {
            readUntil ( desiredEntries );
        }
    }
    puts ( TERMINATION_SIGNAL );

    return NO_ERROR_EXIT;
}

/**
 * FUNCTION NAME: printDate
 * This function prints a fully valid date.
 * @param pDate : date to be printed (pointer)
 * @return N/A
 */
void printDate(Date *pDate)
{
    
    printf ( "%d/%d/%d \n", pDate->month, pDate->day, pDate->year );
}

/**
 * FUNCTION NAME: validateYear
 * This function is in charge of making sure that the date built from the buffer is a valid date.
 * IE, the number of month is between Jan and DEC and number of days do not exceed the number of days in that particular
 * month. This takes into account if the year is a Leap year for Feb.
 * @param datePtr : pointer to Date to be validated.
 * @return : returns true if date is valid, false otherwise.
 */
bool validateYear( Date *datePtr)
{
    bool isLeap = isLeapYear ( datePtr->year );
    
    if ( datePtr->month > DEC || datePtr->month < JAN )
    {
        return false;
    }
    if ( datePtr->month == FEB && isLeap )
    {
        if ( datePtr->day < MIN_DAYS || datePtr->day > DAYS_LONG_FEB )
        {
            return false;
        }
    } else if ( datePtr->month == FEB )
    {
        if ( datePtr->day < MIN_DAYS || datePtr->day > DAYS_SHORT_FEB )
        {
            return false;
        }
    }
    if ( !isShortMonth ( datePtr->month ) && datePtr->month != FEB )
    {
        if ( datePtr->day < MIN_DAYS || datePtr->day > DAYS_IN_LONG_MONTH )
        {
            return false;
        }
    } else if ( isShortMonth ( datePtr->month ))
    {
        if ( datePtr->day < MIN_DAYS || datePtr->day > DAYS_IN_MED_MONTH )
        {
            return false;
        }
    }
    return true;
}

/**
 * FUNCTION NAME: validateBuffer
 * The primary function for this method is to verify that the information in the buffer can be built into a date,
 * this function is not in charge of validating the date, it only makes sures that a date can be build from the information
 * in the buffer. If the date can be built, it stores into the datePtr structure.
 * @param buffer  : char array containing the buffer to be validated.
 * @param datePtr : if a date can be built from the buffer it will be saved here.
 * @return true if date was built successfully, false otherwise.
 */
bool validateBuffer(char *buffer, Date * datePtr)
{
    int day = ZERO_INITIALIZER;
    int month = ZERO_INITIALIZER;
    long year = ZERO_INITIALIZER;
    
    if ( sscanf ( buffer, "%d/%d/%ld", &month, &day, &year ) != EXPECTED_SSCANF_MATCHES )
    {
        return false;
    } else
    {
        if ( year > MAX_YEAR || year < MIN_YEAR )
        {
            return false;
        }
        datePtr->day = day;
        datePtr->month = month;
        datePtr->year = year;
        return true;
    }
}

/**
 * FUNCTION NAME: processArgs
 * This function takes in a char array (string) and iterates through it to confirm that there are no
 * characters in the input, If there is a character in the input, we will return a sentinel value, otherwise
 * the value converted value of the string will be returned.
 * @param arg: argument to be processed for validation
 * @return : -1 if a char is detected, otherwise the int value of the arg is passed.
 */
int processArgs(char arg[])
{
    int counter = ZERO_INITIALIZER;
    while ( arg[ counter ] != '\0' )
    {
        if ( !isdigit( arg[ counter ] ))
        {
            return SENTINEL_VALUE;
        }
        counter++;
    }
    int tmpVal = atoi ( arg );
    if ( tmpVal < ZERO_INITIALIZER )
    {
        return SENTINEL_VALUE;
    } else
    {
        return tmpVal;
    }
}

/**
 * FUNCTION NAME: readUntil
 * Function reads input from stdin until specified number of valid entries have been validated or
 * until the end of the stream is reached.
 * @param desiredEntries : number of valid entries to process.
 * @return: N/A
 */
void readUntil(int desiredEntries)
{
    Date currentWorkingDate;
    Date * CWDPtr = &currentWorkingDate;
    char inputBuffer[BUFFER_SIZE];
    int validCounter = ZERO_INITIALIZER - 1;

    while ( scanf ( "%s", inputBuffer ) != EOF && validCounter < desiredEntries )
    {
        if ( validateBuffer ( inputBuffer, CWDPtr ))
        {
            if ( validateYear ( CWDPtr ))
            {
                printDate ( CWDPtr );
                if ( desiredEntries != ALL_ENTRIES )
                {
                    validCounter++;
                }
            }
        }
    }

    if(validCounter < desiredEntries && desiredEntries != ALL_ENTRIES)
    {
        printError ( REACHED_END_OF_STREAM_ERROR );
    }
}

/**
 * FUNCTION NAME: isLeapYear;
 * The rules for leap years state that a leap year must meet the fallowing criteria:
 * it must be divisible by 4,
 * it must then  not be divisible by 100,
 * but it must be divisible by 400.
 * There for it is a constant definition that a leap year is one which is
 * mod 4 equals 0, mod 400 equals zero but mod 100 does not equal 0.
 * @parm : int: year to be checked if is leap.
 * @return : returns true if is leap year, false otherwise.
 */
bool isLeapYear(int year)
{
    //THIS NUMBERS ARE NOT MAGIC, READ FUNCTION HEADER!!!!!!!!!!! (EYE!!!!)
    if ( year % 4 == ZERO_INITIALIZER )
    {
        if ( year % 100 == ZERO_INITIALIZER )
        {
            return false;
        } else
        {
            if ( year % 400 == ZERO_INITIALIZER )
            {
                return true;
            }
        }
        return true;
    }
    else
    {
        return false;
    }
}

/**
 * FUNCTION NAME: isShortMonth
 * Function is used to determine if the passed month is a month containing only 30 days,
 * it is common knowledge that only April, June, September and November are months with 30 days
 * @param month : month to check if is short
 * @return true if the month is one of the stated above, false otherwise.
 */
bool isShortMonth(int month)
{
    if ( month == APR || month == JUN || month == SEP || month == NOV )
    {
        return true;
    }
    return false;
}
