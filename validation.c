//Used to validate Dates
#include "validation.h"

int main(int argc, char * args[])
{
    if ( argc != EXPECTED_ARGS )
        {
        printError (INVALID_ARGUMENTS_ERROR);
        printf ( TERMINATION_SIGNAL );
        return ERROR_EXIT;
        } else
        {
        int desiredEntries = processArgs ( args[ DESIRED_ENTRIES_INDEX ] );
        if ( desiredEntries == SENTINEL_VALUE )
            {
            printError ( DESIRED_ENTRIES_ERROR);
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
 * FUNCTION NAME: printError
 * This function is in charge of printing errors to stderr
 * @param errMsg : message to be printed.
 */
void printError(char * errMsg)
{
    fprintf ( stderr, "%s\n", errMsg);

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
    if ( tmpVal < 0 )
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
        printError (REACHED_END_OF_STREAM_ERROR);
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
    if(year % 4 == ZERO_INITIALIZER)
    {
        if(year % 100 == ZERO_INITIALIZER)
        {
            return false;
        } else
        {
            if(year % 400 == ZERO_INITIALIZER)
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
    if(month == APR || month == JUN || month == SEP || month == NOV)
    {
        return true;
    }
    return false;
}
