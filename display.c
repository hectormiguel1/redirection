/*=============================================================================
|   Source code:  [display.c]
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
|               $gcc -std=c99 display.c printError.c –o displayMain
|        [RUN (STAND-ALONE]: running in standalone mode, display will not validate the input,
|                               it will attempt to convert all input from stdin to a date as specified with the
|                               specifications. This will not stop until end of the stream has been reached (EOF)
|               $ ./displayMain
|       [RUN COMBINED] : combined with display, this program will process the input from stdin and send it to main
|                           to be displayed in the specified format as per the specifications.
|               $ ./validationMain [DESIRED NUMBER OF VALID ENTRIES] | ./displayMain
|  +-----------------------------------------------------------------------------
|
|  Description:  [This program will take the input from stdin assume is a valid date and convert it into a string for the
|                  specified format (see project specifications). After the end of the stream from stdin has been reached
|                   or the sentinel value is detected (-1), the program will open "Dates.dat" (assumed to be in the same
|                   directory as the executable) and read the contents of the file and print it to stdout. ]
|
|        Input: [display assumes that the value coming in from stdin is a previously validated date and will transform it
|                   into the string as per the specifications. After that section is complete it will then read input from
|                   "Dates.dat" file (assumed to be in the same directory as the executable).]
|       Output: [The new date string will be printed to stdout as well as the contents of "Dates.dat", error messages will be
|                   printed to stderr. ]
|      Process: [ read string from stdin, convert it into a date type, print the date in the specified format. When stdin
|                   has reached EOF or sentinel value is detected, open "Dates.dat" for reading and prints ints contents to
|                   stdout.]
|
|   Required Features Not Included:[All features are working as expected.]
|
|   Known Bugs:  [No known bugs]
|  *===========================================================================*/
#include "display.h"

int main(void)
{
    FILE * datesPtr = NULL;
    if (( datesPtr = fopen ( DATES_PATH, MODE )) == NULL)
    {
        printError (OPEN_DATES_ERROR);
    }
    handleInput ( );
    printFile ( datesPtr );
    fclose ( datesPtr );
}

/**
 * FUNCTION NAME: printFile
 * This function is designed to take a pointer to a file and print out the contents of the file to stdout
 * @param datesPtr : Pointer to file to print contents of
 * @return N/A
 */
void printFile(FILE *datesPtr)
{
    
    char buffer[BUFFER_SIZE];
    while ( fscanf ( datesPtr, "%s", buffer ) != EOF)
    {
        printf ( "%s\n", buffer );
    }
}

/**
 * FUNCTION NAME: handleInput
 * This function handles all input coming from stdin and buffers into an internal buffer, it then splits it into
 * the proper sections of a date (Assumes that all input from stdin is pre-validated). it does the printing of the final
 * date in the specified format according to program specifications.
 * @param N/A
 * @return N/A
 */
void handleInput()
{
    char buffer[BUFFER_SIZE];
    Date currentDate;
    while ( scanf ( "%s", buffer ) != EOF && buffer[ SENTINEL_VALUE_INDEX ] != TERMINATION_SIGNAL[ SENTINEL_VALUE_INDEX ] )
    {
        if ( sscanf ( buffer, SCANNER_FORMAT, &currentDate.month, &currentDate.day, &currentDate.year ) ==
             EXPECTED_SSCANF_MATCHES )
        {
            
            printf ( PRINT_FORMAT, DAY_CELL_SIZE, currentDate.day, MONTH_STRING[ currentDate.month ], YEAR_CELL_SIZE,
                     currentDate.year );
        }
    }
    printf ( NEW_LINE );
}
