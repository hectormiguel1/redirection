//
// Created by hectorramirez on 11/6/19.
//
#include "validation.h"
#include "errorPrinter.h"

#define DATES_PATH "Dates.dat"
#define MODE "r"
#define MONTH_CELL_SIZE 3
#define DAY_CELL_SIZE 2
#define YEAR_CELL_SIZE 20
#define NEW_LINE "\n"
#define PRINT_FORMAT "%*d %s %-*d\n"
#define OPEN_DATES_ERROR "UNABLE TO OPEN Dates.dat. FOR READING!"

const char * MONTH_STRING[] =
        {
        "", "JAN", "FEB", "MAR", "APR","MAY","JUN","JUL","AUG", "SEP", "OCT", "NOV", "DEC"
        };

void handleInput();

void printFile(FILE *datesPtr);
