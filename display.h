//
// Created by hectorramirez on 11/6/19.
//
#include "validation.h"

#define DATES_PATH "Dates.dat"
#define MODE "r"
#define MONTH_CELL_SIZE 3
#define DAY_CELL_SIZE 2
#define YEAR_CELL_SIZE 20
#define NEW_LINE "\n"
#define PRINT_FORMAT "%*d %s %-*d\n"

const char * MONTH_STRING[] =
        {
        "", "JAN", "FEB", "MAR", "APR","MAY","JUN","JUL","AUG", "SEP", "OCT", "NOV", "DEC"
        };