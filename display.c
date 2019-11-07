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

//TODO HEADER
void printFile(FILE *datesPtr)
{
    
    char buffer[BUFFER_SIZE];
    while ( fscanf ( datesPtr, "%s", buffer ) != EOF)
    {
        printf ( "%s\n", buffer );
    }
}

//TODO FIX MAGIC NUMBERS
void handleInput()
{
    char buffer[BUFFER_SIZE];
    Date currentDate;
    while ( scanf ( "%s", buffer ) != EOF && buffer[ 0 ] != TERMINATION_SIGNAL[ 0 ] )
    {
        if ( sscanf ( buffer, "%d/%d/%d", &currentDate.month, &currentDate.day, &currentDate.year ) ==
             EXPECTED_SSCANF_MATCHES )
        {
            
            printf ( PRINT_FORMAT, DAY_CELL_SIZE, currentDate.day, MONTH_STRING[ currentDate.month ], YEAR_CELL_SIZE,
                     currentDate.year );
        }
    }
    printf ( NEW_LINE );
}
