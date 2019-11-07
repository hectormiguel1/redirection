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
 * the proper sections of a date (Assumes that all input from stdin is prevalidated). it does the printing of the final
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
