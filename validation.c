//Used to validate Dates
#include "validation.h"

bool validateBuffer(char *buffer, Date *);
bool validateYear(Date *pDate);
void printDate(Date *pDate);
int processArgs(char arg[]);
void printError();
void readUntil(int);

int main(int argc, char * args[]) {
    if (argc != EXPECTED_ARGS) {
        fprintf(stderr, "%s \n", "VALIDATION MAIN: ARGUMENTS PASSED ARE NOT VALID");
        printf(TERMINATION_SIGNAL);
        return ERROR_EXIT;
    } else {
        int desiredEntries = processArgs(args[1]);
        if (desiredEntries == SENTINEL_VALUE) {
            printError();
            return ERROR_EXIT;
        } else {
            readUntil(desiredEntries);
        }


    }
    puts(TERMINATION_SIGNAL);
    return NO_ERROR_EXIT;
}

void printError() {
    fprintf(stderr,"%s\n","NON VALID ARGUMENT PASSED");

}

void printDate(Date *pDate) {

    printf("%d/%d/%d \n",pDate->month,pDate->day,pDate->year);
}

bool validateYear( Date *datePtr) {

    bool isLeap = isLeapYear(datePtr->year);

    if(datePtr->year > MAX_YEAR || datePtr->year < MIN_YEAR)
    {
        return false;
    }
    if(datePtr->month > DEC || datePtr->month < JAN)
    {
        return false;
    }
    if(datePtr->month == FEB && isLeap)
    {
        if(datePtr->day < MIN_DAYS || datePtr->day > DAYS_LONG_FEB)
        {
            return false;
        }
    }
    else if(datePtr->month == FEB)
    {
        if(datePtr->day < MIN_DAYS || datePtr->day > DAYS_SHORT_FEB)
        {
            return false;
        }
    }
    if(!isMediumMonth(datePtr->month) && datePtr->month != FEB)
    {
        if(datePtr->day < MIN_DAYS || datePtr->day > DAYS_IN_LONG_MONTH)
        {
            return false;
        }
    }
    else if(isMediumMonth(datePtr->month))
    {
        if (datePtr->day < MIN_DAYS || datePtr->day > DAYS_IN_MED_MONTH)
        {
            return false;
        }
    }
    return true;
}

bool validateBuffer(char *buffer, Date * datePtr)
{
   int day = ZERO_INITIALIZER;
   int month = ZERO_INITIALIZER;
   long year = ZERO_INITIALIZER;

   if(sscanf(buffer,"%d/%d/%ld",&month,&day,&year) != EXPECTED_SSCANF_MATCHES)
   {
       return false;
   }
   else
   {
       if(year > MAX_YEAR || year < MIN_YEAR)
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
    while (arg[counter] != '\0')
    {
        if (!isdigit(arg[counter]))
        {
            return SENTINEL_VALUE;
        }
        counter++;
    }
    int tmpVal = atoi(arg);
    if(tmpVal < 0)
    {
        return SENTINEL_VALUE;
    }
    else
    {
        return tmpVal;
    }
}

void readUntil(int desiredEntries)
{
    Date currentWorkingDate;
    Date *CWDPtr = &currentWorkingDate;
    char inputBuffer[BUFFER_SIZE];
    int validCounter = ZERO_INITIALIZER;

    if(desiredEntries == ALL_ENTRIES)
    {
        while (scanf("%s", inputBuffer) != EOF) {
            if (validateBuffer(inputBuffer, CWDPtr)) {
                if (validateYear(CWDPtr)) {
                    printDate(CWDPtr);
                }
            }
        }
    }
    else
    {
        while (scanf("%s", inputBuffer) != EOF && validCounter < desiredEntries) {
            if (validateBuffer(inputBuffer, CWDPtr)) {
                if (validateYear(CWDPtr)) {
                    printDate(CWDPtr);
                    validCounter++;
                }
            }
        }
    }
}