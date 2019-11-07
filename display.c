//
// Created by hectorramirez on 11/6/19.
//

#include "display.h"

void handleInput();

void printFile(FILE *datesPtr);

int main(void)
{
    FILE *datesPtr = NULL;
    if((datesPtr = fopen(DATES_PATH,MODE)) == NULL)
    {
        fprintf(stderr,"%s%s%s\n","DISPLAY: FAILED TO OPEN ",DATES_PATH, " FOR READING");
    }
    handleInput();
    printFile(datesPtr);
    fclose(datesPtr);
}

void printFile(FILE *datesPtr) {

   char buffer[BUFFER_SIZE];
   while(fscanf(datesPtr,"%s",buffer) != EOF)
   {
       printf("%s\n",buffer);
   }
}

void handleInput() {
    char buffer[BUFFER_SIZE];
    Date currentDate;
    while(scanf("%s",buffer) != EOF && buffer[0] != TERMINATION_SIGNAL[0])
    {
        if(sscanf(buffer,"%d/%d/%d",&currentDate.month,&currentDate.day,&currentDate.year) == EXPECTED_SSCANF_MATCHES) {

            printf(PRINT_FORMAT, DAY_CELL_SIZE, currentDate.day, MONTH_STRING[currentDate.month], YEAR_CELL_SIZE,
                   currentDate.year);
        }
    }
    printf(NEW_LINE);
}
